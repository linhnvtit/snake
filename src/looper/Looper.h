#pragma once

#include <SDL_timer.h>

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
#include <atomic>

#include "../utils/Log.h"
#include "IJob.h"

using namespace std;

class Looper {
   public:
    void addJob(std::unique_ptr<IJob> job) {
        LOGD("Add new action %s", job->TAG.c_str());
        jobs[job->TAG] = std::move(job);
    }

    void run() {
        LOGD("Running");

        isRunning = true;
        while (isRunning.load()) {
            for (auto &pair : jobs) {
                if (!pair.second) continue;
                signalListener(pair.second->execute());
            }

            SDL_Delay(16);

            signalListener(make_unique<Signal>(Signal{SignalType::TICK, {}}));
            SDL_Delay(16);
        }

        jobs.clear();
    }

    void stop() {
        LOGD("Stop");
        isRunning.store(false);
    }

    void setSignalListener(function<void(unique_ptr<Signal>)> func) {
        signalListener = std::move(func);
    }

   private:
    atomic<bool> isRunning = false;
    unordered_map<string, unique_ptr<IJob>> jobs = {};

    function<void(unique_ptr<Signal>)> signalListener;
};
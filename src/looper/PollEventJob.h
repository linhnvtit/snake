#pragma once

#include <SDL_events.h>
#include <SDL_render.h>

#include <string>
#include <unordered_map>

#include "../Type.h"
#include "IJob.h"

class PollEventJob : public IJob {
   public:
    PollEventJob(std::string tag) : IJob(tag) {}

    unique_ptr<Signal> execute() override {
        SignalType signalType = SignalType::TICK;
        unordered_map<string, Object> extras = {};

        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    signalType = SignalType::QUIT;
                    break;
                default:
                    break;
            }
        }

        const Uint8* keyState = SDL_GetKeyboardState(NULL);

        if (keyState[SDL_SCANCODE_UP]) {
            signalType = SignalType::USER_ACTION_MOVE_UP;
        }
        if (keyState[SDL_SCANCODE_DOWN]) {
            signalType = SignalType::USER_ACTION_MOVE_DOWN;
        }
        if (keyState[SDL_SCANCODE_LEFT]) {
            signalType = SignalType::USER_ACTION_MOVE_LEFT;
        }
        if (keyState[SDL_SCANCODE_RIGHT]) {
            signalType = SignalType::USER_ACTION_MOVE_RIGHT;
        }

        return make_unique<Signal>(Signal{signalType, extras});
    }

   private:
    SDL_Event event;
};
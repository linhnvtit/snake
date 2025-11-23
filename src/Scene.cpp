#include "Scene.h"

#include "./looper/DrawJob.h"
#include "looper/PollEventJob.h"

SDL_Window* Scene::getWindow() const {
    return sdlProvider->window;
}

SDL_Renderer* Scene::getRenderer() const {
    return sdlProvider->renderer;
}

MapController& Scene::getMapController() const {
    return *mapController;
}

void Scene::enterScene() {
    LOGD("Enter scene");

    mapController = std::make_unique<MapController>();
    mapController->initMap(32, 32);
    LOGD("Init map");

    looper = std::make_unique<Looper>();
    looper->addJob(make_unique<PollEventJob>("PoolEventJob"));
    looper->addJob(make_unique<DrawJob>(*this, "DrawAction"));
    looper->setSignalListener([this](std::unique_ptr<Signal> s) {
        this->handleSignal(std::move(s));
    });

    LOGD("Finish setup looper, starting..");

    looper->run();
}

void Scene::exitScene() const {
    looper->stop();

    freeResource();
    SDL_Quit();
}

void Scene::freeResource() const {
    SDL_DestroyRenderer(getRenderer());
    SDL_DestroyWindow(getWindow());
}

void Scene::handleSignal(unique_ptr<Signal> signal) {
    // LOGD("Receive signal: %i", static_cast<int>(signal->type));

    switch (signal->type) {
        case SignalType::TICK:
            mapController->updateMap();
            break;

        case SignalType::QUIT:
            LOGD("Receive quit signal");

            exitScene();
            break;

        case SignalType::USER_ACTION_MOVE_DOWN:
        case SignalType::USER_ACTION_MOVE_UP:
        case SignalType::USER_ACTION_MOVE_RIGHT:
        case SignalType::USER_ACTION_MOVE_LEFT:
            mapController->onSnakeMove(signal->type);
            break;

        default: ;
    }
}
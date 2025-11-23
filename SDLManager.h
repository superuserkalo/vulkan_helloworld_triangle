#pragma once

namespace SDLManager {
    class SDL {
    public:
        int run();
        SDL_Window* GetWindow() const;
        int kill();
    private:
        int SDLInit();
        int CreateWindow();
        int SDLDestroy();
        SDL_Window* window = nullptr;
    };
}
#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>

#include <iostream>
#include <vector>

#include "SDLManager.h"
using namespace SDLManager;

 int SDL::run() {
	if (SDLInit() != 0) return 1;
	if (CreateWindow() != 0) return 1;
	return 0; 
 }

int SDL::kill() {
	if (SDLDestroy() != 0) return 1;
	return 0;

}

	int SDL::SDLInit() {
		if (SDL_Init(SDL_INIT_VIDEO) != true) {
			std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";
			return 1;
		}
		return 0;
	}

	int SDL::CreateWindow() {
		window = SDL_CreateWindow(
			"SDL3 + Vulkan Example",
			800, 600,
			SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE
		);
		if (!window) {
			std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << "\n";
			SDL::kill();
			return 1;
		}
		return 0;
	}

	SDL_Window* SDL::GetWindow() const {
		return window;
	}

	int SDL::SDLDestroy() {
		if (window) {
			SDL_DestroyWindow(window);
		}
		SDL_Quit();
		return 0;
	}

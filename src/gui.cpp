// Includes
#include "SDL2/SDL.h"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>


// Main function
int main(int argc, char** args) {

	//
	SDL_Renderer* renderer = nullptr;
	SDL_Window* window = nullptr;
	SDL_Event e;
	bool running = true;
	//
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create window and renderer
	SDL_CreateWindowAndRenderer(1200, 800, 0, &window, &renderer);

	while(running)
	{
	    while(SDL_PollEvent(&e))
		{
		    if(e.type == SDL_QUIT)
			{
			    running = false;
			}
		}


		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

	    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	    SDL_RenderDrawPoint(renderer, 800/2, 600/2);

	    SDL_RenderPresent(renderer);

	}
	return 0;
}

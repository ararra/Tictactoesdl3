#include <stdio.h>

#include "SDL3/SDL.h"

#include <SDL3_image/SDL_image.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480


SDL_Window *g_window;
SDL_Renderer *g_renderer;
SDL_Surface *surface;


SDL_Texture* gameboard;
SDL_Texture* X;
SDL_Texture* O;



bool initialize_game();
void game_loop();

bool shutdown_game();

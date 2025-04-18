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


void mouse_click_action(SDL_Event event);

float position[9][2] = {{110.0,75.0},{330,75},{550,75},{110,225},{330,225},{550,225},{110,390},{330,390},{550,390}};
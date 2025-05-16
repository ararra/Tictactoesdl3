#include <stdio.h>

#include "SDL3/SDL.h"

#include <SDL3_image/SDL_image.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define NUM_TEXTURES 9
SDL_Window *g_window;
SDL_Renderer *g_renderer;
SDL_Surface *g_surface;


SDL_Texture* g_gameboard;
SDL_Texture* g_X;
SDL_Texture* g_O;
//if turn == 1 then  X
//if turn == 0 then O
int g_turn;
SDL_FRect g_clicked_box;

SDL_FRect g_filled_slots[NUM_TEXTURES];
SDL_Texture* g_turn_arr[NUM_TEXTURES];
bool initialize_game();
void game_loop();

bool shutdown_game();


void mouse_click_action(SDL_Event event);

//float square_middle_pos[9][2] = {{110.0,75.0},{330,75},{550,75},{110,225},{330,225},{550,225},{110,390},{330,390},{550,390}};

//
float g_square_x_ends[3] = {0.0, 225.0, 440.0};
float g_square_y_ends[3] = {0.0, 148.0, 303.0};

void find_square(float x, float y);

bool game_win();
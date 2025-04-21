#include "main.h"



int main(int argc, char *argv[])
{
    if(!SDL_SetAppMetadata("A Game", "1.0", ""))
    {
        SDL_GetError();
    }

    initialize_game();
    game_loop();
    shutdown_game();
}


bool initialize_game()
{
    
    SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO| SDL_INIT_EVENTS |SDL_INIT_GAMEPAD);
    g_window = SDL_CreateWindow("Game window", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

    if (g_window == NULL) {
        // In the case that the window could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    g_renderer = SDL_CreateRenderer(g_window, NULL);
    if (g_renderer == NULL) {
        // In the case that the renderer could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create renderer: %s\n", SDL_GetError());
        return 1;
    }
    g_surface = IMG_Load("./assets/Board.png");
    if (g_surface == NULL) {
        // In the case that the surface could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create surface: %s\n", SDL_GetError());
        return 1;
    }

    g_gameboard = SDL_CreateTextureFromSurface(g_renderer, g_surface);
    if (g_gameboard == NULL) {
        // In the case that the gameboard could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create texture gameboard: %s\n", SDL_GetError());
        return 1;
    }    
    g_surface = IMG_Load("./assets/X.png");
    if (g_surface == NULL) {
        // In the case that the surface  X could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create surface X: %s\n", SDL_GetError());
        return 1;
    }
    g_X = SDL_CreateTextureFromSurface(g_renderer, g_surface);
    if (g_X == NULL) {
        // In the case that the X could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create texture X: %s\n", SDL_GetError());
        return 1;
    }    
    g_surface = IMG_Load("./assets/O.png");
    if (g_surface == NULL) {
        // In the case that the surface  O could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create surface O: %s\n", SDL_GetError());
        return 1;
    }
    g_O = SDL_CreateTextureFromSurface(g_renderer, g_surface);
    if (g_O == NULL) {
        // In the case that the O could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create texture O: %s\n", SDL_GetError());
        return 1;
    }
    
    //X starts
    g_turn = 1;
    
    //TODO: Add start button
    //TODO: Add win screen
    
    return true;
}


void game_loop()
{
    bool game_is_running = true;
    //events
    while (game_is_running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {  // poll until all events are handled!
            // decide what to do with this event.
            //check for input
            // Add case for all wanted types of input
            switch (event.type) {
                case SDL_EVENT_MOUSE_BUTTON_DOWN:
                    mouse_click_action(event);
                    break;
                case SDL_EVENT_QUIT:  
                    game_is_running = false;
                    break;

            }
        }  

    // printf("are we here\n");
    SDL_RenderClear(g_renderer);
    SDL_RenderTexture(g_renderer, g_gameboard, NULL, NULL);
    //TODO: Whatever is wrong with this
    //SDL_RenderTexture(g_renderer, g_O, NULL, g_clicked_box);


    SDL_RenderPresent(g_renderer);
    // update game state, draw the current frame

    //logics
    //render
    }
}

bool shutdown_game()
{

    SDL_DestroyWindow(g_window);

    void SDL_Quit(void);

    printf("game has finnished shutting down\n");
    return true;
}

void mouse_click_action(SDL_Event event)
{
    
    float x = event.button.x;
    float y = event.button.y;
    //find_square(x,y);
    //TODO: adding values to g_clicked box crashes the game fix it
    g_clicked_box.w = 50.0;
    g_clicked_box.h = 50.0;


}

//function to find out what square has been selected
//TODO: figure out a more elegant way
void find_square(float x, float y)
{
    int position_x = -1;
    int position_y = -1;
    //check which column
    if(x < g_square_x_ends[1])
    {
        position_x = 0;
    }
    else if (x < g_square_x_ends[2])
    {
        position_x = 1;
    }
    else
    {
        position_x = 2;
    }

    //check which row
    if(y < g_square_y_ends[1])
    {
        position_y = 0;
    }
    else if (y < g_square_y_ends[2])
    {
        position_y = 1;
    }
    else
    {
        position_y = 2;
    }

    g_clicked_box->x = g_square_x_ends[position_x];
    g_clicked_box->y = g_square_y_ends[position_y];

}

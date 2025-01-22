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
        // In the case that the window could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }
    //write error handling on this.
    surface = IMG_Load("../assets/Board.png");
    
    //TODO: INIT other libraries
    //TODO: Load gameboard and pieces.
    
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
                case SDL_EVENT_QUIT:  
                    game_is_running = false;
                    break;

            }
        }  

    //TODO:render tictactoe board
    //TODO:

    SDL_RenderClear(g_renderer);
    //SDL_RenderTexture(g_renderer, bitmapTex, NULL, NULL);
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
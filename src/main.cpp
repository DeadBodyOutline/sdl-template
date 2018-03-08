#include "SDL.h"
#include "SDL_image.h"

constexpr Uint32 fps = 60;
constexpr Uint32 minimumFrameTime = 1000 / fps;
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main(int argc, char **argv) {
    SDL_Init(SDL_INIT_VIDEO);

    // create a window
    SDL_Window *window = SDL_CreateWindow("sdl-template", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!window)
        return 1;

    // now the renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
        return 2;

    SDL_SetRenderDrawColor(renderer, 5, 6, 8, 255);

    // load Dead Body Outline logo TODO
    SDL_Texture *texture = IMG_LoadTexture(renderer, RESOURCES_DIR"/dbo_logo.png");
    if (!texture)
        return 3;

    int textureWidth, textureHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    SDL_Rect textureRect {(WINDOW_WIDTH / 2) - (textureWidth / 2), (WINDOW_HEIGHT / 2) - (textureHeight / 2), textureWidth, textureHeight};

    bool quit = false;
    SDL_Event event;
    Uint32 frameTime;

    while (!quit) {
        frameTime = SDL_GetTicks();

        while (!quit && SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        quit = true;
                    break;
                default:
                    break;
            }
        }

        if (quit) break;

        if (frameTime) {
            // update deltas and last frame time
        }

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, texture, NULL, &textureRect);
        SDL_RenderPresent(renderer);

        if ((SDL_GetTicks() - frameTime) < minimumFrameTime)
            SDL_Delay(minimumFrameTime - (SDL_GetTicks() - frameTime));
    }

    SDL_DestroyTexture(texture);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}

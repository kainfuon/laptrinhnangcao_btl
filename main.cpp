//#include <iostream>
//#include <SDL.h>
//#include <string>
#include "Utils.h"
#include "box.h"
#include "score.h"
//#include <SDL_image.h>

using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
int size = 100;
int size_obj = 50;
const string WINDOW_TITLE = "Snake snake snake";


int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    if (TTF_Init()<0) {
        cout << "Error: " << TTF_GetError() << endl;
    }

    int score = 0;

    int x = SCREEN_WIDTH/7; int y = SCREEN_HEIGHT/2;
    int stepX = 0; int stepY = 0;

    SDL_Event e;

    int threaten_x = SCREEN_WIDTH/2, threaten_y = SCREEN_HEIGHT/2;
    int threaten_x1 = SCREEN_WIDTH, threaten_y1 = SCREEN_HEIGHT/4;

    int ap_x = SCREEN_WIDTH/2, ap_y = SCREEN_HEIGHT/3;
    //int ap_x1 = SCREEN_WIDTH, ap_y1 = SCREEN_HEIGHT/5;

    while (inside(x, y, stepX, stepY, SCREEN_WIDTH, SCREEN_HEIGHT, size) &&
           check(x, y, threaten_x, threaten_y, size, size_obj) &&
           check(x, y, threaten_x1, threaten_y1, size, size_obj)) {


        drawbackground(renderer, 0, 0);
        //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        //SDL_RenderClear(renderer);



        move(x, y, stepX, stepY);
        drawmain (renderer, x, y, size);



        move(threaten_x, threaten_y, -10, 0);
        if (threaten_x<=0) {
                threaten_x=SCREEN_WIDTH; threaten_y = random(threaten_y);
                if ((threaten_y == threaten_y1) or (threaten_y == ap_y)) threaten_y += 50;
        }
        threaten (renderer, threaten_x, threaten_y, size_obj);

        move(threaten_x1, threaten_y1, -15, 0);
        if (threaten_x1<=0) {
                threaten_x1=SCREEN_WIDTH; threaten_y1 = random(threaten_y1);
                if ((threaten_y1 == threaten_y) or (threaten_y1 == ap_y)) threaten_y1 += 50;

        }
        threaten (renderer, threaten_x1, threaten_y1, size_obj);

        move(ap_x, ap_y, -13, 0);
        if (ap_x<=0)  {
                ap_x=SCREEN_WIDTH; ap_y = random(ap_y);
                if ((ap_y == threaten_y) or (ap_y == threaten_y1)) ap_y += 50;
        }

        if ((check(x, y, ap_x, ap_y, size, size_obj) == false)) {
                ap_x=SCREEN_WIDTH; ap_y = random(ap_y); size += 10;
                if ((ap_y == threaten_y) or (ap_y == threaten_y1)) ap_y += 50;
                score++;
                //cout<<score;
        }

        apple (renderer, ap_x, ap_y, size_obj);

        renderScore(renderer, score, SCREEN_WIDTH, SCREEN_HEIGHT);

        SDL_RenderPresent (renderer);
        SDL_Delay(10);

        if (SDL_PollEvent(&e) == 0) continue;
        else if (e.type == SDL_QUIT) break;
        else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_UP: stepY = -10; stepX=0;  break;
                case SDLK_DOWN: stepY = 10; stepX=0;  break;
                case SDLK_LEFT: stepY = 0; stepX=-5;  break;
                case SDLK_RIGHT: stepY = 0; stepX=5;  break;
            }

        }

    }

    gameOver(renderer, e, score, SCREEN_WIDTH, SCREEN_HEIGHT);

    //SDL_RenderPresent (renderer);
    waitUntilKeyPressed();
    TTF_Quit();
    quitSDL(window, renderer);
    return 0;
}

void move_pic(SDL_Renderer* renderer)
{

}


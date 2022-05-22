#include "Utils.h"
#include "box.h"
#include "score.h"
#include "sound.h"

using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
int size = 100;
int size_obj = 50;
int size_thr_w = 200, size_thr_h = 100;
const string WINDOW_TITLE = "fune";
int score = 0;
int speed = 7;

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    if (TTF_Init()<0) {
        cout << "Error: " << TTF_GetError() << endl;
    }

    int x = SCREEN_WIDTH/3; int y = SCREEN_HEIGHT/2;
    int stepX = 0; int stepY = 0;

    SDL_Event e;

    int threaten_x = SCREEN_WIDTH, threaten_y = SCREEN_HEIGHT/2;
    int threaten_x1 = 0, threaten_y1 = SCREEN_HEIGHT/4;

    int ap_x = SCREEN_WIDTH/2, ap_y = SCREEN_HEIGHT/3;

    int background1_x = 0, background2_x = SCREEN_WIDTH;


    playsound();

    while (inside(x, y, stepX, stepY, SCREEN_WIDTH, SCREEN_HEIGHT, size) &&
           check(x, y, threaten_x, threaten_y, size, size_thr_w, size_thr_h) &&
           check(x, y, threaten_x1, threaten_y1, size, size_thr_w, size_thr_h)) {



        drawbackground1(renderer, background1_x, 0);
        drawbackground2(renderer, background2_x, 0);
        background1_x -= 3, background2_x -= 3;
        if (background1_x <= -SCREEN_WIDTH) background1_x = SCREEN_WIDTH;
        if (background2_x <= -SCREEN_WIDTH) background2_x = SCREEN_WIDTH;

        //SDL_SetRenderDrawColor(renderer, 255, 155, 255, 255);
        //SDL_RenderClear(renderer);



        move(x, y, stepX, stepY);
        drawmain (renderer, x, y, size);

        move(threaten_x, threaten_y, -2*speed, 0);
        if (threaten_x<=0) {
                threaten_x=SCREEN_WIDTH; threaten_y = random(threaten_y);
                if (threaten_y == threaten_y1) threaten_y += 100;
        }
        threaten (renderer, threaten_x, threaten_y, size_thr_w, size_thr_h);

        move(threaten_x1, threaten_y1, speed, 0);
        if (threaten_x1>=SCREEN_WIDTH) {
                threaten_x1 = 0; threaten_y1 = random(threaten_y1);
                if (threaten_y1 == threaten_y)  threaten_y1 +=100;

        }
        threaten1 (renderer, threaten_x1, threaten_y1, size_thr_w, size_thr_h);

        move(ap_x, ap_y, -speed, 1);
        if (ap_x<=0 or ap_y>= SCREEN_HEIGHT)  {
                size += 10; //speed += 5;
                ap_x=SCREEN_WIDTH; ap_y = random(ap_y) - 100;
        }

        if ((checkpoint(x, y, ap_x, ap_y, size, size_obj) == false)) {
                ap_x=SCREEN_WIDTH; ap_y = random(ap_y); //size += 10;
                if ((ap_y == threaten_y) or (ap_y == threaten_y1)) ap_y += 50;
                score++;
                if (score % 5 == 0) speed += 3;
                cout<<speed;
                //cout<<score;
        }
        apple (renderer, ap_x, ap_y, size_obj);

        renderScore(renderer, score, SCREEN_WIDTH, SCREEN_HEIGHT);

        SDL_RenderPresent (renderer);
        SDL_Delay(20);

        if (SDL_PollEvent(&e) == 0) continue;
        else if (e.type == SDL_QUIT) break;
        else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_UP: stepY = -speed; stepX=0;  break;
                case SDLK_DOWN: stepY = speed; stepX=0;  break;
                //case SDLK_LEFT: stepY = 0; stepX=-5;  break;
                //case SDLK_RIGHT: stepY = 0; stepX=5;  break;
            }

        }

    }
    Mix_CloseAudio();
    gameOver(renderer, e, score, SCREEN_WIDTH, SCREEN_HEIGHT);

    //SDL_RenderPresent (renderer);
    waitUntilKeyPressed();

    TTF_Quit();
    quitSDL(window, renderer);
    return 0;
}

void move_background(SDL_Renderer* renderer)
{

}


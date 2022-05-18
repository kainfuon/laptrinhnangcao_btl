#ifndef SDL_SCORE_H
#define SDL_SCORE__H
#include <iostream>
#include <SDL_ttf.h>

using namespace std;

void renderScore(SDL_Renderer* renderer, int score, int SCREEN_WIDTH, int SCREEN_HEIGHT);

void gameOver(SDL_Renderer* renderer, SDL_Event event, int sco, int SCREEN_WIDTH, int SCREEN_HEIGHT);

#endif // SDL_SCORE_H

//#include <iostream>
//#include <SDL.h>
#include "box.h"
#include "Utils.h"

//using namespace std;

void box (SDL_Renderer* renderer, int x, int y, int size)
{

    SDL_Rect filled_rect;
    filled_rect.x = x;
    filled_rect.y = y;
    filled_rect.w = size;
    filled_rect.h = size;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &filled_rect);

}

void drawmain (SDL_Renderer* renderer, int x, int y, int size)
{
    SDL_Texture* main = loadTexture("fish.png", renderer);
    SDL_Rect mainRect;
    SDL_QueryTexture(main, NULL, NULL, &mainRect.w, &mainRect.h);
    mainRect.x = x;
    mainRect.y = y;
    mainRect.w = size;
    mainRect.h = size;
    SDL_RenderCopy(renderer, main, NULL, &mainRect);
    SDL_DestroyTexture(main);
    //main = NULL;
}

void threaten (SDL_Renderer* renderer, int x, int y, int size_obj)
{
    SDL_Texture* main = loadTexture("fish1.jpg", renderer);
    SDL_Rect mainRect;
    SDL_QueryTexture(main, NULL, NULL, &mainRect.w, &mainRect.h);
    mainRect.x = x;
    mainRect.y = y;
    mainRect.w = size_obj;
    mainRect.h = size_obj;
    SDL_RenderCopy(renderer, main, NULL, &mainRect);
    SDL_DestroyTexture(main);
    //main = NULL;
}



void apple (SDL_Renderer* renderer, int x, int y, int size_obj)
{
    SDL_Texture* main = loadTexture("cherry.png", renderer);
    SDL_Rect mainRect;
    SDL_QueryTexture(main, NULL, NULL, &mainRect.w, &mainRect.h);
    mainRect.x = x;
    mainRect.y = y;
    mainRect.w = size_obj;
    mainRect.h = size_obj;
    SDL_RenderCopy(renderer, main, NULL, &mainRect);
    SDL_DestroyTexture(main);
    //main = NULL;
}



void drawbackground (SDL_Renderer* renderer, int x, int y)
{
    SDL_Texture* background = loadTexture("bg600.png", renderer);
    SDL_Rect backgroundRect;
    SDL_QueryTexture(background, NULL, NULL, &backgroundRect.w, &backgroundRect.h);
    backgroundRect.x = 0;
    backgroundRect.y = 0;
    SDL_RenderCopy(renderer, background, NULL, &backgroundRect);
    SDL_DestroyTexture(background);
}

void move(int &x, int &y, int stepX, int stepY) {
        x += stepX;
        y += stepY;
}

int random(int draw_y)
{
    srand((int)time(0));
    int r = 1 + rand() % 5;
    draw_y = r*100;
    return draw_y;
}

bool inside(int &x, int &y, int stepX, int stepY, int SCREEN_WIDTH, int SCREEN_HEIGHT, int size) {
        return (0 <= x && 0 <= y && x+stepX <= SCREEN_WIDTH - size + 5  && y+stepY <= SCREEN_HEIGHT - size +5 );

}

bool check(int &x, int &y, int check_x, int check_y, int size, int size_obj)
    {
        if (x + size  >= check_x  && x <= check_x + size_obj &&
            y >= check_y - size && y <= check_y + size_obj) return false;
        return true;
    }

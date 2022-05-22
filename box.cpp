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
    SDL_Texture* main = loadTexture("taungam6.jpg", renderer);
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

void threaten (SDL_Renderer* renderer, int x, int y, int size_obj_w, int size_obj_h)
{
    SDL_Texture* main = loadTexture("threaten.jpg", renderer);
    SDL_Rect mainRect;
    SDL_QueryTexture(main, NULL, NULL, &mainRect.w, &mainRect.h);
    mainRect.x = x;
    mainRect.y = y;
    mainRect.w = size_obj_w;
    mainRect.h = size_obj_h;
    SDL_RenderCopy(renderer, main, NULL, &mainRect);
    SDL_DestroyTexture(main);
    //main = NULL;
}

void threaten1 (SDL_Renderer* renderer, int x, int y, int size_obj_w, int size_obj_h)
{
    SDL_Texture* main = loadTexture("threaten1.jpg", renderer);
    SDL_Rect mainRect;
    SDL_QueryTexture(main, NULL, NULL, &mainRect.w, &mainRect.h);
    mainRect.x = x;
    mainRect.y = y;
    mainRect.w = size_obj_w;
    mainRect.h = size_obj_h;
    SDL_RenderCopy(renderer, main, NULL, &mainRect);
    SDL_DestroyTexture(main);
    //main = NULL;
}

void apple (SDL_Renderer* renderer, int x, int y, int size_obj)
{
    SDL_Texture* main = loadTexture("flower.jpg", renderer);
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



void drawbackground1 (SDL_Renderer* renderer, int x, int y)
{
    SDL_Texture* background = loadTexture("bgr9.1.jpg", renderer);
    SDL_Rect backgroundRect;
    SDL_QueryTexture(background, NULL, NULL, &backgroundRect.w, &backgroundRect.h);
    backgroundRect.x = x;
    backgroundRect.y = y;
    backgroundRect.w = 1200;
    backgroundRect.h = 600;
    SDL_RenderCopy(renderer, background, NULL, &backgroundRect);
    SDL_DestroyTexture(background);
}

void drawbackground2 (SDL_Renderer* renderer, int x, int y)
{
    SDL_Texture* background = loadTexture("bgr9.2.jpg", renderer);
    SDL_Rect backgroundRect;
    SDL_QueryTexture(background, NULL, NULL, &backgroundRect.w, &backgroundRect.h);
    backgroundRect.x = x;
    backgroundRect.y = y;
    backgroundRect.w = 1200;
    backgroundRect.h = 600;
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
    int r = 0 + rand() % 5;
    draw_y = r*100;
    return draw_y;
}

bool inside(int &x, int &y, int stepX, int stepY, int SCREEN_WIDTH, int SCREEN_HEIGHT, int size) {
        return (0 <= x && 0 <= y && x+stepX <= SCREEN_WIDTH - size -5  && y+stepY <= SCREEN_HEIGHT - size  );

}

bool check(int &x, int &y, int check_x, int check_y, int size, int size_obj_w, int size_obj_h)
    {
        if (x + size >= check_x + size_obj_w/2 && x <= check_x + size_obj_w/2 &&
            y + size - size/5 >= check_y && y <= check_y + size_obj_h/2) return false;
        return true;
    }

bool checkpoint (int &x, int &y, int check_x, int check_y, int size, int size_obj)
{
        if (x + size >= check_x + 5 && x <= check_x + size_obj - 5 &&
            y + size - 5 >= check_y && y <= check_y + size_obj - 5) return false;
        return true;
}

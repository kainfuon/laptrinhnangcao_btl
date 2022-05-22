#ifndef SDL_BOX__H
#define SDL_BOX__H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
using namespace std;

void box (SDL_Renderer* renderer, int x, int y, int size);

void drawmain (SDL_Renderer* renderer, int x, int y, int size);

void drawbackground1 (SDL_Renderer* renderer, int x, int y);

void drawbackground2 (SDL_Renderer* renderer, int x, int y);

void threaten (SDL_Renderer* renderer, int x, int y, int size_obj_w, int size_obj_h);

void threaten1 (SDL_Renderer* renderer, int x, int y, int size_obj_w, int size_obj_h);

void apple (SDL_Renderer* renderer, int x, int y, int size_obj);

void move(int &x, int &y, int stepX, int stepY);

bool inside(int &x, int &y, int stepX, int stepY, int SCREEN_WIDTH, int SCREEN_HEIGHT, int size);

bool check(int &x, int &y, int check_x, int check_y, int size, int size_obj_w, int size_obj_h);

bool checkpoint (int &x, int &y, int check_x, int check_y, int size, int size_obj);

int random(int draw_y);

#endif


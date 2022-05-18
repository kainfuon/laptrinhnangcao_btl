#include "score.h"
#include "Utils.h"

void renderScore(SDL_Renderer* renderer, int sco, int SCREEN_WIDTH, int SCREEN_HEIGHT) {
	SDL_Color Black = { 0, 0, 0 };

	// Get the font used for displaying text
	TTF_Font* font = TTF_OpenFont((char*)"arial.ttf", 10);
	if (font == NULL) {
		cout << "Font loading error" << endl;
		return;
	}

	SDL_Surface* score = TTF_RenderText_Solid(font, (string("Score: ") + to_string(sco * 10)).c_str(), Black);
	SDL_Texture* scoreMessage = SDL_CreateTextureFromSurface(renderer, score);
	SDL_Rect scoreRect;
	scoreRect.w = 100;
	scoreRect.h = 30;
	scoreRect.x = SCREEN_WIDTH/3;
	scoreRect.y = 0;
	SDL_RenderCopy(renderer, scoreMessage, NULL, &scoreRect);

	TTF_CloseFont(font);
}

void gameOver(SDL_Renderer* renderer, SDL_Event event, int sco, int SCREEN_WIDTH, int SCREEN_HEIGHT) {
	SDL_Color Red = { 255, 0, 0 };
	//SDL_Color White = { 255, 255, 255 };
	//SDL_Color Black = { 0, 0, 0 };

	// Get the font used for displaying text
	TTF_Font* font = TTF_OpenFont((char*)"arial.ttf", 10);
	if (font == NULL) {
		cout << "Font loading error" << endl;
		return;
	}

	SDL_Surface* gameover = TTF_RenderText_Solid(font, "Game Over", Red);
	//SDL_Surface* retry = TTF_RenderText_Solid(font, "Press Enter to retry", White);
	//SDL_Surface* score = TTF_RenderText_Solid(font, (string("Score: ") + to_string(sco * 10)).c_str(), Black);
	SDL_Texture* gameoverMessage = SDL_CreateTextureFromSurface(renderer, gameover);
	//SDL_Texture* retryMessage = SDL_CreateTextureFromSurface(renderer, retry);
	//SDL_Texture* scoreMessage = SDL_CreateTextureFromSurface(renderer, score);
	SDL_Rect gameoverRect;
	//SDL_Rect retryRect;
	//SDL_Rect scoreRect;
	gameoverRect.w = 200;
	gameoverRect.h = 100;
	gameoverRect.x = SCREEN_WIDTH/3;
	gameoverRect.y = SCREEN_HEIGHT/2;
	//retryRect.w = 300;
	//retryRect.h = 50;
	//retryRect.x = SCREEN_WIDTH/3;
	//retryRect.y = SCREEN_HEIGHT/2 + 150;
	//scoreRect.w = 100;
	//scoreRect.h = 30;
	//scoreRect.x = SCREEN_WIDTH/3;
	//scoreRect.y = 0;
	SDL_RenderCopy(renderer, gameoverMessage, NULL, &gameoverRect);
	//SDL_RenderCopy(renderer, retryMessage, NULL, &retryRect);
	//SDL_RenderCopy(renderer, scoreMessage, NULL, &scoreRect);

	TTF_CloseFont(font);

	// Show game over screen while space has not been pressed
	while (true) {
		SDL_RenderPresent(renderer);

		if (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				exit(0);
			}

			if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
				return;
			}

		}

	}

}

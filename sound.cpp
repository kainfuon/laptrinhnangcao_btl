#include "sound.h"
#include "Utils.h"

void playsound()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
        cout << Mix_GetError();
    }
    Mix_Music* music = NULL;
    music = Mix_LoadMUS("NightOfThePiano.mp3");
    if (music == NULL) {
        cout << Mix_GetError();
    }
    Mix_PlayMusic(music, -1);

    /*if (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				exit(0);
			}

		}*/
}


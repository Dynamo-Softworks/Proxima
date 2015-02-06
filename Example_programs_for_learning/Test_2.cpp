//A thousand pennies to whoever can figure out per-pixel collision!

//Import ALL the files!
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <sstream>
#include <time.h>
#include <iostream>
#include <cmath>
#include <stdlib.h>

//Doesn't need a comment
double x = 0;
double y = 0;

//X and Y velocities along with thrust velocity
double xvel = 0;
double yvel = 0;
double tvel = 0;

//Yup, ignore these just for smoking
/*
double smokex = 0;
double smokey = 0;
double smokexvel = 0;
double smokeyvel = 0;
double smoketvel = 0;
*/

//For the angle
double degrees = 270;
double degreesrate = 0;

//For the clocks
int next = 0;
int nextsmoke = 0;

//A bunch of initialization-ing
int main(int argc, char ** argv)
{
	bool quit = false;
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	//Here is the window!
	SDL_Window * window = SDL_CreateWindow("Shuttled", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	//The 3 sprites used, ignore smoke
	SDL_Surface * image = IMG_Load("Lander.png");
	/*SDL_Surface * smokesurface = IMG_Load("LanderAnim.png");*/
	SDL_Surface * backgroundsurface = IMG_Load("Background.png");
	SDL_Surface * backgroundsurface2 = IMG_Load("Background2.png");
	//And making those into textures
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
	/*SDL_Texture * smoketexture = SDL_CreateTextureFromSurface(renderer, smokesurface);*/
	SDL_Texture * backgroundtexture = SDL_CreateTextureFromSurface(renderer, backgroundsurface);
	SDL_Texture * backgroundtexture2 = SDL_CreateTextureFromSurface(renderer, backgroundsurface2);
	//Now the size and such
	SDL_Rect srcrect = { 0, 0, 32, 25 };
	SDL_Rect srcsmoke = { 0, 0, 1, 1 };
	SDL_Rect srcbackground = { 0, 0, 1280, 480};
	SDL_Rect srcbackground2 = { 0, 0, 1280, 480 };
	//Sets color
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	//Rendering clearing
	SDL_RenderClear(renderer);

	/*SDL_Rect dstsmoke = { x, y, 10, 10 };*/

	SDL_Event e;

	//While not quit...
	while (!quit)
	{
		//Clearing at top, doesn't really matter where I put it.
		SDL_RenderClear(renderer);
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		//Keys and such
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		if (currentKeyStates[SDL_SCANCODE_UP])
		{
			//Slow thrust increase
			tvel += 0.0000001;
			xvel -= tvel * cos(degrees * 3.1415 / 180);
			yvel += tvel * sin(degrees * 3.1415 / 180);
		}
		else{
			//Restarts thrust power if let go, can be increase to give a grace period.
			tvel = 0;
		}
		if (currentKeyStates[SDL_SCANCODE_SPACE])
		{
			tvel += 0.00001;
		}
		if (currentKeyStates[SDL_SCANCODE_DOWN])
		{
			//Stops turning
			degreesrate *= 0.5;
		}
		//Starts turning
		if (currentKeyStates[SDL_SCANCODE_LEFT])
		{
			degreesrate -= 0.000055;
		}
		if (currentKeyStates[SDL_SCANCODE_RIGHT])
		{
			degreesrate += 0.000055;
		}

		//If the current amount of ticks is greater than next...
		if (clock() > next)
		{
			//Add 20 so it does in another twenty ticks
			next += 20;

			//Slow all down. Best if there is a limit to XVEL, even if no atmosphere
			tvel *= 0.985;
			xvel *= 0.985;
			yvel *= 0.985;
			degreesrate *= 0.95;

			//Ignore this thing

			/*if (clock() > nextsmoke){
				nextsmoke += 2000;
				smoketvel = tvel * -1;
				smokex = x + 11;
				smokey = y + 12;
				smokexvel = tvel * cos(degrees * 3.1415 / 180);
				smokeyvel = tvel * sin(degrees * 3.1415 / 180);
				}*/
		}

		//Here is the gravity. Behold, it's wonder.
		yvel += 0.0001;

		//Here we have x movement and y movement happen fluidly
		x += xvel;
		y += yvel;

		//Ignore this
		/*
		smokex += smokexvel;
		smokey += smokeyvel;
		*/

		//Fluid angle turning
		degrees += degreesrate;


		//This whole section is devoted to the stopping of the rocket if it exceeds its bounderies
		//Even though the code is for the ship to remain stationary, the x boundary check is very important
		if (x > 1280){
			x = 0;
		}
		if (x < 0){
			x = 1280;
		}
		//-25 for the sprite size
		if (y > 480 - 25){
			//Temporary bouncing when landing, would be "=0" to stop falling normally
			yvel = -0.1;
			//No falling further
			y = 480 - 25;
			//Slows down the speed of the craft
			xvel *= 0.999;
			//Turns it back over, currently flips until degrees = 0 instead of until degrees % 360 = 0...
			if (degrees > 90){
				degreesrate -= 0.0001;
			}
			if (degrees < 90){
				degreesrate += 0.0001;
			}
			//If in center, stop rotating, else it just wobbles
			if (91 > degrees){
				if (degrees > 89){
					degreesrate = 0;
				}
			}
		}


		SDL_Rect dstbackground2 = { x, 0, 1280, 480 };
		SDL_RenderCopyEx(renderer, backgroundtexture2, &srcbackground2, &dstbackground2, 0, 0, SDL_FLIP_NONE);
		SDL_Rect dstbackground2add = { x - 1280, 0, 1280, 480 };
		SDL_RenderCopyEx(renderer, backgroundtexture2, &srcbackground2, &dstbackground2add, 0, 0, SDL_FLIP_NONE);
		//If you string two together it makes the background loop fluently.
		SDL_Rect dstbackground = { x, 0, 1280, 480 };
		SDL_RenderCopyEx(renderer, backgroundtexture, &srcbackground, &dstbackground, 0, 0, SDL_FLIP_NONE);
		SDL_Rect dstbackgroundadd = { x - 1280, 0, 1280, 480 };
		SDL_RenderCopyEx(renderer, backgroundtexture, &srcbackground, &dstbackgroundadd, 0, 0, SDL_FLIP_NONE);

		//Now x is just the middle column
		SDL_Rect dstrect = { 320, y, 32, 25 };
		SDL_RenderCopyEx(renderer, texture, &srcrect, &dstrect, degrees - 270, 0, SDL_FLIP_HORIZONTAL);

		//More smoke stuff...
		/*
		//SDL_Rect dstsmoke = { smokex, smokey, 10, 10 };
		//SDL_RenderCopyEx(renderer, smoketexture, &srcsmoke, &dstsmoke, 0, 0, SDL_FLIP_NONE);
		*/
		int SDL_RenderReadPixels(SDL_Renderer* renderer, const SDL_Rect* rect, Uint32 format, void* pixels, int pitch);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}

#include<bits/stdc++.h>
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "game.h"
using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* texture[10];
SDL_Surface* surface[10];
TTF_Font *font = NULL;

void initWindow()
{
	if( SDL_Init( SDL_INIT_VIDEO ) >= 0 )
	{
		window = SDL_CreateWindow( "DOTS AND BOXES", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window != NULL )
		{
			renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
			if( renderer != NULL )
				SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
		}
	}
	surface[0] = IMG_Load("background.png");
	texture[0] = SDL_CreateTextureFromSurface( renderer, surface[0] );
	surface[1] = IMG_Load("x.png");
	texture[1] = SDL_CreateTextureFromSurface( renderer, surface[1] );
	surface[2] = IMG_Load("o.png");
	texture[2] = SDL_CreateTextureFromSurface( renderer, surface[2] );
	surface[3] = IMG_Load("start.png");
	texture[3] = SDL_CreateTextureFromSurface( renderer, surface[3] );
	surface[4] = IMG_Load("player.png");
	texture[4] = SDL_CreateTextureFromSurface( renderer, surface[4] );
	surface[5] = IMG_Load("computer.png");
	texture[5] = SDL_CreateTextureFromSurface( renderer, surface[5] );
	surface[6] = IMG_Load("draw.png");
	texture[6] = SDL_CreateTextureFromSurface( renderer, surface[6] );

}

void loadMedia(int ob,int x,int y)
{
	SDL_Rect dest = {x, y,surface[ob]->w,surface[ob]->h};

    SDL_RenderCopy(renderer, texture[ob], NULL, &dest);
}
void startGame()
{
    loadMedia(3,0,0);
     SDL_RenderPresent(renderer);
}
void endGame(int winner)
{
    loadMedia(winner+4,0,0);
    SDL_RenderPresent(renderer);
}
void Game::render()
{
    loadMedia(0,0,0);
    for(int i = 0; i<numCell; i++)
        for(int j = 0; j<numCell; j++)
            if(board[i][j]!=-1)
            loadMedia(board[i][j]+1,i*100+10,j*100+10);
    SDL_RenderPresent(renderer);
}
void close()
{
	for(int i = 0; i<10;i++)
	SDL_DestroyTexture( texture[i] );
	for(int i = 0; i<10;i++)
    SDL_FreeSurface(surface[i]);
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	window = NULL;
	renderer = NULL;
	IMG_Quit();
	SDL_Quit();
}


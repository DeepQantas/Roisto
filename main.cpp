/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Teemu
 *
 * Created on 16. helmikuuta 2016, 15:44
 */

#include <cstdlib>
#include <iostream>

// Remember compiler options:
// -lmingw32 -lSDL2main -lSDL2.dll
#include <SDL2/SDL.h>

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/*
 * 
 */
int main(int argc, char** argv) {
    // Initialize SDL
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }
    
    //
    
    // End program
    cout << "All good! Goodbye!" << endl;
    
    return 0;
}


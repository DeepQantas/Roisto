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

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Hello World!" << endl;
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Quit();
    
    cout << "Goodbye!" << endl;
    return 0;
}


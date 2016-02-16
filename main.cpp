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

// Standard libraries
#include <cstdlib>
#include <iostream>

using namespace std;

// SDL libraries
#include <SDL.h>
#include "SDL_image.h"

// Our Classes
#include "CApp.h"

/*
 * 
 */
int main(int argc, char** argv) {
    // Initialize
    CApp Client;
    Client.bRunning = Client.initializeSDL();
    
    
    // Main loop
    int i = 0;
    
    while ( Client.bRunning ) {
        Client.update();
        SDL_Delay( 20 );
        
        i++;
        if ( i > 100 ) {
            Client.bRunning = false;
        }
    }
    
    
    // Close
    Client.shutdown();
    
    return 0;
}


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

#include "CApp.h"

using namespace std;
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
        Client.handleEvents();
        Client.draw();
        Client.updateScreen();
        
        SDL_Delay( 33 );
    }
    
    
    // Close
    Client.shutdown();
    
    return 0;
}


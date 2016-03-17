/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CApp.cpp
 * Author: Teemu
 * 
 * Created on 16. helmikuuta 2016, 21:16
 */

#include "CApp.h"

CApp::CApp() {
    window = NULL;
    bRunning = true;
    
    startingTile = 0;
    tileOffset = 0;
}

CApp::~CApp() {
}


bool CApp::initializeSDL() {
    // Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "Roistomainen a0.01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
            return false;
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );
            
            if ( screenSurface ) {
                cout << "Got a screenSurface!" << endl;
            }
            else {
                cout << "screenSurface == NULL" << endl;
                return false;
            }
            
            // Create tiled texture
            tiles = TileTexture::loadTileTexture("resources/terrain.png");
        }
    }
    
    return true;
}


void CApp::handleEvents() {
    SDL_Event e;
    
    while( SDL_PollEvent( &e ) != 0 )
    {
        switch (e.type) {
            case SDL_QUIT:
                bRunning = false;
                break;
            default:
                break;
        }
    }
}


void CApp::draw() {
    // Dancing tiles or something
    SDL_FillRect( screenSurface, NULL, 0 );
    
    if ( tiles != NULL ) 
    {
        for ( int i = 0; i<360; i++ ) 
        {
            tiles->drawTile( i + startingTile, 34*(i%16) - tileOffset, 34*(i/16) );
        }
        
        tileOffset++;
        if (tileOffset >= 34) 
        {
            tileOffset -= 34;
            startingTile++;
        }
    } 
    else 
    {
        // Texture missing
        bRunning = false;
    }
    
}

void CApp::updateScreen() {
    //Update the surface
    SDL_UpdateWindowSurface( window );
}


void CApp::shutdown() {
    //Deallocate surface
    SDL_FreeSurface( screenSurface );
    screenSurface = NULL;
    
    //Destroy window
    if ( window != NULL ) {
        SDL_DestroyWindow( window );
        window = NULL;
    }
    
    //Quit SDL subsystems
    SDL_Quit();
}

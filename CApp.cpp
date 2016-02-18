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
            TileTexture* tiles = TileTexture::loadTileTexture("resources/terrain.png");
            
            if ( tiles != NULL ) {
                for ( int i = 0; i<360; i++ ) {
                    tiles->drawTile( i, 34*(i%16), 34*(i/16) );
                }
            }
        }
    }
    
    return true;
}

void CApp::update() {
    if ( bRunning ) {
        //Update the surface
        SDL_UpdateWindowSurface( window );
    }
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

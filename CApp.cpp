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
    screenSurface = NULL;
    
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

            // Load image and draw it on screen
            SDL_Surface* surf = loadMedia();
            SDL_BlitSurface( surf, NULL, screenSurface, NULL );
            
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

SDL_Surface* CApp::loadMedia()
{
    SDL_Surface* surf;
    surf = IMG_Load("resources/windrunner_by_lddmitry.jpg");
    
    if( !surf ) {
        cout << "IMG_Load: " << SDL_GetError() << endl;
        
    }
    
    return surf;
}
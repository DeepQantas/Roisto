/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TileTexture.h
 * Author: Seepra
 *
 * Created on 18 February 2016, 18:32
 */

#ifndef TILETEXTURE_H
#define TILETEXTURE_H

// Standard libraries
#include <cstdlib>
#include <iostream>

// SDL libraries
#include <SDL.h>
#include "SDL_image.h"

// Our headers
#include "Globals.h"

using namespace std;

class TileTexture {
public:
    TileTexture();
    virtual ~TileTexture();
    
    static TileTexture* loadTileTexture( const char* file );
    bool drawTile( int subimg, int x, int y );
private:
    SDL_Surface* tileSurface;
    SDL_Rect sourceRect;
    
    int columns, rows;
};

#endif /* TILETEXTURE_H */


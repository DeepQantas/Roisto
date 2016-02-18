/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TileTexture.cpp
 * Author: Seepra
 * 
 * Created on 18 February 2016, 18:32
 */

#include "TileTexture.h"

TileTexture::TileTexture() {
    tileSurface = NULL;
    sourceRect.w = 32;
    sourceRect.h = 32;
    sourceRect.x = 0;
    sourceRect.y = 0;
    rows = 0;
    columns = 0;
}

TileTexture::~TileTexture() {
}

TileTexture* TileTexture::loadTileTexture( const char* file ) {
    TileTexture* tiles;
    SDL_Surface* surf;
    
    surf = IMG_Load( file );
    
    if( !surf ) {
        cout << "Error loading from texture file\n IMG_Load: " << SDL_GetError() << endl;
        return NULL;
    }
    
    tiles = new TileTexture;
    tiles->tileSurface = surf;
    
    // Find out the dimension
    if ( surf->w < tiles->sourceRect.w ) {
        tiles->sourceRect.w = surf->w;
        tiles->columns = 1;
    }
    else {
        tiles->columns = surf->w / tiles->sourceRect.w;
    }
    
    if ( surf->h < tiles->sourceRect.w ) {
        tiles->sourceRect.h = surf->h;
        tiles->rows = 1;
    }
    else {
        tiles->rows = surf->h / tiles->sourceRect.h;
    }
    
    return tiles;
}

bool TileTexture::drawTile( int subimg, int x, int y ) {
    if ( screenSurface == NULL ) {
        cout << "Drawing to NULL screenSurface!" << endl;
        return false;
    }
    
    if ( tileSurface == NULL ) {
        cout << "TileTexture's surface points to NULL!" << endl;
        return false;
    }
    
    SDL_Rect targetRect;
    targetRect.x = x;
    targetRect.y = y;
    targetRect.w = sourceRect.w;
    targetRect.h = sourceRect.h;
    
    sourceRect.x = sourceRect.w * ( subimg % columns );
    sourceRect.y = sourceRect.h * ( (subimg / columns) % rows );
    
    SDL_BlitSurface( tileSurface, &sourceRect, screenSurface, &targetRect );
    
    return true;
}
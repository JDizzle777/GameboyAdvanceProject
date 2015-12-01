// sprites.h
// GBA sprite data
// This file was automatically generated by Spritely 

#ifndef _SPRITES_H_
#define _SPRITES_H_

#include "palettes.h"

typedef struct {
	// Index (into SpriteInfo) of first sprite.
	short int first_sprite;
	// Total number of sprites in this spriteset.
	short int num_sprites;
	// Total number of tiles in this spriteset.
	short int num_tiles;
	// Index (into SpritePaletteInfo) of palette.
	short int palette_id;
} SpritesetInfoStruct;

// Structure to store basic information for each sprite
typedef struct {
	// Index (into SpriteTiles) of first tile for this sprite.
	int first_tile;
	short int num_tiles;
	int width;
	int height;
	// For 16-color palettes, this is the subpalette index for this sprite.
	int subpalette_id;
	int mask_index;
	int shape;
	int size;
   int numParent; // if the sprite is a laser, keeps track of which alien shot it
} SpriteInfoStruct;

// These sprite/palette data arrays are defined in sprites.cpp

// General info about each foreground ("sprite") palette.
extern const PaletteInfoStruct SpritePaletteInfo[];

// Color data for all the sprite palettes.
extern const unsigned short int SpritePalettes[];

// General info about each Spriteset.
extern const SpritesetInfoStruct SpritesetInfo[];

// General info about each Sprite.
extern SpriteInfoStruct SpriteInfo[];

// Sprite tile data.
extern const unsigned char SpriteTiles[];

// Sprite collision bitmasks (used for pixel-perfect collision detection).
extern const unsigned long int SpriteMasks[];

// Number of (foreground) palettes.
const int kNumPalettes = 1;

// Number of (foreground) spritesets.
const int kNumSpritesets = 1;

// Total number of sprites in all (foreground) spritesets.
const int kTotalSprites = 6;

// Total number of tiles in all (foreground) spritesets.
const int kTotalTiles = 66;

// Spriteset IDs
const int kSpriteset_sprites = 0;

// Sprite IDs
const int ksprites_Laser = 0;
const int ksprites_Laser_Blue = 1;
const int ksprites_SpaceManMike = 2;
const int ksprites_SpaceManMike_Dead = 3;
const int ksprites_Alien = 4;
const int ksprites_Monster = 5;


void setAlientoLaser(int numLaser, int numAlien);
int getAlientoLaser(int numLaser);

#endif	// _SPRITES_H_
// sprites.cpp
// GBA sprite data
// This file was automatically generated by Spritely 

#include <gba_sprites.h>

#include "sprites.h"

// General info about each foreground ("sprite") palette.
const PaletteInfoStruct SpritePaletteInfo[] = {
	{   0,  true }, // Palette #0 : Pal16
};

// Color data for all the sprite palettes.
const unsigned short int SpritePalettes[] = {
	// Palette : Pal16 [16-color]
	// Subpalette #0
	0x7fff,0x0001,0x0010,0x0200,0x7fff,0x4210,0x001f,0x03e0,
	0x0210,0x4000,0x4010,0x4200,0x03ff,0x7c00,0x7c1f,0x7fe0,
	// Subpalette #1
	0x7fff,0x0000,0x7fff,0x0c59,0x0e04,0x6d08,0x0fdf,0x6b64,
	0x56b5,0x318c,0x0d11,0x5a9f,0x4351,0x7e93,0x1e7f,0x5cd1,
	// Subpalette #2
	0x7fff,0x0000,0x0842,0x1084,0x18c6,0x2108,0x294a,0x318c,
	0x4210,0x4e73,0x56b5,0x5ef7,0x6739,0x6f7b,0x77bd,0x7fff,
	// Subpalette #3
	0x7fff,0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	// Subpalette #4
	0x7fff,0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	// Subpalette #5
	0x7fff,0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	// Subpalette #6
	0x7fff,0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	// Subpalette #7
	0x7fff,0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	// Subpalette #8
	0x7fff,0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	// Subpalette #9
	0x7fff,0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	// Subpalette #10
	0x7fff,0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	// Subpalette #11
	0x7fff,0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	// Subpalette #12
	0x7fff,0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	// Subpalette #13
	0x7fff,0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	// Subpalette #14
	0x7fff,0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	// Subpalette #15
	0x7fff,0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
};

// General info about each Spriteset.
const SpritesetInfoStruct SpritesetInfo[] = {
	{   0,   6,  66,   0 }, // Spriteset #0 : sprites
};

// General info about each Sprite.
SpriteInfoStruct SpriteInfo[] = {
	{   0,   1,   8,   8,   0,   0,    ATTR0_SQUARE,    ATTR1_SIZE_8 }, // Sprite_Laser
	{   1,   1,   8,   8,   0,   8,    ATTR0_SQUARE,    ATTR1_SIZE_8 }, // Sprite_Laser_Blue
	{   2,  16,  32,  32,   0,  16,    ATTR0_SQUARE,   ATTR1_SIZE_32 }, // Sprite_SpaceManMike
	{  18,  16,  32,  32,   0,  48,    ATTR0_SQUARE,   ATTR1_SIZE_32 }, // Sprite_SpaceManMike_Dead
	{  34,  16,  32,  32,   0,  80,    ATTR0_SQUARE,   ATTR1_SIZE_32 }, // Sprite_Alien
	{  49,  16,  32,  32,   0, 104,    ATTR0_SQUARE,   ATTR1_SIZE_32 }, // Sprite_Monster
};

// Sprite tile data.
const unsigned char SpriteTiles[] = {
	// Sprite : Laser
	// Size : 1x1 = 1 tiles
	// Tile #0
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x60,0x66,0x06,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,

	// Sprite : Laser_Blue
	// Size : 1x1 = 1 tiles
	// Tile #1
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0xd0,0xdd,0x0d,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,

	// Sprite : SpaceManMike
	// Size : 4x4 = 16 tiles
	// Tile #2
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #3
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #4
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #5
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #6
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #7
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x10,0x11,
	0x00,0x00,0x41,0x44,
	0x00,0x10,0x44,0x11,
	0x00,0x20,0x42,0x11,
	// Tile #8
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x01,0x00,0x00,0x00,
	0x14,0x00,0x00,0x00,
	0x11,0x01,0x00,0x00,
	0x11,0x02,0x00,0x00,
	// Tile #9
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #10
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #11
	0x00,0x10,0x44,0x11,
	0x00,0x00,0x41,0x44,
	0x00,0x11,0x11,0x11,
	0x10,0x44,0x64,0x66,
	0x10,0x44,0x64,0x16,
	0x10,0xdd,0x64,0x51,
	0x10,0x44,0x41,0x51,
	0x00,0x11,0x11,0x51,
	// Tile #12
	0x41,0x01,0x00,0x00,
	0x14,0x00,0x00,0x00,
	0x11,0x11,0x00,0x00,
	0x41,0x44,0x01,0x00,
	0x15,0x11,0x11,0x11,
	0x55,0x55,0x55,0x55,
	0x1f,0xd1,0x11,0x11,
	0x1f,0xdd,0xfd,0x00,
	// Tile #13
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x01,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #14
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #15
	0x00,0x00,0x41,0x16,
	0x00,0x00,0x11,0x11,
	0x00,0x00,0x41,0x44,
	0x00,0x00,0x41,0x11,
	0x00,0x00,0x41,0x11,
	0x00,0x00,0x41,0x11,
	0x00,0x10,0xf1,0x11,
	0x00,0xf1,0xff,0x11,
	// Tile #16
	0x11,0xdd,0xfd,0x00,
	0x11,0x11,0x01,0x00,
	0x14,0x00,0x00,0x00,
	0x14,0x00,0x00,0x00,
	0x14,0x00,0x00,0x00,
	0x14,0x00,0x00,0x00,
	0x1f,0x01,0x00,0x00,
	0xff,0x1f,0x00,0x00,
	// Tile #17
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,

	// Sprite : SpaceManMike_Dead
	// Size : 4x4 = 16 tiles
	// Tile #18
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #19
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #20
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #21
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #22
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #23
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #24
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #25
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #26
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x10,
	0x00,0x00,0x00,0x41,
	// Tile #27
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x10,0x11,
	0x00,0x00,0x41,0xd4,
	0x21,0x01,0x41,0x11,
	0x11,0x14,0x41,0x11,
	0x11,0x41,0x61,0x66,
	// Tile #28
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x11,0x00,0x00,
	0x11,0xff,0x01,0x00,
	0x44,0xff,0x01,0x00,
	0x11,0x1f,0x00,0x00,
	0x11,0x11,0x11,0x11,
	0x44,0x14,0x44,0x44,
	// Tile #29
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x10,0x00,0x00,0x00,
	0xf1,0x00,0x00,0x00,
	0xf1,0x00,0x00,0x00,
	0xff,0x00,0x00,0x00,
	// Tile #30
	0x00,0x00,0x00,0x41,
	0x00,0x00,0x00,0x41,
	0x00,0x00,0x00,0x41,
	0x00,0x00,0x00,0x10,
	0x00,0x00,0x60,0x66,
	0x00,0x60,0x66,0x66,
	0x00,0x66,0x66,0x66,
	0x00,0x66,0x66,0x66,
	// Tile #31
	0x11,0x41,0x61,0x66,
	0x11,0x41,0x61,0x66,
	0x44,0x44,0x61,0x66,
	0x44,0x14,0x41,0x11,
	0x21,0x61,0x41,0xd4,
	0x26,0x66,0x41,0xd4,
	0x66,0x66,0x66,0x11,
	0x66,0x66,0x66,0x66,
	// Tile #32
	0x66,0x16,0x14,0x11,
	0x66,0x16,0x14,0x11,
	0x44,0x14,0x44,0x44,
	0x11,0x11,0x11,0x11,
	0x44,0x1f,0x66,0x66,
	0x44,0xff,0x61,0x66,
	0x11,0xff,0x61,0x66,
	0x66,0x11,0x66,0x66,
	// Tile #33
	0x11,0x00,0x00,0x00,
	0x11,0x00,0x00,0x00,
	0xff,0x00,0x00,0x00,
	0xf1,0x00,0x00,0x00,
	0xf1,0x00,0x00,0x00,
	0x16,0x00,0x00,0x00,
	0x66,0x00,0x00,0x00,
	0x66,0x06,0x00,0x00,

	// Sprite : Alien
	// Size : 4x4 = 16 tiles
	// Tile #34
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #35
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #36
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #37
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #38
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #39
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x10,0x11,
	0x00,0x00,0x31,0x33,
	// Tile #40
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x01,0x00,0x00,0x00,
	0x13,0x00,0x00,0x00,
	// Tile #41
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #42
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #43
	0x00,0x10,0x33,0x36,
	0x00,0x10,0x33,0x63,
	0x00,0x00,0x31,0x33,
	0x00,0x00,0x10,0x33,
	0x00,0x00,0x31,0x11,
	0x00,0x10,0x33,0x33,
	0x00,0x31,0x31,0x11,
	0x00,0x31,0x11,0xd1,
	// Tile #44
	0x63,0x01,0x00,0x00,
	0x63,0x01,0x00,0x00,
	0x16,0x00,0x00,0x00,
	0x01,0x00,0x00,0x00,
	0x13,0x00,0x00,0x00,
	0x33,0x01,0x00,0x00,
	0x11,0x11,0x11,0x11,
	0x65,0x56,0x55,0x55,
	// Tile #45
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x01,0x00,0x00,0x00,
	// Tile #46
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #47
	0x00,0x31,0x33,0x11,
	0x00,0x10,0x11,0x13,
	0x00,0x00,0x11,0x11,
	0x00,0x00,0x31,0x33,
	0x00,0x00,0x31,0x11,
	0x00,0x00,0x31,0x11,
	0x00,0x10,0x31,0x11,
	0x00,0x31,0x33,0x11,
	// Tile #48
	0x15,0x11,0x11,0x11,
	0x15,0x31,0x13,0x00,
	0x11,0x10,0x01,0x00,
	0x13,0x00,0x00,0x00,
	0x13,0x00,0x00,0x00,
	0x13,0x00,0x00,0x00,
	0x13,0x01,0x00,0x00,
	0x33,0x13,0x00,0x00,
	// Tile #49
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,

	// Sprite : Monster
	// Size : 4x4 = 16 tiles
	// Tile #49
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #50
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #51
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #52
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #53
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #54
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #55
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #56
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #57
	0x00,0x00,0x00,0xf0,
	0x00,0x00,0x00,0xf0,
	0x00,0xf0,0x00,0x00,
	0x00,0xf0,0x00,0xff,
	0x00,0xf0,0xff,0xff,
	0x00,0x00,0xf0,0xff,
	0x00,0x00,0xf0,0xff,
	0xf0,0x0f,0xf0,0xff,
	// Tile #58
	0x00,0xf0,0x0f,0x00,
	0x0f,0xf0,0x0f,0x00,
	0xff,0xff,0xff,0xff,
	0xff,0xff,0x6f,0xff,
	0xff,0xff,0x6f,0xf6,
	0xff,0xff,0xff,0x66,
	0xff,0xff,0xff,0x6f,
	0xff,0xff,0xff,0xff,
	// Tile #59
	0xff,0x00,0x0f,0x00,
	0xff,0xff,0x00,0x00,
	0xff,0x0f,0xf0,0xff,
	0xff,0xff,0xff,0x00,
	0xff,0x6f,0xf6,0x00,
	0xff,0x66,0xff,0x00,
	0xf6,0xf6,0xff,0x00,
	0x66,0xf6,0xff,0x0f,
	// Tile #60
	0x00,0x00,0x00,0x00,
	0xff,0x00,0x00,0x00,
	0x0f,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #61
	0x00,0xff,0xff,0xff,
	0x00,0x00,0xf0,0xff,
	0x00,0x00,0xf0,0xff,
	0x00,0x00,0xff,0xff,
	0x00,0xff,0x00,0xff,
	0xf0,0x0f,0x00,0xff,
	0xf0,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	// Tile #62
	0xff,0xff,0xff,0xff,
	0xff,0x1f,0x61,0x61,
	0xff,0xff,0x11,0x11,
	0xff,0xff,0x11,0x11,
	0xff,0xff,0x1f,0x66,
	0xff,0xff,0xff,0x6f,
	0xff,0xff,0xff,0xff,
	0xff,0x00,0xff,0x00,
	// Tile #63
	0xff,0xff,0xff,0xff,
	0x61,0x61,0xf1,0xf0,
	0x11,0x11,0xf1,0x00,
	0x11,0x11,0x01,0x00,
	0x61,0x61,0x0f,0x00,
	0x61,0xf1,0xff,0xff,
	0xff,0x0f,0x00,0xf0,
	0xf0,0x0f,0x00,0x00,
	// Tile #64
	0x00,0x00,0x00,0x00,
	0x0f,0x00,0x00,0x00,
	0xf0,0x0f,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0xff,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
};

// Sprite collision bitmasks (used for pixel-perfect collision detection).
const unsigned long int SpriteMasks[] = {
	// Sprite : Laser
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x78000000,
	0x00000000,
	0x00000000,
	0x00000000,

	// Sprite : Laser_Blue
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x78000000,
	0x00000000,
	0x00000000,
	0x00000000,

	// Sprite : SpaceManMike
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00078000,
	0x000fc000,
	0x001fe000,
	0x001fe000,
	0x001fe000,
	0x000fc000,
	0x003ff000,
	0x007ff800,
	0x007fff00,
	0x007fff80,
	0x007fff00,
	0x003ffc00,
	0x000ffc00,
	0x000ff800,
	0x000fc000,
	0x000fc000,
	0x000fc000,
	0x000fc000,
	0x001fe000,
	0x003ff000,

	// Sprite : SpaceManMike_Dead
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00003000,
	0x0007f800,
	0x000ff840,
	0x00eff0c0,
	0x01ffffc0,
	0x03ffffc0,
	0x03ffffc0,
	0x03ffffc0,
	0x03ffffc0,
	0x01ffffc0,
	0x07ffffc0,
	0x1fffffc0,
	0x3fffffc0,
	0x3fffffe0,

	// Sprite : Alien
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00078000,
	0x000fc000,
	0x001fe000,
	0x001fe000,
	0x000fc000,
	0x00078000,
	0x000fc000,
	0x001fe000,
	0x003fff00,
	0x003fff80,
	0x003fff00,
	0x001ffc00,
	0x000fd800,
	0x000fc000,
	0x000fc000,
	0x000fc000,
	0x001fe000,
	0x003ff000,

	// Sprite : Monster
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x0118c800,
	0x0198f0c0,
	0x10ffe780,
	0x13fffc00,
	0x1ffffc00,
	0x07fffc00,
	0x07fffc00,
	0x67fffe00,
	0x3fffff00,
	0x07fffd80,
	0x07fffc60,
	0x0ffff800,
	0x33fff800,
	0x63ffff00,
	0x40ffe1c0,
	0x00cc6000,
};

// set parent of a laser
void setAlientoLaser(int numLaser, int numAlien){
   SpriteInfo[numLaser].numParent = numAlien;
}

// get parent of a laser
int getAlientoLaser(int numLaser){
   return SpriteInfo[numLaser].numParent;
}

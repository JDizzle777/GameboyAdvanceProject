// background_maps.h
// GBA background tile, palette and map data
// This file was automatically generated by Spritely 

#ifndef _BACKGROUND_MAPS_H_
#define _BACKGROUND_MAPS_H_

#include "palettes.h"

typedef struct {
	// Index (into BackgroundTiles) of first tile in this bg tileset.
	short int first_tile;
	// Total number of tiles in this bg tileset.
	short int num_tiles;
	// Index (into BackgroundPaletteInfo) of palette.
	short int palette_id;
} BgTilesetInfoStruct;

// Structure to store basic information for each background map
typedef struct {
	// Offset (into BackgroundTileMap) to first entry for this map.
	short int first_entry;
	// Width/height for this map.
	short int width, height;
} BgMapInfoStruct;

// These tile/palette/map data arrays are defined in background_maps.cpp

// General info about each background palette.
extern const PaletteInfoStruct BgPaletteInfo[];

// Color data for all the background palettes.
extern const unsigned short int BgPalettes[];

// General info about each BgTileset.
extern const BgTilesetInfoStruct BgTilesetInfo[];

// Background tile data.
extern const unsigned char BgTiles[];

// General info about each background map.
extern const BgMapInfoStruct BgMapInfo[];

// Background Tile Map
//
//  15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
// +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
// |      PAL      | V | H |                 TILE                  |
// +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
//   0-9: TILE - tile id
//    10: H - horizontal flip
//    11: V - vertical flip
// 12-15: PAL - palette index
//        used only for BG_COLOR16 backgrounds
extern const unsigned short int BgMapData[];

// Number of bytes per background map entry.
const int kBytesPerBgMapEntry = 2;

// Number of background palettes.
const int kNumBgPalettes = 1;

// Number of background tilesets.
const int kNumBgTilesets = 1;

// Number of background maps.
const int kNumBgMaps = 1;

// Total number of tiles in all background tilesets.
const int kTotalBgTiles = 6;

// Background tileset IDs
const int kBgTileset_sprites = 0;

// Background tile IDs
const int ksprites_BG = 0;
const int ksprites_Platform1 = 1;
const int ksprites_Platform2 = 2;
const int ksprites_Platform3 = 3;
const int ksprites_Star = 4;
const int ksprites_Ground = 5;

// Map IDs
const int kBgMap_map = 0;

#endif	// _BACKGROUND_MAPS_H_
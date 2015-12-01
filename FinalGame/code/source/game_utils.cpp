// game_utils.cpp
// Helper routines to manage the current game state
// This file was automatically generated by Spritely 0.13.29 beta

#include <gba_dma.h>
#include <gba_sprites.h>
#include <gba_video.h>

#include "game_utils.h"
#include "object_utils.h"

#include "sprites.h"
#include "background_maps.h"
#include "background_images.h"

// Current key/button state.
u16 g_keyPress, g_keyHeld;

void SetSpriteVideoMode() {
	// Initialize the video mode for sprites with a tiled background.
	SetMode(MODE_0 | BG0_ENABLE | OBJ_ENABLE | OBJ_1D_MAP);
}

void SetBitmapVideoMode() {
	// Initialize the video mode for a bitmap background.
	SetMode(MODE_4 | BG2_ENABLE);
}

void ClearSprites() {
	InitializeObjects();
}

// Load spriteset into VRAM.
void LoadSpriteset(int id) {
	// Load palette for this spriteset into VRAM.
	int palette_id = SpritesetInfo[id].palette_id;
	bool is_color16 = SpritePaletteInfo[palette_id].color16;
	int first_palette_entry = SpritePaletteInfo[palette_id].first_entry;
	dmaCopy((void*)&SpritePalettes[first_palette_entry],
			(void*)SPRITE_PALETTE, kPalette_Size);
	
	// Load sprite/tile data into VRAM.
	int first_sprite = SpritesetInfo[id].first_sprite;
	int first_tile = SpriteInfo[first_sprite].first_tile;
	int total_bytes = SpritesetInfo[id].num_tiles;
	if (is_color16)
		total_bytes *= kBytesPerTile16;
	else
		total_bytes *= kBytesPerTile256;
	if (SpritesetInfo[id].num_tiles != 0) {
		dmaCopy((void*)&SpriteTiles[first_tile],
				(void*)SPRITE_GFX, total_bytes);
	}
}

void ClearBackgrounds() {
	// Set the attributes in the background 0 control reg
	REG_BG0CNT = 0;
}

// Load background tileset into VRAM.
void LoadBgTileset(int id) {
	// Set background 0 control register for 16-color tile stored in Tile Data Block 0.
	REG_BG0CNT |= BG_16_COLOR | BG_TILE_BASE(0);

	// Load palette for this background tileset into VRAM.
	int palette_id = BgTilesetInfo[id].palette_id;
	bool is_color16 = BgPaletteInfo[palette_id].color16;
	int first_palette_entry = BgPaletteInfo[palette_id].first_entry;
	dmaCopy((void*)&BgPalettes[first_palette_entry],
			(void*)BG_PALETTE, kPalette_Size);

	// Load background tile data into VRAM
	int first_tile = BgTilesetInfo[id].first_tile;
	int total_bytes = BgTilesetInfo[id].num_tiles;
	if (is_color16)
		total_bytes *= kBytesPerTile16;
	else
		total_bytes *= kBytesPerTile256;
	if (total_bytes != 0) {
		dmaCopy((void*)&BgTiles[first_tile],
				(void*)TILE_BASE_ADR(0),
				total_bytes);
	}
}

// Load background map into VRAM.
void LoadBgMap(int id) {
	// Set background 0 control register for 32x32 tile background stored in
	// Tile Map Block 31.
	REG_BG0CNT |= TEXTBG_SIZE_256x256 | BG_MAP_BASE(31);

	// Load background map into VRAM
	int first_entry = BgMapInfo[id].first_entry;
	int total_bytes = BgMapInfo[id].width
						* BgMapInfo[id].height
						* kBytesPerBgMapEntry;
	if (total_bytes != 0) {
		dmaCopy((void*)&BgMapData[first_entry],
				(void*)MAP_BASE_ADR(31),
				total_bytes);
	}
}

void LoadBgImage(int id) {
	dmaCopy((void*)BgImageInfo[id].palette, (void*)BG_PALETTE, kPalette_Size);

	int w = BgImageInfo[id].width;
	int h = BgImageInfo[id].height;
	if (w == SCREEN_WIDTH && h == SCREEN_WIDTH) {
		dmaCopy((void*)BgImageInfo[id].data,
							(void*)VRAM,
							w*h);
	} else {
		const u8 *fb = (const u8*)VRAM;
		const u8 *bm = (const u8*)BgImageInfo[id].data;
		int num_bytes = SCREEN_WIDTH;
		if (num_bytes > w)
			num_bytes = w;
		// Bitmap doesn't match screen/framebuffer.
		// Copy each row separately.
		for (int y=0; y<h; y++) {
			dmaCopy((void*)bm, (void*)fb, num_bytes);
			fb += SCREEN_WIDTH;
			bm += w;
		}
	}
}

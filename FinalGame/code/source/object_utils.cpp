// object_utils.cpp
// Object utility routines.
// This file was automatically generated by Spritely 

#include <gba_dma.h>
#include <gba_sprites.h>

#include "object_utils.h"
#include "sprites.h"

typedef struct {
	int sprite_id;
} ObjectInfo;

// This is a shadow copy of the OAM (Object Attribute Memory) that
// we maintain to keep track of our sprites.
// Changes made here are not applied until this is copied into the real
// OAM using UpdateScreen().
static SpriteEntry oam_shadow[kMaxObjects];

// Additional information about each object.
static ObjectInfo obj_info[kMaxObjects];

static bool s_UpdateScreen = false;

// Initialize the objects in the shadow OAM. By default, all of the sprites are active,
// so we need to disable them.
void InitializeObjects()
{
	for (int i=0; i < kMaxObjects; ++i) {
		oam_shadow[i].attribute[0] = ATTR0_DISABLED;
		obj_info[i].sprite_id = 0;
	}
	s_UpdateScreen = true;
}

// InitObject
// Update the given object entry in the shadow OAM with info about the specified sprite.
// Call UpdateScreen() after this to see the sprite on the screen.
//
// Parameters:
//   <object> is the index of the object to create
//   <sprite> is the sprite index to use to init the object
//
// See gba_oam.h for more information about how the OAM entries are encoded.
void InitObject(int object, int sprite)
{
	if (object >= kMaxObjects || sprite >= kTotalSprites)
		return;
		
	oam_shadow[object].attribute[0] = SpriteInfo[sprite].shape | ATTR0_COLOR_16 | OBJ_Y(0);
	oam_shadow[object].attribute[1] = SpriteInfo[sprite].size | OBJ_X(0);
	oam_shadow[object].attribute[2] = ATTR2_PALETTE(SpriteInfo[sprite].subpalette_id) | SpriteInfo[sprite].first_tile;
	obj_info[object].sprite_id = sprite;
	s_UpdateScreen = true;
}

// Get the sprite currently assigned to this object.
int GetObjectSprite(int object)
{
	if (object >= kMaxObjects)
		return -1;

	return obj_info[object].sprite_id;
}

// Change the sprite associated with this object.
void SetObjectSprite(int object, int sprite)
{
	if (object >= kMaxObjects || sprite >= kTotalSprites)
		return;

	oam_shadow[object].attribute[0] &= 0x3fff;
	oam_shadow[object].attribute[0] |= SpriteInfo[sprite].shape;
	oam_shadow[object].attribute[1] &= 0x3fff;
	oam_shadow[object].attribute[1] |= SpriteInfo[sprite].size;
	oam_shadow[object].attribute[2] = ATTR2_PALETTE(SpriteInfo[sprite].subpalette_id) | SpriteInfo[sprite].first_tile;
	obj_info[object].sprite_id = sprite;
	s_UpdateScreen = true;
}

// Move the object to the new location, leaving the other object attributes unchanged.
void MoveObjectTo(int object, int x, int y)
{
	if (object >= kMaxObjects)
		return;

	oam_shadow[object].attribute[0] &= ~OBJ_Y(0xffff);
	oam_shadow[object].attribute[0] |= OBJ_Y(y);
	oam_shadow[object].attribute[1] &= ~OBJ_X(0xffff);
	oam_shadow[object].attribute[1] |= OBJ_X(x);
	s_UpdateScreen = true;
}

// Update the objects on the screen by copying the shadow OAM into the real OAM,
void UpdateScreen()
{
	if (s_UpdateScreen)
	{
		dmaCopy((void*)&oam_shadow, OAM, sizeof(oam_shadow));
		s_UpdateScreen = false;
	}
}

void GetObjectLocation(int object, int *px, int *py) {
	if (object >= kMaxObjects)
		return;
	*px = oam_shadow[object].attribute[1] & OBJ_X(0xffff);
	*py = oam_shadow[object].attribute[0] & OBJ_Y(0xffff);
}

void GetObjectSize(int object, int *pwidth, int *pheight) {
	if (object >= kMaxObjects)
		return;
	int sprite = obj_info[object].sprite_id;
	*pwidth = SpriteInfo[sprite].width;
	*pheight = SpriteInfo[sprite].height;
}

int GetObjectWidth(int object) {
	if (object >= kMaxObjects)
		return 0;
	int sprite = obj_info[object].sprite_id;
	if (sprite >= kTotalSprites)
		return 0;
	return SpriteInfo[sprite].width;
}

int GetObjectHeight(int object) {
	if (object >= kMaxObjects)
		return 0;
	int sprite = obj_info[object].sprite_id;
	if (sprite >= kTotalSprites)
		return 0;
	return SpriteInfo[sprite].height;
}

void ShowObject(int object, bool show) {
	if (object >= kMaxObjects)
		return;

	if (show)
		oam_shadow[object].attribute[0] &= ~ATTR0_DISABLED;
	else
		oam_shadow[object].attribute[0] |= ATTR0_DISABLED;
	s_UpdateScreen = true;
}

bool IsObjectVisible(int object) {
	if (object >= kMaxObjects)
		return false;

	return !(oam_shadow[object].attribute[0] & ATTR0_DISABLED);
}

void FlipObject(int object, bool horizontal, bool vertical, int right) {
	if (object >= kMaxObjects)
		return;

	// Make sure that rotation/scale flag is off.
	oam_shadow[object].attribute[0] &= ~ATTR0_ROTSCALE;
	
	if (horizontal && !right)
		oam_shadow[object].attribute[1] |= ATTR1_FLIP_X;
	else
		oam_shadow[object].attribute[1] &= ~ATTR1_FLIP_X;

	if (vertical)
		oam_shadow[object].attribute[1] |= ATTR1_FLIP_Y;
	else
		oam_shadow[object].attribute[1] &= ~ATTR1_FLIP_Y;
	
	s_UpdateScreen = true;
}

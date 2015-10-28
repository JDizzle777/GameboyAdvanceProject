// background_images.h
// GBA background images
// This file was automatically generated by Spritely 

#ifndef _BACKGROUND_IMAGES_H_
#define _BACKGROUND_IMAGES_H_

#include "palettes.h"

// Structure to store basic information for each background image
typedef struct {
	// Width/height for this image.
	short int width, height;
	
	const unsigned short int *palette;
	const unsigned char *data;
} BgImageInfoStruct;

// These palette/image data arrays are defined in background_images.cpp

// General info about each background image.
extern const BgImageInfoStruct BgImageInfo[];

// Number of background images.
const int kNumBgImages = 3;

// Background Image IDs
const int kBgImage_SPACE_BACKGROUND = 0;
const int kBgImage_TITLE_BG = 1;
const int kBgImage_GameOver_bmp = 2;

#endif	// _BACKGROUNDS_H_
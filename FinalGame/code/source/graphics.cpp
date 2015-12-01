//
// smgbalib - a GBA API by Sebastian
//
// Routines for graphics manipulation
//

#include "smgbalib.h"

// Video buffers
u16* FrontBuffer = (u16*)0x6000000;
u16* BackBuffer = (u16*)0x600A000;
u16* videoBuffer;

// Current palette memory
u16* paletteMem = (u16*)0x5000000;


void SetPalette( u16* palette ) {
	u16* p = paletteMem;
	while(p < paletteMem+256)*p++ = *palette++;
}

// Mode 4 is 240(120)x160 by 8bit
void PlotPixelOpaque(int x,int y, unsigned short int c)	
{ 
	videoBuffer[(y) *120 + (x)] = (c); 
}

// Mode 4 is 240(120)x160 by 8bit
void PlotPixelTransparent(int x,int y, unsigned short int c)	
{ 
	u16 temp;

	// transform coordinates into a location, so we're a bit faster
	u16 location = (y) * 120 + (x);
	// and get a pointer to this video buffer location so that 
	// we don't index all the time
	u16* vptr = &videoBuffer[location];

	if ((c & 0x00FF) == 0) // bottom is transparent
	{
		if ((c & 0xFF00) == 0) // top is also transparent
			return;
		// so bottom transparent, top is not so....
		temp = (*vptr & 0x00FF);
		temp |= c; // or it with c (to get the highpart of c in
		*vptr = (temp);
	}
	else
	if 	((c & 0xFF00) == 0) // only the top is transprent
	{
		temp = (*vptr & 0xFF00);
		temp |= c;
		*vptr = (temp);
	}
	else // no part is transparent
		*vptr = (c); 
}

// ----- BITMAP functions ------
void DrawBitmapTransparent( u16 x, u16 y, u16 height, u16 width, u16* data ) {
	u16 cx, cy;
	u16 halfWidth = width / 2;
	u16 y_times_halfWidth;
	// draw the tank
	for(cy = 0; cy < height; cy++) {
		y_times_halfWidth = cy*halfWidth;
		for (cx = 0; cx < halfWidth; cx++) {
			PlotPixelTransparent(cx+x, cy+y, *(data + y_times_halfWidth + cx));
		}
	}
}

void DrawBitmapOpaque( u16 x, u16 y, u16 height, u16 width, u16* data ) {
	u16 cx, cy;
	u16 halfWidth = width / 2;
	u16 y_times_halfWidth;
	// draw the tank
	for(cy = 0; cy < height; cy++) {
		y_times_halfWidth = cy*halfWidth;
		for (cx = 0; cx < halfWidth; cx++) {
			PlotPixelOpaque(cx+x, cy+y, *(data + y_times_halfWidth + cx));
			//videoBuffer[y_times_halfWidth + cx] = *(data + y_times_halfWidth + cx);
		}
	}
}

void DrawFullScreenOpaque( u16* data )
{
	int x, y;
	u16 t;
	// draw the picture
	for(y = 0; y < 160; y++)
	{
		t = y * 120;
		for(x = 0; x < 120; x++)
		{
			videoBuffer[t + x] = *(data + t +x);
			
		}
	}
}

void Flip(void)			// flips between the back/front buffer
{
	WaitForVblank();

	if(REG_DISPCNT & BACKBUFFER) //back buffer is the current buffer so we need to switch it to the font buffer
	{ 
		REG_DISPCNT &= ~BACKBUFFER; //flip active buffer to front buffer by clearing back buffer bit
		videoBuffer = BackBuffer; //now we point our drawing buffer to the back buffer
    }
    else //front buffer is active so switch it to backbuffer
    { 
		REG_DISPCNT |= BACKBUFFER; //flip active buffer to back buffer by setting back buffer bit
		videoBuffer = FrontBuffer; //now we point our drawing buffer to the front buffer
	}
}

void EraseScreen(void)
{
	SetPalette( (u16*) blackPalette );
	u16* p = videoBuffer;
	while(p < videoBuffer+160*120){*p++ = 0x0000;}

	Flip();
}

void EraseScreenNoPaletteNoFlip(void) {
	u16* p = videoBuffer;
	while(p < videoBuffer+160*120){*p++ = 0x0000;}
}


void DrawBitmapSectorTransparent( u16 x, u16 y, //where on screen we are writing this character
				u16 height, u16 width, //height and width of the whole character map
				u16 bitmapx, u16 bitmapy, //top left position in the character map where we're starting
				u16 bitmapheight, u16 bitmapwidth, //how many pixels horizontally and vertically we're writing
				u16* data ) {
	u16 cx, cy;
	u16 halfWidth = width / 2;
	u16 halfBitmapWidth = bitmapwidth / 2;
	u16 y_times_halfWidth;
	u16 y_times_bitmapHalfWidth;
	u16 start_at = halfWidth * bitmapy + bitmapx/2;
	
	// draw the tank
	for(cy = 0; cy < bitmapheight; cy++) {
		y_times_halfWidth = cy*halfWidth;
		y_times_bitmapHalfWidth = cy*halfBitmapWidth;
		for (cx = 0; cx < halfBitmapWidth; cx++) {
			PlotPixelTransparent(cx+x, cy+y, *(data + start_at + y_times_halfWidth + cx));
		}
	}
}


void DrawBitmapSectorOpaque( u16 x, u16 y, //where on screen we are writing this character
				u16 height, u16 width, //height and width of the whole character map
				u16 bitmapx, u16 bitmapy, //top left position in the character map where we're starting
				u16 bitmapheight, u16 bitmapwidth, //how many pixels horizontally and vertically we're writing
				u16* data ) {
	u16 cx, cy;
	u16 halfWidth = width / 2;
	u16 halfBitmapWidth = bitmapwidth / 2;
	u16 y_times_halfWidth;
	u16 y_times_bitmapHalfWidth;
	u16 start_at = halfWidth * bitmapy + bitmapx/2;
	
	// draw the tank
	for(cy = 0; cy < bitmapheight; cy++) {
		y_times_halfWidth = cy*halfWidth;
		y_times_bitmapHalfWidth = cy*halfBitmapWidth;
		for (cx = 0; cx < halfBitmapWidth; cx++) {
			PlotPixelOpaque(cx+x, cy+y, *(data + start_at + y_times_halfWidth + cx));
		}
	}
}


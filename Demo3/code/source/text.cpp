//
// smgbalib - a GBA API by Sebastian
//
// Text output routines
//

#include "smgbalib.h"

void WriteCharacter( u16 x, u16 y, unsigned char c ) {
	// font map is 16x16
	u16 bitmapx;
	u16 bitmapy;
	
	bitmapy = ( c / 16 ) * 8;
	bitmapx = ( c % 16 ) * 8;
	
	DrawBitmapSectorTransparent( x, y,
			   fixedfont_HEIGHT, fixedfont_WIDTH, 
			   bitmapx, bitmapy,
			   8, 8,
			   (u16*)fixedfontData);
}

void WriteStringWide( u16 x, u16 y, unsigned char* c ) {
	u16 cx = x;
	while( *c != '\0' ) {
		WriteCharacter( cx, y, *c++ );
		cx += 4;
	}
}

void WriteStringNarrow( u16 x, u16 y, unsigned char* c ) {
	u16 cx = x;
	while( *c != '\0' ) {
		WriteCharacter( cx, y, *c++ );
		cx += 3;
	}
}


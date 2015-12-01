//
// smgbalib - a GBA API by Sebastian
//
// Various utility routines
//

#include "smgbalib.h"

// ------------- TITLE AND VERSION ---------------
const char* author = "smgbalib 1.0 - A GBA API by Sebastian Mihai, 2011";

// Quick and dirty itoa - converts an integer to a string
// Warning - make sure that you have allocated enough memory for *s ! :)
void Itoa( char* s, u16 number ) {

	char temp[] = "Temporary storage!";
	signed char digits = 0;

	u16 x = number;
	while( x >= 10 ) {
		temp[digits] = '0' + x % 10;
		x = x / 10;
		digits++;
	}

	temp[digits] = '0' + x;

	// copy digits to return string, reversing order
	while(digits >= 0) {
		*s++ = temp[digits];
		digits--;
	}

	// add terminator
	*s = 0;

	// hasta la vista baby!
}

// ------------- DELAY ---------------
void Sleep(int i)
{
	int x, y;
	int c;
	for (y = 0; y < i; y++)
	{
		for (x = 0; x < 3800; x++)
			c = c + 2; // do something to slow things down
	}
}

// ---------- RANDOM NUMBERS --------------
volatile s32 RAND_RandomData;

void SeedRandom(void)
{
   RAND_RandomData = REG_VCOUNT;
}

s32 NextRandom(s32 Value)
{
   RAND_RandomData *= 20077;
   RAND_RandomData += 12345;

   return ((((RAND_RandomData >> 16) & RAND_MAX) * Value) >> 15);
}


// --------------- VSYNC ----------------
volatile u16* ScanlineCounter = (volatile u16*)0x4000006;
void WaitForVblank(void)
{
	while(*ScanlineCounter < 160) {
	}
}


// ---------------- BUTTONS -------------
volatile u32* KEYS = (volatile u32*)0x04000130;


// ----------------- INITIALIZATION ---------------
void Initialize(void) {
	// We are using mode 4 - double buffered 240x160
	SetVideoMode(MODE_4 | BG2_ENABLE );

	// Clear both buffers
	EraseScreen();
	EraseScreen();
	
	SetPalette( (u16*)rainbowPalette );
}


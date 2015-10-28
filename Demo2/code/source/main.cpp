// main.cpp
// Sample GBA project to demonstrate how to display sprites/backgrounds.
// This file was automatically generated by Spritely 

#include <gba_dma.h>
#include <gba_interrupt.h>
#include <gba_sprites.h>
#include <gba_systemcalls.h>
#include <gba_video.h>

#include "game_state.h"
#include "object_utils.h"

void InitDevice() {
	// Enable interrupts.
	irqInit();
	irqEnable(IRQ_VBLANK);
}

int main() {
	InitDevice();

	// Initialize the Objects.
	// This initializes all the objects to "off" so that we don't have garbage
	// appearing on the screen.
	InitializeObjects();

	GameState gs;
	UpdateScreen();

	while (true) {
		// Wait for the vertical blank interrupt so that we update the
		// screen at a constant rate.
		VBlankIntrWait();

		gs.Update();
		UpdateScreen();
	}
}

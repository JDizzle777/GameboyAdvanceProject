// game_state.cpp
// Routines to manage the current game state
// This file was automatically generated by Spritely 

#include <gba_video.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>

#include "collision.h"
#include "game_state.h"
#include "game_utils.h"
#include "object_utils.h"
#include "smgbalib.h"

// Constructor
// This is called once at the beginning of the game to
// set up the initial game state.
GameState::GameState() {
	// Setup the stage for level 1.
	SetupStage(kLevel_1);
}

// SetupStage
// This sets up the stage for each level.
void GameState::SetupStage(int level) {
	// Record which level we're in.
	_level = level;
	
	SetupStage_Level1();
}

// SetupStage_Level1
// Set up the stage (sprites and backgrounds) for level 1.
void GameState::SetupStage_Level1() {
   // display splash screen
	Initialize();
   SetBitmapVideoMode();
   LoadBgImage(1);
   GetKeyState();

   // wait for A or START
   while( !(CheckKeyPress(KEY_A) || CheckKeyPress(KEY_START)) ){
      GetKeyState();
   }

	// Set the default sprite video mode.
	SetSpriteVideoMode();

   // initialize random seed
   srand (time(NULL));
	
	// Setup the foreground sprites.
	// The sprite data is not active until we copy it from our data
	// tables (in sprites.cpp) into the real Palette and Graphics memory.
	// So, let's copy the default spriteset there now.
	ClearSprites();
	LoadSpriteset(0);
	
	// Setup the background tiles and map.
	// Just like sprites, the data is not active until we copy it from
	// our data tables (in background_maps.cpp) into real memory.
	ClearBackgrounds();
	LoadBgTileset(0);
	LoadBgMap(0);
	
   // play sound
   PlayNote(NOTE_D4, 50);
   PlayNote(NOTE_CSHARP4_DFLAT4, 100);
   PlayNote(NOTE_DSHARP4_EFLAT4, 100);
   PlayNote(NOTE_D4, 100);
   PlayNote(NOTE_CSHARP4_DFLAT4, 255);

	// Initialize the objects for the first level and update counters
	InitObject(kObj_Player, ksprites_SpaceManMike);
   for(int i = 0; i < MAX_ENEMIES; i++){
      InitObject(kObj_Alien[i], ksprites_Alien);
      InitObject(kObj_Monster[i], ksprites_Monster);
      InitObject(kObj_Laser[i], ksprites_Laser); 
   	InitObject(kObj_playerLaser[i], ksprites_Laser_Blue);
   	ShowObject(kObj_playerLaser[i], false);     
      _has_projectile[i] = false;
      ShowObject(kObj_Laser[i], false);
      ShowObject(kObj_Alien[i], false);
      ShowObject(kObj_Monster[i], false);
      alienJumping[i] = false;
      monsterJumping[i] = false;
      alienPlatform[i] = false;
      monsterPlatform[i] = false;
		_isShooting[i] = false;
      alienYVelocity[i] = 0;
      monsterYVelocity[i] = 0;
      alienHP[i] = 3;
      monsterHP[i] = 4;
   }
   numMonster = 1;
   numAlien = 1;
	
   // Calculate the ground level.
   _yPlayerHeight = GetObjectHeight(kObj_Player);
   alienHeight = GetObjectHeight(kObj_Alien[0]);
   monsterHeight = GetObjectHeight(kObj_Monster[0]);
   _yGroundLevel = 124;

	// Set the initial location of each object. (210 x 128)
	_xPlayer = 0;
	_yPlayer = _yGroundLevel;
   MoveObjectTo(kObj_Player, _xPlayer, _yPlayer);
   for(int i = 0; i < numAlien; i++){
      _xAlien[i] = rand() % 210;
      _yAlien[i] = rand() % 128;
      ShowObject(kObj_Alien[i], true);
      MoveObjectTo(kObj_Alien[i], _xAlien[i], _yAlien[i]);
      curAlienDir[i] = prevAlienDir[i] = 1;
   }
   for(int i = 0; i < numMonster; i++){
      _xMonster[i] = rand() % 210;
      _yMonster[i] = rand() % 128;
      ShowObject(kObj_Monster[i], true);
      MoveObjectTo(kObj_Monster[i], _xMonster[i], _yMonster[i]);
      curMonsterDir[i] = prevMonsterDir[i] = 1;
   }
   
   // Initialize the animation for the player object and monster object
   InitAnimation(&animatePlayer, kObj_Player,
                    ksprites_SpaceManMike, ksprites_SpaceManMike_Dead, 60);

   // set jumping stats
   _isjumping = false;
   _yVelocity = 0;
   onPlatform = false;

	// set current direction of player and HP
   currDirection = prevDirection = 1;
   playerHP = 10;
   points = 0;
	numShot = 0;

   // set the current frame
   frame = 0;
   timer = 0;
}

// Update
// This is called repeatedly, 60 times per second.
// You should check the buttons and update the game state here.
void GameState::Update() {
	// Get the current state of all of the buttons.
	GetKeyState();
	
	// Handle input and updates for level 1.
	Update_Level1();

   if(frame == 60){
      // reset
      frame = 0;
      timer++;
   }
   else{
      frame++;
      timer++;
   }
}

// Update_Level1
// Handle buttons and update game state for level 1.
void GameState::Update_Level1() {
	// The arrow keys are used to move the current object.
	// We use CheckKeyHeld() because we want the action to repeat as long
	// as the player is holding down the button.
	int dx = 0;
	int dy = 0;
   int ay = 0;
   int my = 0;
   int width, height, x, y;
	if (CheckKeyHeld(KEY_LEFT)){
      if(_isjumping){
         dx = -3;
      }
      else{
		   dx = -1;
      }
      currDirection = 0;
   }
	if (CheckKeyHeld(KEY_RIGHT)){
      if(_isjumping){
         dx = 3;
      }
      else{
		   dx = 1;
      }
      currDirection = 1;
   }
	
	// Handle the player pressing the 'A' button.
	// We use CheckKeyPress() because we *don't* want the action to repeat
	// unless the player presses the 'A' button multiple times
	if (CheckKeyPress(KEY_A) && (!_isShooting[0] || !_isShooting[1] || !_isShooting[2] || !_isShooting[3] || !_isShooting[4])) {
      // SHOOT!
      playerLaserX[numShot] = _xPlayer;
      playerLaserY[numShot] = _yPlayer+17;
      _isShooting[numShot] = true;
      playerLaserDir[numShot] = currDirection;
      MoveObjectTo(kObj_playerLaser[numShot], playerLaserX[numShot], playerLaserY[numShot]);
      ShowObject(kObj_playerLaser[numShot++], true);
		numShot = numShot % 5;
   }
	
   // Handle the player jump.
   if (CheckKeyPress(KEY_UP) && !_isjumping) {
      _yVelocity = 9;
      _isjumping = true;
   }
   dy = -_yVelocity;

   // handle key_down
   if(CheckKeyPress(KEY_DOWN) && onPlatform){
      dy = 6;
   }
	
	// If we need to move the player.
	if (dx != 0 || dy != 0) {
      // Calculate the player's new location.
      x = _xPlayer + dx;
      y = _yPlayer + dy;
    
      // Get the width/height of the player.
      GetObjectSize(kObj_Player, &width, &height);

      // Don't let the player go outside the screen boundaries.
      if (x < -12 || x > SCREEN_WIDTH - (width - 12))
         dx = 0;
      if (y < -1 || y > SCREEN_HEIGHT - height)
         dy = 0;

      // Record the player's new location.
      _xPlayer += dx;
      _yPlayer += dy;
		
      // check to see if player switched directions
      if( currDirection != prevDirection ){
         FlipObject(kObj_Player, true, false, currDirection);
         prevDirection = currDirection;
      }

		// Move the player to the new location.
		MoveObjectTo(kObj_Player, _xPlayer, _yPlayer);
	}
   
   // move the alien(s) and monster(s) every half-second
   if(frame == 20 || frame == 40 || frame == 60){
      for(int i = 0; i < numAlien; i++){
         if(_xPlayer < _xAlien[i]){
            // go left
            _xAlien[i]--;
            curAlienDir[i] = 0;

            // if on same level, shoot laser
            if((_yPlayer <= (_yAlien[i]+5) || _yPlayer >= (_yAlien[i]-7)) && !_has_projectile[i]){

               // update laser stats
               _xLaser[i] = _xAlien[i];
               _yLaser[i] = _yAlien[i]+19;
               MoveObjectTo(kObj_Laser[i], _xLaser[i], _yLaser[i]);
               _has_projectile[i] = true;
               laserDirection[i] = 0;
               ShowObject(kObj_Laser[i], true);
               setAlientoLaser(kObj_Laser[i], i);
            }
         }
         else{
            // go right
            _xAlien[i]++;
            curAlienDir[i] = 1;

            // if on same level, shoot laser
            if((_yPlayer <= (_yAlien[i]+5) && _yPlayer >= (_yAlien[i]-7)) && !_has_projectile[i]){

               _xLaser[i] = _xAlien[i]+3;
               _yLaser[i] = _yAlien[i]+19;
               MoveObjectTo(kObj_Laser[i], _xLaser[i], _yLaser[i]);
               _has_projectile[i] = true;
               laserDirection[i] = 1;
               ShowObject(kObj_Laser[i], true);
               setAlientoLaser(kObj_Laser[i], i);
            }
         }

         // check to see if switched directions
         if( curAlienDir[i] != prevAlienDir[i] ){
            FlipObject(kObj_Alien[i], true, false, curAlienDir[i]);
            prevAlienDir[i] = curAlienDir[i];
         }

         // handle y direction
         if((_yPlayer < (_yAlien[i] - 8)) && !alienJumping[i]){
            alienYVelocity[i] = 35;
            alienJumping[i] = true;
            ay = -alienYVelocity[i];
         }   
         else{
            ay += 10;
         }

         // Calculate the alien's new location.
         x = _xAlien[i];
         y = _yAlien[i] + ay;
       
         // Get the width/height of the alien.
         GetObjectSize(kObj_Alien[i], &width, &height);

         // Don't let the alien go outside the screen boundaries.
         if (y < -1 || y > SCREEN_HEIGHT - height)
            ay = 0;

         // move
         _yAlien[i] += ay;
         MoveObjectTo(kObj_Alien[i], _xAlien[i], _yAlien[i]);
         ay = 0;
      }
      
      // move the monster(s)
      for(int i = 0; i < numMonster; i++){
         // handle x-axis
         if(_xPlayer < _xMonster[i]){
            // go left
            _xMonster[i] -= 3;
            curMonsterDir[i] = 0;
         }
         else{
            // go right
            _xMonster[i] += 3;
            curMonsterDir[i] = 1;
         }
         // check to see if switched directions
         if( curMonsterDir[i] != prevMonsterDir[i] ){
            FlipObject(kObj_Monster[i], true, false, curMonsterDir[i]);
            prevMonsterDir[i] = curMonsterDir[i];
         }
         // handle y direction
         if((_yPlayer < (_yMonster[i] - 8)) && !monsterJumping[i]){
            monsterYVelocity[i] = 25;
            monsterJumping[i] = true;
            my = -monsterYVelocity[i];
         }   
         else{
            my += 10;
         }

         // Calculate the monsters's new location.
         x = _xMonster[i];
         y = _yMonster[i] + my;
       
         // Get the width/height of the monster
         GetObjectSize(kObj_Monster[i], &width, &height);

         // Don't let the alien go outside the screen boundaries.
         if (y < -1 || y > SCREEN_HEIGHT - height)
            my = 0;

         // move
         _yMonster[i] += my;
         MoveObjectTo(kObj_Monster[i], _xMonster[i], _yMonster[i]);
         my = 0;
      }
   }

   // update projectile(s) if need be
   for(int i = 0; i < numAlien; i++){
      if (_has_projectile[i]) {
         if(laserDirection[i] == 0){
            _xLaser[i] -= 1;
         }
         else{
            _xLaser[i] += 1;
         }   

         // check for boundaries
         if(_xLaser[i] < 0 || _xLaser[i] > 220){
            _has_projectile[i] = false;
            ShowObject(kObj_Laser[i], false);
         }
         else{
            MoveObjectTo(kObj_Laser[i], _xLaser[i], _yLaser[i]);
         }       
      }
   }
	for(int i = 0; i < MAX_ENEMIES; i++){
		if(_isShooting[i]){
		   if(playerLaserDir[i] == 0){
		      playerLaserX[i] -= 2;
		   }
		   else{
		      playerLaserX[i] += 2;
		   }
		   // check for boundaries
		   if(playerLaserX[i] < 0 || playerLaserX[i] > 220){
		      _isShooting[i] = false;
		      ShowObject(kObj_playerLaser[i], false);
		   }
		   else{
		      MoveObjectTo(kObj_playerLaser[i], playerLaserX[i], playerLaserY[i]);
		   } 
		}
	}


   int bottom = _yPlayer+((_yPlayerHeight+4)/2);
   int bgXPos = ((_xPlayer*30)/240)+1;
   int bgYPos = ((bottom*20)/160)+3;
   int index = 30*bgYPos+bgXPos;

   // If the player is above ground and not on platform, apply gravity.
   if ((_yPlayer < _yGroundLevel) && (BgMapData[index] == 0x0000 || BgMapData[index] == 0x0004 || BgMapData[index] == 0x0005)) {
      // Apply gravity by reducing upward velocity.
      _yVelocity--;
   } 
   else if(_yPlayer == _yGroundLevel){
      // Player is on the ground, so stop jumping.
      _yVelocity = 0;
      _isjumping = false;
      onPlatform = false;

      // Force player to be exactly at ground level.
      _yPlayer = _yGroundLevel;
      MoveObjectTo(kObj_Player, _xPlayer, _yPlayer);
   }
   else{
      // Player is on a platform, so stop jumping.
      onPlatform = true;
      _yVelocity = 0;
      _isjumping = false;
      MoveObjectTo(kObj_Player, _xPlayer, _yPlayer);
   }

   // Gravity for aliens
   for(int i = 0; i < numAlien; i++){
      // recalculate attributes for alien
      bottom = _yAlien[i]+((alienHeight+4)/2);
      bgXPos = ((_xAlien[i]*30)/240)+1;
      bgYPos = ((bottom*20)/160)+3;
      index = 30*bgYPos+bgXPos;

      // check background
      if ((_yAlien[i] < _yGroundLevel) && (BgMapData[index] == 0x0000 || BgMapData[index] == 0x0004 || BgMapData[index] == 0x0005)) {
         // Apply gravity by reducing upward velocity.
         alienYVelocity[i]--;
      } 
      else if(_yAlien[i] == _yGroundLevel){
         // alien is on the ground, so stop jumping.
         alienYVelocity[i] = 0;
         alienJumping[i] = false;
         alienPlatform[i] = false;

         // Force alien to be exactly at ground level.
         _yAlien[i] = _yGroundLevel;
         MoveObjectTo(kObj_Alien[i], _xAlien[i], _yAlien[i]);
      }
      else{
         // alien is on a platform, so stop jumping.
         alienPlatform[i] = true;
         alienYVelocity[i] = 0;
         alienJumping[i] = false;
         MoveObjectTo(kObj_Alien[i], _xAlien[i], _yAlien[i]);
      }
   }

   // gravity for monsters
   for(int i = 0; i < numMonster; i++){
      // recalculate attributes for monster
      bottom = _yMonster[i]+((monsterHeight+4)/2);
      bgXPos = ((_xMonster[i]*30)/240)+1;
      bgYPos = ((bottom*20)/160)+3;
      index = 30*bgYPos+bgXPos;

      // check background
      if ((_yMonster[i] < (_yGroundLevel)) && (BgMapData[index] == 0x0000 || BgMapData[index] == 0x0004 || BgMapData[index] == 0x0005)) {
         // Apply gravity by reducing upward velocity.
         monsterYVelocity[i]--;
      } 
      else if(_yMonster[i] == _yGroundLevel){
         // monster is on the ground, so stop jumping.
          monsterYVelocity[i] = 0;
          monsterJumping[i] = false;
          monsterPlatform[i] = false;

         // Force monster to be exactly at ground level.
         _yMonster[i] = _yGroundLevel;
         MoveObjectTo(kObj_Monster[i], _xMonster[i], _yMonster[i]);
      }
      else{
         // monster is on a platform, so stop jumping.
         monsterPlatform[i] = true;
         monsterYVelocity[i] = 0;
         monsterJumping[i] = false;
         MoveObjectTo(kObj_Monster[i], _xMonster[i], _yMonster[i]);
      }      
   }
	
   // check for collisions with Alien(s) and laser(s)
	char buf[5];
	buf[0] = '\0';
   for(int i = 0; i < numAlien; i++){
      // check for collisions with aliens
      if(CollidePixel(kObj_Player, kObj_Alien[i])){      
         // game over?  
         if(playerHP <= 1){
				PlayNote(NOTE_C2, 128);
				PlayNote(NOTE_D2, 128);
				PlayNote(NOTE_E2, 128);
				PlayNote(NOTE_F2, 128);
				PlayNote(NOTE_G2, 128);
				PlayNote(NOTE_A2, 128);
				PlayNote(NOTE_B2, 128);
				PlayNote(NOTE_C3, 128);
				PlayNote(NOTE_D3, 128);
				PlayNote(NOTE_E3, 128);
				PlayNote(NOTE_F3, 128);
				PlayNote(NOTE_G3, 128);
				PlayNote(NOTE_A3, 128);
				PlayNote(NOTE_B3, 128);
				PlayNote(NOTE_C4, 128);
				PlayNote(NOTE_D4, 128);
				PlayNote(NOTE_E4, 128);
				PlayNote(NOTE_F4, 128);
				PlayNote(NOTE_G4, 128);
				PlayNote(NOTE_A4, 128);
				PlayNote(NOTE_B4, 128);
            GetKeyState();

            // wait until A or START button is pressed
	         while( !(CheckKeyPress(KEY_A) || CheckKeyPress(KEY_START) || CheckKeyPress(KEY_LEFT) || CheckKeyPress(KEY_RIGHT))){
					volatile unsigned char *ioram = (unsigned char *)0x04000000;
					ioram[0] = 0x03;
					ioram[1] = 0x01;
					Initialize();
					EraseScreenNoPaletteNoFlip();
					char string[] = "Score: ";
					strcat(string, itoa(points, buf, 10));
					WriteStringWide(38, 60, string);
					Flip();
					Sleep(510);

					// wait for A or START
					while( !(CheckKeyPress(KEY_A) || CheckKeyPress(KEY_START)) ){
						GetKeyState();
					}

			   // display game over screen
               SetBitmapVideoMode();
               LoadBgImage(2);
               GetKeyState();

               // wait for A or START
               while( !(CheckKeyPress(KEY_A) || CheckKeyPress(KEY_START)) ){
                  GetKeyState();
               }

               // go back to the beginning
               SetupStage_Level1();
            }
	      }
         else{
            if(alienHP[i] <= 1){
               MoveObjectTo(kObj_Alien[i], -20, -35);
               ShowObject(kObj_Alien[i], false);
               MoveObjectTo(kObj_Laser[i], -20, -35);         
               ShowObject(kObj_Laser[i], false);
               _has_projectile[getAlientoLaser(kObj_Laser[i])] = false;
               numAlien--;
               playerHP--;
               points++;
					PlayNote(WHITE_NOISE_SPLASH, 55);
            }
            else{
               alienHP[i]--;
               playerHP--;
            }
         }
      }

      // check for collisions with laser(s)
      if(CollidePixel(kObj_Player, kObj_Laser[i])){
         // game over?  
         if(playerHP <= 1){
				PlayNote(NOTE_C2, 128);
				PlayNote(NOTE_D2, 128);
				PlayNote(NOTE_E2, 128);
				PlayNote(NOTE_F2, 128);
				PlayNote(NOTE_G2, 128);
				PlayNote(NOTE_A2, 128);
				PlayNote(NOTE_B2, 128);
				PlayNote(NOTE_C3, 128);
				PlayNote(NOTE_D3, 128);
				PlayNote(NOTE_E3, 128);
				PlayNote(NOTE_F3, 128);
				PlayNote(NOTE_G3, 128);
				PlayNote(NOTE_A3, 128);
				PlayNote(NOTE_B3, 128);
				PlayNote(NOTE_C4, 128);
				PlayNote(NOTE_D4, 128);
				PlayNote(NOTE_E4, 128);
				PlayNote(NOTE_F4, 128);
				PlayNote(NOTE_G4, 128);
				PlayNote(NOTE_A4, 128);
				PlayNote(NOTE_B4, 128);
            GetKeyState();

            // wait until A or START button is pressed
	         while( !(CheckKeyPress(KEY_A) || CheckKeyPress(KEY_START) || CheckKeyPress(KEY_LEFT) || CheckKeyPress(KEY_RIGHT))){
					volatile unsigned char *ioram = (unsigned char *)0x04000000;
					ioram[0] = 0x03;
					ioram[1] = 0x01;
					Initialize();
					EraseScreenNoPaletteNoFlip();
					char string[] = "Score: ";
					strcat(string, itoa(points, buf, 10));
					WriteStringWide(38, 60, string);
					Flip();
					Sleep(510);

					// wait for A or START
					while( !(CheckKeyPress(KEY_A) || CheckKeyPress(KEY_START)) ){
						GetKeyState();
					}

			   // display game over screen
               SetBitmapVideoMode();
               LoadBgImage(2);
               GetKeyState();

               // wait for A or START
               while( !(CheckKeyPress(KEY_A) || CheckKeyPress(KEY_START)) ){
                  GetKeyState();
               }

               // go back to the beginning
               SetupStage_Level1();
            }
	      }
         else{
            MoveObjectTo(kObj_Laser[i], -20, -35);         
            ShowObject(kObj_Laser[i], false);
            _has_projectile[getAlientoLaser(kObj_Laser[i])] = false;
            playerHP--;
            points--;
         }     
      }
      
      // check for collision of player laser w/ aliens
		for(int j = 0; j < MAX_ENEMIES; j++){
		   if(_isShooting[j]){
		      if(CollideBBox(kObj_playerLaser[j], kObj_Alien[i])){
		         if(alienHP[i] <= 1){
		            MoveObjectTo(kObj_playerLaser[j], -20, -35);
		            MoveObjectTo(kObj_Alien[i], -20, -35);
		            ShowObject(kObj_Alien[i], false);
		            ShowObject(kObj_playerLaser[j], false);
		            _isShooting[j] = false;
		            numAlien--;
		            points += 5;
						PlayNote(WHITE_NOISE_SPLASH, 55);
		         }
		         else{
		            MoveObjectTo(kObj_playerLaser[j], -20, -35);
		            ShowObject(kObj_playerLaser[j], false);
		            _isShooting[j] = false;
		            alienHP[i]--;
		            points++;
		         }
		      }
		   }
		}
   }


   // check for collision w/ monster
   for(int i = 0; i < numMonster; i++){
      if(CollidePixel(kObj_Player, kObj_Monster[i])){      
         // game over?  
         if(playerHP <= 1){
				PlayNote(NOTE_C2, 128);
				PlayNote(NOTE_D2, 128);
				PlayNote(NOTE_E2, 128);
				PlayNote(NOTE_F2, 128);
				PlayNote(NOTE_G2, 128);
				PlayNote(NOTE_A2, 128);
				PlayNote(NOTE_B2, 128);
				PlayNote(NOTE_C3, 128);
				PlayNote(NOTE_D3, 128);
				PlayNote(NOTE_E3, 128);
				PlayNote(NOTE_F3, 128);
				PlayNote(NOTE_G3, 128);
				PlayNote(NOTE_A3, 128);
				PlayNote(NOTE_B3, 128);
				PlayNote(NOTE_C4, 128);
				PlayNote(NOTE_D4, 128);
				PlayNote(NOTE_E4, 128);
				PlayNote(NOTE_F4, 128);
				PlayNote(NOTE_G4, 128);
				PlayNote(NOTE_A4, 128);
				PlayNote(NOTE_B4, 128);
            GetKeyState();

            // wait until A or START button is pressed
	         while( !(CheckKeyPress(KEY_A) || CheckKeyPress(KEY_START) || CheckKeyPress(KEY_LEFT) || CheckKeyPress(KEY_RIGHT))){
					volatile unsigned char *ioram = (unsigned char *)0x04000000;
					ioram[0] = 0x03;
					ioram[1] = 0x01;
					Initialize();
					EraseScreenNoPaletteNoFlip();
					char string[] = "Score: ";
					strcat(string, itoa(points, buf, 10));
					WriteStringWide(38, 60, string);
					Flip();
					Sleep(510);

					// wait for A or START
					while( !(CheckKeyPress(KEY_A) || CheckKeyPress(KEY_START)) ){
						GetKeyState();
					}

               // display game over screen
               SetBitmapVideoMode();
               LoadBgImage(2);
               GetKeyState();

               // wait for A or START
               while( !(CheckKeyPress(KEY_A) || CheckKeyPress(KEY_START)) ){
                  GetKeyState();
               }

               // go back to the beginning
               SetupStage_Level1();
            }
	      }
         else{
            if(monsterHP[i] <= 1){
               MoveObjectTo(kObj_Monster[i], -20, -35);
               ShowObject(kObj_Monster[i], false);
               numMonster--;
               playerHP-=2;
               points++;
					PlayNote(WHITE_NOISE_CRASH, 55);
            }
            else{
               monsterHP[i]--;
               playerHP--;
            }
         }
      }

      // colliison with player laser and monster
		for(int j = 0; j < MAX_ENEMIES; j++){
		   if(_isShooting[j]){
		      if(CollideBBox(kObj_playerLaser[j], kObj_Monster[i])){
		         if(monsterHP[i] <= 1){
		            MoveObjectTo(kObj_playerLaser[j], -20, -35);
		            MoveObjectTo(kObj_Monster[i], -20, -35);
		            ShowObject(kObj_Monster[i], false);
		            ShowObject(kObj_playerLaser[j], false);
		            _isShooting[j] = false;
		            numMonster--;
		            points += 5;
						PlayNote(WHITE_NOISE_CRASH, 55);
		         }
		         else{
		            MoveObjectTo(kObj_playerLaser[j], -20, -35);
		            ShowObject(kObj_playerLaser[j], false);
		            _isShooting[j] = false;
		            monsterHP[i]--;
		            points++;
		         }
		      }
		   } 
		}     
   }   

   // check for number of enemies on the screen
   if((timer > 500 && timer < 4000) && numAlien == 0){
      numAlien++;
      for(int i = 0; i < numAlien; i++){
         _xAlien[i] = rand() % 210;
         _yAlien[i] = rand() % 128;
         ShowObject(kObj_Alien[i], true);
         MoveObjectTo(kObj_Alien[i], _xAlien[i], _yAlien[i]);
         curAlienDir[i] = prevAlienDir[i] = 1;
      }
   }
   if((timer > 500 && timer < 4000) && numMonster == 0){
      numMonster++;
      for(int i = 0; i < numMonster; i++){
         _xMonster[i] = rand() % 210;
         _yMonster[i] = rand() % 128;
         ShowObject(kObj_Monster[i], true);
         MoveObjectTo(kObj_Monster[i], _xMonster[i], _yMonster[i]);
         curMonsterDir[i] = prevMonsterDir[i] = 1;
      }
   }

   // check timer to see if any more enemies need to be added
   switch(timer){
      case 1000:
         if(numAlien < 2){
            for(int i = numAlien; i < 2; i++){
               _xAlien[i] = rand() % 220;
               _yAlien[i] = rand() % 135;
               ShowObject(kObj_Alien[i], true);
               MoveObjectTo(kObj_Alien[i], _xAlien[i], _yAlien[i]);
               curAlienDir[i] = prevAlienDir[i] = 1;
               alienHP[i] = 2;
            }
            numAlien=2;
         }
         if(numMonster < 2){
            for(int i = numMonster; i < 2; i++){
               _xMonster[i] = rand() % 220;
               _yMonster[i] = rand() % 135;
               ShowObject(kObj_Monster[i], true);
               MoveObjectTo(kObj_Monster[i], _xMonster[i], _yMonster[i]);
               curMonsterDir[i] = prevMonsterDir[i] = 1;
               monsterHP[i] = 2;
            }
            numMonster=2;
         }
         break;

      case 1600:
         if(numAlien < 3){
            for(int i = numAlien; i < 3; i++){
               _xAlien[i] = rand() % 220;
               _yAlien[i] = rand() % 135;
               ShowObject(kObj_Alien[i], true);
               MoveObjectTo(kObj_Alien[i], _xAlien[i], _yAlien[i]);
               curAlienDir[i] = prevAlienDir[i] = 1;
               alienHP[i] = 2;
            }
            numAlien=3;
         }
         if(numMonster < 3){
            for(int i = numMonster; i < 3; i++){
               _xMonster[i] = rand() % 220;
               _yMonster[i] = rand() % 135;
               ShowObject(kObj_Monster[i], true);
               MoveObjectTo(kObj_Monster[i], _xMonster[i], _yMonster[i]);
               curMonsterDir[i] = prevMonsterDir[i] = 1;
               monsterHP[i] = 2;
            }
            numMonster=3;
         }
         break;

      case 2500:
         if(numAlien < 4){
            for(int i = numAlien; i < 4; i++){
               _xAlien[i] = rand() % 210;
               _yAlien[i] = rand() % 128;
               ShowObject(kObj_Alien[i], true);
               MoveObjectTo(kObj_Alien[i], _xAlien[i], _yAlien[i]);
               curAlienDir[i] = prevAlienDir[i] = 1;
               alienHP[i] = 2;
            }
            numAlien=4;
         }
         if(numMonster < 4){
            for(int i = numMonster; i < 4; i++){
               _xMonster[i] = rand() % 210;
               _yMonster[i] = rand() % 128;
               ShowObject(kObj_Monster[i], true);
               MoveObjectTo(kObj_Monster[i], _xMonster[i], _yMonster[i]);
               curMonsterDir[i] = prevMonsterDir[i] = 1;
               monsterHP[i] = 2;
            }
            numMonster=4;
         }
         break;

      case 4000:
         if(numAlien < 5){
            for(int i = numAlien; i < 5; i++){
               _xAlien[i] = rand() % 220;
               _yAlien[i] = rand() % 135;
               ShowObject(kObj_Alien[i], true);
               MoveObjectTo(kObj_Alien[i], _xAlien[i], _yAlien[i]);
               curAlienDir[i] = prevAlienDir[i] = 1;
               alienHP[i] = 2;
            }
            numAlien=5;
         }
         if(numMonster < 5){
            for(int i = numMonster; i < 5; i++){
               _xMonster[i] = rand() % 220;
               _yMonster[i] = rand() % 135;
               ShowObject(kObj_Monster[i], true);
               MoveObjectTo(kObj_Monster[i], _xMonster[i], _yMonster[i]);
               curMonsterDir[i] = prevMonsterDir[i] = 1;
               monsterHP[i] = 2;
            }
            numMonster=5;
         }
         break;
   }
}


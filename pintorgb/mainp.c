#include <stdio.h>
#include <gb/gb.h>
#include <gb/drawing.h>

#include "sprites/pencils.c"
/*
#include "sprites/data.c"
#include "bg/bg_d.c"
*/

#include "sprites/titlet.c"
#include "bg/title.c"
#include "sprites/ins.c"
#include "bg/inns.c"

#define GRAPHICS_WIDTH	40
#define GRAPHICS_HEIGHT 36

char val = 1;
char cl;

unsigned char x = 0;
unsigned char y = 0;

void inputt(UBYTE nintendo){
  switch(nintendo) {
    //CONTROLES
    case J_UP: y--; break;
    case J_DOWN: y++; break;
    case J_LEFT: x--; break;
    case J_RIGHT: x++; break;
    //ATRAVEZADOS
    case J_UP + J_LEFT: y--; x--; break;
    case J_UP + J_RIGHT: y--; x++; break;
    case J_DOWN + J_LEFT: y++; x--; break;
    case J_DOWN + J_RIGHT: y++; x++; break;
    //CONTROLES CON COLOR
    case J_UP + J_A: y--; plot( x, y, cl); break;
    case J_DOWN + J_A: y++; plot( x, y, cl); break;
    case J_LEFT + J_A: x--; plot( x, y, cl); break;
    case J_RIGHT + J_A: x++; plot( x, y, cl); break;
    //ATRAVEZADOS CON COLOR
    case J_UP + J_LEFT + J_A: y--; x--; plot( x, y, cl); break;
    case J_UP + J_RIGHT + J_A: y--; x++; plot( x, y, cl); break;
    case J_DOWN + J_LEFT + J_A: y++; x--; plot( x, y, cl); break;
    case J_DOWN + J_RIGHT + J_A: y++; x++; plot( x, y, cl); break;
    //OTROS
    case J_A: plot( x, y, cl); break;
    case J_B: HIDE_SPRITES; waitpad(J_B); SHOW_SPRITES; break;
    case J_START: val++; break;
    case J_SELECT: val--; break;
  }
}

int main() {

  //set_bkg_data(0,11,tile_data);
  //set_bkg_tiles(0,0,20,18,tile_bg_d);

  set_bkg_data(0, 28, tile_title);
  set_bkg_tiles(0, 0, 20, 18, tile_title_gb);

  SHOW_BKG;
  waitpad(J_START);
  HIDE_BKG;

  set_bkg_data(0, 62, tile_i_gb);
  set_bkg_tiles(0, 0, 20, 18, ins_bg);

  SHOW_BKG;
  waitpad(J_START);
  HIDE_BKG;
  
  set_sprite_data(0, 4, pencils);
  set_sprite_tile(0, val);

  while(1) {
    //otras funciones

    //SHOW_BKG;
    SHOW_SPRITES;
    inputt(joypad());

    //sprites
    move_sprite(0, x + 8, y + 9);
    
    switch (val) {
      case -1: val = 0; break;
      case 0: cl = LTGREY; set_sprite_tile(0, val); break;
      case 1: cl = DKGREY; set_sprite_tile(0, val); break;
      case 2: cl = BLACK; set_sprite_tile(0, val);  break;
      case 3: cl = WHITE; set_sprite_tile(0, val); break;
      case 4: val = 3; break;
    }
    
    //retraso de FPS
    delay(65);
  }
  return(0);
}

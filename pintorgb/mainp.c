#include <stdio.h>
#include <gb/gb.h>
#include <gb/drawing.h>

#include "sprites/pencils.c"

unsigned char val = 3;
unsigned char cl;

unsigned char x = 0;
unsigned char y = 0;

int main() {

  set_sprite_data(0, 4, pencils);
  set_sprite_tile(0, val);

  while(1) {
    //otras funciones

    SHOW_SPRITES;

    switch (val) {
      case -1: val = 0; break;
      case 0: cl = WHITE; set_sprite_tile(0, val); break;
      case 1: cl = LTGREY; set_sprite_tile(0, val); break;
      case 2: cl = DKGREY; set_sprite_tile(0, val);  break;
      case 3: cl = BLACK; set_sprite_tile(0, val); break;
      case 4: val = 3; break;
    }

    //controles
    if (joypad() == J_UP) {y--;}
    if (joypad() == J_DOWN) {y++;}
    if (joypad() == J_RIGHT) {x++;}
    if (joypad() == J_LEFT) {x--;}
    if (joypad() == J_A) {plot(x,y,cl);}
    if (joypad() == J_START) {val++;}
    if (joypad() == J_SELECT) {val--;}
    
    //controles pero atravezados
    if (joypad() == J_UP + J_RIGHT) {x++;y--;}
    if (joypad() == J_UP + J_LEFT) {x--;y--;}
    if (joypad() == J_DOWN + J_RIGHT) {x++;y++;}
    if (joypad() == J_DOWN + J_LEFT) {x--;y++;}

    //sprites
    move_sprite(0, x, y);
    
    //retraso de FPS
    delay(1000);
  }
  return(0);
}

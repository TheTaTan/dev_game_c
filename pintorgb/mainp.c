#include <gb/gb.h>
#include <stdio.h>

unasingned char x = 0;
unasingned char y = 0;

void main(){
  While(1){
    //controles
    if (joypad() == j_UP) {y++}
    if (joypad() == j_DOWN) {y--}
    if (joypad() == j_RIGHT) {x++}
    if (joypad() == j_LEFT) {x--}
  }

}

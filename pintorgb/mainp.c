#include <stdio.h>
#include <gb/gb.h>
#include <gb/drawing.h>

unasingned char x = 0;
unasingned char y = 0;

void main(){
  While(1){
    //controles
    if (joypad() == j_UP) {y++;}
    if (joypad() == j_DOWN) {y--;}
    if (joypad() == j_RIGHT) {x++;}
    if (joypad() == j_LEFT) {x--;}
    //controles pero atravezados
    if (joypad() == j_UP + j_RIGHT) {x++;y++;}
    if (joypad() == j_UP + j_LEFT) {x--;y++;}
    if (joypad() == j_DOWN + j_RIGTH) {y--;x++;}
    if (joypad() == j_DOWN + J_LEFT) {y--;x--;}
  }

}

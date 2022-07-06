#include <stdio.h>
#include <gb/gb.h>
#include <gb/drawing.h>

unsigned char val = 0;
unsigned char cl;

unsigned char x = 0;
unsigned char y = 0;

void main(){
  While(1){
    //otras funciones
    delay(35);
    if (val == -1) {val++;}
    if (val == 0) {cl = WHITE;}
    if (val == 1) {cl = LTGRAY;}
    if (val == 2) {cl = BKGRAY;}
    if (val == 3) {cl = BLACK;}
    if (val == 4) {val--;}
    
    //controles
    if (joypad() == j_UP) {y++;}
    if (joypad() == j_DOWN) {y--;}
    if (joypad() == j_RIGHT) {x++;}
    if (joypad() == j_LEFT) {x--;}
    if (joypad() == j_A) {plot(x,y,cl);}
    if (joypad() == j_START) {val++;}
    if (joypad() == J_SELECT) {val--;}
    
    //controles pero atravezados
    if (joypad() == j_UP + j_RIGHT) {x++;y++;}
    if (joypad() == j_UP + j_LEFT) {x--;y++;}
    if (joypad() == j_DOWN + j_RIGTH) {y--;x++;}
    if (joypad() == j_DOWN + J_LEFT) {y--;x--;}
  }

}

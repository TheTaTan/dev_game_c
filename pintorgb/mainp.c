#include <stdio.h>
#include <gb/gb.h>
#include <gb/drawing.h>

unsigned char val = 0;
unsigned char cl;

unsigned char x = 0;
unsigned char y = 0;

int main() {
  while(1) {
    //otras funciones
    if (val == -1) {val++;}
    if (val == 0) {cl = WHITE;}
    if (val == 1) {cl = LTGREY;}
    if (val == 2) {cl = DKGREY;}
    if (val == 3) {cl = BLACK;}
    if (val == 4) {val--;}
    
    //controles
    if (joypad() == J_UP) {y++;}
    if (joypad() == J_DOWN) {y--;}
    if (joypad() == J_RIGHT) {x++;}
    if (joypad() == J_LEFT) {x--;}
    if (joypad() == J_A) {plot(x,y,cl);}
    if (joypad() == J_START) {val++;}
    if (joypad() == J_SELECT) {val--;}
    
    //controles pero atravezados
    if (joypad() == J_UP + J_RIGHT) {x++;y++;}
    if (joypad() == J_UP + J_LEFT) {x--;y++;}
    if (joypad() == J_DOWN + J_RIGHT) {y--;x++;}
    if (joypad() == J_DOWN + J_LEFT) {y--;x--;}
    
    //retraso de FPS
    delay(35);
  }
  return(0);
}

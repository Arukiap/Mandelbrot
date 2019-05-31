#include "mouse.h"
#include "math.h"

Mouse::Mouse(float x,float y){
    this->x = x;
    this->y = y;
}

void Mouse::moveMouse(float x, float y){
    this->x += x;
    this->y += y;
}

float Mouse::GetX(){
    return this->x;
}

float Mouse::GetY(){
    return this->y;
}
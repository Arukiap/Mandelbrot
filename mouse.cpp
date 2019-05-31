#include "mouse.h"
#include "math.h"

Mouse::Mouse(float x,float y, float sensitivity){
    this->x = x;
    this->y = y;
    this->sensitivity = sensitivity;
}

void Mouse::moveMouse(float x, float y){
    this->x += x*this->sensitivity;
    this->y += y*this->sensitivity;
}

float Mouse::GetX(){
    return this->x;
}

float Mouse::GetY(){
    return this->y;
}
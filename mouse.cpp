#include "mouse.h"
#include "math.h"

Mouse::Mouse(float x,float y, float sensitivity){
    this->x = x;
    this->y = y;
    this->sensitivity = sensitivity;
    this->zoom = 1.0;
    this->zoomNormalized = 1.0;
}

void Mouse::moveMouse(float x, float y){
    this->x += x*this->sensitivity*this->zoomNormalized; //Move less the more zoom we have
    this->y += y*this->sensitivity*this->zoomNormalized;
}

void Mouse::zoomMouse(){
    this->zoom += 0.1;
    this->zoomNormalized = 1.0/this->zoom;
}

void Mouse::unzoomMouse(){
    if(this->zoom - 0.1 < 1.0){
        return;
    }
    this->zoom -= 0.1;
    this->zoomNormalized = 1.0/this->zoom;
}

float Mouse::GetX(){
    return this->x;
}

float Mouse::GetY(){
    return this->y;
}

float Mouse::GetZoomNormalized(){
    return this->zoomNormalized;
}
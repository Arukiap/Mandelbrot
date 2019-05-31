#ifndef MOUSE_H
#define MOUSE_H

class Mouse {
    public:
        Mouse(float x, float y, float sensitivity);
        void moveMouse(float x, float y);
        void zoomMouse();
        void unzoomMouse();
        float GetX();
        float GetY();
        float GetZoomNormalized();
    private:
        float x,y,sensitivity,zoom,zoomNormalized;
};

#endif // MOUSE_H
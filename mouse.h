#ifndef MOUSE_H
#define MOUSE_H

class Mouse {
    public:
        Mouse(float x, float y);
        void moveMouse(float x, float y);
        float GetX();
        float GetY();
    private:
        float x,y;
};

#endif // MOUSE_H
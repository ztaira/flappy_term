#ifndef BIRD
#define BIRD
// bird object
class bird
{
public:
    // constructor
    bird(int x, int y, int wheight, int wwidth);
    // width and height
    int height;
    int width;
    // location of the upper-left corner
    int ul_x;
    int ul_y;
    // width and height of window
    int win_height;
    int win_width;
    // draw function
    void draw(bool flag);
    void move(bool direction);
    // what arc phase;
    int dir;
};
#endif

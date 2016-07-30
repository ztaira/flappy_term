#ifndef CLOUD
#define CLOUD
// cloud object
class cloud
{
public:
    // constructor
    cloud(int x, int y, int wheight, int wwidth);
    // width and height
    int height;
    int width;
    // location of the upper-left corner
    int ul_x;
    int ul_y;
    // height and width of the terminal
    int win_height;
    int win_width;
    // draw function
    void draw(bool flag);
    void move();
};
#endif

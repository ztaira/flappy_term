// include bird.h
#include "bird.h"
// include ncurses
#include <ncurses.h>

//constructor
bird::bird(int y, int x, int wheight, int wwidth)
{
    ul_x = x;
    ul_y = y;
    height = 4;
    width = 7;
    win_height = wheight;
    win_width = wwidth;
    dir = false;
};

// prints a bird
void bird::draw(bool flag)
{
    if (flag == true)
    {
        mvprintw(ul_y, ul_x+1, ",===,");
        mvprintw(ul_y+1, ul_x, "/   0 \\");
        mvprintw(ul_y+2, ul_x, "\\    -/");
        mvprintw(ul_y+3, ul_x+1, "'==='");
    }
    else
    {
        mvprintw(ul_y, ul_x+1, "     ");
        mvprintw(ul_y+1, ul_x, "        ");
        mvprintw(ul_y+2, ul_x, "        ");
        mvprintw(ul_y+3, ul_x+1, "     ");
    }
}

void bird::move(bool direction)
{
    draw(0);
    dir = direction;
    if (dir == true)
    {
        ul_y -= 1;
    }
    else
    {
        ul_y += 1;
    }
}

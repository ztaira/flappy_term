// include pipe.h
#include "pipe.h"
// include ncurses
#include <ncurses.h>
// include stdlib
#include <stdlib.h>

// constructor
pipe::pipe(int y, int x, int wheight, int wwidth)
{
    ul_x = x;
    ul_y = y;
    height = wheight;
    width = 11;
    win_height = wheight;
    win_width = wwidth;
};

// prints a pipe
void pipe::draw(bool flag)
{
    if (flag == true)
    {
        mvprintw(ul_y-2, ul_x, ".---------.");
        mvprintw(ul_y-1, ul_x, "|||       |");
        mvprintw(ul_y, ul_x,   "===========");
        mvprintw(ul_y+15, ul_x,"===========");
        mvprintw(ul_y+16, ul_x,"|||       |");
        mvprintw(ul_y+17, ul_x,".---------.");
        for (int i=ul_y-3; i>=0; --i)
        {
            mvprintw(i, ul_x, " |||     | ");
        }
        for (int i=ul_y+18; i<win_height; ++i)
        {
            mvprintw(i, ul_x, " |||     | ");
        }
    }
    else
    {
        mvprintw(ul_y-2, ul_x, "           ");
        mvprintw(ul_y-1, ul_x, "           ");
        mvprintw(ul_y, ul_x,   "           ");
        mvprintw(ul_y+15, ul_x,"           ");
        mvprintw(ul_y+16, ul_x,"           ");
        mvprintw(ul_y+17, ul_x,"           ");
        for (int i=ul_y-3; i>=0; --i)
        {
            mvprintw(i, ul_x, "           ");
        }
        for (int i=ul_y+18; i<win_height; ++i)
        {
            mvprintw(i, ul_x, "           ");
        }
    }
}

void pipe::move()
{
    draw(0);
    ul_x -= 2;
    if (ul_x < 1)
    {
        ul_y = ( rand() % ( win_height - 22 ))+4;
        ul_x = win_width-11;
    }
    draw(1);
    refresh();
}

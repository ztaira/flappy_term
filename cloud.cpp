// include cloud.h
#include "cloud.h"
// include ncurses
#include <ncurses.h>

// constructor
cloud::cloud(int y, int x, int wheight, int wwidth)
{
    ul_x = x;
    ul_y = y;
    height = 10;
    width = 36;
    win_height = wheight;
    win_width = wwidth;
};

// prints a cloud
void cloud::draw(bool flag)
{
    if (flag == true)
    {
        mvprintw(ul_y, ul_x+15, "____");
        mvprintw(ul_y+1, ul_x+12, "__(    )");
        mvprintw(ul_y+2, ul_x+10, "_(       ))____");
        mvprintw(ul_y+3, ul_x+9,  "(        ))))   )_");
        mvprintw(ul_y+4, ul_x+4,  "____(         ))     )))");
        mvprintw(ul_y+5, ul_x+2,  "_(((((               ))))))_____");
        mvprintw(ul_y+6, ul_x+1,  "(((((                   )))     ))");
        mvprintw(ul_y+7, ul_x,    "(( (((                  ))      ))))");
        mvprintw(ul_y+8, ul_x+1,  "(                             )))))");
        mvprintw(ul_y+9, ul_x+2, "=================================");
    }
    else
    {
        mvprintw(ul_y, ul_x+15, "    ");
        mvprintw(ul_y+1, ul_x+12, "        ");
        mvprintw(ul_y+2, ul_x+10, "               ");
        mvprintw(ul_y+3, ul_x+9,  "                  ");
        mvprintw(ul_y+4, ul_x+4,  "                        ");
        mvprintw(ul_y+5, ul_x+2,  "                                ");
        mvprintw(ul_y+6, ul_x+1,  "                                  ");
        mvprintw(ul_y+7, ul_x,    "                                    ");
        mvprintw(ul_y+8, ul_x+1,  "                                   ");
        mvprintw(ul_y+9, ul_x+2, "                                 ");
    }
}

void cloud::move()
{
    draw(0);
    ul_x -= 1;
    if (ul_x < 1)
    {
        ul_x = win_width-37;
    }
    draw(1);
    refresh();
}

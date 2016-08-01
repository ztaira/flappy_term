#include <iostream>
#include <string>
#include <vector>
#include <ncurses.h>
#include "bird.h"
#include "pipe.h"
#include "cloud.h"
using namespace std;

int collision(pipe *obj1, bird *obj2);
void lose_screen(int y, int x);
void open_screen(int y, int x);
void reset_screen(int wheight, int wwidth);

int main()
{   
    int ch, win_height, win_width;
    bool bird_dir = false;
    // create a screen
    // get the screen's height and width
    initscr();
    getmaxyx(stdscr, win_height, win_width);
    // we don't want to print input characters
    noecho();
    // we want the cursor to be invisible
    curs_set(0);
    // we want to turn colors on
    start_color();
    // cloud, pipe, bird, and background color
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    // print the opening screen, which won't go away until a key is pressed
    attron(COLOR_PAIR(4));
    open_screen(win_height/2, win_width/2);
    attroff(COLOR_PAIR(4));
    refresh();
    getch();
    // create a bird instance
    // draw them all
    werase(stdscr);
    bird mybird = bird(win_height/2, 15, win_height, win_width);
    pipe mypipe  = pipe(10, win_width-12, win_height, win_width);
    vector<cloud> cloudvector;
    for (int i=0; i<win_width; i+=30)
    {
        cloudvector.push_back(cloud(rand()%(win_height/2), i, win_height, win_width));
    }
    for (vector<cloud>::iterator itr = cloudvector.begin();
            itr != cloudvector.end(); ++itr)
    {
        itr->draw(1);
    }
    mybird.draw(1);
    mypipe.draw(1);
    // we now want to auto-refresh the screen every 0.05 secs or so
    timeout(50);

    // game loop
    while ((ch = getch()) != 'q')
    {
        reset_screen(win_height, win_width);
        for (vector<cloud>::iterator itr = cloudvector.begin();
                itr != cloudvector.end(); ++itr)
        {
            itr->move();
        }
        switch(ch)
        {
            case ' ':
                bird_dir = !bird_dir;
                mybird.move(bird_dir);
                break;
            default:
                mybird.move(bird_dir);
                break;
        }
        mypipe.move();
        attron(COLOR_PAIR(1));
        for (vector<cloud>::iterator itr = cloudvector.begin();
                itr != cloudvector.end(); ++itr)
        {
            itr->draw(1);
        }
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(3));
        mybird.draw(1);
        attroff(COLOR_PAIR(3));
        attron(COLOR_PAIR(2));
        mypipe.draw(1);
        attroff(COLOR_PAIR(2));
        if (collision(&mypipe, &mybird)==1)
        {
            break;
        }
    }
    werase(stdscr);
    attron(COLOR_PAIR(4));
    lose_screen(win_height/2, win_width/2);
    attroff(COLOR_PAIR(4));
    refresh();
    while((ch = getch())!='q')
    {
        refresh();
    }
    endwin();           /* End curses mode        */

    return 0;
}

// checks whether or now obj2's top 2 corners are within obj1
int collision(pipe *obj1, bird *obj2)
{
    // mvprintw(0, 0, to_string(obj1->ul_x).c_str());
    // mvprintw(1, 0, to_string(obj1->ul_y).c_str());
    // mvprintw(2, 0, to_string(obj2->ul_x).c_str());
    // mvprintw(3, 0, to_string(obj2->ul_y).c_str());
    if (obj2->ul_y <= obj1->ul_y
            and obj2->ul_x+obj2->width-1 > obj1->ul_x
            and obj2->ul_x+obj2->width-1 < obj1->ul_x + obj1->width-1)
    {
        return 1;
    }
    else if (obj2->ul_y+obj2->height-1 >= obj1->ul_y+15
            and obj2->ul_x+obj2->width-1 > obj1->ul_x
            and obj2->ul_x+obj2->width-1 < obj1->ul_x + obj1->width-1)
    {
        return 1;
    }
    else if (obj2->ul_y >= obj2->win_height - 3)
    {
       return 1;
    } 
    else if (obj2->ul_y <= 0)
    {
        return 1;
    }
    return 0;
}

void lose_screen(int y, int x)
{
    mvprintw(y-2, x-4, "YOU LOSE");
    mvprintw(y, x-23, "Sorry, Bird Mario. Today just wasn't your day.");
    mvprintw(y+2, x-7, "Press q to exit");
}

void open_screen(int y, int x)
{
    mvprintw(y, x-24, "You are a bird, and there are pipes in your way.");
    mvprintw(y+2, x-8, "Need I say more?");
    mvprintw(y+4, x-19, "Use the space key to change direction.");
    if (!has_colors())
    {
        mvprintw(y+6, x-20, "Your terminal does not support colors.");
    }
}

void reset_screen(int wheight, int wwidth)
{
    for (int i=0; i<wheight; ++i)
    {
        for (int j=0; j<wwidth; ++j)
        {
            mvprintw(i, j, " ");
        }
    }
}

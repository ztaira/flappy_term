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
    // print the opening screen, which won't go away until a key is pressed
    open_screen(win_height/2, win_width/2);
    refresh();
    getch();
    // create a bird instance
    // draw them all
    werase(stdscr);
    bird mybird = bird(20, 20, win_height, win_width);
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
    }
    werase(stdscr);
    lose_screen(win_height/2, win_width/2);
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
    if (obj2->ul_y >= obj1->ul_y and obj2->ul_y < obj1->ul_y + obj1->height
            and obj2->ul_x > obj1->ul_x and obj2->ul_x < obj1->ul_x + obj1->width)
    {
        return 1;
    }
    else if (obj2->ul_y >= obj1->ul_y and obj2->ul_y < obj1->ul_y+obj1->height 
            and obj2->ul_x+obj2->width > obj1->ul_x and obj2->ul_x+obj2->width < obj1->ul_x + obj1->width)
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
}

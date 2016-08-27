# Flappy Term
Hack-A-Week 4: ASCII Flappy Bird clone inspired by Flappy Bird.

### Usage:
- Executable is named 'flappy\_term' by default (see makefile)
- To run, execute it as follows from the flappy\_term directory:

`./flappy_term`

### Features:
- Now with color!
- Parallax background

### What it does:
- Lets you play flappy bird.
- Checks for collisions between the bird/pipes and bird/boundary
- Changes gameplay based on the size of your terminal window
- Uses ncurses library to render text and color

### What it doesn't do:
- It does everything I wanted to try. (Parallax, color, design)

### Included Files:
```
- README.md..................This readme file
- bird.cpp...................Bird class file
- bird.h.....................Bird header file
- cloud.cpp..................Cloud class file
- cloud.h....................Cloud header file
- diagrams...................Reference images and diagrams
- flappy_term................Example executable file
- main.cpp...................Main file
- makefile...................Makefile
- pipe.cpp...................Pipe class file
- pipe.h.....................Pipe header file
```

### Example Gameplay:

### Opening Screen:

![alt text][outputimage]
[outputimage]: https://github.com/ztaira14/flappy_term/blob/master/diagrams/openingscreen.png "Opening Screen"

### Gamplay:

![alt text][outputimage2]
[outputimage2]: https://github.com/ztaira14/flappy_term/blob/master/diagrams/gameplay.png "Gameplay"

### Closing Screen:

![alt text][outputimage3]
[outputimage3]: https://github.com/ztaira14/flappy_term/blob/master/diagrams/closingscreen.png "Closing Screen"

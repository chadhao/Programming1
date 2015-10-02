/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab02ex04.c
*  Author:     Duan Hao
*  Student Id: 1426688
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - None
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - None
********************************************************************************/

#include "p1student.h"

/*
* Function: draw_hexagon()
* Draw one hexagon.
*/
void draw_hexagon()
{
    forward(100);
    turn(60);
    forward(100);
    turn(60);
    forward(100);
    turn(60);
    forward(100);
    turn(60);
    forward(100);
    turn(60);
    forward(100);
    turn(60);
}

/*
* Function: main()
* Draw three hexagons in different colours.
*/
int main(int argc, char *argv[])
{
    create_turtle_world();

    turn(60);
    
    pen_colour(CYAN);
    draw_hexagon();
    
    turn(120);
    
    pen_colour(YELLOW);
    draw_hexagon();
    
    turn(120);
    
    pen_colour(MAGENTA);
    draw_hexagon();
    
    return (p1world_shutdown());
}
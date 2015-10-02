/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab01ex01.c
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

/* Function: move_to_next()
 * ------------------------
 * Moves the turtle into the starting position to draw the next square.
 */
void move_to_next()
{
    pen_up();
    
    turn(-90);
    forward(125);
    turn(90);
    
    pen_down();
}

/* Function: draw_side()
 * ------------------------
 * Draw one side of a square.
 */
void draw_side()
{
    forward(100);
    turn(90);
}

/* Function: draw_square()
 * ------------------------
 * Draw one square.
 */
void draw_square()
{
    draw_side();
    draw_side();
    draw_side();
    draw_side();
}

/* Function: main()
 * ----------------
 * Draws three squares.
 */
int main(int argc, char *argv[])
{
    create_turtle_world();

    turn(45);
    
    draw_square();
    
    move_to_next();
    
    draw_square();

    move_to_next();
    
    draw_square();
    
    return (p1world_shutdown());
}
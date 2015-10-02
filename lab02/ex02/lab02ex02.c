/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab02ex02.c
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
 * Function: draw_triangle()
 * -------------------------
 * Draw one triangle.
*/
void draw_triangle()
{
    forward(100);
    turn(120);
    forward(100);
    turn(120);
    forward(100);
    turn(120);
}

/*
 * Function: main()
 * -------------------------
 * Draw three triangles in different colour.
*/
int main(int argc, char *argv[])
{
    turn_on_debug_output();
    create_turtle_world();

    turn(60);
    
    print_stub("Drawing Red Triagle");
    pen_colour(RED);
    draw_triangle();
    turn(120);

    print_stub("Drawing Green Triagle");
    pen_colour(GREEN);
    draw_triangle();
    turn(120);
    
    print_stub("Drawing Blue Triagle");
    pen_colour(BLUE);
    draw_triangle();
    turn(120);
    
    return (p1world_shutdown());
}

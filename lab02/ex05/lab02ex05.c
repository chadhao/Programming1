/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab02ex05.c
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
* Function: turn_left()
* Turn left.
*/
void turn_left()
{
    print_stub("Turn left.");
    turn(-90);
}

/*
* Function: turn_right()
* Turn right.
*/
void turn_right()
{
    print_stub("Turn right.");
    turn(90);
}

/*
* Function: draw_short_line()
* Draw short line.
*/
void draw_short_line()
{
    print_stub("Draw short line.");
    forward(25);
}

/*
* Function: draw_long_line()
* Draw lone line.
*/
void draw_long_line()
{
    print_stub("Draw long line.");
    forward(75);
}

/*
* Function: draw_pattern()
* Draw a pattern.
*/
void draw_pattern()
{
    print_stub("Draw a pattern.");
    draw_short_line();
    turn_left();
    draw_long_line();
    turn_right();
    draw_short_line();
    turn_right();
    draw_long_line();
    turn_left();
    draw_short_line();
}

/*
* Function: main()
* Draw a shape use the pattern.
*/
int main(int argc, char *argv[])
{
    turn_on_debug_output();
    set_delay_time(1);
    create_turtle_world();

    turn(90);

    draw_pattern();
    turn(45);
    
    draw_pattern();
    turn(45);
    
    draw_pattern();
    turn(45);
    
    draw_pattern();
    turn(45);
    
    draw_pattern();
    turn(45);
    
    draw_pattern();
    turn(45);
    
    draw_pattern();
    turn(45);
    
    draw_pattern();
    turn(45);
    
    return (p1world_shutdown());
}

/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       <File Name>.c
*  Author:     <Your Name>
*  Student Id: <ID Number>
*
*  The following people were consulted by the author in the creation of the 
*  code submitted in this file:
*   - <Student's Names>
*   - <TA's Names>
*   - <Tutor's Names>
*   - <Lecturer's Names>
*
*  The following resources were used by the author in the creation of the 
*  code submitted in this file:
*   - <Website's URLs>
*   - <Source Code Repositories>
********************************************************************************/

#include "p1student.h"

void draw_square_of_size(int side_length)
{
    // The code in this function is incomplete!
    for (int i = 0; i < 4; ++i)
    {
		forward(side_length);
		turn(90);
    }
}

void gap(int number_of_pixels)
{
    pen_up();
    turn(90);
    forward(number_of_pixels);
    turn(-90);
    pen_down();
}

int main(int argc, char *argv[])
{
    create_turtle_world();

    turn_on_debug_output();

    draw_square_of_size(20);
    gap(30);

    draw_square_of_size(40);
    gap(50);

    draw_square_of_size(60);
    gap(70);

    draw_square_of_size(80);
    gap(90);
    
    draw_square_of_size(100);
    
    return (p1world_shutdown());
}
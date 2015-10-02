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

void draw_tall_building();
void draw_medium_building();
void draw_short_building();

void draw_sky_tower()
{
    print_stub("Sky Tower Drawing Now!");
    turn(5);
    forward(100);
    turn(-5);
    forward(200);
    turn(-30);
    forward(10);
    turn(30);
    forward(70);
    turn(-45);
    forward(25);
    turn(45);
    forward(10);
    turn(45);
    forward(25);
    turn(-40);
    forward(200);
    turn(170);
    forward(200);
    turn(-40);
    forward(25);
    turn(45);
    forward(10);
    turn(45);
    forward(25);
    turn(-45);
    forward(70);
    turn(30);
    forward(10);
    turn(-30);
    forward(200);
    turn(-5);
    forward(100);
    turn(-175);
    
}

void move_to_skyline_starting_position()
{
    pen_up();
    turn(-90);
    forward(300);
    turn(90);
    forward(-250);
    pen_down();
}

int main(int argc, char *argv[])
{
    set_delay_time(1);
    create_turtle_world();

    move_to_skyline_starting_position();
    
    draw_short_building();
    draw_tall_building();
    draw_short_building();
    draw_short_building();
    draw_tall_building();
    draw_short_building();
    draw_medium_building();
    draw_short_building();
    draw_short_building();
    draw_medium_building();
    draw_sky_tower();
    draw_tall_building();
    draw_short_building();
    draw_medium_building();
    draw_short_building();
    draw_short_building();
    draw_medium_building();
    draw_short_building();
    draw_short_building();
    draw_medium_building();
    draw_medium_building();
    draw_short_building();
    
    draw_tall_building();
    
    return (p1world_shutdown());
}

void draw_tall_building()
{
    turn(90);
    forward(5);
    turn(-90);
    forward(250);
    turn(90);
    forward(10);
    turn(90);
    forward(250);
    turn(-90);
    forward(5);
    turn(-90);
}

void draw_medium_building()
{
    turn(90);
    forward(5);
    turn(-90);
    forward(150);
    turn(90);
    forward(10);
    turn(90);
    forward(150);
    turn(-90);
    forward(5);
    turn(-90);
}

void draw_short_building()
{
    turn(90);
    forward(5);
    turn(-90);
    forward(50);
    turn(90);
    forward(10);
    turn(90);
    forward(50);
    turn(-90);
    forward(5);
    turn(-90);
}
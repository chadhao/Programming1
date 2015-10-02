/********************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       lab03ex01.c
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

int get_my_student_id()
{
    // Replace the number below with your student id number.
    // Don't accidentally remove the return part or the semicolon at the end.
    return 1426688;
}

void turn_robot_right()
{
	for(int n = 0; n < 3; n++)
	{
		turn_robot_left();
	}
}

void move_along_corridor()
{
	for(int n = 0; n < 3; n++)
	{
		move_robot_forwards();
	}
	
	turn_robot_right();
	
	for(int n = 0; n < 6; n++)
	{
		move_robot_forwards();
	}
	
	turn_robot_left();
	
	for(int n = 0; n < 2; n++)
	{
		move_robot_forwards();
	}
	
	turn_robot_left();
	
	for(int n = 0; n < 7; n++)
	{
		move_robot_forwards();
	}
	
	turn_robot_right();
	
	for(int n = 0; n < 3; n++)
	{
		move_robot_forwards();
	}
	
	turn_robot_right();
	
	move_robot_forwards();
	
	turn_robot_left();
	
	move_robot_forwards();
}

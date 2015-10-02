/*******************************************************************************
* Programming 1 (405701) / Programming for Engineering Applications (735318):
*
*  File:       hw02q01.c
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
*******************************************************************************/

#include "p1student.h"

int main(int argc, char *argv[])
{
    create_turtle_world();

    // Enclose the code below this comment inside a loop.

    for (int i = 0; i < 18; i++)
    {
    	forward(100);
    	turn(90);
    	forward(25);
    	turn(90);
    	forward(100);
    	turn(40);
    }

    // Enclose the code above this comment inside a loop.
    
    return (p1world_shutdown());
}
#include "q04.h"

#include "p1staff.h"

#include <unistd.h>
#include <stdio.h>


void test1()
{
	char* world1[] = {
		"wwwww",
		"w   w",
		"w w w",
		"w   w",
		"wwwww"
	};
	create_robot_world_from_string(world1, 5, "Test 1", 1);
	
	create_robot_with_direction(1, 1, get_east());
	for(int n = 0; n < 4; n++)
	{
		give_robot_beeper();
	}
	
	show_robot_world();

	mark_corners();


    P1U_ASSERT_EQUAL("Robot should be at X = 1", 1, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 1", 1, get_current_robot_y());    
    P1U_ASSERT_EQUAL("Robot should be facing east", get_current_robot_orientation(), get_east());    
    P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());
    
    P1U_ASSERT_EQUAL("There should be one beeper at (1, 1)", 1, get_count_of_beepers_at(1, 1));

    P1U_ASSERT_EQUAL("There should be one beeper at (3, 1)", 1, get_count_of_beepers_at(3, 1));

    P1U_ASSERT_EQUAL("There should be one beeper at (3, 3)", 1, get_count_of_beepers_at(3, 3));

    P1U_ASSERT_EQUAL("There should be one beeper at (1, 3)", 1, get_count_of_beepers_at(1, 3));
	
	p1world_shutdown();
}

void test2()
{
	char* world2[] = {
		"wwwwwww",
		"w     w",
		"w www w",
		"w www w",
		"w     w",
		"wwwwwww"
	};
	create_robot_world_from_string(world2, 6, "Test 2", 1);
	
	create_robot_with_direction(1, 1, get_east());
	for(int n = 0; n < 4; n++)
	{
		give_robot_beeper();
	}
	
	show_robot_world();

	mark_corners();


    P1U_ASSERT_EQUAL("Robot should be at X = 1", 1, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 1", 1, get_current_robot_y());    
    P1U_ASSERT_EQUAL("Robot should be facing east", get_current_robot_orientation(), get_east());    
    P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());
    
    P1U_ASSERT_EQUAL("There should be one beeper at (1, 1)", 1, get_count_of_beepers_at(1, 1));

    P1U_ASSERT_EQUAL("There should be one beeper at (5, 1)", 1, get_count_of_beepers_at(5, 1));

    P1U_ASSERT_EQUAL("There should be one beeper at (5, 4)", 1, get_count_of_beepers_at(5, 4));

    P1U_ASSERT_EQUAL("There should be one beeper at (1, 4)", 1, get_count_of_beepers_at(1, 4));
	
	p1world_shutdown();
}



int main(int argc, char* argv[])
{
    p1u_setup();
    
    printf("Test 1\n");
    fflush(stdout);
    
    sleep(1);
    
    test1();
    
    printf("Test 2\n");
    fflush(stdout);
    
    sleep(2);
    
    test2();

		// Final checks
    p1u_shutdown();
    
    return 0;
}
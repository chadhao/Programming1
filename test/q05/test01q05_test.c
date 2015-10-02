#include "test01q05.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "p1utils.h"
#include "p1staff.h"

#include <stdio.h>


void test1()
{
	printf("Test 1: More than four spaces\n");
	fflush(stdout);
	sleep(2);

	enable_robot_debug_message();

	char* world[] = {
	
		"wwwww w",
		"wwwww w",
		"wwwww w",
		"      w",
		"wwwww w",
		"wwwww w"
	};
		
    create_robot_world_from_string(world, 6, "test01q05", 1);

	for(int n = 0; n < 5; n++)
	{
		setup_beeper(5, 2);
	}

	create_robot_at(0, 2);

	move_beepers();
	
	P1U_ASSERT_EQUAL("Robot should be at X = 5", 5, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 5", 5, get_current_robot_y());
	P1U_ASSERT_EQUAL("Robot should be facing north", get_north(), get_current_robot_orientation());
	P1U_ASSERT_EQUAL("There should be 5 beepers at (5, 5)", 5, get_count_of_beepers_at(5, 5));
  	P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());
 
  	p1world_shutdown();
}

void test2()
{
	printf("Test 2: Fewer than 5 beepers\n");
	fflush(stdout);
	sleep(2);

	enable_robot_debug_message();

	char* world[] = {
	
		"ww w",
		"ww w",
		"  bw",
		"ww w",
		"ww w",
		"ww w"
	};
	
    create_robot_world_from_string(world, 6, "test01q05", 1);

	create_robot_at(0, 3);

	move_beepers();

	
	P1U_ASSERT_EQUAL("Robot should be at X = 2", 2, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 5", 5, get_current_robot_y());
	P1U_ASSERT_EQUAL("Robot should be facing north", get_north(), get_current_robot_orientation());
	P1U_ASSERT_EQUAL("There should be one beeper at (2, 5)", 1, get_count_of_beepers_at(2, 5));
  	P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());
  	
  	p1world_shutdown();
}

void test3()
{
	printf("Test 3: Exactly 5 beepers\n");
	fflush(stdout);
	sleep(2);

	enable_robot_debug_message();

	char* world[] = {
	
		"www w",
		"www w",
		"www w",
		"    w",
		"www w",
		"www w",
		"www w"
	};
		
    create_robot_world_from_string(world, 7, "test01q05", 1);

	for(int n = 0; n < 5; n++)
	{
		setup_beeper(3, 3);
	}

	create_robot_at(0, 3);

	move_beepers();

	P1U_ASSERT_EQUAL("Robot should be at X = 3", 3, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 0", 0,  get_current_robot_y());
	P1U_ASSERT_EQUAL("Robot should be facing south", get_south(), get_current_robot_orientation());
	P1U_ASSERT_EQUAL("There should be 5 beepers at (3, 0)", 5, get_count_of_beepers_at(3, 0));
  	P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());

	p1world_shutdown();
}

void test4()
{
	printf("Test 4: More than 5 beepers\n");
	fflush(stdout);
	sleep(2);

	enable_robot_debug_message();

	char* world[] = {
	
		"www w",
		"www w",
		"www w",
		"    w",
		"www w",
		"www w",
		"www w"
	};
		
    create_robot_world_from_string(world, 7, "test01q05", 1);

	for(int n = 0; n < 6; n++)
	{
		setup_beeper(3, 3);
	}

	create_robot_at(0, 3);

	move_beepers();

	P1U_ASSERT_EQUAL("Robot should be at X = 0", 0, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 3", 3,  get_current_robot_y());
	P1U_ASSERT_EQUAL("Robot should be facing west", get_west(), get_current_robot_orientation());
	P1U_ASSERT_EQUAL("There should be 6 beepers at (0, 3)", 6, get_count_of_beepers_at(0, 3));
  	P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());

	p1world_shutdown();
}

int main(int argc, char* argv[])
{
    p1u_setup();

	test1();
	test2();
	test3();
	test4();
 	
 	p1u_shutdown();
    return 0;
}
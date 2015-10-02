#include "hw03q03.h"

#include <unistd.h>
#include <time.h>
#include "p1utils.h"
#include "p1staff.h"

#include <stdio.h>


void make_world()
{
	char* world[] = { 
		"   w w   ",
		"     w   ",
		"   w w   ",
		"wwww wwww",
		"   w w   ",
		"     w   ",
		"   w w   " 
	};
		
	create_robot_world_from_string(world, 7, "Q03", 1);
}


int test1()
{
#define TEST1 "Beeper and door both to south"	
    p1u_setup();
	enable_robot_debug_message();
	
	make_world();
    setup_floor(5, 1);
    setup_beeper(1, 1);
	create_robot_with_direction(4, 0, get_north());
	turn_on_debug_output();
        
    move_beeper();

	P1U_ASSERT_EQUAL("There should be 1 beeper at (7, 1)", 1, get_count_of_beepers_at(7, 1));
    P1U_ASSERT_EQUAL("Robot should be at X = 7", 7, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 1", 1, get_current_robot_y());    
    P1U_ASSERT_EQUAL("Robot should be facing east", get_current_robot_orientation(), get_east());
    P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());

    p1u_shutdown();
    
    return (p1world_shutdown());
}


int test2()
{
#define TEST2 "Beeper to south, door to north"
    p1u_setup();
	enable_robot_debug_message();
	
	make_world();
    setup_floor(5, 5);
    setup_beeper(1, 1);
	create_robot_with_direction(4, 0, get_north());
	turn_on_debug_output();
        
    move_beeper();

	P1U_ASSERT_EQUAL("There should be 1 beeper at (7, 5)", 1, get_count_of_beepers_at(7, 5));
    P1U_ASSERT_EQUAL("Robot should be at X = 7", 7, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 5", 5, get_current_robot_y());    
    P1U_ASSERT_EQUAL("Robot should be facing east", get_current_robot_orientation(), get_east());    
    P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());

    p1u_shutdown();
    
    return (p1world_shutdown());
}


int test3()
{
#define TEST3 "Beeper and door both to north"
    p1u_setup();
	enable_robot_debug_message();
	
	make_world();
    setup_floor(5, 5);
    setup_beeper(1, 5);
	create_robot_with_direction(4, 0, get_north());
	turn_on_debug_output();
        
    move_beeper();

	P1U_ASSERT_EQUAL("There should be 1 beeper at (7, 5)", 1, get_count_of_beepers_at(7, 5));
    P1U_ASSERT_EQUAL("Robot should be at X = 7", 7, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 5", 5, get_current_robot_y());    
    P1U_ASSERT_EQUAL("Robot should be facing east", get_current_robot_orientation(), get_east());    
    P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());

    p1u_shutdown();
    
    return (p1world_shutdown());
}


int test4()
{
#define TEST4 "Beeper to north, door to south"
    p1u_setup();
	enable_robot_debug_message();
	
	make_world();
    setup_floor(5, 1);
    setup_beeper(1, 5);
	create_robot_with_direction(4, 0, get_north());
	turn_on_debug_output();
        
    move_beeper();

	P1U_ASSERT_EQUAL("There should be 1 beeper at (7, 1)", 1, get_count_of_beepers_at(7, 1));
    P1U_ASSERT_EQUAL("Robot should be at X = 7", 7, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 1", 1, get_current_robot_y());    
    P1U_ASSERT_EQUAL("Robot should be facing east", get_current_robot_orientation(), get_east());    
    P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());

    p1u_shutdown();
    
    return (p1world_shutdown());
}


struct test {
	
		char* test_name;
		int (*test_func)();
};


void announce(char* message)
{
	printf("\n================\n");
	printf(message);
	printf("\n================\n...\n\n");
	fflush(stdout);
	sleep(2);
}


int run_tests(int test_count, struct test tests[])
{
	int passed = 1;
	for(int n = 0; n < test_count; n++)
	{
		announce(tests[n].test_name);
		passed &= (tests[n].test_func)();
	}
}


int main(int argc, char* argv[])
{
	struct test tests[] = {

		{ "Test 1 - " TEST1, test1 },
		{ "Test 2 - " TEST2, test2 },
		{ "Test 3 - " TEST3, test3 },
		{ "Test 4 - " TEST4, test4 }
	};

	int test_count = sizeof(tests) / sizeof(struct test);
	return run_tests(test_count, tests);
}

#include "hw03q02.h"

#include <unistd.h>
#include <time.h>
#include "p1utils.h"
#include "p1staff.h"

#include <stdio.h>



int test1()
{	
    p1u_setup();
	enable_robot_debug_message();    
    create_robot_world_with_dimensions(5, 5);
    setup_beeper(0, 1);
    setup_beeper(0, 2);
    create_robot();
    turn_on_debug_output();
    
    move_beepers();

		// Beepers both present so both should be moved
	P1U_ASSERT_EQUAL("There should be 2 beepers at (2, 4)", 2, get_count_of_beepers_at(4, 2));
    P1U_ASSERT_EQUAL("Robot should be at X = 4", 4, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 2", 2, get_current_robot_y());    
    P1U_ASSERT_EQUAL("Robot should be facing east", get_current_robot_orientation(), get_east());    
    P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());

    p1u_shutdown();
    
    return (p1world_shutdown());
}


int test2()
{
    p1u_setup();
	enable_robot_debug_message();    
    create_robot_world_with_dimensions(5, 5);
    setup_beeper(0, 2);
    create_robot();
	turn_on_debug_output();
	
    move_beepers();

		// Beepers both present so both should be moved
	P1U_ASSERT_EQUAL("There should be 1 beeper at (0, 2)", 1, get_count_of_beepers_at(0, 2));
    P1U_ASSERT_EQUAL("Robot should be at X = 0", 0, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 0", 0, get_current_robot_y());    
    P1U_ASSERT_EQUAL("Robot should be facing east", get_current_robot_orientation(), get_east());    
    P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());

    p1u_shutdown();
    return (p1world_shutdown());
}




int test3()
{
    p1u_setup();
	enable_robot_debug_message();    	
    create_robot_world_with_dimensions(5, 5);
    setup_beeper(0, 1);
    create_robot();
    turn_on_debug_output();
    
    move_beepers();

		// Beepers both present so both should be moved
	P1U_ASSERT_EQUAL("There should be 1 beeper at (0, 1)", 1, get_count_of_beepers_at(0, 1));
    P1U_ASSERT_EQUAL("Robot should be at X = 0", 0, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 0", 0, get_current_robot_y());    
    P1U_ASSERT_EQUAL("Robot should be facing east", get_current_robot_orientation(), get_east());    
    P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());

    p1u_shutdown();
    return (p1world_shutdown());
}


int test4()
{
    p1u_setup();
	enable_robot_debug_message();    
    create_robot_world_with_dimensions(5, 5);
    create_robot();
    turn_on_debug_output();
        
    move_beepers();

		// Beepers both present so both should be moved
    P1U_ASSERT_EQUAL("Robot should be at X = 0", 0, get_current_robot_x());
	P1U_ASSERT_EQUAL("Robot should be at Y = 0", 0, get_current_robot_y());    
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

		{ "Test 1 - both beepers", test1 },
		{ "Test 2 - first beeper missing", test2 },
		{ "Test 3 - second beeper missing", test3 },
		{ "Test 4 - both beepers missing", test4 }
	};

	int test_count = sizeof(tests) / sizeof(struct test);
	return run_tests(test_count, tests);
}

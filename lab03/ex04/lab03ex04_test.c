
#include "lab03ex04.h"
#include "p1staff.h"
#include <stdio.h>


void fill_world_with_beepers()
{
	for(int y = 1; y < get_world_height(); y++)
	{
		for(int x = 1; x < get_world_width(); x++)
		{
			if(getRandom(0, 1))
				setup_beeper(x, y);
		}
	}
}


void check_world_clean()
{
	for(int y = 1; y < get_world_height(); y++)
	{
		for(int x = 1; x < get_world_width(); x++)
		{
			char message[100];
			sprintf(message, "There should be no beeper at X = %d Y = %d\n", x, y);
			P1U_ASSERT_FALSE(message, is_item_present(x, y));
		}
	}
}



void test_clean_up_world()
{
	p1u_setup();

	set_random_seed(get_my_student_id());
	
	create_robot_world_with_dimensions(6, 6);
	fill_world_with_beepers();

	create_robot_at(0, 0);
	
	clean_up_world();

	check_world_clean();
		
	P1U_ASSERT_FALSE("Robot should survive", is_robot_dead());
	
	p1u_shutdown();	

}


int main(int argc, char* argv[])
{
	test_clean_up_world();
	return (p1world_shutdown());
}

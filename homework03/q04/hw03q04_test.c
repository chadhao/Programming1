#include "hw03q04.h"

#include <time.h>
#include <stdlib.h>

#include "p1staff.h"

#include <stdio.h>


int main(int argc, char* argv[])
{
    p1u_setup();
    
    srand(time(0));

    setup_challenge();
    
    P1U_ASSERT_FALSE("Robot should be alive initially", is_robot_dead());

    complete_challenge();
    
    P1U_ASSERT_FALSE("Robot should be alive after completing the challenge", is_robot_dead());
    
    p1u_shutdown();
    
    return (p1world_shutdown());
}
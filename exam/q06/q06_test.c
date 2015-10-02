#include "q06.h"

#include "p1staff.h"

#include <stdio.h>


int main(int argc, char* argv[])
{
    p1u_setup();
    char test_string[256];
    
    	// Test the good values - EVERY ONE!
    for(int hour = 0; hour < 24; hour++)
    {
   		for(int minute = 0; minute < 60; minute++)
   		{
   			sprintf(test_string, "%02d:%02d is a valid 24 hour time", hour, minute);
		    P1U_ASSERT_TRUE(test_string, is_24_hour(hour, minute));
		}
	}
		// Some bad values
	P1U_ASSERT_FALSE("-999999:00 is not a valid 24 hour time", is_24_hour(-999999, 0));
    P1U_ASSERT_FALSE("-01:00 is not a valid 24 hour time", is_24_hour(-1, 0));
    P1U_ASSERT_FALSE("24:00 is not a valid 24 hour time", is_24_hour(24, 0));
    P1U_ASSERT_FALSE("999999:00 is not a valid 24 hour time", is_24_hour(999999, 0));
    P1U_ASSERT_FALSE("00:-999999 is not a valid 24 hour time", is_24_hour(0, -999999));
    P1U_ASSERT_FALSE("00:-1 is not a valid 24 hour time", is_24_hour(0, -1));
    P1U_ASSERT_FALSE("00:60 is not a valid 24 hour time", is_24_hour(0, 60));
    P1U_ASSERT_FALSE("00:999999 is not a valid 24 hour time", is_24_hour(0, 999999));
    
    p1u_shutdown();
    return 0;
}

#include "q06.h"

int is_24_hour(int hours, int minutes)
{
	return (hours>=0 && hours<=23) && (minutes>=0 && minutes<=59);
}
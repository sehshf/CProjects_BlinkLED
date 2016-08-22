/*
 * main.c
 *
 *  Created on: 04/08/2016
 *      Author: ses
 */

/*
 * **************************************************
 * APPLICATION INCLUDE FILES						*
 * **************************************************
 */
#include "portable.h"
#include "gpio.h"

int main()
{
	uint16_T g, map;

	map = map_peripheral(&gpio);

	if(map == -1)
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return FAILED;
	}

	// Define pin 21 as output
	g = 21;
	INP_GPIO(g);
	OUT_GPIO(g);

	while(1)
	{
		// Toggle pin 21 (blink a led!)
		SET_GPIO = 1 << g;
		sleep(3);

		CLR_GPIO = 1 << g;
		sleep(3);
	}

	return PASSED;

} // END: main()

// EOF: main.c

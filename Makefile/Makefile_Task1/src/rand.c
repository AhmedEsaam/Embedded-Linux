#include <stdlib.h>
#include <time.h>

/**
 *@brief function that generates a random integer number between lower and upper bounds
 *
 *@param min 
 *@param max 
 *@return int 
*/
int generate_random_number(int min, int max)
{
    /* Setting the srand() function with a random value */
    srand(time(NULL));

    /* Initializing the Number using the rand() function */
    int num;
    num = (rand() % (max - min + 1) + min);

    return num;
}
#include <stdio.h>
#include "rand.h"

int main(int argc, char const *argv[])
{
    int min = 1, max = 100, guessed_num, actual_num, no_of_tries;
    char choice;

    do
    {
        /* Set the number of tries to 0 */
        no_of_tries = 0;

        /* Generate a random number and store it in actual_num */
        actual_num = generate_random_number(1, 10);

        /* Asking the user to guess the random number in only 5 tries */
        printf("** Guess a number between 1 and 10 (in only 5 tries) **\n");

        while(1)
        {
            /* Game over if the number of tries exceeds 5 */
            if (no_of_tries >= 5)
            {
                printf("** Game Over **\n");
                break;
            }
            
            /* Asking the user to enter a number */
            printf("\nEnter number: ");
            scanf("%d", &guessed_num);

            /* Displaying the guessed number */
            printf("You guessed: %d\n", guessed_num);

            /* Check whether the guessed number matches the actual number */
            if (guessed_num != actual_num)
            {
                printf("Wrong guess!, Number of tries: %d\n", ++no_of_tries);
            }
            else if (guessed_num == actual_num)
            {
                printf("Correct! :), Number of tries: %d\n", ++no_of_tries);
                break;
            }
        }

        /* Asking the user if he/she wants to play again */
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &choice);

    }while( choice == 'y' );


    return 0;
}


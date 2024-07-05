#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    /* Define the input and result variables */
    int input, result;

    /* Initialize result ith zero */
    result = 0;

    /* Asking the user to enter a number */
    cout << "Please Enter Number: ";

    /* Loop to enter new numbers untill the user enters 0 */
    while(true)
    {
        /* input number */
        cin >> input;

        /* Check if the input number not equal 0 */
        if(input != 0)
        {
            /* If not, acculilate to the result var */
            result += input;

            /* Asking the user to enter a new number */
            cout << "Please Enter a New Number: ";
        }
        else
        {
            /* If the input number equal 0, stop */
            break;
        }
    }
    
    /* Display the resulted acculated result */
    cout << "The result is: " << result << endl;
    


    return 0;
}

#include <iostream>

using namespace std;

/**
 *@brief Get the time period from seconds
 *
 *@param input_seconds 
 *@param out_hours 
 *@param out_mins 
 *@param out_seconds 
*/
void get_time_period(int input_seconds, int* p_out_hours, int* p_out_mins, int* p_out_seconds)
{
    /* calculating the output hours, minutes, and seconds */
    *p_out_hours = input_seconds / 3600;
    *p_out_mins = (input_seconds / 60) - (*p_out_hours * 60);
    *p_out_seconds = input_seconds % 60;
}


int main(int argc, char const *argv[])
{
    /* define input seconds and output hours, minutes, and seconds */
    int input_seconds, out_hours, out_mins, out_seconds;

    /* Asking the user to enter the number of seconds in the time period */
    cout << "Input seconds: ";

    /* store the input value in input_second var */
    cin >> input_seconds;

    /* calculate the time period in hours, minutes, and seconds */
    get_time_period(input_seconds, &out_hours, &out_mins, &out_seconds);

    /* Display the output time peroid in the required format */
    cout << "H:M:S - " << out_hours << ":" << out_mins << ":" << out_seconds << endl;
    
    return 0;
}

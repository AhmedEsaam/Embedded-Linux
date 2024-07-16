#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int noOfDigits(int num)
{
    int n = 1;
    while (num >= 10)
    {
        num /= 10;
        n++;
    }
    return n;
}

int main()
{
    /* Define input file */
    std::ifstream input{"input.txt", std::ios::in};

    const int MAX = 20;
    int arr[MAX];

    int sum = 0, min = 0, max = 0;
    double avg;

    int i = 0;

    while (!input.eof())
    {
        /* Get number */
        input >> arr[i];

        /* accumilate sum */
        sum += arr[i];

        /* initialize min and max */
        if (i == 0)
        {
            min = arr[0];
            max = arr[0];
        }

        /* check min */
        if (arr[i] < min)
        {
            min = arr[i];
        }

        /* check max */
        if (arr[i] > max)
        {
            max = arr[i];
        }

        /* Print input */
        std::cout << arr[i] << std::endl;

        /* increment index */
        ++i;
    }

    input.close();

    /* caculate average */
    avg = static_cast<double>(sum) / i;

    std::cout << sum << " " << avg << " " << min << " " << max << std::endl;

    /* Writing results to output.txt */

    /* Define output file */
    std::ofstream output{"output.txt", std::ios::out};

    /* Print table heads */
    output << "-------------------------------------------------------------------------" << std::endl;
    std::string heads[4] = {"Sum", "Avg", "Min", "Max"};
    output << "|";
    for (int i = 0; i < 4; ++i)
    {
        output << std::setw(10) << heads[i] << std::setw(8) << "|";
    }

    /* Print table values */
    output << std::endl
           << "-------------------------------------------------------------------------" << std::endl;

    /* Calcualte each table value number of digits to always print the value in the middle of the cell */
    int sum_digits = noOfDigits(sum);
    int avg_digits = noOfDigits(static_cast<int>(avg)) + 2; // 2: is the fixed number of digits after the floating point
    int min_digits = noOfDigits(min);
    int max_digits = noOfDigits(max);

    /* Print values with needed flags and padding */
    output << "|";
    output << std::setw(9 + sum_digits / 2) << sum << std::setw(9 - sum_digits / 2) << "|";
    output << std::setw(9 + avg_digits / 2) << std::setprecision(2) << std::fixed << avg << std::setw(9 - avg_digits / 2) << "|";
    output << std::setw(9 + min_digits / 2) << min << std::setw(9 - min_digits / 2) << "|";
    output << std::setw(9 + max_digits / 2) << max << std::setw(9 - max_digits / 2) << "|";
    output << std::endl
           << "-------------------------------------------------------------------------" << std::endl;

    output.close();

    return 0;
}

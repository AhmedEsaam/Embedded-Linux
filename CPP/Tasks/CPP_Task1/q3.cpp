#include <iostream>
#include <cmath>

using namespace std;

/* convert from binary to decimal */
int from_bin_to_dicimal(int binary)
{
    int decimal = 0;

    for (int i = 0; i < sizeof(int) * 8; ++i)
    {
        decimal += (binary % 10) * pow(2, i);
        binary /= 10;
    }
    
    return decimal;
}

/* convert from decimal to binary */
int from_decimal_to_binary(int decimal)
{
    int binary = 0;

    for (int i = 0; i < sizeof(int) * 8; ++i)
    {
        binary += (decimal % 2) * pow(10, i);
        decimal /= 2;
    }
    
    return binary;
}


int main(int argc, char const *argv[])
{
    /* define input in binary and decimal*/
    int input_binary, input_decimal;


    /* Asking the user to enter a binary number */
    cout << "Enter a binary number: ";
    /* storing the input binary */
    cin >> input_binary;
    /* calculate the decimal value and display it */
    cout << " = " << from_bin_to_dicimal(input_binary) << " in decimal" << endl;


    /* Asking the user to enter a decimal number */ 
    cout << "Enter a decimal number: ";
    /* storing the input decimal */
    cin >> input_decimal;
    /* calculate the binary value and display it */
    cout << " = " << from_decimal_to_binary(input_decimal) << " in binary" << endl;
    
    return 0;
}

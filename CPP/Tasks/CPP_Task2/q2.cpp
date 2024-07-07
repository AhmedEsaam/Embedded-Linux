#include <iostream>
#include <cmath>

using namespace std;

class Calculator
{
private:
    // Class attributes
    int num1, num2, result;
    char op;

    // mathematical Operations Functions
    int add(int num1, int num2)
    {
        return num1 + num2;
    }

    int subtract(int num1, int num2)
    {
        return num1 - num2;
    }

    int multiply(int num1, int num2)
    {
        return num1 * num2;
    }

    int divide(int num1, int num2)
    {
        return num1 / num2;
    }

    int power(int num1, int num2)
    {
        return num1 ^ num2;
    }

    int square_root(int num1)
    {
        return sqrt(num1);
    }

public:

    // Function to input values
    void inputValues()
    {
        cout << "Please Enter the Operation (+, -, *, /, ^, 'S' squrt()): ";
        cin >> op;
     
        cout << "Please Enter Number: ";
        cin >> num1;

        if(op != 'S')
        {
            cout << "Please Enter the Second Number: ";
            cin >> num2;
        }
    }

    // Function to display result
    void displayResult()
    {
        switch (op)
        {
        case '+':
            result = add(num1, num2);
            break;
            
        case '-':
            result = subtract(num1, num2);
            break;
            
        case '*':
            result = multiply(num1, num2);
            break;
            
        case '/':
            result = divide(num1, num2);
            break;

        case '^':
            result = pow(num1, num2);
            break;

        case 'S':
            result = square_root(num1);
            break;
            
        default:
            break;
        }
        cout << "The result is: " << result << endl;
    }
};

int main()
{
    // Define the Calculator object
    Calculator calc;
    
    char choice;

    do
    {
        /* Asking the user to input the mathematical equation */
        calc.inputValues();

        /* Displaying the result */
        calc.displayResult();

        /* Asking the user whether to perform another mathimatical operation */
        cout << "Do you want to perform another calculation> (y/n): ";
        cin >> choice;
        
    } while (choice != 'n');

    
    return 0;
}

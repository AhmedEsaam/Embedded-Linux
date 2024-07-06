#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    /* The city population */
    const int population = 162100;

    /*
    - Every year, the population grows by 6.5%. 
    - Which means after 1 year, it will become (1.65 * 162100)
    - In a number of years n, it will become (((1.65 * 162100) * 1.65) * 1.65) ... n times
    - Which calculates to (1.65 ^ n) * 162100
    - To get the number of years (n) for the population to reach 1 million or less: (1.65 ^ n) * 162100 <= 1000000
    - We solve for n: 
        log(1000000/162100) to the base (1.65) 
    - We add 1 more year for the population to exceed 1 million.
    */

    /* (log(x) to the base y) calculates to (log(x) / log(y)) to a common base (e for example) */
    /* log(x) is the natural log (to the base e) */
    int num_of_years_to_1_million = log(1000000.0f / static_cast<double>(population)) / log(1.65) + 1;
    
    /* Displaying the number of years */
    cout << "The number of years it would take the population to reach 1 million = " << num_of_years_to_1_million << " years." << endl;

    /* Displaying the population after each year */
    int pop = population, year = 0;

    while(pop < 1000000)
    {
        pop *= 1.65;
        cout << "Poplation at year " << ++year << ": " << pop << endl;
    }
    
    return 0;
}

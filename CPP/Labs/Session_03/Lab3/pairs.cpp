#include <iostream>

// using namespace std;

namespace ArrayPairs
{
    /* Function to create pair array */
    std::pair<int, int> * createArray(int size)
    {
        std::pair<int, int> * pairArr = new std::pair<int, int> [size]; 
        return pairArr;
    }

    /* Function to delete pair array */
    void deleteArray(std::pair<int, int> * pairArr)
    {
        delete [] pairArr;
    }

    /* Function to set a pair array item at specific index */
    void setPair(std::pair<int, int> * pairArr, int index, int pairFirst, int pairSecond)
    {
        pairArr[index].first = pairFirst;
        pairArr[index].second = pairSecond;
    }

    /* Function to get a pair array item at specific index */
    std::pair<int, int> getPair(std::pair<int, int> * pairArr, int index)
    {
        return  pairArr[index];
    }

    /* Functin to print a pair array */    
    void printPairArray(std::pair<int, int> * pairArr, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << "Pair Array[" << i << "] .first = " << pairArr[i].first
                << " .second = " << pairArr[i].second << std::endl;
        }
    }

    /* Function to print a Pair */
    void printPair(std::pair<int, int> pair)
    {
        std::cout << "Pair .first = " << pair.first
            << " .second = " << pair.second << std::endl;
    }

}


int main(void)
{
    /* Creating the Pair Array */
    const int SIZE = 3; 
    std::pair<int, int> * pairArr = ArrayPairs::createArray(SIZE);

    /* Setting the pair array elements */
    ArrayPairs::setPair(pairArr, 0, 1, 2);
    ArrayPairs::setPair(pairArr, 1, 3, 4);
    ArrayPairs::setPair(pairArr, 2, 5, 6);
    
    /* Getting the pair array elements and printing each one to check the getPair functionality */
    ArrayPairs::printPair(ArrayPairs::getPair(pairArr, 0));
    ArrayPairs::printPair(ArrayPairs::getPair(pairArr, 1));
    ArrayPairs::printPair(ArrayPairs::getPair(pairArr, 2));

    /* Printing the pair array */
    ArrayPairs::printPairArray(pairArr, SIZE);

    /* Deallocating the pair array pointer */
    ArrayPairs::deleteArray(pairArr);


    return 0;
}
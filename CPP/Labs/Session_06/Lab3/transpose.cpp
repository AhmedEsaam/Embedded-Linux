#include <iostream>
#include <vector>

/* Generate transposed matrix of given matrix */
std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>> &v2d)
{
    /* Define transposed matrix with the size of the row of the given matrix */
    std::vector<std::vector<int>> transposed(v2d[0].size());

    int trans_row = 0;

    for (auto &row : v2d)
    {
        for (auto &val : row)
        {
            transposed[trans_row].push_back(val);
            trans_row++;
        }
        trans_row = 0;
    }

    return transposed;
}

/* Print Matrix */
void print(const std::vector<std::vector<int>> &v2d)
{
    for (auto &row : v2d)
    {
        for (auto &val : row)
        {
            std::cout << val << " ";
        }

        std::cout << std::endl;
    }
}

int main()
{
    /* Define given matrix */
    std::cout << "Given matrix: " << std::endl;
    std::vector<std::vector<int>> v2d = {{1, 2}, {4, 5}, {7, 8}, {9, 5}};
    print(v2d);

    /* Generate transposed matrix and print it */
    std::cout << std::endl
              << "Transposed matrix: " << std::endl;
    print(transpose(v2d));

    return 0;
}

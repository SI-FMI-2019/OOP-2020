#include <iostream>

int main()
{
    int m = 0;
    int n = 0;
    int a = 0;
    
    // user defined length and width the matrix
    std::cout << "Input nrow: ";
    std::cin >> m;
    std::cout << "Input ncol: ";
    std::cin >> n;
    std::cout << "Input a: ";
    std::cin >> a;    

    // memory allocation
    int** matrix = new int* [m];
    for (int i = 0; i < m; i++)
    {
        matrix[i] = new int[n];
    }
    
    // working with allocated  memory
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                matrix[i][j] = a;
            }
            else
            {
                matrix[i][j] = -1;
            }      
        }
    }

    // print the values in the matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    // memory deallocation
    for (int i = 0; i < m; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
#include <iostream>

void printMatrix(int** matrix, const int rows, const int columns)
{
    std::cout << std::endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << matrix[i][j] << " ";       
        }
        std::cout << std::endl;        
    }
}

void deleteMatrix(int** matrix, const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    int rows = 0;
    int columns = 0;

    std::cout << "Enter rows: ";
    std::cin >> rows;

    std::cout << "Enter columns: ";
    std::cin >> columns;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int [columns];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << "a" << i + 1 << j + 1 << " = ";
            std::cin >> matrix[i][j];
        }
    }
        
    printMatrix(matrix, rows, columns);

    int transposedRows = columns;
    int transposedColumns = rows;

    int** transposedMatrix = new int* [transposedRows];
    for (int i = 0; i < transposedRows; i++)
    {
        transposedMatrix[i] = new int [transposedColumns];
    }
    
    for (int i = 0; i < transposedRows; i++)
    {
        for (int j = 0; j < transposedColumns; j++)
        {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }
    
    printMatrix(transposedMatrix, transposedRows, transposedColumns);

    deleteMatrix(matrix, rows);
    deleteMatrix(transposedMatrix, transposedRows);

    return 0;
}
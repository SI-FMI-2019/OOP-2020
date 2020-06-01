#include <iostream>
#include <string>

template <class T>
class Matrix{
public:
    Matrix(): rows(2), cols(2)
    {
        this->matrix = Matrix::alloc_memory(this->rows, this->cols);
    }

    Matrix(const unsigned& rows, const unsigned& cols): rows(rows), cols(cols)
    {
        this->matrix = Matrix::alloc_memory(rows, cols);
    }

    Matrix(const Matrix& from): rows(from.rows), cols(from.cols)
    {
        this->matrix = Matrix::alloc_memory(this->rows, this->cols);
        Matrix::copy_memory(from.matrix, this->matrix, {this->rows, this->cols});
    }

    Matrix<T>& operator=(const Matrix& from)
    {
        if(this != &from)
        {
            this->rows = from.rows;
            this->cols = from.cols;

            Matrix::free_memory(this->matrix, this->cols);
            this->matrix = Matrix::alloc_memory(this->rows, this->cols);
            Matrix::copy_memory(from.matrix, this->matrix, {this->rows, this->cols});
        }
        return *this;
    }

    ~Matrix()
    {
        Matrix::free_memory(this->matrix, this->cols);
    }

    void set_at(const unsigned& row, const unsigned& col, const T& element)
    {
        this->matrix[row - 1][col - 1] = element;
    }

    const T& get_at(const unsigned& row, const unsigned& col) const
    {
        return &(this->matrix[row - 1][col - 1]);
    }

    void transpose()
    {
        /*
         * (2, 3)
         * (4, 5)
         * (6, 7)
         * MxN
         *
         * (2, 4, 6)
         * (3, 5, 7)
         * NxM
         */

        T** transposed_matrix = alloc_memory(this->cols, this->rows);

        // [i][j] => [j][i]

        for(int i = 0; i < this->rows; i++)
        {
            for(int j = 0; j < this->cols; j++)
            {
                transposed_matrix[j][i] = this->matrix[i][j];
            }
        }

        Matrix::free_memory(this->matrix, this->cols);
        this->matrix = transposed_matrix;

        std::swap(this->rows, this->cols);
    }

    void print() const
    {
        for(int i = 0; i < this->rows; i++)
        {
            std::cout << "(";
            for(int j = 0; j < this->cols - 1; j++)
            {
                std::cout << this->matrix[i][j] << ", ";
            }
            std::cout << this->matrix[i][this->cols - 1] << ")" << std::endl;
        }

    }

private:
    T** matrix;

    unsigned rows;
    unsigned cols;

    static T** alloc_memory(const unsigned& rows, const unsigned& cols)
    {
        T** memory = new T*[rows];
        for(int i = 0; i < rows; i++)
        {
            memory[i] = new T[cols];
        }
        return memory;
    }

    static void copy_memory(T** source, T** destination, std::pair<const unsigned&, const unsigned&> size)
    {
        for(int i = 0; i < size.first; i++)
        {
            for(int j = 0; j < size.second; j++)
            {
                destination[i][j] = source[i][j];
            }
        }
    }

    static void free_memory(T** memory, const unsigned& size)
    {
        for(int i = 0; i < size; i++)
        {
            delete[] memory[i];
        }
        delete[] memory;
    }
};

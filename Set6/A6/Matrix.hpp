#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <sstream>
using namespace std;

template<typename T>
class Matrix {
public:
    /**
     * @brief Construct a new matrix of size rows, cols
     * @param rows
     * @param cols
     */
    Matrix(const int rows, const int cols) : rows(rows), cols(cols) {
        _arr = new T[rows * cols];
    }

    ~Matrix() {
        delete[] _arr;
    }

    /**
     * @brief Index into the matrix, throws out of range
     * @param row row index
     * @param col column index
     * @return object at the specified index
     */
    T& get(const int row, const int col) const {
        if (row >= rows || col >= cols) {
            stringstream ss;

            ss << "Position (" << row << ", " << col << ") out of range";

            throw std::out_of_range(ss.str());
        }

        return _arr[row * cols + col];
    }

    /**
     * @brief Set the specified index to the given value
     * @param row row index
     * @param col column index
     * @param value value to set at the given index
     */
    void set(const int row, const int col, T value) {
        if (row >= rows || col >= cols) {
            stringstream ss;

            ss << "Position (" << row << ", " << col << ") out of range";

            throw std::out_of_range(ss.str());
        }

        _arr[row * cols + col] = value;
    }

    /**
     * @brief Get the number of rows in the matrix
     * @return the number of rows
     */
    int getRows() const {
        return rows;
    }

    /**
     * @brief Get the number of columns in the matrix
     * @return the number of columns
     */
    int getCols() const {
        return cols;
    }

private:
    const int rows;
    const int cols;

    T* _arr;
};

#endif //MATRIX_HPP
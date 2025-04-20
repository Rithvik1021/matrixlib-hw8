// Matrix.cpp
#include "Matrix.h"
#include <stdexcept>
#include <cmath>
#include <iostream>

using namespace std;

Matrix::Matrix(size_t numRows, size_t numCols, double val)
  : m_rows(numRows)
  , m_cols(numCols)
  , m_data(numRows * numCols, val)
{ }

double& Matrix::operator()(size_t row, size_t col) {
    if (row >= m_rows || col >= m_cols)
        throw out_of_range("Matrix index out of range");
    return m_data[index(row, col)];
}

double Matrix::operator()(size_t row, size_t col) const {
    if (row >= m_rows || col >= m_cols)
        throw out_of_range("Matrix index out of range");
    return m_data[index(row, col)];
}

// addition
Matrix Matrix::operator+(const Matrix& o) const {
    if (m_rows != o.m_rows || m_cols != o.m_cols)
        throw invalid_argument("Size mismatch in +");
    Matrix result(m_rows, m_cols);
    for (size_t idx = 0; idx < m_data.size(); ++idx)
        result.m_data[idx] = m_data[idx] + o.m_data[idx];
    return result;
}

// matrix × matrix
Matrix Matrix::operator*(const Matrix& o) const {
    if (m_cols != o.m_rows)
        throw invalid_argument("Size mismatch in *");
    Matrix result(m_rows, o.m_cols, 0.0);
    for (size_t row = 0; row < m_rows; ++row) {
        for (size_t k = 0; k < m_cols; ++k) {
            double v = (*this)(row, k);
            for (size_t col = 0; col < o.m_cols; ++col)
                result(row, col) += v * o(k, col);
        }
    }
    return result;
}

// transpose
Matrix Matrix::transpose() const {
    Matrix result(m_cols, m_rows);
    for (size_t row = 0; row < m_rows; ++row)
        for (size_t col = 0; col < m_cols; ++col)
            result(col, row) = (*this)(row, col);
    return result;
}

// scalar × matrix
Matrix Matrix::scale(double k) const {
    Matrix result(*this);
    for (double &x : result.m_data)
        x *= k;
    return result;
}

bool Matrix::equals(const Matrix& o, double eps) const {
    if (m_rows != o.m_rows || m_cols != o.m_cols) return false;
    for (size_t idx = 0; idx < m_data.size(); ++idx)
        if (fabs(m_data[idx] - o.m_data[idx]) > eps) return false;
    return true;
}

// print
void Matrix::print(ostream& out) const {
    for (size_t row = 0; row < m_rows; ++row) {
        out << "[ ";
        for (size_t col = 0; col < m_cols; ++col) {
            out << (*this)(row, col);
            if (col + 1 < m_cols) out << " ";
        }
        out << " ]\n";
    }
}

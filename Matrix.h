// Matrix.h
#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Matrix {
public:
    // matrix and entries = val
    Matrix(size_t numRows, size_t numCols, double val = 0.0);

    // read/write element at row/col
    double& operator()(size_t row, size_t col);
    double  operator()(size_t row, size_t col) const;

    Matrix  operator+(const Matrix& o) const;
    Matrix  operator*(const Matrix& o) const;
    Matrix  transpose() const;
    Matrix  scale(double k) const;

    bool equals(const Matrix& o, double eps = 1e-9) const;
    void print(ostream& os = cout) const;

    size_t  rows()  const { return m_rows; }
    size_t  cols()  const { return m_cols; }

private:
    size_t m_rows, m_cols;
    vector<double> m_data;

    size_t index(size_t row, size_t col) const {
        return row * m_cols + col;
    }
};

inline ostream& operator<<(ostream& os, const Matrix& M) {
    M.print(os);
    return os;
}

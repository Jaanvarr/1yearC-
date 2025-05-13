#include <iostream>
#include <stdexcept>
#include <cstdio>  // Для snprintf
#include <cstdlib> // Для rand

class Vector {
private:
    double* data;
    size_t size_;

public:
    Vector() : size_(0), data(nullptr) {}

    Vector(size_t size, double value = 0) : size_(size) {
        data = new double[size_];
        for (size_t i = 0; i < size_; ++i) {
            data[i] = value;
        }
    }

    Vector(const Vector& other) : size_(other.size_) {
        data = new double[size_];
        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size_ = other.size_;
            data = new double[size_];
            for (size_t i = 0; i < size_; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~Vector() {
        delete[] data;
    }

    double& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range in Vector");
        }
        return data[index];
    }

    const double& operator[](size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range in Vector");
        }
        return data[index];
    }

    size_t size() const {
        return size_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
        for (size_t i = 0; i < v.size_; ++i) {
            os << v.data[i] << " ";
        }
        return os;
    }
};

class Matrix {
private:
    Vector* data;
    size_t rows_;
    size_t cols_;
    static int counter;
    char name[20];

public:
    Matrix(size_t rows, size_t cols, double value = 0)
        : rows_(rows), cols_(cols) {
        counter++;
        snprintf(name, sizeof(name), "Matrix #%d", counter);

        data = new Vector[rows_];
        for (size_t i = 0; i < rows_; ++i) {
            data[i] = Vector(cols_, value);
        }
    }

    Matrix(const Matrix& other)
        : rows_(other.rows_), cols_(other.cols_) {
        counter++;
        snprintf(name, sizeof(name), "Matrix #%d", counter);

        data = new Vector[rows_];
        for (size_t i = 0; i < rows_; ++i) {
            data[i] = other.data[i];
        }
    }

    Matrix& operator=(const Matrix& other) {
        
        for (int i = 0; i < rows_; i++)
            data[i].~Vector();
        
        if (this != &other) {
            delete[] data;
            rows_ = other.rows_;
            cols_ = other.cols_;
            data = new Vector[rows_];
            for (size_t i = 0; i < rows_; ++i) {
                data[i] = other.data[i];
            }
            snprintf(name, sizeof(name), "Matrix #%d", ++counter);
        }
        return *this;
    }

    ~Matrix() {
        delete[] data;
    }

    Vector& operator[](size_t index) {
        if (index >= rows_) {
            throw std::out_of_range("Row index out of range in Matrix");
        }
        return data[index];
    }

    const Vector& operator[](size_t index) const {
        if (index >= rows_) {
            throw std::out_of_range("Row index out of range in Matrix");
        }
        return data[index];
    }

    size_t rows() const { return rows_; }
    size_t cols() const { return cols_; }

    void print() const {
        std::cout << name << ":\n";
        for (size_t i = 0; i < rows_; ++i) {
            std::cout << data[i] << "\n";
        }
    }

    Matrix operator+(const Matrix& other) const {
        if (rows_ != other.rows_ || cols_ != other.cols_) {
            throw std::invalid_argument("Matrix dimensions do not match for addition");
        }
        Matrix result(rows_, cols_);
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < cols_; ++j) {
                result[i][j] = data[i][j] + other[i][j];
            }
        }
        return result;
    }

    Matrix operator*(double scalar) const {
        Matrix result(rows_, cols_);
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < cols_; ++j) {
                result[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    Matrix transpose() const {
        Matrix result(cols_, rows_);
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < cols_; ++j) {
                result[j][i] = data[i][j];
            }
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        m.print();
        return os;
    }
};



double MinimumOutOfN(Matrix C, int index_line, int index_column, int MatrixSize)
{
    double min = C[index_line][index_column];
    while (index_column < MatrixSize && index_line < MatrixSize)
    {
        if (C[index_line][index_column] < min)
            min = C[index_line][index_column];
        index_column++;
        index_line++;
    }
    return min;
}

int Matrix::counter = 0;

int main() {
    Matrix A(3, 3, 10);
    Matrix B(3, 3, 20);
    int a = 5, b = 5;
    double c = 0;
    Matrix C(a, a, c);

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) { 
            C[i][j] = rand() % 10;
        }
    }

    std::cout << C << "\n";

    int index_line = a-1;
    int index_column = 0;

    Vector ResVector(2*a-1,0);
   
    int VectorIndex = 0;

    for (VectorIndex; VectorIndex < a-1; VectorIndex++)
    {
        ResVector[VectorIndex] = MinimumOutOfN(C, index_line, index_column, a);

        index_line--;
        
    }
    for (VectorIndex; VectorIndex < 2*a - 1; VectorIndex++)
    {
        ResVector[VectorIndex] = MinimumOutOfN(C, index_line, index_column, a);

        
        index_column++;
    }
    std::cout << ResVector << std::endl;
    return 0;
}


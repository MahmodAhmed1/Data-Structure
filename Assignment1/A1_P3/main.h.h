#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <iostream>
#include <vector>
using namespace std;
template <typename T> class Matrix{
private:
    vector< vector<T> > matrix;
    int rows, cols;
public:
    Matrix(){};
    Matrix(int rows_, int cols_, const T& type_); // constructor
    Matrix(const Matrix<T>& rhs); //copy constructor
    virtual ~Matrix(); // destructor
    // Declaration of the Matrix mathematical operations
    Matrix<T> operator+(const Matrix<T>& rhs);
    Matrix<T> operator-(const Matrix<T>& rhs);
    Matrix<T> operator*(const Matrix<T>& rhs);
    Matrix<T> transpose();
    //return the values of row and column for a matrix
    int get_rows() const;
    int get_cols() const;
    // overloaded i/o operators
    template <class T1>
    friend ostream& operator<<(ostream& OUT, const Matrix<T1>& rhs);

    template <class T1>
    friend istream &operator>>( istream  &IN, Matrix<T1> &rhs );

    T& operator()(const int& row, const int& col);
    const T& operator()(const int& row, const int& col) const;

    void print(){
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

};

#endif // MAIN_H_INCLUDED

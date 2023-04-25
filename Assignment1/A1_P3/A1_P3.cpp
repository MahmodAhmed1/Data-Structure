#include "main.h"

template<typename T>
Matrix<T>::Matrix(int rows_, int cols_, const T& type_) {
  matrix.resize(rows_);
  for (int i=0; i<matrix.size(); i++) {
    matrix[i].resize(cols_, type_);
  }
  rows = rows_;
  cols = cols_;
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& rhs) {
    matrix = rhs.matrix;
    rows = rhs.get_rows();
    cols = rhs.get_cols();
}

template<typename T>
Matrix<T>::~Matrix(){}

// Access the individual elements
template<typename T>
T& Matrix<T>::operator()(const int& row, const int& col) {
  return this->matrix[row][col];
}

// Access the individual elements (const)
template<typename T>
const T& Matrix<T>::operator()(const int& row, const int& col) const {
  return this->matrix[row][col];
}


template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) {
    Matrix result(rows, cols, 0.0);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            result(i,j) = matrix[i][j] + rhs(i,j);
            }
        }
    return result;
}


template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs) {
    int rows = rhs.get_rows();
    int cols = rhs.get_cols();
    Matrix result(rows, cols, 0.0);
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                    result(i,j) += this->matrix[i][j] * rhs(i,j);
            }
        }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs) {
    int rows = rhs.get_rows();
    int cols = rhs.get_cols();
    Matrix result(rows, cols, 0.0);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            result(i,j) = this->matrix[i][j] - rhs(i,j);
        }
    }
    return result;
}


template<typename T>
Matrix<T> Matrix<T>::transpose(){
    Matrix result(rows, cols, 0.0);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            result(i,j) = this->matrix[j][i];
            }
        }
    return result;
}

// Get the number of rows of the matrix
template<typename T>
int Matrix<T>::get_rows() const {
  return this->rows;
}

// Get the number of columns of the matrix
template<typename T>
int Matrix<T>::get_cols() const {
  return this->cols;
}









int main()
{
    int n1 , n2, option;
    cout << "Welcome to mazen matrix calculator " << endl;
    cout << "---------------------------------------" << endl;
    cout << "0- Exit" << endl;
    cout << "1- Perform Matrix Addition" << endl;
    cout << "2- Perform Matrix Subtraction" << endl;
    cout << "3- Perform Matrix Multiplication" << endl;
    cout << "4- Matrix Transpose" << endl;
    cin >> option;
    cout << "Enter Your First Matrix" << endl;
    cin >> n1;
    cout << "Enter Your Second Matrix" << endl;
    cin>>n2;
    Matrix<int> mat1(3,3, n1) , mat2(3,3,n2);

    bool flag = true;
    while(flag){
    if(option == 1){
        if(mat1.get_rows()==mat2.get_rows() && mat1.get_cols()==mat2.get_cols()){
            Matrix<int> mat3 = mat1 + mat2;
            cout <<"Matrix 1 + Matrix 2 = " << endl;
            mat3.print();
            flag = false;
        }
        else{
            cout<<"Rows and Columns are not equal\n";
            flag = false;

        }
    }
    else if(option == 2){
        if(mat1.get_rows()==mat2.get_rows() && mat1.get_cols()==mat2.get_cols()){
            Matrix<int> mat3 = mat1 - mat2;
            cout <<"Matrix 1 - Matrix 2 = "<<endl;
            mat3.print();
            flag = false;
        }
        else{
            cout<<"Rows and Columns are not equal\n";
            flag = false;

        }

    }
    else if(option == 3){
        if(mat1.get_rows()==mat2.get_rows() && mat1.get_cols()==mat2.get_cols()){
            Matrix<int> mat3 = mat1 * mat2;
            cout <<"Matrix 1 * Matrix 2= " <<endl;
            mat3.print();
            flag = false;
        }
        else{
            cout<<"Rows and Columns are not equal\n";
            flag = false;

        }
    }
    else if(option == 4){
        mat1.transpose();
        cout << "the transposed matrix: " << endl;
        mat1.print();
        flag = false;
    }
    else if(option == 0){
        flag = false;
    }
    }
    return 0;
}

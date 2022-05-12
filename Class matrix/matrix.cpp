#include <iostream>
#include <vector>
using namespace std;

int N; // size of matr
const int rows = 3;
const int cols = 3;

class Matrix {
public:
	int arr[rows][cols];
	void input(vector<vector<int> >& A);
	void operator+(Matrix x);
	void operator-(Matrix x);
	void operator*(Matrix x);
	void print();
};


void Matrix::print()
{ 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

void Matrix::input(vector<vector<int> >& A)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = A[i][j];
		}
	}
}

void Matrix::operator+(Matrix x)
{
	Matrix mat;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mat.arr[i][j] = arr[i][j] + x.arr[i][j];
		}
	}
	mat.print();
}

void Matrix::operator-(Matrix x)
{
	Matrix mat;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mat.arr[i][j] = arr[i][j] - x.arr[i][j];
		}
	}

	mat.print();
}


void Matrix::operator*(Matrix x)
{
	Matrix mat;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mat.arr[i][j] = 0;
			for (int k = 0; k < N; k++) {
				mat.arr[i][j] += arr[i][k]* (x.arr[k][j]);
			}
		}
	}
	mat.print();
}


int main()
{
	N = 3;
	vector<vector<int> > arr1
		= { { 5, 3, 2 },
			{ 4, 5, 2 },
			{ 1, 1, 5 } };

	vector<vector<int> > arr2
		= { { 2, 8, 9 },
			{ 4, 5, 16 },
			{ 4, 2, 12 } };

	Matrix mat1, mat2;
	mat1.input(arr1);
	mat2.input(arr2);

	cout << "1st Matr:\n";
	mat1.print();
	cout << "2nd Matr:\n";
	mat2.print();

	cout << "Addition: \n";
	mat1 + mat2;

	cout << "Subtraction: \n";
	mat1 - mat2;

	cout << "Multiplication: \n";
	mat1* mat2;

	return 0;
}


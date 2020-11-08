#include <iostream>
#include <time.h>
#include "Matrix.h"
using namespace std;

int main() {
	int colums, rows;
	cout << "Input Rows: ";
	cin >> rows;
	cout << "Input Colums: ";
	cin >> colums;
	static Matrix A(colums, rows), B(colums, rows), C;
	srand(time(NULL));
	A.random_matrix(); B.random_matrix();
	cout << A << endl;
	cout << B << endl;
	C = A - B;
	cout << C << endl;
	

	return 0;
}
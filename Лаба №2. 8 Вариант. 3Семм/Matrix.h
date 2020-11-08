#include <iostream>
#include <iomanip>
#include<time.h>

class Matrix {
public:
	//Конструкторы и деструктор
	Matrix();
	Matrix(int& col, int& rows, int** MatrixPtr); 
	Matrix(int& col, int& rows); 
	~Matrix();

	//Геттеры Сеттеры
	int** get_matrix();
	void set_matrix(int& col, int&rows);

	void random_matrix();
	
	//Перегрузки операторов
	friend std::ostream& operator<< (std::ostream& OurOut, Matrix& OurLogicMatrix);
	friend std::istream& operator>> (std::istream& OurIn, Matrix& OurLogicMatrix);
	friend Matrix& operator- (Matrix& Left, Matrix& Right);
	Matrix& operator= (const Matrix& OurMatrix);

private:
	int** OurMatrix;
	int colums, rows;
};



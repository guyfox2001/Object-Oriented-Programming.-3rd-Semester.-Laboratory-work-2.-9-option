#include "Matrix.h"

std::ostream& operator<<(std::ostream& OurOut, Matrix& OurLogicMatrix)
{
	setlocale(LC_ALL, "RUS");
	OurOut << "Наша матрица: \n";
	for (int i = 0; i < OurLogicMatrix.rows; i++) {
		for (int j = 0; j < OurLogicMatrix.colums; j++) {
			OurOut << std::setw(3) << OurLogicMatrix.OurMatrix[i][j];
		}
		OurOut << std::endl;
	}
	return OurOut;
}

std::istream& operator>>(std::istream& OurIn, Matrix& OurLogicMatrix)
{
	//Есть вероятность, что запись будет сделана в неинициализированную матрицу
	try {
		if (OurLogicMatrix.OurMatrix == nullptr) throw "Exeption! OurMatrix is not initialized\n";
		for (int i = 0; i < OurLogicMatrix.rows; i++) {
			for (int j = 0; j < OurLogicMatrix.colums; j++) {
				OurIn >> OurLogicMatrix.OurMatrix[i][j];
			}
		}
	}
	catch (const char* string) {
		std::cout << string;
	}
	return OurIn;
}

Matrix& operator-(Matrix& Left, Matrix& Right)
{
	static Matrix Result(Left.rows, Left.colums);
	try {
		if (Left.colums != Right.colums || Left.rows != Right.rows) throw "Exception! Size of Left Matrix != Size of Right Matrix\n";
		for (int i = 0; i < Left.rows; i++) {
			for (int j = 0; j < Left.rows; j++) {
				Result.OurMatrix[i][j] = Left.OurMatrix[i][j] - Right.OurMatrix[i][j];
			}
		}
	}
	catch (const char* StringException) {
		std::cout << StringException;
	}
	return Result;
}




Matrix::Matrix()
{
	OurMatrix = nullptr;
}

Matrix::Matrix(int& col, int& rows, int** MatrixPtr)
{
	this->colums = col;
	this->rows = rows;
	this->OurMatrix = new int* [this->rows];
	for (int i = 0; i < rows; i++) {
		this->OurMatrix[i] = new int[this->colums];
	}
	this->OurMatrix = MatrixPtr;
}

Matrix::Matrix(int& col, int& rows)
{
	this->colums = col;
	this->rows = rows;
	this->OurMatrix = new int* [this->rows];
	for (int i = 0; i < rows; i++) {
		this->OurMatrix[i] = new int[this->colums];
	}
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->colums; j++) {
			this->OurMatrix[i][j] = 0;
		}
	}
}

Matrix::~Matrix()
{
	if (this->OurMatrix[0] != NULL) {
		for (int i = 0; i < this->rows; ++i) {
			delete [] this->OurMatrix[i];
		}
		delete [] this->OurMatrix;
		this->OurMatrix[0] = NULL;
	}
	
}

int** Matrix::get_matrix()
{
	return this->OurMatrix;
}

Matrix& Matrix::operator=(const Matrix& OurMatrix)
{
	this->OurMatrix = OurMatrix.OurMatrix;
	this->rows = OurMatrix.rows;
	this->colums = OurMatrix.colums;
	return *this;
}

void Matrix::set_matrix(int& col, int& rows)
{
	this->colums = col;
	this->rows = rows;
	this->OurMatrix = new int* [this->rows];
	for (int i = 0; i < rows; i++) {
		this->OurMatrix[i] = new int[this->colums];
	}
}

void Matrix::random_matrix()
{
	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->colums; ++j) {
			this->OurMatrix[i][j] = rand() % 50+1;
		}
	}
}

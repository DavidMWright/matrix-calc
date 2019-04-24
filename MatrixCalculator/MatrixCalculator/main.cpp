
#include <math.h>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

void printTitle ();
void enterMatrix (Matrix &matrix);
void printMatrix (Matrix matrix);
Matrix add (Matrix matrix1, Matrix matrix2);
Matrix mult (Matrix matrix1, Matrix matrix2);
Matrix reduce (Matrix matrix);


int main ()
{
	Matrix result, matrix1, matrix2;
	char operation;
	char cont = 'n';

	do
	{
		system ("CLS");
		printTitle ();

		cout << "\nEnter Operation: ";
		cin >> operation;

		switch (operation)
		{
			case 'a':
				enterMatrix (matrix1);
				enterMatrix (matrix2);
				result = add (matrix1, matrix2);
				break;

			case 'm':
				enterMatrix (matrix1);
				enterMatrix (matrix2);
				result = mult (matrix1, matrix2);
				break;

			case 'r':
				enterMatrix (matrix1);
				result = reduce (matrix1);
				break;
		}

		printMatrix (matrix1);
		cout << "+\n";
		printMatrix (matrix2);
		cout << "=\n";
		printMatrix (result);

		do
		{
			cout << "Continue? (y/n) ";
			cin >> cont;
		} while (cont != 'y' && cont != 'n');
	} while (cont == 'y');


	system ("pause");
	return 0;
}


void printTitle ()
{
	cout << "*********************\n"
			 << "* Matrix Calculator *\n"
			 << "*********************\n"
			 << "Addition: a\n"
			 << "Multiplication: m\n"
			 << "Row Reduction: r\n";
}


void enterMatrix (Matrix &matrix)
{
	int rows, columns;
	vector<int> row;
	int num;

	cout << "Enter # Rows: ";
	cin >> rows;
	cout << "Enter # Columns: ";
	cin >> columns;

	for (int i = 0; i < rows; i++)
	{
		cout << "Enter Row: ";
		
		for (int j = 0; j < columns; j++)
		{
			cin >> num;
			row.push_back (num);
		}

		matrix.push_back (row);
		row.clear ();
		row.shrink_to_fit ();
	}
}

void printMatrix (Matrix matrix)
{
	for (int i = 0; i < matrix.size (); i ++)
	{
		cout << "|";
		for (int j = 0; j < matrix[i].size (); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "|\n";
	}
}

Matrix add (Matrix matrix1, Matrix matrix2)
{
	Matrix result = matrix1;

	for (int i = 0; i < matrix1.size (); i++)
	{
		for (int j = 0; j < matrix1[i].size (); j++)
		{
			result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}

	return result;
}

Matrix mult (Matrix matrix1, Matrix matrix2)
{
	Matrix result;

	return result;
}

Matrix reduce (Matrix matrix)
{

	return matrix;
}


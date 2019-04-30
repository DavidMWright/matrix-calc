
#include <math.h>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

typedef vector<vector<double>> Matrix;

vector<double>add (vector<double> left, vector<double> right);
vector<double>multiply (vector<double> row, double scaler);
void printTitle ();
void enterMatrix (Matrix &matrix, int &rows, int &columns, char op);
void printMatrix (Matrix matrix);
Matrix add (Matrix matrix1, Matrix matrix2);
Matrix mult (Matrix matrix1, Matrix matrix2);
Matrix reduce (Matrix matrix);
Matrix transpose (Matrix matrix);
void clear (Matrix &matrix);


int main ()
{
	Matrix result, matrix1, matrix2;
	char operation;
	char cont = 'n';
	int rows;
	int columns;

	do
	{
		clear (result);
		clear (matrix1);
		clear (matrix2);
		rows = 0;
		columns = 0;

		system ("CLS");
		printTitle ();

		cout << "\nEnter Operation: ";
		cin >> operation;

		switch (operation)
		{
			case 'a':
				enterMatrix (matrix1, rows, columns, 'a');
				cout << "\n";
				enterMatrix (matrix2, rows, columns, 'a');
				cout << "\n";
				result = add (matrix1, matrix2);
				break;

			case 'm':
				enterMatrix (matrix1, rows, columns, 'm');
				cout << "\n";
				rows = 0;
				enterMatrix (matrix2, columns, rows, 'm');
				cout << "\n";
				result = mult (matrix1, matrix2);
				break;

			case 'r':
				enterMatrix (matrix1, rows, columns, 'r');
				cout << "\n";
				result = reduce (matrix1);
				break;

			case 't':
				enterMatrix (matrix1, rows, columns, 't');
				cout << "\n";
				result = transpose (matrix1);
		}

		printMatrix (matrix1);
		
		switch (operation)
		{
			case 'a': cout << "+";
				break;

			case 'm': cout << "*";
				break;

			case 'r': cout << "\nIn Row Echolon From";
				break;

			case 't': cout << "\ntTranspose";
		}

		cout << "\n";

		printMatrix (matrix2);
		cout << "=\n\n";
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



vector<double>add(vector<double> left, vector<double> right)
{
	vector<double> temp = right;

	for (int i = 0; i < right.size (); i++)
	{
		temp[i] = left[i] + right[i];
	}

	return temp;
}

vector<double>multiply (vector<double> row, double scaler)
{
	for (int i = 0; i < row.size (); i++)
	{
		row[i] = row[i] * scaler;
	}

	return row;
}

void printTitle ()
{
	cout << "*********************\n"
			 << "* Matrix Calculator *\n"
			 << "*********************\n"
			 << "Addition: a\n"
			 << "Multiplication: m\n"
			 << "Row Echelon Form: r\n"
			 << "Transpose: t\n";
}

void enterMatrix (Matrix &matrix, int &rows, int &columns, char op)
{
	vector<double> row;
	int num;

	if (rows == 0)
	{
		cout << "Enter # Rows: ";
		cin >> rows;
	}

	if (columns == 0 || op == 'm')
	{
		cout << "Enter # Columns: ";
		cin >> columns;
	}

	for (int i = 0; i < rows; i++)
	{
		cout << "Enter Row " << i << ": ";
		
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
	for (int i = 0; i < (int)matrix.size (); i ++)
	{
		cout << "|";
		for (int j = 0; j < (int)matrix[i].size (); j++)
		{
			cout << setw (3) << matrix[i][j] << " ";
		}
		cout << "|\n";
	}
}

Matrix add (Matrix matrix1, Matrix matrix2)
{
	Matrix result = matrix1;

	for (int i = 0; i < (int)matrix1.size (); i++)
	{
		for (int j = 0; j < (int)matrix1[i].size (); j++)
		{
			result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}

	return result;
}

Matrix mult (Matrix matrix1, Matrix matrix2)
{
	int i, j, k;
	int entry = 0;
	Matrix result;
	vector<double> push;

	for (i = 0; i < (int)matrix2[0].size (); i++)
	{
		push.push_back (0);
	}

	for (i = 0; i < (int)matrix1.size (); i++)
	{
		result.push_back (push);
	}

	for (i = 0; i < (int)matrix1.size (); i++)
	{
		for (j = 0; j < (int)matrix2[0].size (); j++)
		{
			for (k = 0; k < (int)matrix2.size (); k++)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	return result;
}

Matrix reduce (Matrix matrix)
{
	int rows = matrix.size ();
	int columns = matrix[0].size ();

	for (int j = 0; j < rows - 1; j++)
	{
		if (matrix[j][j] != 0)
		{
			matrix[j] = multiply (matrix[j], (1 / matrix[j][j]));

			for (int i = j + 1; i < rows; i++)
			{
				matrix[i] = add (multiply (matrix[j], -1 * matrix[i][j]), matrix[i]);
			}
		}
	}

	return matrix;
}

Matrix transpose (Matrix matrix)
{
	vector<double> row;
	Matrix result;

	for (int j = 0; j < matrix[0].size (); j++)
	{
		for (int i = 0; i < matrix.size (); i++)
		{
			row.push_back (matrix[i][j]);
		}

		result.push_back (row);
		row.clear ();
		row.shrink_to_fit ();
	}

	return result;
}

void clear (Matrix &matrix)
{
	matrix.clear ();
	matrix.shrink_to_fit ();
}
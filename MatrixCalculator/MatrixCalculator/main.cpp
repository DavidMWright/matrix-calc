
#include <math.h>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void printTitle ();

int main ()
{
	vector<int> matrix;
	char cont = 'n';

	do
	{
		system ("CLS");
		printTitle ();



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
			 << "*********************\n";
}
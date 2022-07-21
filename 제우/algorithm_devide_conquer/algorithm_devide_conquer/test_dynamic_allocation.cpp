#include <iostream>
using namespace std;


void dynamic_print(int **t,int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
		
}
int main()
{
	int num;
	cin >> num;
	int** table;
	table = new int* [num];
	for (int i = 0; i < num; i++)
		table[i] = new int[num];
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			cin >> table[i][j];

	dynamic_print(table, num);

	for (int i = 0; i < num; i++)
		delete[] table[i];
	delete[] table;

	return 0;
}
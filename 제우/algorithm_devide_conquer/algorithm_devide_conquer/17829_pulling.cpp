#include <iostream>
using namespace std;
int second_max_arr(int Array[][2]) {
	int second;
	int max;
	int x, y;
	max = Array[0][0];
	second = Array[0][0];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (max <= Array[i][j])
			{
				max = Array[i][j];
				x = i;
				y = j;
			}
				
			
		}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (second =!Array[x][y]&& second <= Array[i][j])
			{
				second = Array[i][j];
			}


		}
	return second;
}
int second_max_dynamic(int **t) {
	int second;
	int max;
	int x, y;
	max = t[0][0];
	second = t[0][0];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (max <= t[i][j])
			{
				max = t[i][j];
				x = i;
				y = j;
			}


		}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (second = !t[x][y] && second <= t[i][j])
			{
				second = t[i][j];
			}


		}
	return second;
}
void pulling(int** t,int n) {
	if (n <= 2)
	{
		cout << second_max_dynamic(t) << endl;
	}
	int arr[2][2];
	int** table1;
	for (int i = 0; i < (n/2); i++)
		table1[i] = new int[(n/2)];
	for (int i = 0; i < (n / 2); i++)
		for (int j = 0; j < (n / 2); j++)
		{
			arr[0][0] = t[2 * i][2 * j];
			arr[0][1] = t[2 * i][2 * j + 1];
			arr[1][0] = t[2 * i + 1][2 * j];
			arr[1][1] = t[2 * i + 1][2 * j + 1];
			table1[i][j] = second_max_arr(arr);
		}	
	while (n <= 2)
	{
		pulling(table1, n - 1);

	}
	for (int i = 0; i < (n / 2); i++)
		delete[] table1[i];
	delete table1;
}
int main() {
	int num1;
	cin >> num1;
	int** table;
	table = new int* [num1];
	for (int i = 0; i < num1; i++)
	{
		table[i] = new int[num1];
	}
	for(int i=0;i<num1;i++)
		for (int j = 0; j < num1; j++)
		{
			cin >> table[i][j];
		}
	cout << "result is " << endl;
	//pulling(table, num1);

	return 0;
}
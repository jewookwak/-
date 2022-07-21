#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int second_max_arr(int Array[][2])
{
	int second;
	int temp;
	int temp_arr[4];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			temp_arr[2 * i + j] = Array[i][j];

	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4; j++)
		{
			if (temp_arr[j] < temp_arr[i])
			{
				temp = temp_arr[j];
				temp_arr[j] = temp_arr[i];
				temp_arr[i] = temp;
			}
		}
	}

	return temp_arr[2];

}

void dynamic_print(int** t, int n)
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
void pooling(int** t,int n) {
	vector<int> arr;
	if (n <= 2)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				arr.push_back(t[i][j]);
			}
		}
		sort(arr.begin(), arr.end());
		cout << arr[2] << endl;
	}

	int arr2[2][2];
	int** t2;
	t2 = new int* [n/2];
	for (int i = 0; i < n/2; i++)
		t2[i] = new int[n/2];
	for (int i = 0; i < (n / 2); i++)
		for (int j = 0; j < (n / 2); j++)
		{
			arr2[0][0] = t[2 * i][2 * j];
			arr2[0][1] = t[2 * i][2 * j + 1];
			arr2[1][0] = t[2 * i + 1][2 * j];
			arr2[1][1] = t[2 * i + 1][2 * j + 1];
			t2[i][j] = second_max_arr(arr2);
		}
	if (n > 2)
	{
		pooling(t2, n / 2);
	}
	for (int i = 0; i < n/2; i++)
		delete[] t2[i];
	delete[] t2;

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

	pooling(table, num);

	for (int i = 0; i < num; i++)
		delete[] table[i];
	delete[] table;

	return 0;
}
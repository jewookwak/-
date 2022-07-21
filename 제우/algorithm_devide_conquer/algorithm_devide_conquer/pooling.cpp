#include <iostream>
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

void pooling(int l[][8], int n) {
	if (n <= 2)
	{
		int list2[2][2];
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				list2[i][j] = l[i][j];
		cout << "n<=2" << endl;
		cout << second_max_arr(list2) << endl;
		return;
	}
	int arr[2][2];
	int list[8][8];
	for (int i = 0; i < (n / 2); i++)
		for (int j = 0; j < (n / 2); j++)
		{
			arr[0][0] = l[2 * i][2 * j];
			arr[0][1] = l[2 * i][2 * j + 1];
			arr[1][0] = l[2 * i + 1][2 * j];
			arr[1][1] = l[2 * i + 1][2 * j + 1];
			list[i][j] = second_max_arr(arr);
		}
	if (n > 2)
	{
		pooling(list, n / 2);
	}
}
int main() {
	int num1;
	int first_arr[8][8];
	cin >> num1;
	for (int i = 0; i < num1; i++)
		for (int j = 0; j < num1; j++)
		{
			cin >> first_arr[i][j];
		}
	cout << "result is " << endl;
	pooling(first_arr, num1);
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int second_max_arr(int Array[][2])  // This function returns 2x2 array's second largest number.
{
	int second;
	int temp;
	int temp_arr[4];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			temp_arr[2 * i + j] = Array[i][j];  //temp_arr is 1D vector.

	for (int i = 0; i < 4; i++)                 // This is sorting 1D vector(1X4). 
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

	return temp_arr[2];   // temp_arr[3] is largest number.

}

void dynamic_print(int** t, int n)  // This function is checking for the function index using dynamic allocation. 
{									// Printing out the array.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << t[i][j] << " ";
		}
		cout << endl;
	}

}
void pooling(int** t,int n) {			// This is pooling function and if(n<2) then cout second largest number of 2x2 array.
										// if(n>=2) then do pooling.
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
	if (n > 2)								// this is recursive method.
	{
		pooling(t2, n / 2);
	}
	for (int i = 0; i < n/2; i++)           // Memory Deallocation.
		delete[] t2[i];
	delete[] t2;

}
int main()
{
	int num;								// input
	cin >> num;
	int** table;
	table = new int* [num];
	for (int i = 0; i < num; i++)
		table[i] = new int[num];
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			cin >> table[i][j];

	pooling(table, num);					// pooling function

	for (int i = 0; i < num; i++)			// memory deallocation
		delete[] table[i];
	delete[] table;

	return 0;
}
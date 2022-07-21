#include <iostream>

using namespace std;

void main()
{
	int num1, num2;
	int arr1[100000];
	int arr2[100000][2];

	cin >> num1;
	for (int i = 0; i < num1; i++)
	{
		cin >> arr1[i];
	}
	cin >> num2;
	for (int i = 0; i < num2; i++)
	{
		arr2[0][i] = i;
		cin >> arr2[1][i];
	}

	cout << arr2[0][0] << endl;
	int arr3[100000];
	arr3[0] = arr2[1][0];
	arr3[1] = arr2[1][1];
	arr3[2] = arr2[1][4];
}
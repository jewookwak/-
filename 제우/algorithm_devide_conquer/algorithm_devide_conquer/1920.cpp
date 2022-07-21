#include <iostream>
using namespace std;

int main()
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
		arr2[i][0] = i;
		cin >> arr2[i][1];
	}


	int arr3[100000];
	arr3[0] = arr2[0][1];
	arr3[1] = arr2[1][1];
	arr3[2] = arr2[4][1];
	cout << arr3[0] << endl;
	cout << arr3[1] << endl;
	cout << arr3[2] << endl;
	return 0;
}
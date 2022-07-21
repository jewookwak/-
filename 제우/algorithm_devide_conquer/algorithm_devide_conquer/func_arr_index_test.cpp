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

void print_arr(int arr[][8],int num) 
{
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;
	int list[2][2];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> list[i][j];
	//print_arr(list, n);
	//second_max_arr(list);
	cout << second_max_arr(list) << endl;
}
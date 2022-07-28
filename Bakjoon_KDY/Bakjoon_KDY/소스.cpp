#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;


int* pooling(int* arr[], int n) {
	int m = n;
	int** temp = new int* [m];

	for (int i = 0; i < m ; i++) {
		temp[i] = new int[m];
	}

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < m; j++) {
			temp[i][j] = arr[i][j];
		}
	}

	temp;
	
	
	return *temp;

}

int main() {
	int N;
	cin >> N;
	int** arr = new int* [N];

	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

		*arr = pooling(arr, N);
	

	cout << arr[0][0] << " " << arr[0][1] << " " << arr[1][0] << " " << arr[1][1];


	return 0;
}
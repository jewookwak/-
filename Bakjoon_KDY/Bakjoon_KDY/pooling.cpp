#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;


int SIZE = 0;

int sec(int a, int b, int c, int d) {
	int ary[4];
	ary[0] = a;
	ary[1] = b;
	ary[2] = c;
	ary[3] = d;
	sort(ary, ary + 4);
	return ary[2];
}



int pooling(int* arr[] ,int n) {
	
	
	
		int** temp = new int* [n / 2];
		

		for (int i = 0; i < n / 2; i++) {
			temp[i] = new int[n / 2];
		}



		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				
				temp[i][j] = sec(arr[i * 2][j * 2], arr[i * 2][j * 2 + 1], arr[i * 2 + 1][j * 2], arr[i * 2 + 1][j * 2 + 1]);

				//= min(max(arr[i*2][j*2], arr[i*2][j*2+1]),max(arr[i*2+1][j*2], arr[i*2+1][j*2 + 1]));
			}
		}
		SIZE = n / 2;
		
		if(SIZE>1){
			pooling(temp, SIZE);
		}
		if (SIZE <= 1) {
			//return temp[0][0];
		}

		
		return 0;
}

int main() {
	int N;
	cin >> N;
	static int** arr = new int* [N];
	
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	


	
	SIZE = N;
	cout << pooling(arr, SIZE);

	
	return 0;
}
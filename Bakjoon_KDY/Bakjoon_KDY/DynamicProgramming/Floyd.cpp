#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	cin >> m;

	int** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}



	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}

	cout << arr[1][1];
}
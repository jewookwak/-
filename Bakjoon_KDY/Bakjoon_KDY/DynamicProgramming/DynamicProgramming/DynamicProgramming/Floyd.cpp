#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;


int arr[101][101];

void dist(int n) {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <=n; j++) {
				arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
				
			}
		}
}

int main() {
	int n, m;
	cin >> n;
	cin >> m;



	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			arr[i][j] = 987654321;
		}
	}

	for (int i = 1; i <= n; i++) {
		arr[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = min(arr[a][b], c);
	}




	dist(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 987654321)
				arr[i][j] = 0;
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}



	return 0;
}
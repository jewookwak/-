#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[100][100];
void calculate(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(arr[i][j] == 0 )
				arr[i][j] = 1000000;
			if (i == j)
				arr[i][j] = 0;
			//cout << arr[i][j] << " ";
		}
		//cout << endl;
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
			}
		}
	}	
	//cout << endl << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}
int main()
{	
	vector <pair<pair<int, int>, int>> v;
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int start, end, weight;
		cin >> start >> end >> weight;
		v.push_back({ {start,end},weight });


	}
	sort(v.begin(), v.end());

	for (int i = m - 1; i >= 0; i--)
		arr[v[i].first.first-1][v[i].first.second-1] = v[i].second;
	
	calculate(n,m);
	
	return 0;
}
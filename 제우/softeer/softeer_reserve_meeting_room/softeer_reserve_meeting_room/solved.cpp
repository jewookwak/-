#include<iostream>
#include<vector>
#include<queue>
#include <functional> 
using namespace std;
#define P pair<int, int>
vector<pair<string, pair<int, int>>> v;
string arr_n[50];


void Scadule(int n, int m) {

	bool reserved_time[50][11];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 11; j++)
		{
			if (j == 0 )
				reserved_time[i][j] = true;
			else if (j == 10)
				reserved_time[i][j] = true;
			else
				reserved_time[i][j] = false;
		}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 11; j++)
			cout << reserved_time[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr_n[i] == v[j].first)
			{
				for (int k = (v[j].second.first - 8); k < (v[j].second.second - 8); k++) // 만약 9~10시에 예약 되었으면 reserved_time의 1 번째,2번째 index를 true로 바꿈.
					reserved_time[i][k] = true;
			}
		}
	}
	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 11; j++)
			cout << reserved_time[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		int available_time[10][2];
		cout << "Room " << arr_n[i] << ": " << endl;
		
		for (int j = 0; j < 11; j++)
		{
			if (reserved_time[i][j] == false)
			{
				if (reserved_time[i][j - 1] == true)
					available_time[count][0]=j+8;
				if (reserved_time[i][j + 1] == true)
				{
					available_time[count][1] = j + 9;
					count++;
				}
			}
		}
		if (count == 0)
		{
			cout << "Not available" << endl;
		}
		else
		{
			cout << count << " available:" << endl;
			for (int t = 0; t < count; t++)
			{
				if (available_time[t][0] == 9)
					cout << "0";
				cout << available_time[t][0] << "-" << available_time[t][1] << endl;
			}
			
		}



		if (i != n - 1)
			cout << "-----" << endl;
	}


}

int main()
{

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr_n[i];
	for (int i = 0; i < M; i++) {
		string name;
		int start, end;
		cin >> name >> start >> end;
		v.push_back({ name,{start,end} });
	}
	cout << endl << endl;
	for (int i = 0; i < M; i++)
	{
		cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;

	}
	cout << endl << endl;
	Scadule(N,M);
	return 0;
}
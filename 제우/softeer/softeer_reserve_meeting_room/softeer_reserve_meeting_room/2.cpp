#include<iostream>
#include<vector>
#include<queue>
#include <functional> 
using namespace std;
#define P pair<int, int>
vector<pair<string, pair<int, int>>> v;
string arr_n[50];

void Scadule(int n, int m) {
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

	for (int i = 0; i < M; i++)
	{
		cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;

	}
	//Scadule(N,M);
	return 0;
}
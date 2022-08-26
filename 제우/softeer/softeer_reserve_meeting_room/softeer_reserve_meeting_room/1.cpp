#include<iostream>
#include<vector>
#include<queue>
#include <functional> 
using namespace std;
#define P pair<int, int>
vector<pair<string, pair<int, int>>> v;
string arr_n[50];

void Scadule(int n, int m) {
	int nine=9, eighteen=18;
	priority_queue<P, vector<P>, greater<P>>* pq = new priority_queue<P, vector<P>, greater<P>>[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr_n[i] == v[j].first)
			{
				pq[i].push(P(v[j].second.first, v[j].second.second)); // pq[0] : grandeur, pq[1] : avente, pq[2] : sonata.
			}

		}
		
	}
	/*
	for (int i = 0; i < n; i++)
	{
		cout << arr_n[i] << " : " << endl;
		while (!pq[i].empty()) 
		{
			P cur = pq[i].top();
			pq[i].pop();

			cout << cur.first << ", " << cur.second << endl;
		}
	}
	*/

	cout << "Room " << arr_n[0] << ":" << endl;
	int temp_list[18];
	int count_available = 0;
	int temp_prenum;
	if (pq[0].empty())
	{
		cout << "----" << endl;
		cout << "1 available:" << endl;
		cout << "09-18" << endl;
	}
	else
	{
		if (nine != pq[0].top().first)
		{
			count_available++;
			temp_list[0] = nine;
			temp_list[1] = pq[0].top().first;
			temp_prenum = pq[0].top().second;
			pq[0].pop();
		}
		if (temp_prenum != pq[0].top().first)
		{
			temp_list[2] = temp_prenum;

		}
	}

	delete[] pq;
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
	/*
	for (int i = 0; i < M; i++)
	{
		cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;

	}
	*/
	Scadule(N,M);
	return 0; 
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define P pair<string, pair<int, int>>


using namespace std;


//int reserv() {
//
//}

int main() {

	vector<P>v;
	

	int N, M;
	cin >> N >> M;


	string arr[50];

	for (int i = 0; i < N; i++) {
		string A;
		cin >> A;
		arr[i]=A;
	}

	for (int i = 0; i < M; i++) {
		string r;
		int s, t;
		cin >> r >> s >> t;
		v.push_back({ r,{s,t} });
	}

	priority_queue<P, vector<P>, greater<P>>pq;

	for (int i = 0; i < M; i++) {
		pq.push(v[i]);
	}

	sort(arr, arr + 10);

	vector<int>A;

	for (int i = 0; i < M; i++) {
		P cur = pq.top();
		pq.pop();
		for (int j = 0; j < N; j++) {
			if (cur.first == arr[j])
				return 0;
		}

	//}

	//int ind = 0;
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		if (arr[i] == v[j].first)
	//			ind = j;
	//		else
	//			break;
	//	}
	//}

	//for (int i = 0; i < M; i++) {
	//	cout << v[i].first << v[i].second.first << v[i].second.second << ' ';
	//}

	//cout << v[0].first << v[0].second.first << v[0].second.second;

	return 0;
}

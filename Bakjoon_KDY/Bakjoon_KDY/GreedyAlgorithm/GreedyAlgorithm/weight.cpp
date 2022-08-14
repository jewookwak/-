#include <iostream>
#include <vector>
#include <queue>
#define P pair<int, int>

using namespace std;
int visited[10001];
vector<P> edge[100001];

int weight(int St, int En) {
	int limit = 1000000001;
	priority_queue<P, vector<P>, less<P>>pq; // first�� ����ġ second �� ���� minheap 
	pq.push(P(1000000001, St)); //1�� �������� ����       // ����ġ�� ������������ top���� ���Եȴ�! 


	while (!pq.empty()) {
		

		P cur = pq.top();
		P Q = pq.top();
		

		pq.pop();

		

		if (visited[cur.second]) { //�湮 ���� ǥ�� 
			
			continue;
		}
		if (limit > cur.first)
			limit = cur.first;
		visited[cur.second] = 1;

		

		for (int i = 0; i < edge[cur.second].size(); i++) { //���� �������� �̵� �� �� �ִ� �湮���� ���� ���� Ǫ�� 
			if (!visited[edge[cur.second][i].second]) {
				pq.push(edge[cur.second][i]);
				

				if (visited[St] == 1 && visited[En] == 1) {
					return limit;
					break;
				}
			}
		}
		
		


	}

	
	return limit;
}


int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		edge[A].push_back(P(C, B));
		edge[B].push_back(P(C, A));
	}


	int A, B;
	cin >> A >> B;


	int result = weight(A, B);

	cout << result;

	return 0;
}
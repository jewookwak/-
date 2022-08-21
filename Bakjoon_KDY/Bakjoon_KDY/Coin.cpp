#include <iostream>
#include <vector>
#include <queue>
#define P pair<int, int>

int limit = 1000000001;
using namespace std;
int visited[10001];
vector<P> edge[10001];

void weight(int St, int En) {
	
	priority_queue<P>pq; // first는 가중치 second 는 정점 minheap 
	pq.push(P(1000000001, St)); //1번 정점부터 시작       // 가중치가 가장작은것이 top으로 가게된다! 


	while (!pq.empty()) {


		P cur = pq.top();


		pq.pop();



		if (visited[cur.second]) { //방문 정점 표시 

			continue;
		}
		if (limit > cur.first)
			limit = cur.first;
		visited[cur.second] = 1;



		for (int i = 0; i < edge[cur.second].size(); i++) { //현재 정점에서 이동 할 수 있는 방문하지 않은 정점 푸쉬 
			if (!visited[edge[cur.second][i].second]) {
				pq.push(edge[cur.second][i]);


				if (visited[St] == 1 && visited[En] == 1) {
					break;
				}
			}
		}




	}

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


	weight(A, B);

	cout << limit;

	return 0;
}
	#include <iostream>
	#include <vector>
	#include <queue>
	#include <functional>    // greater, less
	#define P pair<int, int>
	using namespace std;
	/* 
	By using MST_prim algorithm in a reverse way(put greater cost of passing road on top of queue)
	*/
	int visited[100001];
	vector<P> edge[100001];
	int fixed_prim(int start, int end)
	{
		int ans;
		priority_queue<int, vector<int>, greater<int>> results;
		priority_queue<P> pq; // first�� ����ġ second �� ���� minheap 
		pq.push(P(1000000001, start)); //1�� �������� ����       // ����ġ�� ������������ top���� ���Եȴ�! 

		while (!pq.empty()) {
			P cur = pq.top();
			pq.pop();
		
			if (visited[cur.second]) //�湮 ���� ǥ�� 
				continue;
			visited[cur.second] = 1;

			results.push(cur.first);

			for (int i = 0; i < edge[cur.second].size(); i++) { //���� �������� �̵� �� �� �ִ� �湮���� ���� ���� Ǫ�� 
				if (!visited[edge[cur.second][i].second]) {
					pq.push(edge[cur.second][i]);
				}
			}
			if (cur.second == end)
				break;
		}
		ans = results.top();
		return ans;
	}
	int main()
	{
		int N,M,start,end;
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			int A, B, C;
			cin >> A >> B >> C;
			edge[A].push_back(P(C, B));
			edge[B].push_back(P(C, A));
		}
		cin >> start >> end;

	
		int result = fixed_prim(start, end);
		cout << result;
		return 0;
	}

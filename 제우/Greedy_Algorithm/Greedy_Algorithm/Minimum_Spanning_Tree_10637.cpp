#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Minimum_Spanning_Tree

struct graph {
	int a; // node1
	int b; // node2
	int w;  // wight between node 1 and 2;
};

int KruskalMST(vector<graph>)
{
	int result;


	return result;
}


int main()
{
	int n, m;
	cin >> n >> m;
	vector<graph> G(n);

	for (int i = 0; i < n; i++)
	{
		cin >> G[i].a >> G[i].b >> G[i].w;
	}


	// print check 
	/*
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << G[i].a << " " << G[i].b << " " << G[i].w << endl;
	}
	*/
	


	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


void nearest_two_point_distance(int p_x, int p_y)
{
	cout << " " << endl;
}

void main()
{
	int point_num;
	int x[500000];
	int y[500000];

	// input
	cin >> point_num;
	for (int i = 0; i < point_num; i++)
		cin >> x[i] >> y[i];
	
	for (int i = 0; i < point_num; i++)
		cout << x[i] << " " << y[i] << endl;
}
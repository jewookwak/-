#include <iostream>
using namespace std;

int main() //Input check
{
	cout << "example : " << endl;
	cout << "3 3" << endl;
	cout << "1" << endl;
	cout << "1 0" << endl;
	cout << "1 1" << endl;
	cout << "1 2 3 4" << endl;
	cout << "방 크기가 3 * 3이고,장애물이(1, 0)에 있으며, 시작 위치는(1, 1), 해빈이가 지정한 방향이(상, 하, 좌, 우) 일 때, [로봇의 마지막 위치는(0, 0)이다.]" <<endl;
		
	int row, col, num_obstacle;
	cin >> row, cin >> col;
	cin >> num_obstacle;
	

	int** obstacle_location;
	obstacle_location = new int* [num_obstacle];
	for (int i = 0; i < num_obstacle; i++)
	{
		obstacle_location[i] = new int[num_obstacle];
	}

	for (int i = 0; i < num_obstacle; i++)
		for (int j = 0; j < 2; j++)
		{
			cin >> obstacle_location[i][j];
		}
	int start_location_x, start_location_y;
	cin >> start_location_x, cin >> start_location_y;

	int move[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> move[i];
	}
	cout << row << " " << col << endl;
	cout << num_obstacle << endl;
	for (int i = 0; i < num_obstacle; i++) {
		cout << obstacle_location[i][0] << " " << obstacle_location[i][1] << endl;
	}
	cout << start_location_x << " " << start_location_y << endl;


	for (int i = 0; i < 4 ;i++)
	{
		cout << move[i] << " ";
	}
	
	cout << "commit test2" << endl;

	
}

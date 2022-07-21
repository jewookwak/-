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
	cout << "�� ũ�Ⱑ 3 * 3�̰�,��ֹ���(1, 0)�� ������, ���� ��ġ��(1, 1), �غ��̰� ������ ������(��, ��, ��, ��) �� ��, [�κ��� ������ ��ġ��(0, 0)�̴�.]" <<endl;
		
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
	cout << "commit test3" << endl;
	cout << "commit test with different computer" << endl;
	
}

#include <iostream>
using namespace std;

int up(int x, int y, int** obs_location, int** map);
int down(int x, int y, int** obs_location, int** map);
int left(int x, int y, int** obs_location, int** map);
int right(int x, int y, int** obs_location, int** map);
int get_Max_Int(int arr[][2], int xy, int size); int get_Min_Int(int arr[][2], int xy, int size);
int num_obstacle;
int row, col;
int main()
{	
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
	int cur_x, cur_y;
	cur_x = start_location_x;
	cur_y = start_location_y;
	
	int** map;
	map = new int* [row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[col];
	}
	// map initialize
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			map[i][j] = 0;

	// add abostacle to map
	for (int i = 0; i < num_obstacle; i++) {
		map[obstacle_location[i][0]][obstacle_location[i][1]] = -1;
	}
	
	// add current x,y to map
	map[cur_x][cur_y] = -1;


	// checking the map
	cout << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << map[i][j] << "  ";
		cout << endl;
	}


	// memory deallocation
	delete[] obstacle_location;

	for (int i = 0; i < row; i++)
		delete[] map[i];
	delete[] map;

	// up,down,left,right
	for (int i = 0; i < 4; i++) {
		switch (move[i]) {

		case 1: 
			cur_y = up(cur_x,cur_y, obstacle_location,map);
			break;
		case 2:
			cur_y = down(cur_x, cur_y, obstacle_location,map);
			break;
		case 3:
			cur_x = left(cur_x, cur_y, obstacle_location,map);
			break;
		case 4:
			cur_x =right(cur_x, cur_y, obstacle_location,map);
			break;
		}
	}
	
	cout << "current location : " << cur_x << " " << cur_y << endl;

	cout << "finish" << endl;
	return 0;
}

int up(int x,int y, int** obs_location, int **map) {
	int temp_location[1000][2];
	int max_index;
	int axis = 1; // fixed axis  (x:0,y:1)
	cout << "up" << endl;
	for (int i = 0; i < num_obstacle; i++) {
		if (obs_location[i][1] == y && obs_location[i][0] < x) {
			for (int j = 0; j < 2; j++) {
				temp_location[i][j] = obs_location[i][j];		
			}
		}
		
	}
	max_index = get_Max_Int(temp_location, axis,y+1);
	for (int i = max_index; i < y; i++)
	{
		map[x][i] = -1;
	}
	return (max_index + 1); // => cur_y
}

int down(int x, int y, int** obs_location, int** map) {
	int temp_location[1000][2];
	int min_index;
	int axis = 1; //fixed axis  (x:0,y:1)
	cout << "down" << endl;
	for (int i = 0; i < num_obstacle; i++) {
		if (obs_location[i][1] == y && obs_location[i][0] > x) {
			for (int j = 0; j < 2; j++) {
				temp_location[i][j] = obs_location[i][j];
			}
		}

	}
	min_index = get_Min_Int(temp_location, axis, row-y-1);
	for (int i = y; i < min_index; i++)
	{
		map[x][i] = -1;
	}
	return (min_index -1); // => cur_y
}

int left(int x, int y, int** obs_location, int** map) {
	int temp_location[1000][2];
	int max_index;
	int axis = 0; // fixed axis  (x:0,y:1)
	cout << "left" << endl;
	for (int i = 0; i < num_obstacle; i++) {
		if (obs_location[i][1] == x && obs_location[i][0] < y) {
			for (int j = 0; j < 2; j++) {
				temp_location[i][j] = obs_location[i][j];
			}
		}

	}
	max_index = get_Max_Int(temp_location, axis, x + 1);
	for (int i = max_index; i < x; i++)
	{
		map[y][i] = -1;
	}
	return (max_index + 1); // => cur_x
}
int right(int x, int y, int** obs_location, int** map) {
	int temp_location[1000][2];
	int min_index;
	int axis = 0; //fixed axis  (x:0,y:1)
	cout << "right" << endl;
	for (int i = 0; i < num_obstacle; i++) {
		if (obs_location[i][1] == x && obs_location[i][0] > y) {
			for (int j = 0; j < 2; j++) {
				temp_location[i][j] = obs_location[i][j];
			}
		}

	}
	min_index = get_Min_Int(temp_location, axis, col-x-1);
	for (int i = x; i < min_index; i++)
	{
		map[y][i] = -1;
	}
	return (min_index - 1); // => cur_x
}

int get_Max_Int(int arr[][2],int xy ,int size) {
	int max = arr[0][xy];
	for (int i = 0; i < size; i++) {
		if (arr[i][xy] > max) {
			max = arr[i][xy];
		}
	}
	return max;
}

int get_Min_Int(int arr[][2], int xy, int size) {
	int min = arr[0][xy];
	for (int i = 0; i < size; i++) {
		if (arr[i][xy] < min) {
			min = arr[i][xy];
		}
	}
	return min;
}
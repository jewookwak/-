#include<iostream>
using namespace std;
//Coin_Change 

int main()
{
	int coin_type_num, W;  // 각각 코인 종류 수, 거스름돈 액수를 뜻함.
	cin >> coin_type_num >> W;

	int* coin_type;
	coin_type = new int[coin_type_num];
	for (int i = 0; i < coin_type_num; i++)
		cin >> coin_type[i];
	
	//print check
	/*
	for (int i = 0; i < coin_type_num; i++)
		cout << coin_type[i] << endl;
	*/
	int count=0;
	for (int i = 0; i < coin_type_num; i++)
	{
		while (W >= coin_type[coin_type_num -i-1])
		{
			W = W- coin_type[coin_type_num - i - 1];
			count++;
		}
		//print check
		//cout << "W : " << W << " count : " << count << endl;
	}
	
	cout << count << endl;

	delete[] coin_type;
	return 0;
}
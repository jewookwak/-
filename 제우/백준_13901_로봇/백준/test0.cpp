#include <iostream>
using namespace std;

void doubleIt(int x, int* p)
{
	*p = 2 * x;
}

int main(int argc, const char* argv[])
{
	int a = 16;
	doubleIt(9, &a);
	cout << " a : " << a << endl;





	return 0;
}

#include<iostream>
#include<algorithm>

using namespace std;

int array1[100000], array2[100000];

int findnum(int n, int len) {
    int fst = 0, mid = 0 , last = len - 1;

    while (fst <= last) {
        int mid = (fst + last) / 2;
        if (array1[mid] == n) return 1;
        else if (n < array1[mid]) last = mid - 1;
        else fst = mid + 1;
    }
    return 0;
}

int main()
{
    cout << "입력해주세요" << endl;
    int n1;
    cin >> n1;
    

    for (int i = 0; i < n1; i++)
        cin >> array1[i];

    sort(array1, array1 + n1);

    int n2,val;
    cin >> n2;

    for (int i = 0; i < n2; i++){
        cin >> val;
        cout << findnum(val, n2) << "\n";
    }
}
    


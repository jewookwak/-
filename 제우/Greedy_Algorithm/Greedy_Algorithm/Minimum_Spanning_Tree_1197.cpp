#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Minimum_Spanning_Tree

struct Joint {
    int a, b, c; // a : first point, b : second point, c : weight of joint between a and b.
    int num;
};

bool compareW(Joint w1, Joint w2) {
    return w1.c < w2.c;
}

int NaiveDisjointSet(vector<Joint> v) {
    int min_total_weight = 0;



    return min_total_weight;
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<Joint> joints(v);

    for (int i = 0; i < v; i++)
        cin >> joints[i].a >> joints[i].b >> joints[i].c;

    /*
    check print
    for (int i = 0; i < v; i++)
        cout << joints[i].a << ", " << joints[i].b << ", " << joints[i].c << endl;
    cout << endl;
    */
 
    sort(joints.begin(), joints.end(),compareW);

   
    /*
    check print
    for (int i = 0; i < v; i++)
        cout << joints[i].a << ", " << joints[i].b << ", " << joints[i].c << endl;
    */
    
    cout << NaiveDisjointSet(joints) << endl;

	return 0;
}
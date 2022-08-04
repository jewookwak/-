#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Minimum_Spanning_Tree

struct Joint {
    int a, b, c; // a : first point, b : second point, c : weight of joint between a and b.
    int parent;
};

bool compareW(Joint w1, Joint w2) {
    return w1.c < w2.c;
}

int find(int u, vector<Joint>& j)
{
    if (u == j[u].parent)
        return u;
    else
        return find(j[u].parent, j);
}
void merge(int u, int v, vector<Joint>& j) {
    u = find(u, j);
    v = find(v, j);
    if (u == v) return;
    j[v].parent = u;
}

int NaiveDisjointSet(int num,vector<Joint>& v) {
    int min_total_weight = 0;
    for (int i = 1; i < num; i++)
    {
        if((v[i].parent == v[i+1].parent) & (v[i].b == v[i+1].a) )
        { }
        else
        {
            merge(i, i + 1, v);
            min_total_weight += v[i].c;
        }
            

    }

    return min_total_weight;
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<Joint> joints(v);
    for (int i = 0; i < e; i++) 
    {
        cin >> joints[i].a >> joints[i].b >> joints[i].c;
        joints[i].parent = joints[i].a;
    }
        

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
    
    cout << NaiveDisjointSet(e,joints) << endl;

	return 0;
}
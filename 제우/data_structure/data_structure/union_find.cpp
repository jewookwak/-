#include <iostream>
#include <vector>
using namespace std;
//union-find

struct NaiveDisjointSet {
    vector<int> parent;
    NaiveDisjointSet(int n) : parent(n) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;//초기화
    }
    //u가 속한 트리의 번호를 반환
    int find(int u) const {
        if (u == parent[u]) return u;//u가 루트인 경우
        return find(parent[u]);
    }

    //u가 속한 트리와 v가 속한 트리를 합친다
    void merge(int u, int v) {//union이 C/C++ 예약어라서 다른 단어로 대체
        u = find(u); v = find(v);
        //이미 u와 v가 같은 트리인 경우를 걸러낸다
        if (u == v) return;
        parent[v] = u;
    }
};

int main()
{
    NaiveDisjointSet n(10);
    n.merge(1, 2);
    n.merge(2, 3);
    n.merge(3, 4);
    n.merge(5, 6);
    n.merge(6, 7);
    n.merge(7, 8);
    cout <<"root of 1,2,3,4 : " << n.find(1) << n.find(2) << n.find(3) << n.find(4) << ", root of 5,6,7,8 : " << n.find(5) << n.find(6) << n.find(7) << n.find(8) << endl;
    return 0;
}

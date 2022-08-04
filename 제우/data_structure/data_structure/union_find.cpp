#include <iostream>
#include <vector>
using namespace std;
//union-find

struct NaiveDisjointSet {
    vector<int> parent;
    NaiveDisjointSet(int n) : parent(n) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;//�ʱ�ȭ
    }
    //u�� ���� Ʈ���� ��ȣ�� ��ȯ
    int find(int u) const {
        if (u == parent[u]) return u;//u�� ��Ʈ�� ���
        return find(parent[u]);
    }

    //u�� ���� Ʈ���� v�� ���� Ʈ���� ��ģ��
    void merge(int u, int v) {//union�� C/C++ ������ �ٸ� �ܾ�� ��ü
        u = find(u); v = find(v);
        //�̹� u�� v�� ���� Ʈ���� ��츦 �ɷ�����
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

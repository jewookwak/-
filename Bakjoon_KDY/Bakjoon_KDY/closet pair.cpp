#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;






struct Point {
    int x;
    int y;

    bool operator < (const Point& b) const {
        if (x == b.x)
            return y < b.y;
        else
            return x < b.x;
    }
};

bool cmp(Point a, Point b) {
    return a.y < b.y;
}


int distance(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}






int Findall(vector<Point> A, int st, int en) {
    int mindst = -1;
    for (int i = st; st <= en - 1; st++) {
        for (int j = i + 1; j <= en; j++) {
            int dist = distance(A[i], A[j]);
            if (mindst == -1 || mindst > dist) mindst = dist;
        }
    }
    return mindst;
}





int closep(vector<Point>& vec, int st, int en) {
    int mid = (st + en) / 2;
    vector<Point> v1;


    int SL, SR;

    if (en - st <= 3) {
        return Findall(vec, st, en);
    }

    SL = closep(vec, st, mid);
    SR = closep(vec, mid + 1, en);
    int ans = min(SL, SR);


    for (int i = 0; i <= en; i++) {
        int Xdst = vec[i].x - vec[mid].x;
        if (Xdst * Xdst < ans) v1.push_back(vec[i]);
    }

    int maxind = v1.size();
    sort(v1.begin(), v1.end(), cmp);

    for (int i = 0; i < maxind - 1; i++) {
        for (int j = 0; j < maxind; j++) {
            int ydst = distance(v1[i], v1[j]);
            if (ydst * ydst < ans) ans = ydst;
            else break;
        }

    }


    return ans;

}

int main() {
    int n;
    cin >> n;

    vector<Point> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y;
    }

    sort(A.begin(), A.end());

    cout << Findall(A, 0, n - 1) << '\n';
}


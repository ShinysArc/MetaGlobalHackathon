#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

struct Data_Center {
    int64_t x;
    int64_t y;
};

struct Outage {
    Outage(Data_Center A, Data_Center B, Data_Center C)
    : A(A)
    , B(B)
    , C(C)
    {}

    Data_Center A;
    Data_Center B;
    Data_Center C;
};

int64_t sign(Data_Center p1, Data_Center p2, Data_Center p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool point_in_triangle(Data_Center pt, Data_Center v1, Data_Center v2, Data_Center v3)
{
    int64_t d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

void solve(vector<Data_Center> dc, Outage outage)
{
    int count = 0;
    for (int i = 0; i < dc.size(); i++)
        count += (point_in_triangle(dc[i], outage.A, outage.B, outage.C));

    cout << count << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, Q;
    cin >> N >> Q;

    vector<Data_Center> dc(N);
    for (int i = 0; i < N; i++)
    {
        int X, Y;
        cin >> X >> Y;
        dc[i].x = X;
        dc[i].y = Y;
    }

    for (int i = 0; i < Q; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        Data_Center A, B, C;
        A.x = x + d; A.y = y;
        B.x = x; B.y = y;
        C.x = x; C.y = y + d;

        Outage outage(A, B, C);

        solve(dc, outage);
    }
}

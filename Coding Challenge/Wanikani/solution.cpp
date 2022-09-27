#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

double product(int a, int b)
{
    if (a == b)
        return 1;
    if (a == 0)
        a = 1;
    double ans = a;
    for (int i = a + 1; i <= b; i++)
        ans *= i;

    return ans / a;
}

double solution(int N, int K, int Q)
{
    double a = product(2 * N - 2 * K - Q, 2 * N - Q);
    double b = product(Q + K - N, Q);
    double c = pow(2, 2 * (N - K) - Q);
    //cout << a << " " << b << " " << c << endl;

    return a * b * c;
}

void solve() {
    int N, K;
    cin >> N >> K;
    double ans1 = 0;
    double ans2 = 0;

    for (int Q = N - K; Q <= 2 * (N - K); Q++) {
        //cout << "Q: " << Q << "\n";
        ans1 += Q * solution(N, K, Q);
    }

    for (int Q = N - K; Q <= 2 * (N - K); Q++) {
        ans2 += solution(N, K, Q);
    }

    cout << fixed << ans1 / ans2 << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout.precision(6);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}

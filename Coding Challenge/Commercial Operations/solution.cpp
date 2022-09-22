#include <bits/stdc++.h>

using namespace std;

const double INF = 1000000000;
vector<vector<pair<int, double>>> adj;

double dijkstra(int s, int dest) {
    vector<double> d;
    vector<int> p;
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0.0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            double len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }

    return d[dest];
}

double round_off(double value, int precision)
{
    double pow_10 = pow(10.0f, (double)precision);
    return round(value * pow_10) / pow_10;
}

int main()
{
    int N, M;
    cin >> N >> M;
    adj.resize(2 * N);
    vector<int> I(M), J(M), A(M), B(M);

    for (int i = 0; i < M; i++)
        cin >> I[i] >> J[i] >> A[i] >> B[i];
    cout.precision(5);

    double incr = 0.0000001;
    double ans = 0.0;
    double t_max;
    double prev = 0.0;
    for (int t = 0; t <= 24 * 60; t++)
    {
        for (int i = 0; i < M; i++)
        {
            double w = A[i] * t + B[i];
            adj[I[i]].push_back({J[i], w});
            adj[J[i]].push_back({I[i], w});
        }

        double curr = dijkstra(1, N);
        if (curr > ans) {
            ans = curr;
            t_max = (double)(t - 1);
        }

        if (prev >= curr)
            break;

        prev = curr;

        adj.clear();
        adj.resize(2 * N);
    }

    for (double t = t_max; t < t_max + 1; t += incr)
    {
        for (int i = 0; i < M; i++)
        {
            double w = A[i] * t + B[i];
            adj[I[i]].push_back({J[i], w});
            adj[J[i]].push_back({I[i], w});
        }

        double curr = dijkstra(1, N);
        if (curr > ans)
            ans = curr;

        cout << fixed << ans << endl;

        adj.clear();
        adj.resize(2 * N);
    }

    cout << fixed << ans << endl;
}
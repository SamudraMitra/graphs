#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<bool> vis(n + 1, false);
    dist[1] = 0;
    vis[1] = true;
    pq.push({0, 1});
    vector<ll> par(n + 1, -1);
    while ((pq.size()) > 0)
    {
        auto z = pq.top();
        pq.pop();
        ll node = z.second;
        ll dis = z.first;
        if (dist[node] < dis)
        {
            continue;
        }
        vis[node] = true;
        for (auto &i : adj[node])
        {
            if (dist[i.first] > (dis + i.second))
            {
                dist[i.first] = dis + i.second;
                par[i.first] = node;
                pq.push({dist[i.first], i.first});
            }
        }
    }
    if (dist[n] == LLONG_MAX)
    {
        cout << "-1\n";
        return 0;
    }
    vector<ll> path;
    ll x = n;
    while (par[x] != -1)
    {
        path.push_back(x);
        x = par[x];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    for (auto &I : path)
    {
        cout << I << " ";
    }
}
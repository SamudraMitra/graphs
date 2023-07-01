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
    vector<vector<ll>> edges;
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        edges.push_back({x, y, w});
    }
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<ll> parent(n + 1, -1);
    dist[1] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (auto &e : edges)
        {
            ll u = e[0];
            ll v = e[1];
            ll w = e[2];
            if ((dist[u] != LLONG_MAX) && (dist[v] > (dist[u] + w)))
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
    bool f = true;
    ll node = 0;
    for (auto &e : edges)
    {
        ll u = e[0];
        ll v = e[1];
        ll w = e[2];
        if ((dist[u] != LLONG_MAX) && (dist[v] > (dist[u] + w)))
        {
            f = false;
            node = v;
            dist[v] = dist[u] + w;
            parent[v] = u;
        }
    }
    if (f)
    {
        cout << "No ngative cycle detected\n";
        for (ll i = 1; i <= n; i++)
        {
            cout << i << " " << dist[i] << "\n";
        }
    }
    else
    {
        cout << "Negative cycle exists\n";
        vector<ll> cycle = {node};
        unordered_set<ll> st;
        st.insert(node);
        while (1)
        {
            node = parent[node];
            cycle.push_back(node);
            if (st.find(node) != st.end())
                break;
        }
    }
}

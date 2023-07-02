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
void dfs(ll node, ll par, vector<vector<ll>> &adj, vector<ll> &dist, ll dis)
{
    dist[node] = dis;
    for (auto &i : adj[node])
    {
        if (i == par)
            continue;
        dfs(i, node, adj, dist, dis + 1);
    }
}
int main()
{
    fastio;
    ll n, m;
    cin >> n;
    m = n - 1;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<ll> dist(n + 1);
    dfs(1, -1, adj, dist, 0);
    ll maxdist = -1;
    ll maxnode = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (maxdist < dist[i])
        {
            maxdist = dist[i];
            maxnode = i;
        }
    }
    dfs(maxnode, -1, adj, dist, 0);
    ll diameter = -1;
    for (ll i = 1; i <= n; i++)
        diameter = max(diameter, dist[i]);
    cout << diameter << "\n";
}
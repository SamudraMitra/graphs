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
void dfs(ll node, vector<vector<ll>> &adj, vector<ll> &toposort, vector<bool> &vis)
{
    vis[node] = true;
    for (auto &i : adj[node])
    {
        if (!vis[i])
        {
            dfs(i, adj, toposort, vis);
        }
    }
    toposort.push_back(node);
}
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    ll timer = 0;
    vector<ll> toposort;
    vector<bool> vis(n + 1, false);
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, toposort, vis);
        }
    }
    for (auto &i : toposort)
    {
        cout << i << " ";
    }
}
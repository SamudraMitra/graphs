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
void dfs(ll node, ll parent, vector<vector<ll>> &adj, vector<ll> &dist)
{

    dist[node] = -1;
    for (auto &i : adj[node])
    {
        if (i == parent)
            continue;
        dfs(i, node, adj, dist);
        dist[node] = max(dist[node], dist[i]);
    }
    dist[node]++;
}
void dfs2(ll node, ll parent, vector<vector<ll>> &adj, vector<ll> &dist, vector<ll> &dp)
{
    dp[node] = dist[node];
    ll maxnode;
    ll maxnodedist = -1;
    ll secmax = -1;
    for (auto &i : adj[node])
    {
        if (maxnodedist < dist[i])
        {
            maxnodedist = dist[i];
            maxnode = i;
        }
    }
    for (auto &i : adj[node])
    {
        if (i == maxnode)
            continue;
        secmax = max(secmax, dist[i]);
    }

    for (auto &i : adj[node])
    {
        if (i == parent)
            continue;
        ll x = dist[node];
        ll y = dist[i];
        if (i == maxnode)
        {
            dist[node] = secmax + 1;
            dist[i] = max(dist[i], dist[node] + 1);
            dfs2(i, node, adj, dist, dp);
            dist[node] = x;
            dist[i] = y;
        }
        else
        {
            dist[i] = max(dist[i], dist[node] + 1);
            dfs2(i, node, adj, dist, dp);
            dist[node] = x;
            dist[i] = y;
        }
    }
}
int main()
{
    fastio;
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<ll> dist(n + 1);
    dfs(1, -1, adj, dist);

    vector<ll> dp(n + 1);
    dfs2(1, -1, adj, dist, dp);
    for (ll i = 1; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
}
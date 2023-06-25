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
bool dfs(ll node, vector<vector<ll>> &adj, vector<ll> &color)
{
    color[node] = 1;
    for (auto &i : adj[node])
    {
        if (color[node] == 1)
            return true;
        else if (color[node] == 0)
        {
            if (dfs(i, adj, color))
            {
                return true;
            }
        }
    }
    color[node] = 2;
    return false;
}
int main()
{
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<ll> color(n + 1, 0);
    bool f = false;
    for (ll i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            if (dfs(i, adj, color))
            {
                f = true;
                break;
            }
        }
    }
    if (f)
        cout << "cycle\n";
    else
        cout << "NO cycle\n";
}

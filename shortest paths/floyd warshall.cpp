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
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, LLONG_MAX));
    for (ll i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        dist[x][y] = w;
        dist[y][x] = w;
    }
    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                if ((dist[i][k] != LLONG_MAX) && (dist[k][j] != LLONG_MAX))
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
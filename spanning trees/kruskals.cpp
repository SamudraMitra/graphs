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
vector<int> par;
vector<int> rnk;
void makeset(int n)
{
    par.resize(n + 1);
    rnk.resize(n + 1, 1);
    for (ll i = 1; i <= n; i++)
        par[i] = i;
}
int findset(int x)
{
    if (par[x] == x)
        return x;
    return (par[x] = findset(par[x]));
}
void unionset(ll x, ll y)
{
    ll a = findset(x);
    ll b = findset(y);
    if (a == b)
        return;
    if (rnk[a] > rnk[b])
    {
        rnk[a] += rnk[b];
        par[b] = a;
    }
    else
    {
        rnk[b] += rnk[a];
        par[a] = b;
    }
}
int main()
{
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        edges.push_back({w, x, y});
    }
    sort(edges.begin(), edges.end());
    makeset(n);
    vector<vector<ll>> mst;
    for (auto &edge : edges)
    {
        ll weight = edge[0];
        ll u = edge[1];
        ll v = edge[2];
        if (findset(u) != findset(v))
        {
            mst.push_back(edge);
            unionset(u, v);
        }
    }
    ll sum = 0;
    for (auto &edge : mst)
    {
        sum += edge[0];
        cout << edge[1] << " " << edge[2] << "\n";
    }
    cout << "Cost of mst is : " << sum << "\n";
}
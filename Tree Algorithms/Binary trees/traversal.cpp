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
void dfs(ll node, ll par, vector<ll> &preorder, vector<ll> &inorder, vector<ll> &postorder, vector<vector<ll>> &adj)
{
    preorder.push_back(node);
    if (adj[node][0] != -1)
        dfs(adj[node][0], node, preorder, inorder, postorder, adj);
    inorder.push_back(node);
    if (adj[node][1] != -1)
        dfs(adj[node][1], node, preorder, inorder, postorder, adj);
    postorder.push_back(node);
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
    vector<ll> preorder;
    vector<ll> inorder;
    vector<ll> postorder;
    dfs(1, -1, preorder, inorder, postorder, adj);
}
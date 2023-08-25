#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

const ll INF = LLONG_MAX;
typedef long double ld;
typedef string ss;
typedef vector<long long> vll;
typedef stack<ll> skll;
typedef pair<char, ll> pci;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
typedef map<char, ll> mcl;
#define pb push_back
#define fi first
#define se second
#define pr(a, b) pb(make_pair(a, b))
#define nl endl
#define all(v) v.begin(), v.end()
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define fost(i, a, b, d) for (ll i = a; i < b; i += d)
#define ofst(i, a, b, d) for (ll i = a; i > b; i -= d)
#define forb(i, a, b) for (ll i = a; i < b; i++)
#define fon(i, a, b) for (ll i = a; i >= b; i--)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define itmp(mp) for (auto it = mp.begin(); it != mp.end(); it++)



const ll N = 2 * (10e5 + 10);
ll vis[N];
ll color[N];
vll g[N];
// mll var;
// vll v;
ll t = 0;
void dfs(ll vertex)
{
  bool leaf = 1;
  if (vis[vertex] != 1)
  {
    vis[vertex] = 1;
  }
  for (auto child : g[vertex])
  {
    if (vis[child] != 1)
    {
      leaf = 0;
      vis[child] = 1;
      dfs(child);
    }
  }
}

// ll vis2[N];
// mll var2;
// vll v2;
// void dfs2(ll vertex)
// {
//   bool leaf = 1;
//   if (vis2[vertex] != 1)
//   {
//     vis2[vertex] = 1;
//   }
//   for (auto child : g[vertex])
//   {
//     if (vis2[child] != 1)
//     {
//       leaf = 0;
//       // dfs_traversed.pb(child);
//       vis2[child] = 1;
//       dfs2(child);
//     }
//   }
// }

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("inputf.in", "r", stdin);
  freopen("outputf.in", "w", stdout);
#endif
  int ttt = 1;
  while (ttt--)
  {
    ll n,m, max = 0, min = INF, sum = 0, ans = 0, f = 0;
    cin >> n >> m;
    // !input m!!!!

    // fo(i, n)
    // {
    //   cin >> color[i];
    // }

    // n->number of vertices, m->number of edges
    fo(i, n)
    {
      ll v1, v2;
      cin >> v1 >> v2;
      g[v1].pb(v2);
      g[v2].pb(v1);
    }
  }
  return 0;
}
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
#define yes cout << "YES" << nl;
#define no cout << "NO" << nl;

void parr(ll a[], ll n)
{
  for (ll i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}
void pvec(vector<ll> v)
{
  for (ll i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
// const ll N = (10e5 + 10);

ll a, b;
// mll var;
ll t = 0;

void dfs(ll vertex, ll xo, ll par, vector<pll> g[], set<ll> &s)
{

  for (auto child : g[vertex])
  {
    if (child.fi == par || child.fi == b)
      continue;
    s.insert(xo ^ child.se);

    dfs(child.fi, xo ^ child.se, vertex, g, s);
  }
}

void dfs2(ll vertex, ll xo, ll par, vector<pll> g[], set<ll> s)
{

  for (auto child : g[vertex])
  {
    if (child.fi == par)
      continue;
    // cout << vertex << " " << child.first << " " << (xo ^ child.se) << " " << xo << nl;
    if (s.count(xo ^ child.se) == 1)
    {
      t++;
      return;
    }
    // cout << child.first << " " << xo << nl;
    dfs2(child.fi, xo ^ child.se, vertex, g, s);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("inputf.in", "r", stdin);
  freopen("outputf.in", "w", stdout);
#endif
  int ttt = 1;
  cin >> ttt;
  while (ttt--)
  {
    ll n, m, max = 0, min = INF, sum = 0, ans = 0, f = 0;
    cin >> n >> a >> b;

    vector<pll> g[n + 7];
    set<ll> s;
    s.insert(0);
    // n->number of vertices, m->number of edges
    fo(i, n - 1)
    {
      ll v1, v2, w;
      cin >> v1 >> v2 >> w;

      g[v1].pr(v2, w);
      g[v2].pr(v1, w);
    }
    dfs(a, 0, -1, g, s);
    dfs2(b, 0, -1, g, s);
    // itmp(s){
    //       cout << *it << nl;
    // }
    if (t)
      yes else no
          //       pvec(vis);
          // pvec(vis2);
          t = 0;
    a = b = 0;
  }
  return 0;
}
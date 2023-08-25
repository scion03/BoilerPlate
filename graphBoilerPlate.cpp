#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
typedef long double ld;
typedef string ss;
typedef vector<ll> vll;
typedef stack<ll> skll;
typedef pair<char, ll> pci;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
typedef map<char, ll> mcl;
#define ret return

#define pb push_back
#define conti continue
#define siz(v) v.size()
#define fat(e, v) for (auto &e : v)
#define fi first
#define se second
#define in insert
#define pr(a, b) pb(make_pair(a, b))
#define mkp(a, b) make_pair(a, b)
#define nl '\n'
#define all(v) v.begin(), v.end()
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define mins(a, b) a = (a < b ? a : b)
#define maxs(a, b) a = (a > b ? a : b)
#define fost(i, a, b, d) for (ll i = a; i < b; i += d)
#define ofst(i, a, b, d) for (ll i = a; i > b; i -= d)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define fon(i, a, b) for (int i = a; i >= b; i--)
#define fo(i, n) for (int i = 0; i < n; i++)
#define inp(v, n) \
  vll v(n);       \
  fo(i, n) cin >> v[i];
#define dc(x) \
  ll x;       \
  cin >> x;
#define itmp(mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define pvec(v)               \
  itmp(v) cout << *it << ' '; \
  cout << nl;
#define start_clock() auto start_time = std::chrono::high_resolution_clock::now();
#define measure()                                            \
  auto end_time = std::chrono::high_resolution_clock::now(); \
  cerr << (end_time - start_time) / std::chrono::milliseconds(1) << "ms" << endl;
#define yes cout << "YES" << nl;
#define no cout << "NO" << nl;
/*-----------------------------debug----------------------------*/
// DEBUG FUNCTIONS
#ifndef ONLINE_JUDGE

template <typename T>
void __p(T a)
{
  cout << a;
}
template <typename T, typename F>
void __p(pair<T, F> a)
{
  cout << "{";
  __p(a.first);
  cout << ",";
  __p(a.second);
  cout << "}";
}
template <typename T>
void __p(std::vector<T> a)
{
  cout << "{";
  for (auto it = a.begin(); it < a.end(); it++)
    __p(*it), cout << ",}"[it + 1 == a.end()];
}
template <typename T>
void __p(std::set<T> a)
{
  cout << "{";
  for (auto it = a.begin(); it != a.end();)
  {
    __p(*it);
    cout << ",}"[++it == a.end()];
  }
}
template <typename T>
void __p(std::multiset<T> a)
{
  cout << "{";
  for (auto it = a.begin(); it != a.end();)
  {
    __p(*it);
    cout << ",}"[++it == a.end()];
  }
}
template <typename T, typename F>
void __p(std::map<T, F> a)
{
  cout << "{\n";
  for (auto it = a.begin(); it != a.end(); ++it)
  {
    __p(it->first);
    cout << ": ";
    __p(it->second);
    cout << "\n";
  }
  cout << "}\n";
}

template <typename T, typename... Arg>
void __p(T a1, Arg... a)
{
  __p(a1);
  __p(a...);
}
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
  cout << name << " : ";
  __p(arg1);
  cout << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
  int bracket = 0, i = 0;
  for (;; i++)
    if (names[i] == ',' && bracket == 0)
      break;
    else if (names[i] == '(')
      bracket++;
    else if (names[i] == ')')
      bracket--;
  const char *comma = names + i;
  cout.write(names, comma - names) << " : ";
  __p(arg1);
  cout << " | ";
  __f(comma + 1, args...);
}
#define db(...) cout << "Line:" << __LINE__ << " ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#define error(...)
#endif

// DEBUG FUNCTIONS END

/*-----------------------------debug----------------------------*/
/*-----------------------------printfs----------------------------*/
int log2n(ll n)
{
  return (63 - __builtin_clzll(n));
}
const ll N = 3e5 + 7;
vll vis(N), vis2(N);
vll lvl(N);
vll component, order;
vll g[N], grev[N];
ll n, m;
ll t = 0, logn;
// mll var;
// vll v;
// ll tout[N], tin[N], timer = 0;

void dfs(ll v)
{
  if (!vis[v])
    vis[v] = 1;
  for (auto u : g[v])
  {
    if (vis[u])
      conti;
    dfs(u);
  }
}
// meant for scc:
/*
void dfs2(ll v)
{
  vis2[v] = 1;
  component.pb(v);
  for (auto u : grev[v])
  {
    if (!vis2[u])
      dfs2(u);
  }
}
*/

void resetGraph()
{
  vis.assign(n + 1, 0), vis2.assign(n + 1, 0), lvl.assign(n + 1, 0);
  // fo(i, n + 1) col[i] = 0;
  fo(i, n + 1) g[i].clear(), grev[i].clear();
}
void solve()
{
  // always check N first
  cin >> n >> m;
  for (ll i = 0; i < m; i++)
  {
    ll x, y;
    cin >> x >> y;
    g[x].pb(y); // x->y
    g[y].pb(x); // for a directed graph!
                // grev[y].pb(x);
                // check for 0 based indexing
  }
  // never break a dfs during post order traversal!
  resetGraph();
}
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("inputf.in", "r", stdin);
  freopen("outputf.in", "w", stdout);
  freopen("debug.txt", "w", stderr);
#endif

  int ttt = 1;
  cout << setprecision(30);
  cin >> ttt;
  fo(i, ttt)
  {
    // cout<<"Case #"<<i+1<<": ";
    solve();
  }
  return 0;
}

/*
Be cautious of cases when updation using DFS fails and you gotta use BFS!
1. Always be cautious of 'n==1 and n==2' in Number theory Ques.
2. Always treat your edge cases distinctly, never try to indulge them in usual loops!
3. Always check back and forth for equality cases!
4. always add a break after f++;
5. always sort before using upper_bound
6. any changing DS is best declared as global and cleared after each test case!
7. Don't overthink, at first just try to go for the simplemost approach
*/

// bfs & shortest path:
/*
ll bfs(ll v, ll n, vll &pred, vll &dist, ll dest)
{
  fo(i, n)
      vis[i + 1] = 0;
  queue<ll> q;
  vis[v] = 1;
  pred[v] = -1;
  q.push(v);
  while (!q.empty())
  {
    for (auto child : g[q.front()])
    {
      if (!vis[child])
      {
        q.push(child);
        pred[child] = q.front();
        // level[child] = level[q.front()] + 1;
        dist[child] = dist[q.front()] + 1;
        vis[child] = 1;
        if (child == dest)
          return 1;
      }
    }
    q.pop();
  }
  return 0;
}

vll shortestPath(ll src, ll dest, ll n)
{
  vll pred(n + 1), path, dist(n + 1);
  if (!bfs(src, n, pred, dist, dest))
    return path;
  ll crawl = dest;
  path.pb(crawl);
  while (pred[crawl] != -1)
  {
    path.pb(pred[crawl]);
    crawl = pred[crawl];
  }
  reverse(all(path));
  return path;
}
*/
// cycles:
/*
ll col[N];
ll isBipartite(ll v)
{
  queue<ll> q;
  vis[v] = 1;
  q.push(v);
  while (!q.empty())
  {
    for (auto u : g[q.front()])
      if (!vis[u])
      {
        q.push(u);
        vis[u] = 1;
        col[u] = (col[q.front()] ^ 1);
      }
      else if (col[u] == col[q.front()])
        ret 0;
    q.pop();
  }
  return 1;
}
*/

/*
ll dest=0;
skll cycle;
ll spvis[N];
ll cycleDFS(int v, int gpar)
{
  spvis[v] = 1;
  if (!spvis[v])
    cycle.push(v);

  for (auto u : g[v])
  {
    if(u==gpar) conti;
    if (spvis[u] == 0)
    {
      cycle.push(u);
      if (cycleDFS(u,v))
        return 1;
    }
    else if (spvis[u] == 1)
    {
      cycle.push(v);
      cycle.push(u);
      dest=u;
      return 1;
    }
  }
  spvis[v] = 2;
  return 0;
}
*/
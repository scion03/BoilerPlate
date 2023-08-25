#pragma GCC optimize('O3,unroll-loops')
// #pragma GCC target('avx2,bmi,bmi2,lzcnt,popcnt')
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
typedef long double ld;
typedef string ss;
typedef vector<long long> vll;
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
vector<string> vec_splitter(string s)
{
  s += ',';
  vector<string> res;
  while (!s.empty())
  {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(
    vector<string> __attribute__((unused)) args,
    __attribute__((unused)) int idx,
    __attribute__((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T)
{
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifndef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

/*-----------------------------debug----------------------------*/
/*-----------------------------printfs----------------------------*/

struct custom_hash
{
  static uint64_t splitmix64(uint64_t x)
  {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const
  {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

/*----------------------------printfs----------------------------*/
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
ll gcd(ll a, ll b)
{
  if (a == 0)
    return b;
  ll r = b % a;
  if (r == 0)
    return a;
  else
    return gcd(r, a);
}

long long nCr(int n, int r, int M)
{
  if (r > n - r)
    r = n - r;
  long long ans = 1;
  int i;

  for (i = 1; i <= r; i++)
  {
    ans *= n - r + i;
    ans /= i;
  }
  return ans;
}

/*---------------------------------- NUMBER THEORY--------------------------------*/
// /*----------------------------weighed_graphs_here----------------------------*/
const ll N = 3e5 + 7;
vll vis(N);
ll n, m;

vector<pll> g[N], grev[N];
// vll dp[N + 1];

void dfs(ll v)
{
  if (!vis[v])
    vis[v] = 1;
  for (auto u : g[v])
  {
    if (vis[u.fi])
      conti;
    dfs(u.fi);
  }
}
void Dijkstra(vll &d, ll src, vll &par) // 0based indexing!!
{
  set<pll> q;
  d.assign(n, INF);
  // par.assign(n, -1);
  d[src] = 0;
  q.insert(mkp(0, src));
  while (!q.empty()) // O(V)
  {
    ll v = ((*q.begin()).se);
    q.erase(q.begin()); // V*logV
    for (auto p : g[v])
    {
      ll u = p.fi, w = p.se;
      if ((d[u] > d[v] + w)) // each edge once only!
      {
        if (!q.empty())
          q.erase({d[u], u}); // E*logV
        d[u] = d[v] + w;
        // par[u] = v;
        q.insert({d[u], u});
      }
    }
  }
} // O((V+E)*logV)
void prims(ll src) // vis fix first
{
  multiset<pll> q;
  multiset<ll> mst;
  q.in({0, src});
  while (!q.empty()) // O(V)
  {
    pll p = *(q.begin()); // V*logV
    ll v = p.se, w = p.fi;

    if (!vis[v])
    {
      mst.in(w);          //
      for (auto e : g[v]) // O(E)
      {
        if (!vis[e.fi])
        {
          q.in({e.se, e.fi}); // E*logV
        }
      }
    }
    q.erase(q.begin());
  }
}

void resetGraph()
{
  fo(i, n + 1) vis[i] = 0;
  // fo(i, n + 1) color[i] = 0;
  // fo(i, n + 1) level[i] = 0;
  fo(i, n + 1) g[i].clear();
}
// vll par(N, 0);
ll x = -1;
ll bellmanFord(ll s, vll &d) // actually its SPFA
{
  d.assign(n, INF); // for finding negative cycle, assign 0 to d, its kinda running by all the soruces all together!
  d[s] = 0;
  ll x = -1;
  fo(i, n)
  {
    x = -1;
    fo(v, n) // O(E)
    {
      for (auto e : g[v])
      {
        ll w = e.se, to = e.fi;
        if (d[v] < INF)
          if (d[to] > d[v] + w)
          {
            d[to] = max(-INF, d[v] + w);
            // par[to] = v;
            x = to;
          }
      }
    }
  }
  return x;
}

void solve()
{
  // PS: to manage multiple weights of the same edge define a 2D vector instead of using maps!
  // ALways check for N and Directed and Undirected first!
  ll max = 0, min = INF, sum = 0, ans = 0, f = 0;
  cin >> n >> m;
  for (ll i = 0; i < m; i++)
  {
    ll x, y, w;
    cin >> x >> y >> w;
    x--, y--;
    g[x].pr(y, w);
    grev[y].pr(x, w);
    // g[x].pr(y, w);
  }

  // Dijkstra(dist, 0, v);
  // pvec(dist);

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
  cout << setprecision(30);
  int ttt = 1;
  fo(i, ttt)
  {
    // cout<<"Case #"<<i+1<<": ";
    solve();
  }
  return 0;
}

/*
In Bellman Ford, there shouldn't be any relaxation in nth phase, but if it still occurs,then no doubt there exists a negative cycle!
*/

// void floyd_w(ll n)
//  {
//    fo(i,n) fo(j,n) dp[i][j]=INF;
//    fo(i,n){
//      dp[i][i] = 0;
//      for (auto p : g[i])
//      {
//        ll j = p.fi,w=p.se;
//        dp[i][j] = w;
//        dp[j][i] = w;
//      }
//    }//init
//   fo(k, n)
//   {
//     fo(i, n)
//     {
//       fo(j, n)
//       {
//         if (dp[i][k] < INF && dp[k][j] < INF)
//           dp[i][j] = min(dp[i][j], dp[k][j] + dp[i][k]);
//       }
//     } // beware about x==y in queries!!!!
//   }
// } // O(V^3)

/*
1. Always be cautious of 'n==1 and n==2' in Number theory Ques.
2. Always treat your edge cases distinctly, never try to indulge them in usual loops!
3. Always check back and forth for equality cases!
4. always add a break after f++;
5. always sort before using upper_bound
6. any changing DS is best declared as global and cleared after each test case!
7. Don't overthink, at first just try to go for the simplemost approach
*/
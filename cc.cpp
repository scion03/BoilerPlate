#pragma GCC optimize('O3,unroll-loops')
// #pragma GCC target('avx2,bmi,bmi2,lzcnt,popcnt')
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
ll lvl[N], logn;
vector<vll> up;
ll sz[N];
vll g[N];
ll t = 0;
ll n;
ll ans = 0;
ll maxProd(vll &a)
{
  ll sum = 0;
  ll n = a.size();
  rep(i, 0, n) sum += a[i];
  ll dp[n + 1][sum + 7];
  memset(dp, 0, sizeof(dp));
  ll mx = 0;
  dp[0][a[0]] = 1;
  dp[0][0] = 1;
  rep(i, 1, n)
  {
    rep(j, 0, sum + 1)
    {
      dp[i][j] = dp[i - 1][j];
    }
    rep(j, 0, sum + 1)
    {
      if (j + a[i] <= sum)
      dp[i][j + a[i]] |= dp[i - 1][j];
    }
  }
  rep(j, 0, sum + 1)
  {
    if (dp[n - 1][j])
      maxs(mx, j * (sum - j));
  }
  return mx;
}

void dfs(ll v, ll gpar)
{
  sz[v] = 1;
  vll a;
  fat(u, g[v])
  {
    if (u != gpar)
    {
      dfs(u, v);
      sz[v] += sz[u];
      a.pb(sz[u]);
    }
  }
  if (siz(a))
    ans += maxProd(a);
}

void addEdge(ll x, ll y)
{
  g[x].pb(y);
  g[y].pb(x);
}

// up.assign(n + 1, vll(LOGN+ 1)); // use in solve() for binary lifting
void solve()
{
  // check N first always
  ll max = 0, min = INF, sum = 0, f = 0;
  cin >> n;

  for (ll i = 0; i < n - 1; i++)
  {
    ll p;
    cin >> p;
    addEdge(p, i + 2);
  }
  dfs(1, 1);
  cout << ans << nl;
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

  fo(i, ttt)
  {
    // cout<<"Case #"<<i+1<<": ";
    solve();
  }

  return 0;
}

/*
1. Always be cautious of 'n==1 and n==2' in Number theory Ques.
2. Always treat your edge cases distinctly, never try to indulge them in usual loops!
3. Always check back and forth for equality cases!
4. always add a break after f++;
5. always sort before using upper_bound
6. any changing DS is best declared as global and cleared after each test case!
7. Don't overthink, at first just try to go for the simplemost approach, use Implementations.md for reference!
*/

// snippet for lca to be put in dfs, in preorder:
/*
 up[u][0] = v;
 for (int i = 1; i < LOGN; ++i)
   up[u][i] = up[up[u][i - 1]][i - 1];
*/
// lca fun():
/*
const ll LOGN=20;
ll lca(ll u, ll v)
{
  if (lvl[u]<lvl[v])
    swap(u, v);
  ll k = lvl[u] - lvl[v];

  // kth ancestor of u(one which is closer to root):
  for (int i = LOGN-1; i >= 0; --i)
    if (k&(1LL << i) )
      u = up[u][i];

  if (u == v)
    ret u;

  for (int i = LOGN-1; i >= 0; --i)
  {
    if (up[u][i] != up[v][i])
    {
      u = up[u][i];
      v = up[v][i];
    }
  }
  ret up[u][0];
}
*/
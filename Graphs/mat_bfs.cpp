#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
#define endl '\n'
#define int ll
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
#define conti continue;
#define fi first
#define se second
#define pr(a, b) pb(make_pair(a, b))
#define mkp(a, b) make_pair(a, b)
#define nl '\n'
#define all(v) v.begin(), v.end()
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define fost(i, a, b, d) for (ll i = a; i < b; i += d)
#define ofst(i, a, b, d) for (ll i = a; i > b; i -= d)
#define forb(i, a, b) for (int i = a; i < b; i++)
#define fon(i, a, b) for (int i = a; i >= b; i--)
#define fo(i, n) for (int i = 0; i < n; i++)
#define itmp(mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define start_clock() auto start_time = std::chrono::high_resolution_clock::now();
#define measure()                                            \
  auto end_time = std::chrono::high_resolution_clock::now(); \
  cerr << (end_time - start_time) / std::chrono::milliseconds(1) << "ms" << endl;
#define yes cout << "YES" << nl;
#define no cout << "NO" << nl;

/*-----------------------------printfs----------------------------*/

void parr(ll a[], ll n)
{
  for (ll i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}
void pvec(vector<pll> v)
{
  for (ll i = 0; i < v.size(); i++)
  {
    cout << v[i].fi << " " << v[i].se;
  }
  cout << endl;
}

/*----------------------------printfs----------------------------*/

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

#define N 1001
vll vis[N + 7];
pll src, dest;
vll mon_dist[N + 7];
vll lvl[N + 7];
ll qt = 0;
queue<pll> q;

bool valid_check(ll i, ll j, ll n, ll m)
{
  if (i < 0 || j < 0)
  {
    return false;
  }
  if (i > n - 1 || j > m - 1)
  {
    return false;
  }
  return true;
}

void dfs(ll i, ll j, ll n, ll m, vll grid[])
{

  if (!valid_check(i, j, n, m))
    return;
  if (make_pair(i, j) == dest)
    qt = 1;
  if (grid[i][j] == 0)
    return;
  if (vis[i][j] == 1)
    return;
  vis[i][j] = 1;

  dfs(i - 1, j, n, m, grid);
  dfs(i + 1, j, n, m, grid);
  dfs(i, j + 1, n, m, grid);
  dfs(i, j - 1, n, m, grid);
}

map<pll, pll> pred;
ll mons_bfs = 1;
void bfs_util(ll i, ll j, vll grid[], ll n, ll m, ll cur)
{
  if (!valid_check(i, j, n, m))
    return;
  if (vis[i][j] || !grid[i][j])
    return;
  vis[i][j] = 1;
  if (mons_bfs)
    mon_dist[i][j] = min(mon_dist[i][j], cur);
  else if (cur >= mon_dist[i][j])
    return;
  if (!mons_bfs)
  {
    lvl[i][j] = cur;
  }
  // cout << lvl[i][j]<<" "<<mon_dist[i][j] << nl;

  q.push(make_pair(i, j));
  if (!mons_bfs)
  {
    pred[make_pair(i, j)] = q.front();
    if (i == 0 || j == 0 || j == m - 1 || i == n - 1)
    {
      qt = 1;
      dest = mkp(i, j);
      return;
    }
  }
}

ll bfs(ll n, ll m, vll grid[])
{
  pred[src] = make_pair(-1, -1);
  // q.push(src);
  while (!q.empty())
  {
    pll p = q.front();
    vis[p.fi][p.se] = 1;
    // cout << q.front().fi << " " << q.front().se << " " << q.size() << nl;
    ll cur;
    if (mons_bfs)
      cur = mon_dist[p.fi][p.se] + 1;
    else
      cur = lvl[p.fi][p.se] + 1;
    bfs_util(p.fi + 1, p.se, grid, n, m, cur);
    bfs_util(p.fi - 1, p.se, grid, n, m, cur);
    bfs_util(p.fi, p.se - 1, grid, n, m, cur);
    bfs_util(p.fi, p.se + 1, grid, n, m, cur);
    if (qt)
      return 1;
    q.pop();
  }
  return 0;
}

vector<pll> ShortestPath(ll n, ll m, vll grid[])
{
  vector<pll> path;
  bfs(src.fi, src.se, grid);
  pll crawl = dest;
  path.pb(dest);
  ll z = 0;
  while (pred[crawl].first != -1)
  {
    // cout << crawl.fi<<" "<<crawl.se << nl;
    crawl = pred[crawl];
    path.pb(crawl);
    // z++;
  }
  return path;
}

void resetVis()
{
  vll vv(N);
  fo(i, N)
      vis[i] = vv;
}

void reset()
{
  resetVis();
  while (!q.empty())
    q.pop();
  qt = 0;
  mons_bfs = 0;

  pred.clear();
}
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("inputf.in", "r", stdin);
  freopen("outputf.in", "w", stdout);
#endif
  vll vv(N);
  fo(i, N)
  {
    vis[i] = vv;
    lvl[i] = vv;
  }
  ll ttt = 1;
  // cin >> ttt;
  while (ttt--)
  {
    cout << setprecision(30);
    ll n, m, max = 0, min = INF, sum = 0, ans = 0, f = 0;
    cin >> n >> m;
    // assert(n != -1);
    vll a[n + 1];
    vector<pll> monsters;
    for (ll i = 0; i < n; i++)
    {
      ss s;
      cin >> s;
      fo(j, m)
      {
        mon_dist[i].pb(n * m + 7);

        if (s[j] == 'A')
        {
          lvl[i][j] = 0;
          a[i].pb(1);
          src = make_pair(i, j);
        }
        else if (s[j] == 'M')
        {
          mon_dist[i][j] = 0;
          a[i].pb(1);
          q.push(mkp(i, j));
        }
        else if (s[j] == '#')
          a[i].pb(0);
        else
          a[i].pb(1);
      }
    }
    // mons bfs
    if (src.fi == 0 || src.se == m - 1 || src.fi == n - 1 || src.fi == 0)
    {
      cout << "YES" << nl;
      cout << 0 << nl;
      conti
    }
    bfs(n, m, a);
    mons_bfs = 0;
    resetVis();
    q.push(src);
    // fo(i, n)
    // {
    //   fo(j, m)
    //   {
    //     cout << lvl[i][j] << " ";
    //   }
    //   cout << nl;
    // }
    bfs(n, m, a);

    // the other bfs!
    pll crawl = dest;
    if (qt)
    {
      vector<pll> vp;
      cout << "YES" << nl;
      while (pred[crawl].fi != 0)
      {
        vp.pb(crawl);
        crawl = pred[crawl];
      }

      cout << vp.size() - 1 << nl;
      pll lp = src;
      reverse(all(vp));
      for (auto p : vp)
      {
        if (p != src)
        {
          if (p.fi < lp.fi)
          {
            cout << 'U';
          }
          else if (p.se < lp.se)
          {
            cout << 'L';
          }
          else if (p.fi > lp.fi)
            cout << 'D';
          else
            cout << 'R';
          lp = p;
        }
      }
    }
    else
      cout << "NO" << nl;
    reset();
  }
  return 0;
}

/*
1. Always be cautious of '1 and 2' in Number theory Ques.
2. Always treat your edge cases distinctly, never try to indulge them in usual loops!
3. Always check back and forth for equality cases!
4. always add a break after f++;
5. always sort before using upper_bound
*/
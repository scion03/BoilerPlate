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

/*-----------------------------printfs----------------------------*/

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
vll vis[N];

ll qt = 0;
void dfs(ll i, ll j, ll n, ll m, vll grid[])
{
  if (i < 0 || j < 0)
  {
    return;
  }
  if (i > n - 1 || j > m - 1)
  {
    return;
  }

  if (vis[i][j] == 1)
    return;
  vis[i][j] = 1;

  dfs(i - 1, j, n, m, grid);
  dfs(i + 1, j, n, m, grid);
  dfs(i, j + 1, n, m, grid);
  dfs(i, j - 1, n, m, grid);
}
void bfs(ll i, ll j, ll n, ll m, vll grid[]){
  queue<pll> q;
  q.push(make_pair(i, j));
  while(!q.empty()){
    pll p = q.front();
    q.push(make_pair(p.fi+1, p.se));
    q.push(make_pair(p.fi, p.se-1));
    q.push(make_pair(p.fi, p.se+1));
    q.push(make_pair(p.fi-1, p.se));
    // if (abs(p.fi - dest.fi) <= 1 && abs(p.se - dest.se)<=1)
      q.pop();
  }
}
 void resetVis()
{
  qt = 0;
  vll vv(N);
  fo(i, N)
      vis[i] = vv;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("inputf.in", "r", stdin);
  freopen("outputf.in", "w", stdout);
#endif
  vll vv(N);
  fo(i, N)
      vis[i] = vv;
  ll ttt = 1;
  cin >> ttt;
  while (ttt--)
  {
    cout << setprecision(30);
    map<ll, ll> mp, cnt;
    ll n, m, max = 0, min = INF, sum = 0, ans = 0, f = 0;
    cin >> n >> m;
    // assert(n != -1);
    vll a[n + 1];
    for (ll i = 0; i < n; i++)
    {
      ss s;
      cin >> s;
      fo(j, m)
      {
        // if(s[j]=='')
      }
    }
    fo(i, n)
    {
      fo(j, m)
      {
        if (a[i][j] == 1)
        {
          dfs(i, j, n, m, a);
        }
      }
    }
    resetVis();
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
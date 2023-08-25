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
#define eb emplace_back
#define conti continue;
#define siz(v) (ll)v.size()
#define fat(e, v) for (auto &e : v)
#define fi first
#define se second
#define in insert
#define pr(a, b) pb(make_pair(a, b))
#define mkp(a, b) make_pair(a, b)
#define exis(a, s) s.find(a) != s.end()
#define nl '\n'
#define all(v) v.begin(), v.end()
#define popE(s) s.erase(--s.end())
#define popF(s) s.erase(s.begin())
#define rm(x, s)   \
  if (exis(x, se)) \
  s.erase(s.find(x))
#define bg begin()
#define rbg rbegin()
#define inp(v, n) \
  vll v(n);       \
  fo(i, n) cin >> v[i];
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
#define rev(v) reverse(all(v))
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

void solve()
{
  ll n, ans = 0;
  cin >> n;
  inp(a, n);

}

/*
      ALWAYS REVIEW WHOLE CODE BEFORE SUBMITTING!!
      */
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
  cin >> ttt;

  fo(i, ttt)
  {
    // cout<<"Case #"<<i+1<<": ";
    solve();
  }
  return 0;
}

/*
-> set vs multiset
-> Always add another check for the non-occuring cases, like when the variables are equal to INF or non-unique then you may not need to consider them!
-> code repitition(copy-pasta) in if-else can cause errors, not visible to the naked eye. Always re-write instead.
-> Whenever the approach itself is wrong, do a fresh start.
-> Remember you can iterate over all multiples of i, for each i in (0,n] in logn.
-> keep an open eye for monotonicity, repititions, unique/special values
-> Don't overthink, at first just try to go for the simplemost approach, use Implementations.md for reference!
-> Also keep an open eye for n*root(n) approaches if n=O(1e5).
*/

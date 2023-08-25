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
#define siz(v) (ll) v.size()
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
class seg
{
  // don't forget to initialise obj.n and beware to update a[ind] too while updating, just fo future ref and being on the safe side!
  ll NEUTRAL_VALUE = 0;

public:
  struct data
  {
    ll val;
  };
  ll n;
  vector<data> t;
  data make_data(ll x)
  {
    data res;
    res.val = x;
    return res;
  }
  data combine(data l, data r)
  {
    data res;
    res.val = l.val + r.val;
    return res;
  }
  void _build(vll &a, ll v, ll tl, ll tr)
  {
    if (tl == tr)
    {
      t[v] = make_data(a[tl]);
    }
    else
    {
      ll tmid = ((tl + tr) >> 1);
      _build(a, v * 2, tl, tmid);
      _build(a, v * 2 + 1, tmid + 1, tr);
      t[v] = combine(t[2 * v], t[2 * v + 1]);
    }
  }
  data _qry(ll v, ll tl, ll tr, ll l, ll r)
  {
    // don't forget to update MAXN to comprehend with the size!
    if (l > r || tl > r || tr < l)
      return make_data(NEUTRAL_VALUE);
    if (l == tl && r == tr)
    {
      return t[v];
    }
    ll tm = (tl + tr) >> 1;
    // for suffix sums, pass reduced value to left child
    return combine(_qry(v * 2, tl, tm, l, min(r, tm)), _qry(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }

  void _update(ll v, ll tl, ll tr, ll pos, ll new_val)
  {
    if (tl == tr)
    {
      t[v] = make_data(new_val);
    }
    else
    {
      ll tm = ((tl + tr) >> 1);
      if (pos <= tm)
        _update(v * 2, tl, tm, pos, new_val); // l-child
      else
        _update(v * 2 + 1, tm + 1, tr, pos, new_val); // r-child
      t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
  }
  // std functions->
  void build(vll &a)
  {
    n = siz(a);
    t.assign(4 * n, make_data(NEUTRAL_VALUE));
    _build(a, 1, 0, n - 1);
  }
  data qry(ll l, ll r)
  {
    ret _qry(1, 0, n - 1, l, r);
  }
  void update(ll ind, ll val)
  {
    _update(1, 0, n - 1, ind, val);
  }
  // for min, modify (l>r) case, both the t[v] in update and build and t's initial val
};
void solve()
{
  mll idx, cnt, mp;

  ll n, ans = 0;
  cin >> n;
  inp(a, n);
  vll va = a;

  sort(all(va));
  va.erase(unique(all(va)), va.end());
  n = siz(va);
  vll a1 = a;
  vll v;
  set<ll> cur;
  rep(i, 0, n)
  {
    cur.in(va[i]);
    cnt[va[i]]++;
    if (i)
      mp[va[i] - va[i - 1]]++;
  }
  ll rem = n, ls = 0;
  for (auto p : mp)
  {
    ans += rem * (p.fi - ls);
    rem -= (p.se);
    ls = p.fi;
    v.pb(p.fi);
  }
  ans += va[0];
  ll q;
  cin >> q;
  vector<pll> vq;
  mll cnt1 = cnt;
  set<ll> cur1 = cur;
  rep(_, 0, q)
  {
    ll i, x;
    cin >> i >> x;
    i--;
    cnt1[a[i]]--;
    if (cnt1[a[i]] == 0)
      cur1.erase(a[i]);
    cnt1[x]++;
    if (cnt1[x] == 1)
    {
      cur1.in(x);
      auto it = cur1.lower_bound(x);
      auto it1 = cur1.upper_bound(x);
      if (it != cur1.begin())
        v.pb(*it - *(--it));
      if (it1 != cur1.end())
        v.pb(*it1 - x);
    }
    if (cnt1[a[i]] == 0)
    {
      cur1.erase(a[i]);
      auto it = cur1.lower_bound(a[i]);
      if (it != cur1.end() and it != cur1.begin())
      {
        v.pb(*it - *(--it));
      }
    }
    vq.pb({i, x});
    a[i] = x;
  }
  // db(v);
  a = a1;
  sort(all(v));
  v.erase(unique(all(v)), v.end());
  rep(i, 0, siz(v)) idx[v[i]] = i;
  ll sz = siz(v);
  cnt1 = cnt, cur1 = cur;
  vll val(sz + 7);
  for (auto p : mp)
  {
    val[idx[p.fi]] = p.se;
  }

  seg sg;
  sg.build(val);
  auto add = [&](ll d)
  {
    val[idx[d]]++;
    ll r = sg.qry(idx[d] + 1, sz - 1).val, l = sg.qry(0, idx[d] - 1).val;
    sg.update(idx[d], val[d]);
    ans += l;
    ans -= r;
  };
  auto rm = [&](ll d)
  {
    val[idx[d]]--;
    ll r = sg.qry(idx[d] + 1, sz - 1).val, l = sg.qry(0, idx[d] - 1).val;
    sg.update(idx[d], val[d]);
    ans -= l;
    ans += r;
  };
  for (auto p : vq)
  {
    ll i = p.fi, x = p.se;
    cnt1[a[i]]--;
    if (cnt1[a[i]] == 0)
      cur1.erase(a[i]);
    cnt1[x]++;
    if (cnt1[x] == 1 and a[i] != x)
    {
      cur1.in(x);
      auto it = cur1.lower_bound(x);
      auto it2 = cur1.lower_bound(x);
      auto it1 = cur1.upper_bound(x);
      ll d1, d2;
      if (it != cur1.begin())
      {
        d1 = x - *(--it);
        add(d1);
      }
      if (it1 != cur1.end())
      {
        d2 = *it1 - x;
        add(d2);
      }
      if (it1 != cur1.end() and it2 != cur1.begin())
        rm(d1 + d2);
    }
    if (cnt1[a[i]] == 0)
    {
      auto it = cur1.lower_bound(a[i]);
      ll d2 = 0, d1 = 0;
      ll ls = 0;
      if (it != cur1.end())
      {
        ll d1 = *it - a[i];
        rm(d1);
      }
      if (it != cur1.begin())
      {
        auto it1 = cur1.lower_bound(a[i]);
        d2 = a[i] - *(--it1);
        rm(d2);
      }
      if (it != cur1.end() and it != cur1.begin())
      {
        add(d1 + d2);
      }
    }
    a[i] = x;
    cout << ans << " ";
  }
  cout << nl;
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

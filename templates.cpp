
// all subsets:
void allPossibleSubset(vll arr, ll n)
{
  ll msk = 1 << n;

  for (int i = 0; i < msk; i++)
  {
    // This loop will generate a subset
    for (int j = 0; j < n; j++)
    {
      if ((i & (1 << j)) != 0)
      {
        // access elements here!
      }
    }
  }
}

// sqrt:
sqrtD sq;
sq.n = n, sq.a = a;
sq.init();
///////
class sqrtD
{
public:
  ll n;
  vll a, b;
  // init in main as: sqrtD.n=n,sqrtD.a=a;
  void init()
  {
    ll sq = (ll)sqrt(n + .0) + 1;
    b = vll(sq);
    for (int i = 0; i < n; ++i)
      b[i / sq] += a[i];
  }
  ll qry(ll l, ll r)
  {
    ll sq = (ll)sqrt(n + .0) + 1;
    ll sum = 0;
    for (int i = l; i <= r;)
      if (i % sq == 0 && i + sq - 1 <= r)
      {
        sum += b[i / sq];
        i += sq;
      }
      else
      {
        sum += a[i];
        ++i;
      }
    ret sum;
  }
};

// Mo's algo:
ll cur_l = 0, cur_r = -1;
for (auto v : q)
{
  ll idx = v[2];
  ll l = vp[idx].fi, r = vp[idx].se;
  while (cur_l > l)
  {
    cur_l--;
    // add
  }
  while (cur_r < r)
  {
    cur_r++;
    // add
  }
  while (cur_l < l)
  {
    // rm
    cur_l++;
  }

  while (cur_r > r)
  {
    // rm
    cur_r--;
  }
}
// small to large merging
set<ll> st[N];
void merge_L2H(ll a, ll b)
{
  if (siz(st[a]) < siz(st[b]))
    swap(st[a], st[b]);
  while (siz(st[b]))
  {
    auto it = st[b].begin();
    ll z = *it;
    st[a].in(z);
    st[b].erase(it);
  }
}
// custom hash:
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
// sparse table RMQ:
template <class T>
struct rmq
{
  int n;
  vector<vector<T>> a;

  T combine(T x, T y)
  {
    return min(x, y);
  }

  rmq(vector<T> b)
  {
    int n = siz(b);
    a.resize(32, vector<T>(n));
    a[0] = b;
    rep(j, 1, 32)
    {
      for (int i = 0; i + (1 << (j - 1)) < n; i++)
      {
        a[j][i] = combine(a[j - 1][i], a[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T qry(int l, int r)
  {
    if (l > r)
      return INF;
    int z = 63 - __builtin_clzll(r - l + 1);
    return combine(a[z][l], a[z][r - (1 << z) + 1]);
  }
};
// declare as rmq<ll> st(pref) and call query as st.qry( L, R)

// seg tree:

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

// lazy seg tree:
const ll MAXN = 1e5 + 7;
class seg
{
  // don't forget to initialise obj.n and beware to update a[ind] too while updating, just fo future ref and being on the safe side!
public:
  struct data
  {
    ll val, lazy, marked;
  };
  ll n;
  vector<data> t;
  // unstable functions:
  const ll NEUTRAL_VALUE = 0;
  data make_data(ll val)
  {
    data res;
    res.val = val;
    res.lazy = 0;
    res.marked = 0;
    return res;
  }
  void propogate(ll v)
  {
    if (t[v].marked)
    {
      t[2 * v].val = t[2 * v + 1].val = t[v].val;
      t[2 * v].marked = 1;
      t[2 * v + 1].marked = 1;
      t[v].marked = 0;
    }
    /*
      t[2 * v].lazy |= t[v].lazy;
      t[2 * v + 1].lazy |= t[v].lazy;
      t[2 * v].val |= t[v].lazy;
      t[2 * v + 1].val |= t[v].lazy;
      t[v].lazy = 0;
    */
  } // for lazy propogation
  void modify_op(ll v)
  {
    t[v].val = min(t[2 * v].val, t[2 * v + 1].val);
  }
  ll query_op(ll v1, ll v2)
  {
    ret min(v1, v2);
  }
  void do_rupdate(ll v, ll x)
  {
    t[v].val = x;
    t[v].marked = 1;
  }
  //
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
      modify_op(v);
      // ->0 for lazy seg tree
    }
  }

  void _rupdate(ll v, ll tl, ll tr, ll l, ll r, ll add)
  {
    if (l > r)
      return;
    if (l == tl && r == tr)
    {
      do_rupdate(v, add);
    }
    else
    {
      propogate(v);
      ll tm = (tl + tr) / 2;
      _rupdate(v * 2, tl, tm, l, min(r, tm), add);
      _rupdate(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
      modify_op(v);
    }
  }
  ll _get(ll v, ll tl, ll tr, ll l, ll r)
  {
    if (l > r)
      ret NEUTRAL_VALUE;
    if (l == tl && r == tr)
    {
      return t[v].val;
    }
    propogate(v);
    int tm = (tl + tr) / 2;
    ll v1 = _get(v * 2, tl, tm, l, min(r, tm));
    ll v2 = _get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    ret query_op(v1, v2);
  }
  void rupdate(ll l, ll r, ll add)
  {
    _rupdate(1, 0, n - 1, l, r, add);
  }
  ll get(ll l, ll r)
  {
    ret _get(1, 0, n - 1, l, r);
  }
  // std functions->
  void build(vll &a)
  {
    n = siz(a);
    t.assign(4 * n, make_data(NEUTRAL_VALUE));
    _build(a, 1, 0, n - 1);
  }

  // for min, modify (l>r) case, both the t[v] in update and build and t's initial val
};

// phi_rootn:
// phi(a*b)=phi(a)*phi(b), where a and b are co-prime
ll phi(ll n)
{
  // phi[i]-> number of co-primes with i in 1 to i
  ll result = n;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      while (n % i == 0)
        n /= i;
      result -= result / i;
    }
  }
  if (n > 1)
    result -= result / n;
  return result;
}
// phi 1 to n :
// phi(a*b)=phi(a)*phi(b), where a and b are co-prime
void phi_1_to_n(ll n)
{
  // phi[i]-> number of co-primes with i in 1 to i
  vector<ll> phi(n + 1);
  for (int i = 0; i <= n; i++)
    phi[i] = i;

  for (int i = 2; i <= n; i++)
  {
    if (phi[i] == i)
    {
      for (int j = i; j <= n; j += i)
        phi[j] -= phi[j] / i;
    }
  }
}
// virtual tree:
bool is_ancestor(ll v, ll u)
{
  return (tin[u] >= tin[v] && tout[u] <= tout[v]);
}
vll virt_tr[N];
void buildVirtualTree(vll &v)
{

  auto cmp = [&](ll x, ll y)
  {
    return tin[x] < tin[y];
  };
  sort(all(v), cmp);
  ll sz = siz(v);
  fo(i, sz - 1)
  {
    v.pb(lca(v[i], v[i + 1]));
  }
  sort(all(v), cmp);
  v.erase(unique(all(v)), v.end());
  int j = 0;
  int i = 0;
  while (i < siz(v))
  {
    while (j < i && lca(v[j], v[i]) == v[j])
      j++;
    virt_tr[v[i]].pb(v[j]);
    virt_tr[v[j]].pb(v[i]);
    i++;
  }
}
// mint:
ll extgcd(ll a, ll b, ll &x, ll &y)
{
  x = 1, y = 0;         // xa+yb=a at all times
  ll q, x1 = 0, y1 = 1; // x1a+y1b=b at all times
  while (a && b)
  {
    if (a > b)
    {
      q = a / b;
      x -= q * x1;
      y -= q * y1;
      a -= q * b;
    }
    else
    {
      q = b / a;
      x1 -= q * x;
      y1 -= q * y;
      b -= q * a;
    }
  }
  if (a == 0)
  {
    x = x1;
    y = y1;
    return b;
  }
  return a;
}
const ll mod = 1e9 + 7;
struct mint
{
  ll x;
  mint() : x(0) {}
  mint(ll y)
  {
    if (y >= 0 && y < mod)
      x = y;
    else
    {
      x = y % mod;
      if (x < 0)
        x += mod;
    }
  }
  mint operator-() { return mint(-x + mod); }
  mint operator~() const
  {
    ll a, b;
    extgcd(x, mod, a, b);
    return a;
  }
  mint &operator+=(const mint &a)
  {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint &a)
  {
    if ((x -= a.x) < 0)
      x += mod;
    return *this;
  }
  mint &operator*=(const mint &a)
  {
    x = (x * a.x) % mod;
    return *this;
  }
  mint &operator/=(const mint &a)
  {
    this->operator*=(~a);
    return *this;
  }
  mint operator++()
  {
    ++x;
    if (x == mod)
      x = 0;
    return (*this);
  }
  mint operator++(int)
  {
    x++;
    if (x == mod)
      x = 0;
    return mint(x - 1);
  }
  mint operator--()
  {
    --x;
    if (x == -1)
      x = mod - 1;
    return (*this);
  }
  mint operator--(int)
  {
    x--;
    if (x == -1)
      x = mod - 1;
    return mint(x + 1);
  }
  mint pow(ll b) const
  {
    mint res(1);
    mint a(*this);
    while (b)
    {
      if (b & 1)
        res *= a;
      a *= a;
      b >>= 1;
    }
    return res;
  }
  mint operator+(const mint &a) const { return mint(*this) += a; }
  mint operator-(const mint &a) const { return mint(*this) -= a; }
  mint operator*(const mint &a) const { return mint(*this) *= a; }
  mint operator/(const mint &a) const { return mint(*this) /= a; }
  bool operator<(const mint &a) const { return x < a.x; }
  bool operator<=(const mint &a) const { return x <= a.x; }
  bool operator>(const mint &a) const { return x > a.x; }
  bool operator>=(const mint &a) const { return x >= a.x; }
  bool operator==(const mint &a) const { return x == a.x; }
  bool operator!=(const mint &a) const { return x != a.x; }

  friend istream &operator>>(istream &is, mint p) { return is >> p.x; }
  friend ostream &operator<<(ostream &os, mint p) { return os << p.x; }
};
// next greater using stack:
vll nexgr(n, n);
stack<ll> stk;
fo(i, n)
{
  while (stk.size() && a[stk.top()] < a[i])
  {
    nexgr[stk.top()] = i;
    stk.pop();
  }
  stk.push(i);
}
// number theory:
ll binMul(ll n, ll k, ll m)
{
  ll ans = 0;
  while (k != 0)
  {
    if (k & 1)
      ans = (ans + n) % m;
    n = (2 * n) % m;
    k = k >> 1;
  } // O(log2(k))
  return ans;
}
ll binPow(ll a, ll b, ll m)
{
  a %= m;
  if (m > 1)
    b %= (m - 1);
  ll ans = 1;
  while (b != 0)
  {
    if (b & 1)
      ans = (ans * a) % m;
    a = (a * a) % m;
    b = b >> 1;
  } // O(log2(k))
  return ans;
}
/*For very large Expo, use b=b%(M-1),where M is a prime number and a^b%M is req*/
ll modInverse(ll n, ll M)
{
  ret binPow(n, M - 2, M);
}
const ll N =
    ll fact[N];
void factMod(ll n, ll M)
{
  fact[0] = 1;
  rep(i, 1, n)
  {
    fact[i] = (i * (fact[i - 1] % M)) % M;
  }
}
ll C(ll n, ll r, ll M)
{
  if (r < 0 || n < 0)
    ret 0;
  if (r > n)
    ret 0;
  ll ans = fact[n];
  ans = binMul(ans, modInverse(fact[n - r], M), M);
  ans = binMul(ans, modInverse(fact[r], M), M);
  return ans;
}

// debug:
//  DEBUG FUNCTIONS
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

// binary search predicate, :
// for max
auto predf = [&](ll mid)
    -> bool {
};
ll lo = 0, hi = INFINITY;
while (lo + 1 < hi)
{

  ll mid = ((hi + lo) >> 1);
  if (predf(mid))
    lo = mid;
  else
    hi = mid - 1;
  db(lo, hi);
} // TTTTTT'T'FFFFFFFF
ll op = (predf(hi) ? hi : lo);
// cout << op << nl;

// binary search for min
auto predf = [&](ll mid)
    -> bool {
};
ll lo = 0, hi = INFINITY;
while (lo + 1 < hi)
{

  ll mid = ((hi + lo) >> 1);
  if (predf(mid))
    hi = mid;
  else
    lo = mid + 1;
  // db(hi, lo);
} // FFFFFF'T'TTTTTT
ll op = (predf(lo) ? lo : hi);
// cout << op << nl;

// gcd:
int gcd(int a, int b)
{
  if (!a || !b)
    return a | b;
  unsigned shift = __builtin_ctz(a | b);
  a >>= __builtin_ctz(a);
  do
  {
    b >>= __builtin_ctz(b);
    if (a > b)
      swap(a, b);
    b -= a;
  } while (b);
  return a << shift;
}
// matrix struct:
const ll R = 1e9 + 7;
const ll matrixRemainder = R;
class matrix
{
public:
  int row, col;
  std::vector<vll> num;
  matrix(ll row, ll col, ll defaultValue = 0)
  {
    this->num = std::vector<std::vector<ll>>(row, std::vector<ll>(col, defaultValue));
    this->row = row, this->col = col;
  }
  matrix(std::vector<vll> num)
  {
    this->num = num;
    this->row = this->num.size();
    this->col = this->num[0].size();
  }
  matrix operator*(const matrix &another)
  {
    if (this->col != another.row)
    {
      printf("Wrong size: %d*%d X %d*%d\n", this->row, this->col, another.row, another.col);
      throw "Wrong size";
    }
    matrix newone(this->row, another.col);
    for (ll r = 0; r < newone.row; r++)
      for (ll c = 0; c < newone.col; c++)
      {
        for (ll k = 0; k < this->col; k++)
        {
          newone.num[r][c] += this->num[r][k] * another.num[k][c];
          newone.num[r][c] %= matrixRemainder;
        }
      }
    return newone;
  }
  matrix operator^(ll x)
  {
    if (x == 0)
    {
      printf("Not implemented yet.\n");
      throw "Not implemented";
    }
    else if (x == 1)
      return *this;
    else
    {
      matrix halfpower = (*this) ^ (x / 2);
      if (x % 2 == 0)
        return halfpower * halfpower;
      else
        return halfpower * halfpower * (*this);
    }
  }
};
// matrix x:
ll mod = 1e9 + 7;
struct Matrix
{
  vector<vll> a = {{0, 0}, {0, 0}};
  Matrix operator*(const Matrix &other)
  {
    Matrix product;
    ll temp;
    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        temp = 0;
        for (int k = 0; k < 2; k++)
        {
          temp = temp + (ll)a[i][k] * other.a[k][j] % mod; // take mod inside this loop if k>9
        }
        product.a[i][j] = (int)(temp % mod);
      }
    }
    return product;
  }
};

// ordered set:
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// o_s.order_of_key(k) : It returns to the number of items that are strictly "smaller".
// o_s.find_by_order(k): It returns to an iterator to the kth element (counting from zero).

// arti:
// articulation_point / Bridges_snippet :

if (u == p)
  continue;
if (vis[u])
{
  low[v] = min(low[v], tin[u]);
}
else
{
  dfs(u, p);
  low[v] = min(low[v], low[u]);
  if (tin[v] <= low[u] && p != -1)
    arti.pb(v);
  if (tin[v] < low[u] && p != -1)
    bridge.pb({v, u});
}

// trie:
const ll ALPHABET_SIZE = 26;
class trie
{
  //   struct node *rt = init(); //use this in int main
  struct node
  {
    struct node *g[ALPHABET_SIZE];
    ll end;
  };
  struct node *init(void)
  {
    struct node *nd = new node;
    nd->end = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
      nd->g[i] = NULL;
    return nd;
  }

  void insert(struct node *root, ss s)
  {
    struct node *nd = root;
    ll n = s.length();
    fo(i, n)
    {
      ll in = s[i] - 'a';
      if (!nd->g[in])
        nd->g[in] = init();
      nd = nd->g[in];
    }
    nd->end = 1;
  } // O(n)

  ll search(struct node *root, ss s)
  {

    struct node *nd = root;
    ll n = s.length();
    fo(i, n)
    {
      ll in = s[i] - 'a';
      if (!nd->g[in])
        ret 0;
      nd = nd->g[in];
    }
    ret nd->end;
  } // O(n)
};

// binary lift init:
lvl[u] = lvl[v] + 1;
up[u][0] = v;
for (int i = 1; i <= logn; ++i)
  up[u][i] = up[up[u][i - 1]][i - 1];
// centroidDecomposition:
ll vis_c[N], sz_c[N], par_c[N];
ll find_size(ll v, ll gpar)
{

  if (vis_c[v])
    return 0;
  sz_c[v] = 1;
  fat(to, g[v])
  {
    if (to != gpar)
    {
      sz_c[v] += find_size(to, v);
    }
  }
  return sz_c[v];
}

ll find_centroid(ll v, ll gpar, ll szz)
{

  fat(to, g[v])
  {
    if (to != gpar && !vis_c[to] && sz_c[to] > szz / 2)
    {
      return find_centroid(to, v, szz);
    }
  }
  return v;
}

void init_centroid(ll v, ll gpar)
{

  ll sz = find_size(v, 0);
  ll c = find_centroid(v, 0, sz);
  vis_c[c] = 1;
  par_c[c] = gpar;

  fat(to, g[c])
  {
    if (!vis_c[to])
    {
      init_centroid(to, c);
    }
  }
}

// sieve fun:
vector<ll> sieve(ll N)
{
  vector<ll> isPrime(N + 1, 1), hp(N + 1), lp(N + 1), primes, Divisors[N + 1];
  isPrime[0] = isPrime[1] = 0;
  fo(i, N + 1)
  {
    if (isPrime[i])
    {
      primes.pb(i);
      fost(j, 2 * i, N + 1, i)
      {
        Divisors[j].pb(i); // gives prime divisors, another variation gives all the divisors if isPrime check is removed
        // in a similar way, you can also save exponents!
        isPrime[j] = 0;
        hp[j] = i;
        if (!lp[j])
          lp[j] = i;
      }
    }
  }
  return primes;
}
// sieve simple:
ll N;
vector<ll> isPrime(N + 1, 1), primes;
forb(i, 2, N + 1)
{
  if (isPrime[i])
  {
    primes.pb(i);
    fost(j, 2 * i, N + 1, i)
    {
      isPrime[j] = 0;
    }
  }
}
// factorisation for queries:

// use set for unique prime factors in ret vector!!
//  lp contains least prime factors from sieve
vector<ll> FactorizationforQueries(ll x, vll lp)
{
  vector<ll> ret;
  while (x != 1)
  {
    ret.push_back(lp[x]);
    x = x / lp[x];
  }
  return ret;
}

// binpow:
ll binPow(ll a, ll b, ll m)
{
  a %= m;
  ll ans = 1;
  while (b != 0)
  {
    if (b & 1)
      ans = (ans * a) % m;
    a = (a * a) % m;
    b = b >> 1;
  } // O(log2(k))
  return ans;
}
/*For very large Expo, use b=b%(M-1),where M is a prime number and a^b%M is req*/
ll modInverse(ll n, ll M)
{
  ret binPow(n, M - 2, M);
}

// ncr usual:
ll nCr(ll n, ll r, ll M)
{
  if (r < 0 || n < 0)
    ret 0;
  if (r > n)
    ret 0;
  ll ans = fact[n];
  ans = binMul(ans, modInverse(fact[n - r], M - 2, M), M);
  ans = binMul(ans, modInverse(fact[r], M - 2, M), M);
  return ans;
}
// ncr fermat:
long long C(ll n, ll r,ll M)
{
  if (r > n)
 ret 0;
  if (r > n - r)
    r = n - r;
  long long ans = 1;
  int i;

  for (i = 1; i <= r; i++)
  {
    ans *= (n - r + i)%M;
    ans *=binPow(i,M-2,M);
  }
  return ans;
}
// binmul:

ll binMul(ll n, ll k,ll m)
{
  ll ans = 0;
  while (k != 0)
  {
    if (k & 1)
      ans= (ans+n)%m;
    n =(n<<1)%m;
    k = k >> 1;
  } // O(log2(k))
  return ans;
}
/*modInverse: binPow(n,M-2,M)*/
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

typedef long double ld;
typedef string ss;
typedef vector<long long> vll;
typedef stack<ll> skll;
typedef pair<char, int> pci;
typedef pair<ll, int> pll;
typedef map<ll, ll> mll;
typedef map<char, ll> mcl;
#define pb push_back
#define all(v) v.begin(), v.end()
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define fost(i, a, b, d) for (ll i = a; i < b; i += d)
#define ofst(i, a, b, d) for (ll i = a; i > b; i -= d)
#define forb(i, a, b) for (int i = a; i < b; i++)
#define fon(i, a, b) for (int i = a; i >= b; i--)
#define fo(i, n) for (int i = 0; i < n; i++)
#define itmp(mp) for (auto it = mp.begin(); it != mp.end(); it++)

/*-----------------------------printfs----------------------------*/
void parr(ll a[], ll n)
{
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}
void pvec(vector<ll> v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
/*----------------------------printfs----------------------------*/

/*---------------------------------- NUMBER THEORY---------------------------*/
vector<ll> sieve(ll n)
{
  vector<ll> isPrime(n + 1, 1), hp(n + 1), lp(n + 1), Divisors[n + 1];

  fo(i, n + 1)
  {
    if (isPrime[i])
    {
      fost(j, i, n + 1, i)
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
  return isPrime;
} // O(nlog(log(n)))

ll gcd(ll a, ll b)
{
  ll r = b % a;
  if (r == 0)
    return a;
  else
    return gcd(r, a);
}

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

/*
For very large Expo, use b=b%(M-1),
where M is a prime number and a^b%M is req
*/

ll binMul(ll n, ll k)
{
  ll ans = 0;
  while (k != 0)
  {
    if (k & 1)
      ans += n;
    n += n;
    k = k >> 1;
  } // O(log2(k))
  return ans;
}

vll getAllDivisors(ll n)
{
  vll v;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      v.pb(i);
      if (n / i != i)
        v.pb(n / i);
    }
  }
  sort(all(v));
  return v;
}

vll getPrimeDivs(ll n)
{
  vll v;
  ll z = n;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      v.pb(i);
      while (n % i == 0)
        n /= i;
    }
  }
  if (n > 1)
    v.pb(n);
  return v;
}

bool isPrime(ll n)
{
  if (n != 1)
  {
    ll t = 0;
    for (int i = 2; i * i <= n; i++)
    {
      if (n % i == 0)
      {
        t++;
        break;
      }
    }
    return !t;
  }
  else
    return false;
}

long long nCr(int n, int r)
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
    cout << setprecision(30);
    map<ll, ll> focr, mp;
    ll n, m, l, sum = 0, r, min = 0, max = 0, ans = 0, f = 0, t = 0;
    ll q;
    cin >> n >> q;
    ll *a = new ll[n];
    ll k[n];
    ll pref[n];
    vll v;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      v.pb(a[i]);
    }
    sort(all(v));
    pref[0] = a[0];
    fo(i, n)
    {
      if (i != 0)
        pref[i] = pref[i - 1] + a[i];
    }
    fo(i,n){
if(focr[a[i]]==0){
  focr[a[i]] = i + 1;
}
    }
    max = a[0];
    ll maxi = 1;
    ll mm = v[n - 1];
    min = focr[v[n - 1]];
    mp[v[n - 1]] = focr[v[n - 1]];
    for (int i = n - 1; i >= 0; i--)
    {
      if(v[i]<=mm)
{    
      min = min(min, focr[v[i]]);
    mp[v[i]] = min;
      mm = v[i];
      // cout << v[i] << endl;
}
    }
    // fo(i, n)
    //         cout
    //     << mp[a[i]] << endl;
    max = *max_element(a, a + n);
    min = *min_element(a, a + n);
    while (q--)
    {
      ll k;
      cin >> k;
      if (k >= max)
        cout << pref[n - 1] << " ";
        else if(k<min){
          cout << 0 << " ";
        }
      else
      {
        ll z = *upper_bound(all(v), k);
        if(mp[z]==1)
          cout << 0 << " ";
          else
        cout << pref[mp[z] - 2] << " ";
        // cout << mp[z] << endl;
      }
    }
    cout << endl;
    delete[] a;
  }
  return 0;
}

/*
1. you can't use fo(v.size()-1), it'll give seg fault!

2. Don't forget to sort arrays b2b after modifying them while applying Binary Search!

3. Always be cautious of '1 and 2' in Number theory Ques.

4. Always treat your edge cases distinctly, never try to indulge them in usual loops!

5. Always check back and forth for equality cases!
*/
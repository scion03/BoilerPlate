#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

typedef long double ld;
typedef string ss;
typedef vector<long long> vll;
typedef stack<ll> skll;
typedef pair<char, ll> pci;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
typedef map<char, ll> mcl;
#define pb push_back
#define pr make_pair
#define nl endl
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
void db(ll a)
{
  cout << a << endl;
}
void db(ss a)
{
  cout << a << endl;
}
void db(char a)
{
  cout << a << endl;
}
void db(int a)
{
  cout << a << endl;
}
void db(bool a)
{
  cout << a << endl;
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
    map<ll, ll> cnt, mp;
    long long n, m, l, k, r, ans = 0, f = 0, t = 0;
    ll a, b;
    // cin >> a >> b;
    a = ttt;
    b = a + 4;
    cout << (a ^ b) <<" "<<a*b<< nl;
  }
  return 0;
}

/*
1. Don't forget to sort arrays b2b after modifying them while applying Binary Search!

2. Always be cautious of '1 and 2' in Number theory Ques.

3. Always treat your edge cases distinctly, never try to indulge them in usual loops!

4. Always check back and forth for equality cases!
*/
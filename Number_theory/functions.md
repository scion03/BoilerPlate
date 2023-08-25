#1

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

#2
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

#3
vector<ll> sieve(ll n)
{
  vector<ll> isPrime(n + 1, 1), hp(n + 1), lp(n + 1), Divisors[n + 1];
  isPrime[0] = isPrime[1] = 0;
  fo(i, n + 1)
  {
    if (isPrime[i])
    {
      fost(j, 2*i, n + 1, i)
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

#4


ll binMul(ll n, ll k,ll m)
{
  ll ans = 0;
  while (k != 0)
  {
    if (k & 1)
      ans= (ans+n)%m;
    n =(2*n)%m;
    k = k >> 1;
  } // O(log2(k))
  return ans;
}
//modInverse: binPow(n,M-2,M) 

#5
long long nCrFermat(int n, int r,int M)
{
  if (r > n - r)
    r = n - r;
  long long ans = 1;
  int i;

  for (i = 1; i <= r; i++)
  {
    ans *= (n - r + i)%M;
    ans *=BinPow(i,M-2,M);
  }
  return ans;
}

#6 GCD_extended:

ll gcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
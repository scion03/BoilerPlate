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
const ll mod = 998244353;
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
/*-------
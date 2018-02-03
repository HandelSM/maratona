/*input
5
0 0
1 1
2 2
1 0
0 1
*/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define PRINT(x...) TRACE(printf(x))
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define FU(i, a, b) for (auto i = a; i < b; ++i)
#define fu(i, b) FU(i, 0, b)
#define FD(i, a, b) for (auto i = (b) - 1; i >= a; --i)
#define fd(i, b) FD(i, 0, b)
#define pb push_back
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vd = vector<long double>;
using vb = vector<bool>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll mod(ll a, ll b) {
  return ((a%b)+b)%b;
}

const long double EPS = 1e-8;

int cmp(long double x, long double y = 0, long double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
  long double x, y;
  explicit point(long double x = 0, long double y = 0): x(x), y(y) {}

  // Only type in the operators you actually need
  point operator +(point q) const { return point(x + q.x, y + q.y); }
  point operator -(point q) const { return point(x - q.x, y - q.y); }
  point operator *(long double t) const { return point(x * t, y * t); }
  point operator /(long double t) const { return point(x / t, y / t); }
  // dot product
  long double operator *(point q) const { return x * q.x + y * q.y; }
  // "cross" product (actually "signed area of the quadrilateral"
  long double operator %(point q) const { return x * q.y - y * q.x; }
  // uses "cmp" from the template
  int cmp(point q) const {
    if (int t = ::cmp(x, q.x)) return t;
    return ::cmp(y, q.y);
  }
  bool operator ==(point q) const { return cmp(q) == 0; }
  bool operator !=(point q) const { return cmp(q) != 0; }
  bool operator < (point q) const { return cmp(q) <  0; }

  friend ostream& operator <<(ostream& o, point p) {
    return o << "(" << p.x << ", " << p.y << ")";
  }

  static point pivot; // only needed for convex hull
};

point point::pivot; // only needed for convex hull

long double norm(point p){ return sqrt(p * p); }
long double arg(point p) { return atan2(p.y, p.x); }

typedef vector<point> polygon;

// decides type of turn pqr. 1 if left, -1 if right, 0 if straight
inline int ccw(point p, point q, point r) {
  return cmp((p - r) % (q - r));
}

// angle of turn pqr
inline long double angle(point p, point q, point r) {
  point u = p - q, v = r - q;
  return atan2(u % v, u * v);
}

////////////////////////////////////////////////////////////////////////////////
// Is q inside [p,r]? (all segments are closed)
//

bool between(point p, point q, point r) {
  return ccw(p, q, r) == 0 && cmp((p - q) * (r - q)) <= 0;
}

////////////////////////////////////////////////////////////////////////////////
// Do segments [p,q] and [r,s] have an intersection?
//

bool seg_intersect(point p, point q, point r, point s) {
  point A = q - p, B = s - r, C = r - p, D = s - q;
  int a = cmp(A % C) + 2 * cmp(A % D);
  int b = cmp(B % C) + 2 * cmp(B % D);
  if (a == 3 || a == -3 || b == 3 || b == -3) return false;
  if (a || b || p == r || p == s || q == r || q == s) return true;
  int t = (p < r) + (p < s) + (q < r) + (q < s);
  return t != 0 && t != 4;
}

////////////////////////////////////////////////////////////////////////////////
// Distance from r to [p,q]
//

long double seg_distance(point p, point q, point r) {
  point A = r - q, B = r - p, C = q - p;
  long double a = A * A, b = B * B, c = C * C;
  if (cmp(b, a + c) >= 0) return sqrt(a);
  else if (cmp(a, b + c) >= 0) return sqrt(b);
  else return fabs(A % B) / sqrt(c);
}

////////////////////////////////////////////////////////////////////////////////
// Classifies p with respect of polygon T (not necessarily convex)
//
// Returns -1 if on border, 0 if outside, 1 if inside
//

int in_poly(point p, polygon& T) {
  long double a = 0; int N = T.size();
  for (int i = 0; i < N; i++) {
    if (between(T[i], p, T[(i+1) % N])) return -1;
    a += angle(T[i], p, T[(i+1) % N]);
  }
  return cmp(a) != 0;
}
////////////////////////////////////////////////////////////////////////////////
// Convex Hull! O(nlogn), *alters the input T*
//

bool radial_lt(point p, point q) {
  point P = p - point::pivot, Q = q - point::pivot;
  long double R = P % Q;
  if (cmp(R)) return R > 0;
  return cmp(P * P, Q * Q) < 0;
}

polygon convex_hull(vector<point>& T) {
  int j = 0, k, n = T.size(); polygon U(n);

  point::pivot = *min_element(all(T));
  sort(all(T), radial_lt);
  // If colinear points are part of hull, insert next two lines
  //for (k = n-2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k--);
  //reverse((k+1) + all(T));

  for (int i = 0; i < n; i++) {
    // If colinear points are part, change >= to >
    while (j > 1 && ccw(U[j-1], U[j-2], T[i]) >= 0) j--;
    U[j++] = T[i];
  }
  U.erase(j + all(U));
  return U;
}

////////////////////////////////////////////////////////////////////////////////
// Computes the (oriented) area of T. Positive if counterclockwise
//
long double poly_area(const polygon& T) {
  long double s = 0; int n = T.size();
  for (int i = 0; i < n; i++)
    s += T[i] % T[(i+1) % n];
  return s / 2;
}

map<point, int> mapa;

int main(){
	int n;
	scanf("%d", &n);
	vector<point> pts;
	fu(i,n){
		int a, b;
		scanf("%d %d", &a, &b);
		pts.pb(point(a,b));
		mapa[point(a,b)] = i+1;
	}
	polygon ch = convex_hull(pts);
	int tam = (int) ch.size();
	printf("%d\n", tam);
	fu(i,tam-1){
		printf("%d ", mapa[ch[i]]);
	}
	printf("%d\n", mapa[ch[tam-1]]);
	long double perimeter = 0.0;
	fu(i,tam){
		perimeter += norm(ch[i] - ch[(i+1)%tam]);
	}
	cout<<setprecision(15)<<perimeter<<endl;
	cout<<setprecision(25)<<poly_area(ch)<<endl;
	return 0;
}

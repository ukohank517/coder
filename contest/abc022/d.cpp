#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>

#define MOD 1000000007
#define ll long long
#define ld long double

using namespace std;

struct ConvexHull {

  struct Point {
    double x,y;
    Point () {}
    Point (double _x, double _y) : x(_x), y(_y) {}
    bool operator < (const Point &a) const {
      return (x == a.x) ? (y < a.y) : (x < a.x);
    }
  };

  double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
  double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
  double norm(Point a) { return sqrt(dot(a, a) * dot(a, a)); }
  Point sub(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }

  vector< Point > Pos;
  vector< Point > CHPos;

  int counter_clockwise(Point p0, Point p1, Point p2) {
    Point a = sub(p1, p0);
    Point b = sub(p2, p0);
    if (cross(a,b) > 1.0e-8) return 1;
    if (cross(a,b) < -1.0e-8) return -1;
    if (dot(a,b) < -1.0e-8) return 2;
    if (norm(a) < norm(b)) return 2;
    return 0;
  }

  void add_point(double x, double y) {
    Pos.push_back(Point(x, y));
  }

  void build() {
    int n = (int) Pos.size(), k = 0;
    sort(Pos.begin(),Pos.end());
    vector< Point > ch(2 * n);
    for (int i = 0; i < n; ch[k++] = Pos[i++]) {
      while (k >= 2 && counter_clockwise(ch[k-2], ch[k-1], Pos[i]) <= 0) --k;
    }
    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = Pos[i--]) {
      while (k >= t && counter_clockwise(ch[k-2], ch[k-1], Pos[i]) <= 0) --k;
    }
    copy(ch.begin(), ch.begin() + k - 1, back_inserter(CHPos));
  }

  double diameter() {
    int n = (int) CHPos.size();
    int is = 0, js = 0;
    for (int i = 1; i < n; i++) {
      if (CHPos[i].y > CHPos[is].y) is = i;
      if (CHPos[i].y < CHPos[js].y) js = i;
    }
    double maxd = norm(sub(CHPos[is], CHPos[js]));
    int i = is, maxi = is;
    int j = js, maxj = js;
    do{
      if (cross(sub(CHPos[(i + 1) % n], CHPos[i]), sub(CHPos[(j + 1) % n], CHPos[j])) >= 0) {
	j = (j + 1) % n;
      } else {
	i = (i + 1) % n;
      }
      if(norm(sub(CHPos[i], CHPos[j])) > maxd) {
	maxd = norm(sub(CHPos[i], CHPos[j]));
	maxi = i, maxj = j;
      }
    } while (i != is || j != js);
    return sqrt(maxd);
  }

  int size() {
    return (int) CHPos.size();
  }

  Point operator [] (int n) {
    return CHPos[n];
  }

};



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  vector<ll> Ax,Ay,Bx,By;

  cin >> N;
  for(ll i =0;i<N;i++){
    ll inx, iny;
    cin >> inx >> iny;
    Ax.push_back(inx);
    Ay.push_back(iny);
  }
  for(ll i =0;i< N;i++){
    ll inx, iny;
    cin >> inx >> iny;
    Bx.push_back(inx);
    By.push_back(iny);
  }

  ConvexHull A;
  ConvexHull B;

  for(ll i = 0;i<N;i++){
    A.add_point(Ax[i],Ay[i]);
    B.add_point(Bx[i],By[i]);
  }
  A.build();
  B.build();
  cout << fixed ;
  cout << setprecision(10) << B.diameter()/A.diameter() << endl;
  return 0;
}

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <complex> // complex<double> a(1.2 , 2.3);// real(): 1.2, imag()2.3
using namespace std;

#define MOD 1000000007
#define ll long long
#define ld long double
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rmsame(a) sort(all(a)),a.erase(unique(all(a)), a.end())
#define rmvector(a,b) rep(i,a.size())rep(j,b.size())if(a[i]==b[j]){a.erase(a.begin()+i);i--;break;}
#define first_more_idx(ve, num) upper_bound(all(ve), num)-ve.begin() // idx = first_more_idx(ve,num); if(idx = ve.size()) , then not exist
#define first_lessequal_idx(ve, num) lower_bound(all(ve), num)-ve.begin()
#define pq_pair_tB priority_queue <pair<ll,ll>, vector<pair<ll,ll> > , greater<pair<ll,ll> > >
#define pq_pair_ts priority_queue <pair<ll,ll> > // only sort first param
template<typename X> bool exist(vector<X> vec, X item){return find(all(vec), item)!=vec.end();}
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
ll power(ll x, ll n){if(n == 0) return 1;return  (n%2)? x*power(x, n-1)%MOD : power(x*x%MOD, n/2);}

ll N;
ld s, g;


// ※
// -1  -0.5  0  0.5   1
//  ＼   \   |   /   ／
ld slope(pair<ld, ld> from, pair<ld,ld> to){
    //return (to.second - from.second) / (to.first - from.first);
    return (to.first- from.first)/ (to.second - from.second);
}

vector<pair<ld, ld> > Pl, Pr;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N ;

    cin >> s >> g;

    rep(i, N + 1){
        ld l, r;
        cin >> l >> r ;
        if(i == 0){
            l = s,
            r = s;
        }
        if(i == N){
            l = g,
            r = g;
        }
        Pl.pb(mp(l,i));
        Pr.pb(mp(r,i));
    }

    vector<pair<ld,ld> > l, r;
    l.pb(Pl[0]), r.pb(Pr[0]);
    ll idx = 1;


    for(int i = 1; i <= N ; i ++){

        // in the left side
        while(l.size() > idx){
            //      + Pl[i]
            //   + pre
            //       + prepre
            pair<ld,ld> pre = l[l.size() - 1];
            pair<ld,ld> prepre = l[l.size() - 2];
            if(slope(pre, Pl[i]) > slope(prepre, pre)){
                l.pop_back();
            }else{
                break;
            }
        }
        // in the right side
        while(r.size() > idx){
            //  + Pr[i];
            //        +
            //   + Pl[i]
            pair<ld,ld> pre = r[r.size() - 1];
            pair<ld,ld> prepre = r[r.size() - 2];
            if(slope(pre, Pr[i]) < slope(prepre, pre)){
                r.pop_back();
            }else{
                break;
            }
        }

        l.pb(Pl[i]), r.pb(Pr[i]);

        while((l.size() == idx + 1) and slope(l[idx-1], l[idx]) > slope(r[idx-1], r[idx]) ){
            l.pop_back();
            l.pb(r[idx]);
            l.pb(Pl[i]);
            idx ++;
        }
        while((r.size() == idx + 1) and slope(l[idx-1], l[idx]) > slope(r[idx-1], r[idx]) ){
            r.pop_back();
            r.pb(l[idx]);
            r.pb(Pr[i]);
            idx ++;
        }
    }

    ld ans1 = 0;
    ld ans2 = 0;

    rep(i, l.size() - 1){
        ld x = l[i + 1].first - l[i].first;
        ld y = l[i + 1].second - l[i].second;
        ans1 += sqrt(x * x + y * y);
    }
    rep(i, r.size() - 1){
        ld x = r[i + 1].first - r[i].first;
        ld y = r[i + 1].second - r[i].second;
        ans2 += sqrt(x * x + y * y);
    }



    cout << fixed << setprecision(16) << min(ans1, ans2) << endl;
    return 0;
}

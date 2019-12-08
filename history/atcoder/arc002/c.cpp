#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <complex> // complex<double> a(1.2 , 2.3);// real(): 1.2, imag()2.3
using namespace std;

#define MOD 1000000007
#define EPS 1e-10
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
ll dx[]={0, 0, -1, 1};
ll dy[]={1, -1, 0, 0};// up,down,left right

ll cal(string inp, string X, string Y){
    
    // cal first char;
    ll ans1 = 0 ;
    rep(i, inp.size()){
        if(i == inp.size() -1) {
            ans1 ++;
            continue;
        }
        string now ;
        now += inp[i];
        now += inp[i+1];
        if(now == X or now == Y){
            i ++;
        }
        ans1 ++;
    }
    return ans1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N; cin >> N;
    string inp; cin >> inp;
    string ch = "ABXY";
    
    vector<string> temp;
    rep(i, ch.size()){
        rep(j, ch.size()){
            string now  = "";
            now += ch[i];
            now += ch[j];
            temp.pb(now);
        }
    }
    
    rmsame(temp);
    
    ll ans = inp.size();
    rep(i, temp.size()){
        rep(j, temp.size()){
            ans = min(ans, cal(inp, temp[i], temp[j]));
        }

    }
    cout << ans << endl;
    
    //cout << fixed << setprecision(16) << ans << endl;
    return 0;
}

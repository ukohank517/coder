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

string chess[8];
ll aim[8];
ll queen_cnt = 0;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    rep(i, 8){aim[i] = -1;}
    
    rep(i, 8){
        cin >> chess[i];
        rep(j, 8){
            if(chess[i][j] == 'Q'){
                aim[i] = j ;
                queen_cnt ++;
            }
        }
    }

    cerr << "###############" << endl;
    
    vector<ll> ans;
    rep(i, 8) ans.pb(i);
    
    
    do{
        // 初期配置のQの一致チェック
        ll tem_cnt = 0;
        rep(i, 8){if(ans[i] == aim[i]) tem_cnt ++;}
        if(tem_cnt != queen_cnt) continue;
        
        // Qの互い牽制をチェック（縦横は既にチェック済み）
        bool check = true;
        map<ll, bool> a,b;
        
        rep(i, 8){
            ll j = ans[i];
            if(a[i + j]){
                check = false;
                break;
            }
            if(b[i - j]) {
                check = false;
                break;
            }
            a[i+j] = true;
            b[i-j] = true;
        }
        if(check){
            rep(i, 8){
                ll j = ans[i];
                chess[i][j] = 'Q';
                cout << chess[i] << endl;
            }
            
            rep(i, 8){
                ll j = ans[i];
                cerr << "[" <<  i + j << "]";
            }
            cerr << endl;
            rep(i, 8){
                ll j = ans[i];
                cerr << "[" <<  i - j << "]";
            }
            cerr << endl;
            return 0;
        }
        
    }while(next_permutation(all(ans)));
    
    cout << "No Answer" << endl;

    //cout << fixed << setprecision(16) << ans << endl;
    return 0;
}

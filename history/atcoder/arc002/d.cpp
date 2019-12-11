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

typedef struct board {
    char ch;
    ll cnt;
} BOARD;

ll  H, W;
BOARD B[2000][2000];
ll x_score = 0;
ll o_score = 0;


bool func(pair<ll,ll> a, pair<ll,ll> b){
    return (a.first + a.second) > (b.first + b.second);
}

void inp(){
    cin >> H >> W;
    
    rep(i, H){
        string inp;
        cin >> inp;
        
        rep(j, inp.size()){
            B[i][j].ch = inp[j];
            B[i][j].cnt = 1;
        }
    }
    
}

pair<bool, char> count_till_end(){
    pair<bool, char> ans = mp(false, '.');
    // till side
    ll x_toleft = 2123;
    ll o_toright = 2123;
    rep(i, H){
        rep(j, W){
            if(B[i][j].ch != '.'){
                if(B[i][j].ch == 'x') x_toleft = min(x_toleft, j);
                break;
            }
        }
        
        rep(k, W){
            ll j = W - 1 - k;
            if(B[i][j].ch != '.'){
                if(B[i][j].ch == 'o') o_toright = min(o_toright, k);
                break;
            }
        }
    }
    
    if(min(x_toleft, o_toright) < 2123){
        cerr << "till side" << endl;
        ans.first = true;
        if(o_toright <= x_toleft) ans.second = 'o';
        else ans.second = 'x';
    }
    
    return ans;
    
}



void compress(){
    // compress
    char before_ch = '-';
    ll before_idx = -1;
    ll before_cnt = 1;
    
    
    rep(i, H){
        // first compress o
        before_ch = '-';
        before_idx = -1;
        before_cnt = 1;
        rep(j, W){
            if(B[i][j].ch != '.'){
                if(before_ch == 'o' and B[i][j].ch == 'o'){
                    o_score += before_cnt * (j - before_idx - 1);
                    B[i][before_idx].ch = '.';
                    B[i][j].cnt = before_cnt + 1;
                    
                    before_cnt ++;
                    before_idx = j;
                }else{
                    before_idx = j;
                    before_ch = B[i][j].ch;
                    before_cnt = 1;
                }
            }
        }
        
        // then compress x
        before_ch = '-';
        before_idx = W;
        before_cnt = 1;
        
        rep(k, W){
            ll j = W - 1 - k;
            if(B[i][j].ch != '.'){
                if(before_ch == 'x' and B[i][j].ch == 'x'){
                    x_score += before_cnt * (before_idx - 1 - j);
                    B[i][before_idx].ch = '.';
                    B[i][j].cnt = before_cnt + 1;
                    
                    before_cnt ++;
                    before_idx = j;
                }else{
                    before_idx = j ;
                    before_ch = B[i][j].ch;
                    before_cnt = 1;
                }
            }
        }
    }
}

void calscore(){
    // score
    char before_ch = '-';
    ll before_idx = -1;
    vector<pair<ll,ll> > score;
    
    rep(i, H){
        rep(j, W){
            char ch = B[i][j].ch;
            if( B[i][j].ch != '.'){
                
                if(before_ch == 'o' and ch == 'x'){
                    ll dist = (j - before_idx - 2);
                    if(dist % 2){
                        score.pb(mp(B[i][before_idx].cnt,B[i][j].cnt));
                        dist --;
                    }
                    
                    rep(k, dist/2){
                        o_score+=(B[i][before_idx].cnt);
                        x_score+=(B[i][j].cnt);
                    }
                }
                
                before_ch = ch;
                before_idx = j;
                
            }
        }
    }
    
    sort(all(score), func);
    
    rep(i, score.size()){
        if(i % 2 == 0) o_score += score[i].first;
        else x_score += score[i].second;
    }
    
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    
    
    inp();
    
    pair<bool, char> tillans = count_till_end();
    if(tillans.first){
        cout << tillans.second << endl;
        return 0;
    }
    
    compress();
    calscore();
    
    cerr << "o score :: x score" << endl;
    cerr << o_score << "    " << x_score << endl;
    if(o_score > x_score){
        cout << "o" << endl;
    }else {
        cout << "x" << endl;
    }
    
    
    //cout << fixed << setprecision(16) << ans << endl;
    return 0;
}






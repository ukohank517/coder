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

class Solution {
public:
    int minFlips(vector<vector<int> >& mat) {
        int siz = mat.size() * mat[0].size();

        int ans = 100;
        rep(i, 1 << siz){
            vector<int>  tr;
            rep(j, siz){
                if(i & (1 << j))tr.pb(j);
            }
            
            if(calculation(mat, tr)){
                ans = min(ans, (int)tr.size());
            }
        }
        
        if(ans == 100) return -1;
        else return ans;
    }
    
    bool calculation(vector<vector<int> > mat, vector<int> op){

        
        rep(k, op.size()){
            int i = op[k] / mat[0].size();
            int j = op[k] % mat[0].size();
            
            if((i - 1) >= 0) mat[i-1][j] = swt(mat[i-1][j]);
            if((i + 1) < mat.size()) mat[i + 1][j] = swt(mat[i+1][j]);
            
            if((j - 1) >= 0) mat[i][j-1] = swt(mat[i][j-1]);
            if((j + 1) < mat[0].size()) mat[i][j+1] = swt(mat[i][j+1]);
            
            mat[i][j] = swt(mat[i][j]);
        }
        

        
        rep(i, mat.size()){
            rep(j, mat[i].size()){
                if(mat[i][j] != 0) return false;
            }
        }
        
        return true;
    }
    
    int swt(int a){
        if(a == 0) return 1;
        else return 0;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    

    
    vector<vector<int> > tmp;
    vector<int> t1, t2;
    t1.pb(0), t1.pb(0);
    t2.pb(0), t2.pb(1);
    tmp.pb(t1), tmp.pb(t2);
    
    
    
    cout << Solution().minFlips(tmp) << endl;
    
    
    

    //cout << fixed << setprecision(16) << ans << endl;
    return 0;
}

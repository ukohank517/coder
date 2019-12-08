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
private:
    vector<int> n;
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        rep(i, nums.size()) n.pb(nums[i]);
        
        int l = 0;
        int r = 1000005;
        
        
        while((l + 1) < r){
            int m = (l + r) / 2;
            int res = cal(m);
            
            if(res <= threshold) r = m;
            else l = m;
        }
        
        return r;
    }
    
    ll cal(int number){
        ll ans  = 0 ;
        rep(i, n.size()){
            ans += (n[i]/number);
            if(n[i] % number != 0) ans ++;
        }
        
        return ans;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    vector<int> a = {962551,933661,905225,923035,990560};

    
    cout << Solution().smallestDivisor(a, 10) << "::" << 4495280<< endl;
    

    //cout << fixed << setprecision(16) << ans << endl;
    return 0;
}

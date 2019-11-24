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

class Solution {
private:
    ll dp[555][555];// dp[step][now]
public:
    int numWays(int steps, int arrLen) {
        arrLen = min(steps, arrLen);
        
        dp[0][1] = 1;
        
        for(int i = 1; i <= steps; i++){
            for(int j = 1; j <= arrLen; j++){
                if((j-i) == 1) {
                    dp[i][j] = 1; // 戻るのみ
                }else if( (j-i) > 1){
                    dp[i][j] = 0; //戻っても間に合わない
                }else {
                    dp[i][j] = dp[i-1][j];// stay
                    if((j - 1) >= 1) dp[i][j] += dp[i-1][j-1]; // left
                    if((j + 1) <= arrLen) dp[i][j] += dp[i-1][j+1]; // right
                }
                dp[i][j] %= MOD;
            }
        }

        return dp[steps][1];
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cout << Solution().numWays(2, 2) << "::" << 2 << endl;

    cout << Solution().numWays(3, 2) << "::" << 4 << endl;
    cout << Solution().numWays(2, 2) << "::" << 2 << endl;
    cout << Solution().numWays(4, 2) << "::" << 8 << endl;
    cout << Solution().numWays(499, 300) << "::" << 8 << endl;


    //cout << fixed << setprecision(16) << ans << endl;
    return 0;
}

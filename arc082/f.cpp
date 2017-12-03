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

vector<ll> r(100000);//反転時間の個数、最大10^5個
vector<ll> t(100000);//問われる時間を保存する配列 指定するクエリ個数、
vector<ll> init(100000);//初期に砂入ってる量を保存する配列 指定するクエリと同じ個数


//reference : http://arc082.contest.atcoder.jp/submissions/1565659

void solve(){
  ll x,n;//砂の量の最大量,反転回数
  cin >> x >> n;
  rep(i,n)cin >> r[i];

  ll tt;
  cin >> tt;//クエリの数
  rep(i,tt){ cin >> t[i] >> init[i];}


  ll a = 0;
  ll val_a = 0;//一番小さい値
  ll b = x;
  ll val_b = x;//一番大きい値
  ll dir = -1;//現在は増えるのか減るのか
  ll ptr = 0; //クエリの番号

  rep(i,n+1){//反転回数がiのあとの動作
    while(ptr < tt && (i==n || t[ptr] <= r[i])){//クエリが残ってある、クエリに問われる時間が次の反転時間以下のとき
      ll now = -1;
      //＿／￣の3区間に分類
      if(init[ptr] <= a) now = val_a;//＿の部分
      else if(b<=init[ptr]) now = val_b; //￣の部分
      else now = val_a+(init[ptr]-a);  //／の部分で、a<init[ptr]<b
    

      now +=(t[ptr]-(i==0 ? 0:r[i-1]))*dir;//時間*増減方向*(1val/s)
      now = max(now,(ll)0);//負なら0
      now = min(now,x);//最大値超えらたx
      cout << now << endl;

      ptr++;
    }
  
    //反転r[i]の処理
    if(i<n){
      int pass = r[i]-(i==0?0:r[i-1]);//経過した時間
      //dir:減るか増えるか
      //dir*pass = この空間の増減量
      val_a += dir*pass;
      val_b += dir*pass;

      if(val_b < 0){//全てが0
	a = 0;
	val_a =0;
	b = 0;
	val_b = 0;
      }
      else if(x<val_a){//全てが最大
	a = 0;
	val_a = x;
	b = 0;
	val_b = x;
      }else {//[a,b]の更新
	if(val_a<0){
	  a-=val_a;//aを右にずらす
	  val_a=0;
	}
	if(x<val_b){
	  //val_b-x分、上限xを超えている。
	  //b-=超えた分をずらす
	  b-=val_b-x;//bを左にずらす
	  val_b=x;
	}
	//a,bの変更がない場合val_a,val_bは既に経過時間分変更してある。
      }
      dir = -dir;//増減を回転
    }
  }
  cout << flush;
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  solve();
  
  return 0;
}

#include<iostream>
using namespace std;

#define mod 1000000007
#define ll long long int


#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)

int R,C,X,Y,D,L;
ll nr[901][901]={0};

void set(int n){
  nr[0][0]=1;
  for(int i = 1;i<=n;i++){
    nr[i][0]=1;
    for(int j =1;j<=i;j++){
      nr[i][j]=nr[i-1][j-1]+nr[i-1][j];
      nr[i][j]%=mod;
    }
  }
}

ll nCr(int n, int r){
  set(n);
  if(n<0||r<0||n<r) return 0;
  else return nr[n][r];
}


void solve_equal(){
  ll result;
  
  result = (R-X+1)*(C-Y+1)*nCr(X*Y,D);
  result = result % mod;
  
  cout << result << endl;
}

ll calc(int n, int r, int times){
  ll result;

  result = times * nCr(n*r,D) * nCr(n*r-D,L);
  result %= mod;
  return result;
}
void solve_not_equal(){
  ll result;
  ll sub0,sub1,sub2,sub3,sub4;

  sub0=calc(X,Y,1);
  sub1=calc(X-1,Y,2)+calc(X,Y-1,2);
  sub2=calc(X-1,Y-1,4)+calc(X-2,Y,1)+calc(X,Y-2,1);
  sub3=calc(X-2,Y-1,2)+calc(X-1,Y-2,2);
  sub4=calc(X-2,Y-2,1);
  
  result = sub0-sub1+sub2-sub3+sub4;
  result %= mod;
  result = result*(R-X+1)*(C-Y+1);
  result %= mod;
  if(result<0) result += mod;
  cout << result << endl;
}


int main(){

  cin >> R >> C >> X >> Y >> D >> L ;

  if((D+L)==(X*Y)) solve_equal();
  if((D+L)!=(X*Y)) solve_not_equal();
  return 0;
}

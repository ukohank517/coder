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

//多くても4文字が答え
int main(){
  string A;
  int a[26] ={0};
  int b[676]={0};
  int c[17576] ={0};
  int d[456976] ={0};
  
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> A;

  for(ll i =0;i<A.size();i++){
    a[A[i]-'a']=1;//0~25
  }
  for(ll i =0;i<26;i++){
    if(a[i]==0) {
      cout << (char)('a'+i) << endl;
      return 0;
    }
  }

  for(ll i =1;i<A.size();i++){
    int s1=A[i-1]-'a';
    int s2=A[i]-'a';
    b[s1*26+s2]=1;
  }
  for(ll i =0;i<26*26;i++){
    if(b[i]==0){
      int s1 = i/26;
      int s2 = i%26;
      cout << (char)('a'+s1) << (char)('a'+s2) << endl;
      return 0;
    }
  }

  for(ll i =2;i<A.size();i++){
    int s1=A[i-2]-'a';
    int s2=A[i-1]-'a';
    int s3=A[i]-'a';
    b[s1*26*26+s2*26+s3]=1;
  }
  for(ll i =0;i<26*26*26;i++){
    if(b[i]==0){
      char s1 = 'a'+i/26;
      i%=26;
      char s2 = 'a'+i/26;
      i%=26;
      char s3 = 'a'+i/26;
      cout << s3 << s2 << s1 << endl;
      return 0;
    }
  }

    for(ll i =3;i<A.size();i++){
    int s1=A[i-3]-'a';
    int s2=A[i-2]-'a';
    int s3=A[i-1]-'a';
    int s3=A[i]-'a';
    b[s1*26*26*26+s2*26*26+s1*26]=1;
  }
  for(ll i =0;i<26*26*26;i++){
    if(b[i]==0){
      char s1 = 'a'+i/26;
      i%=26;
      char s2 = 'a'+i/26;
      i%=26;
      char s3 = 'a'+i/26;
      cout << s3 << s2 << s1 << endl;
      return 0;
    }
  }

  
  return 0;
}

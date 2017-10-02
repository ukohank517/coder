#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

#define MOD 1000000007
#define ll long long

using namespace std;

ll N,M;// N人 , Mスポーツ
ll A[301][301]={0};   //A[人][スポーツ]
vector<ll> choice(1,0);
ll people[301]={0};//実施するそれぞれのスポーツに集まる人数
vector<ll> result; //それぞれの場合の最大参加人数


void ope(){
  ll ninki,ninzu=0;
  
  //実施するスポーツよりそれぞれのスポーツに参加する人数を計算
  for(ll i = 0;i<301;i++) people[i] =0;//参加人数更新

  for(ll i =1;i<= N;i++){
    for (ll j = 1;j<= 301;j++){
      vector<ll>::iterator cIter = find(choice.begin(),choice.end(),A[i][j]);
      if(cIter != choice.end() ){
	people[A[i][j]]++;
	break;
      }
   
    }
  }
  
  //一番人気なスポーツの参加人数をresultに保存
  for(ll i =0;i<301;i++){
    if(people[i]>ninzu){
      ninzu = people[i];
      ninki = i;//一番人気なスポーツ
    }
  }
  result.push_back(ninzu);
  
  //一番人気なスポーツを消去し、M--
  //この時choice.size() = M+1は絶対
  for(ll i =0;i<choice.size();i++){
    if(choice[i]==ninki){
      swap(choice[i], choice[M]);
      choice.pop_back();
      break;
    }
  }
  M--;
}

int main(){
  
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  for(ll i =1;i<=N;i++){
    for(ll j =1; j<=M ;j++){
      cin >> A[i][j];
    }
  }

  for(ll i =1;i<=M;i++){
    choice.push_back(i);
  }

  do{
    ope();
  }while(M>1);

  sort(result.begin(),result.end());

  cout << result[0] <<endl;
  return 0;
}

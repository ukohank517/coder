#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long int
using namespace std;

struct b_array {
  int num;
  int times;
  b_array(int a, int b):num(a),times(b){}
};

int N,K;
vector<b_array> b_arrays;

int main(){
  int a,b;
  
  cin >> N >> K;
  
  for(int i=0;i<N;i++){
    cin >> a >> b;
    b_arrays.emplace_back(a,b);
  }
  sort(b_arrays.begin(),b_arrays.end(),
       [](const b_array& x, const b_array& y){return x.num<y.num;});

  for(b_array sample : b_arrays){
    K-=sample.times;
    if(K<=0) {
      cout << sample.num << endl;
      break;
    }
  }
  
  return 0;
  
}

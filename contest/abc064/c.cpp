#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(){
  int inp;
  int rate[9]={0,0,0,0,0,0,0,0,0};
  int min=0;
  
  cin >> N;
  for(int i =0;i<N;i++){
    cin >> inp;
    if((inp>=1)&&(inp<=399))rate[0]=1;
    else if((inp>=400)&&(inp<=799))rate[1]=1;
    else if((inp>=800)&&(inp<=1199))rate[2]=1;
    else if((inp>=1200)&&(inp<=1599))rate[3]=1;
    else if((inp>=1600)&&(inp<=1999))rate[4]=1;
    else if((inp>=2000)&&(inp<=2399))rate[5]=1;
    else if((inp>=2400)&&(inp<=2799))rate[6]=1;
    else if((inp>=2800)&&(inp<=3199))rate[7]=1;
    else rate[8]+=1;;
    
  }

  for(int i =0;i<8;i++){
    min+=rate[i];
  }
  if (min==0){cout << "1 " << min+rate[8]<<endl;}

  else{cout << min <<" "<<min+rate[8]<<endl;}
  
  return 0;
}

#include <iostream>
#include <string>
using namespace std;

double kakudo[]={-1,11.25, 33.75, 56.25, 78.75, 101.25, 123.75, 146.25, 168.75, 191.25, 213.75, 236.25, 258.75, 281.25, 303.75,326.25, 348.75,3600.0};
string houkaku[]={"N","NNE","NE","ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW","NW", "NNW","N"};

double furyoku[]={-0.1,0.2,1.5,3.3,5.4,7.9,10.7,13.8,17.1,20.7,24.4,28.4,32.6,200};


int main(){

  double deg,dis;
  int Dis,amari;
  int i,j;
  
  cin >> deg >> Dis;

  deg/=10.0;

  Dis=Dis*100/60;
  amari=Dis%10;
  Dis/=10;
  Dis*=10;
  dis=(double)Dis/100.0;
  if(amari>=5) dis += 0.1;

  
  for(i = 0; i < sizeof(kakudo)/sizeof(double)-1;i++){
    if((deg >= kakudo[i])&& (deg<kakudo[i+1])) {
      break;
    }
  }

  for(j = 0;j < sizeof(furyoku)/sizeof(double)-1; j++){
    if((dis > furyoku[j]) && (dis<=furyoku[j+1])) break;      
  }

  if (j==0) cout << "C 0" << endl;
  else cout << houkaku[i] <<" "<< j << endl;
  return 0;
}



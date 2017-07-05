#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <char> s;
int main(){
  char inp;
  int left=0;
  int count=0;

  cin >> n;
  for(int i =0;i<n;i++){
    cin >> inp;
    s.push_back(inp);
  }

  for(int i =0;i<n+count;i++){
    if(s[i]=='(') left++;
    else{
      if(left!=0){left--;}
      else{
	s.insert(s.begin(),'(');
	count++;
	i++;
      }
    }
  }
  
  for(int i=0;i<left;i++){
    s.insert(s.end(),')');
    count++;
  }
  
  for(int i=0;i<n+count;i++){cout << s[i];}
  cout << endl;
  return 0;
}

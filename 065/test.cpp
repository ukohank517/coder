#include <iostream>
#include <vector>
#define ll long long
using namespace std;


int vector_finder(vector<int> vec, int number) {
  auto itr = find(vec.begin(), vec.end(), number);
  size_t index = distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}
int main(){
  vector<int> v_list;
  v_list.push_back(100);
  v_list.push_back(200);
  v_list.push_back(300);
  cout << vector_finder(v_list,400) << endl;
  return 0;
}

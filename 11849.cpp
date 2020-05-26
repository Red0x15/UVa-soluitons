#include <iostream>
#include <map>
using namespace std;

int main(){
  int jackCD, jillCD, conj;
  string catalog;
  scanf("%d %d", &jackCD, &jillCD);
  map<string, int>:: iterator it;
  while (jackCD != 0 && jillCD != 0) {
    conj = 0;
    jackCD += jillCD;
    map<string, int> jj;
    while (jackCD--) {
      cin >> catalog;
      jj[catalog]++;
    }
    for (it = jj.begin(); it != jj.end(); it++) {
      if (it->second > 1){
        conj++;
      }
    }
    printf("%d\n", conj);
    scanf("%d %d", &jackCD, &jillCD);
  }
  return 0;
}

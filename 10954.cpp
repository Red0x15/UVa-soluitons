#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void place(list<int> &set, int num){
  list<int>::iterator act = set.begin();
  while (act != set.end() && num >= *act) {
    act++;
  }
  set.insert(act, num);
}

int main(){
  int i;
  int n, sum, aux, *auxSet;
  long int cost;
  list<int> set;
  list<int>::iterator par1, par2;
  scanf("%d", &n);
  while (n) {
    auxSet = new int[n];
    cost = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", (auxSet + i));
    }
    std::sort(auxSet, auxSet + n);
    for (i = n - 1; i > -1; i--) {
      set.push_front(auxSet[i]);
    }
    while (set.size() > 1) {
      par1 = set.begin();
      par2 = set.begin(); par2++;
        cost += (*par1) + (*par2);
        place(set, (*par1) + (*par2));
        set.pop_front();
        set.pop_front();
    }
    printf("%ld\n", cost);
    set.clear();
    scanf("%d", &n);
  }
  return 0;
}

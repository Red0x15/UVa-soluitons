#include <iostream>
using namespace std;

int main(){
  int cases, store, job, *arr, i;
  scanf("%d", &cases);
  while (cases--) {
    scanf("%d %d", &store, &job);
    arr = new int[store];
    for (i = 0; i < store; i++) {
      scanf("%d", (arr + i));
    }
  }
}

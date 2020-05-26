#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
  int cases, depth, nBall, firstLeaf, jumper, i;
  bool *fbt;
  scanf("%d", &cases);
  while (cases --) {
    scanf("%d", &depth);
    scanf("%d", &nBall);
    fbt = new bool[(int)(pow(2, depth) -1)];
    firstLeaf = (int)pow(2, depth -1);
    nBall = nBall % ((int)pow(2, depth) - firstLeaf + 1);
    for (i = 0; i < nBall; i++) {
      jumper = 1;
      while(jumper < firstLeaf){
        if(fbt[jumper - 1]){
          fbt[jumper - 1] = false;
          jumper = (jumper * 2) + 1;
        }
        else{
          fbt[jumper - 1] = true;
          jumper *= 2;
        }
      }
    }
    cout << jumper << endl;
  }
  scanf("%d", &depth);
  return 0;
}

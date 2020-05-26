#include <iostream>
#include <vector>

using namespace std;

int main(){
  int cases, j, pos;
  string instruc;
  scanf("%d", &cases);
  for (int i = 0; i < cases; i++) {
    vector<int> led(100);
    cin >> instruc;
    pos = 0;
    for (j = 0; j < instruc.size(); j++) {
      switch (instruc[j]) {
        case '>':
          if (pos == 99){
            pos = 0;
          }
          else{
            pos++;
          }
          break;
        case '<':
          if (pos == 0){
            pos = 99;
          }
          else{
            pos--;
          }
          break;
        case '+':
          if (led[pos] == 255){
            led[pos] = 0;
          }
          else{
            led[pos]++;
          }
          break;
        case '-':
          if (led[pos] == 0){
            led[pos] = 255;
          }
          else{
            led[pos]--;
          }
          break;
        default:
          break;
      }
    }
    cout << "Case " << dec << i + 1 << ":";
    for (j = 0; j < 100; j++) {
      cout << " ";
      if (led[j] < 16){
        cout << "0";
      }
      cout << uppercase << hex << led[j];
    }
    cout << endl;
  }
  return 0;
}

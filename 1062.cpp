#include <iostream>
#include <list>
#include <stack>
using namespace std;

int main(){
  string charge;
  int i, cases = 1;
  cin >> charge;
  while (charge != "end") {
    list<stack<char>> port;
    for (i = 0; charge[i]; i++) {
      list<stack<char>>::iterator it = port.begin();
      while (it != port.end() && (it->top() < charge[i])) {
        it++;
      }
      if (it == port.end()){
        stack<char> *n_st = new stack<char>;
        n_st->push(charge[i]);
        port.push_back(*n_st);
        // port[port.size() - 1].push(charge[i]);
      }
      else{
        it->push(charge[i]);
      }
    }
    cout << "Case " << cases  << ": " << port.size() << endl;
    cases++;
    cin >> charge;
  }
  return 0;
}

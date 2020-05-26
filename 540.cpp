#include <iostream>
#include <map>
#include <list>
using namespace std;

int main(){
  int t, tl, aux;
  string command;
  cout << "Teams: ";
  scanf("%d", &t);
  while (t != 0) {
    map<int,int> teams;
    while (t > 0) {
      cout << "Team len: ";
      scanf("%d", &tl);
      while (tl--) {
        cout << "Item: ";
        scanf("%d", &aux);
        teams[aux] = t;
      }
      t--;
    }
    list<int> que;
    list<int>::iterator it;
    int i;

    cout << "COMMANDS!!" << endl;
    cin >> command;
    while (command != "STOP") {
      if(command == "ENQUEUE"){
        scanf("%d", &aux);
        if (team[aux]){
          for (i = 1, it = que.begin(); i < que.size() ; i++) {
            buscador
          }
        }
      }
      else if (command == "DEQUEUE"){

      }
      cin >> command;
    }
    scanf("%d", &t);
  }
}

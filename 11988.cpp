#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main(){
  char lstP, lstC, txt[100002];
  while(scanf("%s", txt) != EOF){
    queue<char> Aque;
    queue<char> Bque;
    queue<char> *act;
    queue<char> *aux;
    act = &Aque;
    if (txt[strlen(txt) - 1] != ']'){
      txt[strlen(txt) + 1] = '\0';
      txt[strlen(txt)] = ']';
    }
    for (int i = 0; i < strlen(txt); i++) {
      if (txt[i] == '[' || txt[i] == ']'){
        if (txt[i] == '[' && lstP != '[' && lstC != '['){
          act == &Aque?act = &Bque: act = &Aque;
          lstP = txt[i];
        }
        else if (txt[i] == ']' || (txt[i] == '[' && lstP == '[' && lstC != '[')){
          act == &Aque?aux = &Bque: aux = &Aque;
          lstP = txt[i];
          while (!aux->empty()) {
            act->push(aux->front());
            aux->pop();
          }
          if (txt[i] == '[' && lstP == '[' && lstC != '['){
            act == &Aque?act = &Bque: act = &Aque;
          }
        }
    }
      else{
        lstC = txt[i];
        act->push(txt[i]);
      }
    }
    while (!act->empty()) {
      cout << act->front();
      act->pop();
    }
    cout << endl;
  }
  return 0;
}

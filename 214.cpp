#include <iostream>
#include <vector>

using namespace std;

class Memory{
public:
  bool loaded;
  int nStorages;
  vector<bool> storages;
  Memory(){
    loaded = false;
    nStorages = 0;
    storages = *new vector<bool>;
  }
  void load(){
    loaded = true;
  }
  void unLoad(){
    loaded = false;
  }
  void store(bool type){
    if(type)
      nStorages++;
    cout << " $" << nStorages;
    storages.push_back(type);
    nStorages++;
  }
  void unStore(){
    nStorages--;
    storages.pop_back();
  }
};

int main(){
  int i;
  string posfix;
  while (getline(cin, posfix)) {
    Memory mem;
    i = 0;
    if (posfix.size() == 1){
      cout << "L " << posfix << endl;
      i = 1;
    }
    while (i < posfix.size()) {
      if ((i + 2 < posfix.size()) && posfix[i] >= 'A' && posfix[i] <= 'Z'
      && posfix[i + 1] >= 'A' && posfix[i + 1] <= 'Z'
      && ((posfix[i + 2] >= 'A' && posfix[i + 2] <= 'Z') || posfix[i + 2] == '@')){
        cout << "L " << posfix[i] << endl;
        cout << "ST";
        mem.store(false); cout << endl;
      }
      else if ((i + 2 < posfix.size()) && posfix[i] >= 'A' && posfix[i] <= 'Z'
      && posfix[i + 1] >= 'A' && posfix[i + 1] <= 'Z'){
        mem.load();
        cout << "L " << posfix[i] << endl;
      }
      else if (posfix[i] >= 'A' && !mem.loaded){
        switch (posfix[i]) {
          case '+':
          cout << "A ";
          break;
          case '-':
          cout << "S ";
          break;
          case '*':
          cout << "M ";
          break;
          case '/':
          cout << "D ";
          break;
        }
        cout << posfix[i - 1] << endl;
      }
      else if (posfix[i] <= 'A' && mem.loaded){
        if (posfix[i] == '@'){
          cout << "L " << posfix[i - 1] << endl;
          cout << "N" << endl;
        }
        else{
          switch (posfix[i]) {
            case '+':
            cout << "A ";
            break;
            case '-':
            cout << "S ";
            break;
            case '*':
            cout << "M ";
            break;
            case '/':
            cout << "D ";
            break;
          }
          cout << posfix[i - 1] << endl;
        }
        mem.unLoad();
      }
      else if (posfix[i] <= 'A' && !mem.loaded){
        switch (posfix[i]) {
          case '+':
          cout << "A ";
          break;
          case '@':
          cout << "N" << endl;
          break;
          case '-':
          cout << "N\nA ";
          break;
          case '*':
          cout << "M ";
          break;
          case '/':
          cout << "D ";
          break;
        }
        cout << "$" << mem.nStorages << endl;
        mem.unStore();
      }
      i++;
    }
    cout << endl;
  }
  return 0;
}

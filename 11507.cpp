#include <iostream>

using namespace std;

class Wire{
  int direction;
public:
  Wire(){
    direction = 1;
  }
  void twist(int order){
    switch (direction) {
      case 1:
        if (order != 2)
          direction = order;
        break;
      case 2:
        switch (order) {
          case 1:
          case 2:
            break;
          case 3:
            direction = 4;
            break;
          case 4:
            direction = 3;
            break;
          case 5:
            direction = 6;
            break;
          case 6:
            direction = 5;
            break;
          default:
            break;
        }
        break;
      case 3:
        switch (order) {
          case 1:
          case 2:
            break;
          case 3:
            direction = 2;
            break;
          case 4:
            direction = 1;
            break;
          case 5:
            direction = 3;
            break;
          case 6:
            direction = 3;
            break;
          default:
            break;
          }
        break;
      case 4:
        switch (order) {
          case 1:
          case 2:
            break;
          case 3:
            direction = 1;
            break;
          case 4:
            direction = 2;
            break;
          case 5:
            direction = 4;
            break;
          case 6:
            direction = 4;
            break;
          default:
            break;
          }
        break;
      case 5:
        switch (order) {
          case 1:
          case 2:
            break;
          case 3:
            direction = 5;
            break;
          case 4:
            direction = 5;
            break;
          case 5:
            direction = 2;
            break;
          case 6:
            direction = 1;
            break;
          default:
            break;
          }
        break;
      case 6:
        switch (order) {
          case 1:
          case 2:
            break;
          case 3:
            direction = 6;
            break;
          case 4:
            direction = 6;
            break;
          case 5:
            direction = 1;
            break;
          case 6:
            direction = 2;
            break;
          default:
            break;
          }
        break;
      default:
        break;
    }
  }
  void infoDirection(){
    switch (direction) {
      case 1:
        cout << "+x";
        break;
      case 2:
        cout << "-x";
        break;
      case 3:
        cout << "+y";
        break;
      case 4:
        cout << "-y";
        break;
      case 5:
        cout << "+z";
        break;
      case 6:
        cout << "-z";
        break;
      default:
      break;
    }
  }
};


int main(){
  int len;
  string order;

  scanf("%d", &len);
  while (len) {
    len--;
    Wire myWire;
    while (len--) {
      cin >> order;
      if (order == "+x")
        myWire.twist(1);
      else if (order == "-x")
        myWire.twist(2);
      else if (order == "+y")
        myWire.twist(3);
      else if (order == "-y")
        myWire.twist(4);
      else if (order == "+z")
        myWire.twist(5);
      else if (order == "-z")
        myWire.twist(6);
    }
    myWire.infoDirection(); cout << endl;
    scanf("%d", &len);
  }
  return 0;
}

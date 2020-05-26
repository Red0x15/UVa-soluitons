#include <iostream>
#include <vector>

using namespace std;

class Square{
  bool lockedState;
  int visits;
public:
  Square(bool n_state){
    lockedState = n_state;
    lockedState? visits = -1 : visits = 0;
  }


  void touch(){
    if (lockedState){
      fprintf(stderr, "Visit to a locked Square\n");
    }
    visits++;
  }

  bool getLockedState(){return lockedState;}


  int getVisits(){return visits;}
};


struct maze{
  int rows;
  int cols;
  vector<vector<Square>> squares;
};typedef struct maze Maze;


class Dungeon{
  Maze *myMaze;
  int posy;
  int posx;
  int direction;
  int starty;
  int startx;

  bool possibleRight(){
    switch (direction) {
      case 0:
        if((posx < myMaze->cols - 1) && !(myMaze->squares[posy][posx + 1].getLockedState())){
          return true;
        }
        else{
          return false;
        }
        break;
      case 1:
        if((posy < myMaze->rows - 1) && !(myMaze->squares[posy + 1][posx].getLockedState())){
          return true;
        }
        else{
          return false;
        }
        break;
      case 2:
        if(posx > 0 && !(myMaze->squares[posy][posx - 1].getLockedState())){
          return true;
        }
        else{
          return false;
        }
        break;
      case 3:
        if(posy > 0 && !(myMaze->squares[posy - 1][posx].getLockedState())){
          return true;
        }
        else{
          return false;
        }
        break;
      default:
        break;
    }
  }


  bool possibleForward(){
    switch (direction) {
      case 0:
        if(posy > 0 && !(myMaze->squares[posy - 1][posx].getLockedState())){
          return true;
        }
        else{
          return false;
        }
        break;
      case 1:
        if((posx < myMaze->cols - 1) && !(myMaze->squares[posy][posx + 1].getLockedState())){
          return true;
        }
        else{
          return false;
        }
      case 2:
        if((posy < myMaze->rows - 1) && !(myMaze->squares[posy + 1][posx].getLockedState())){
          return true;
        }
        else{
          return false;
        }
        break;
      case 3:
        if(posx > 0 && !(myMaze->squares[posy][posx - 1].getLockedState())){
          return true;
        }
        else{
          return false;
        }
        break;
      default:
        break;
    }
  }


  void turnRight(){
    direction == 3? direction = 0: direction++;
  }


  void turnLeft(){
    direction == 0? direction = 3: direction--;
  }


  void forward(){
    switch (direction) {
      case 0:
        posy--;
        break;
      case 1:
        posx++;
        break;
      case 2:
        posy++;
        break;
      case 3:
        posx--;
        break;
      default:
        break;
    }
    myMaze->squares[posy][posx].touch();
  }

public:
  Dungeon(Maze *n_Maze){
    myMaze = n_Maze;
    direction = 1;
    starty = myMaze->rows - 1;
    startx = 0;
    posy = starty;
    posx = startx;
  }


  void move(){
    if(possibleRight()){
      turnRight();
      forward();
    }
    else if (possibleForward()){
      forward();
    }
    else{
      turnLeft();
    }
  }


  bool finished(){
    if (myMaze->squares[posy][posx].getVisits() == 1 && posy == starty && posx == startx){
      return true;
    }
    else{
      return false;
    }
  }


  void answer(){
    int times[5] = {0};
    for (int i = 0; i < myMaze->rows; i++) {
      for (int j = 0; j < myMaze->cols; j++) {
        if(!myMaze->squares[i][j].getLockedState()){
          times[myMaze->squares[i][j].getVisits()]++;
        }
      }
    }
    for (int i = 0; i < 5; i++) {
      if (times[i] < 100)
        cout << ' ';
      if (times[i] < 10)
        cout << ' ';
      cout << times[i];
    }
  }
};


int main(){
  int i, j, lock;
  int dimy, dimx;
  string locks;
  scanf("%d %d", &dimy, &dimx);
  while (dimy != 0 && dimx != 0) {
    vector<vector<Square>> base(dimy);
    for (i = 0; i < dimy; i++) {
      cin >> locks;
      vector<Square> base2;
      for (j = 0; j < dimx; j++) {
        base2.push_back(*new Square(locks[j] - '0'));
      }
      base[i] = base2;
    }
    Maze mazeBase{dimy, dimx, base};
    Dungeon myDungeon(&mazeBase);
    while (!myDungeon.finished()) {
      myDungeon.move();
    }
    myDungeon.answer(); cout << endl;
    scanf("%d %d", &dimy, &dimx);
  }
  return 0;
}

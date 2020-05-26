#include <iostream>
#include <vector>

using namespace std;

struct maze{
  vector<string> dungeon;
  int rows;
  int cols;
};typedef struct maze Maze;


class Runner{
  int posy;
  int posx;
  int direction;
  Maze *myMaze;
public:
  Runner(int n_posy, int n_posx, Maze *n_maze, int n_direction = 0){
    direction = n_direction;
    posy = n_posy - 1;
    posx = n_posx - 1;
    myMaze = n_maze;
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
        if(posy > 0 && !(myMaze->dungeon[posy - 1][posx] != ' ')){
          posy--;
        }
        break;
      case 1:
        if(posx < myMaze->cols && !(myMaze->dungeon[posy][posx + 1] != ' ')){
          posx++;
        }
        break;
      case 2:
        if(posy < myMaze->rows && !(myMaze->dungeon[posy + 1][posx] != ' ')){
          posy++;
        }
        break;
      case 3:
        if(posx > 0 && !(myMaze->dungeon[posy][posx - 1] != ' ')){
          posx--;
        }
        break;
      default:
        break;
    }
  }


  void answer(){
    cout << posy + 1 << ' ' << posx + 1 << ' ';
    switch (direction) {
      case 0:
        cout << 'N';
        break;
      case 1:
        cout << 'E';
        break;
      case 2:
        cout << 'S';
        break;
      case 3:
        cout << 'W';
        break;
      default:
        break;
    }
  }
};


int main(){
  int cases, i, j;
  int dimy, dimx;
  int posy, posx;
  char oper, finisher;
  scanf("%d\n\n", &cases);
  while (cases--) {
    scanf("%d %d\n", &dimy, &dimx);
    vector<string> base(dimy);
    for (i = 0; i < dimy; i++) {
      getline(cin, base[i]);
    }
    scanf("%d %d\n", &posy, &posx);
    Maze n_maze{base, dimy, dimx};
    Runner run1(posy, posx, &n_maze);
    oper = getchar();
    while (oper != 'Q') {
      switch (oper) {
        case 'R':
          run1.turnRight();
          break;
        case 'L':
          run1.turnLeft();
          break;
        case 'F':
          run1.forward();
          break;
        default:
          break;
      }
      oper = getchar();
    }
    run1.answer(); cout << endl;
    getchar();
    if (cases)
      cout << endl;
  }
  return 0;
}

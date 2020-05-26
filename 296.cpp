#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct line{
  char num[5];
  int matches;
  int miss_matches;
};

class number{
  public:
    char val;
    vector<int> pos_pos;
    vector<int> non_pos;
    int position;

    number(char v){
      val = v;
    }

    bool operator ==(const class number &n2){
      return val == n2.val;
    }
};

int main(){
  int cases, lines, i, j;
  scanf("%d", &cases);
  vector<class number> my_numbers;
  vector<class number> non_posible;
  vector<class number>::iterator mn_it;
  while (cases--) {
    scanf("%d", &lines);
    vector<struct line> my_lines(lines);
    for (j = 0; j < lines; j++ ) {
      scanf("%s %d/%d", my_lines[j].num, my_lines[j].matches, my_lines[j].miss_matches);
      for (i = 0; i < 4; i++) {
        if(!binary_search(my_numbers.begin(), my_numbers.end(), number(my_lines[j].num[i]))){
          my_numbers.push_back(number(my_lines[j].num[i]));
        }
        if (my_lines[j].matches == 0){
          if (my_lines[j].miss_matches == 0){
            mn_it = find(non_posible.begin(), non_posible.end(), number(my_lines[j].num[i]));
            non_posible.push_back(my_lines[j].num[i]);
          }
          else{
            mn_it = find(my_numbers.begin(), my_numbers.end(), number(my_lines[j].num[i]));
            mn_it->pos_pos.push_back(i);
          }
        }
        else{
          
        }
      }
    }
  }
}

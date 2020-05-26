#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class person{
public:
  char name[17];
  int day;
  int month;
  int year;

  bool operator <(const person &p2) const{
    if (p2.year == year){
      if (p2.month == month){
        return p2.day < day;
      }
      return p2.month < month;
    }
    return p2.year < year;
  }
};

int main(){
  int people = 0, i = 0;
  scanf("%d", &people);
  vector<class person> class_room(people);
  while (i < people) {
    scanf("%s %d %d %d", class_room[i].name, &class_room[i].day, &class_room[i].month, &class_room[i].year);
    i++;
  }
  sort(class_room.begin(), class_room.end());
  printf("%s\n%s\n", class_room[0].name, class_room[people - 1].name);
  return 0;
}

#include <iostream>
#include <map>

using namespace std;

int main(){
  int people, gift, given, i, j;
  bool first = true;
  string giver, receiver, names[13];
  map<string, int> group;

  while (scanf("%d", &people) != EOF) {
    group.clear();
    if (!first) cout << endl;
    else first = false;
    for (i = 0; i < people; i++) {
      cin >> names[i];
    }
    for (i = 0; i < people; i++) {
      cin >> giver >> gift >> given;
      if (given)
        gift /= given;
      group[giver] -= gift * given;
      for (j = 0; j < given; j++) {
        cin >> receiver;
        group[receiver] += gift;
      }
    }
    for (i = 0; i < people; i++) {
      cout << names[i] << ' ' << group[names[i]] << endl;
    }
  }
  return 0;
}

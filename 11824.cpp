#include <iostream>
#include <vector>
#include <algorithm>

/*Nuestra solución al problema de UVa 11824 (A Minimum land of Price)
/*tiene una complejidad de O(n) ya que no tiene cíclos anidados pero
/*si cíclos que dependen de la entrada*/

using namespace std;

void my_pow(int &res, int ex){
  int base = res;
  res = 1;
  while (ex--) {
    res *= base;
  }
}

int main(){
  int cases, years, land, acum, i;
  bool out;
  vector<int> prices;
  vector<int>::iterator it;
  cin >> cases;
  while (cases--) {
    cin >> land;
    while (land) {
      prices.push_back(land);
      cin >> land;
    }
    sort(prices.begin(), prices.end());
    reverse(prices.begin(), prices.end());
    i = 0;
    acum = 0;
    out = false;
    for (it = prices.begin(); it != prices.end(); it++) {
      i++;
      my_pow(*it, i);
      acum += (*it) * 2;
      if (acum > 4999999){
        out = true;
        break;
      }
    }
    if (out){
      cout << "Too expensive" << endl;
    }
    else{
      cout << acum << endl;
    }

    prices.clear();
  }
  return 0;
}

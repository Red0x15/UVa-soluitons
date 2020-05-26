#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

/*Nuestra solución para el problema 725 (Division)
/*tiene una complejidad de O(n²),ya que el máximo de cíclos anidaddos que se da
/* es 2, cuando se da un cíclo y una de las funciones que máximo tienen un cíclo*/

using namespace std;

bool repeted(int x){
  int len, i;
  string num;

  if(x < 10){
    len = 1;
  }
  else{
    len = ceil(log10(x));
  }
  for (i = 0; i < len; i++) {
    num += (x % 10) + '0';
    x /= 10;
  }
  reverse(&num[0], &num[len]);

  vector<char> can(len);
  for (i = 0; i < len; i++) {
    if(find(can.begin(), can.end(), num[i]) - can.end()){
      return 1;
    }
    can[i] = num[i];
  }
  return 0;
}


bool prov_0(int x){
  int len, i;
  string num;

  if(x < 10){
    len = 1;
  }
  else{
    len = ceil(log10(x));
  }
  for (i = 0; i < len; i++) {
    num += (x % 10) + '0';
    x /= 10;
  }
  if(find(&num[0], &num[len], '0') - &num[len]){
    return 1;
  }
  else{
    return 0;
  }
}


bool inter_rep(int div, int it){
  int len_d, len_it, i;

  if(div < 10){
    len_d = 1;
  }
  else{
    len_d = ceil(log10(div));
  }

  if(it < 10){
    len_it = 1;
  }
  else{
    len_it = ceil(log10(it));
  }

  vector<char> x(len_d);
  char y;

  for (i = 0; i < len_d; i++) {
    x[i] = (div % 10) + '0';
    div /= 10;
  }

  for (i = 0; i < len_it; i++) {
    y = (it % 10) + '0';
    if(find(x.begin(), x.end(), y) - x.end()){
      return 1;
    }
    it /= 10;
  }
  return 0;
}


int main(){
  int query, div,
   num = 1234, l_num = 98765,
   tope, sol;

  vector<int> not_repeated;
  vector<int>::iterator it;


  while (num < l_num) {
    while (repeted(num) && num < l_num) {
      num++;
    }
    not_repeated.push_back(num);
    num++;
  }

  cin >> query;
  while (query != 0) {
    if(query % 10 == 0 || (query % 11 == 0 && query % 2 != 0) || query > 68){
      cout << "There are no solutions for " << query << "." << endl;
    }
    else{
      sol = 0;
      (query < 5)?tope = 49876: tope = 30124;
      it = not_repeated.begin();
      while (it != not_repeated.end() && *it != tope) {
        div = query * (*it);
        if(ceil(log10(div)) > 4){

          if(binary_search(not_repeated.begin(), not_repeated.end(), div)){

            if(!inter_rep(div, *it)){

              if(ceil(log10(*it)) < 5){
                if(!prov_0(div) && !prov_0(*it)){
                  if(!sol)sol = 1;
                  cout << div << " / " << "0" << *it << " = " << query << endl;
                }
              }
              else{
                if(!sol)sol = 1;
                cout << div << " / " << *it << " = " << query << endl;
              }
            }
          }
        }
        it++;
      }
      if(!sol){
        cout << "There are no solutions for " << query << "." << endl;
      }
    }
    cin >> query;
    if(query)cout << endl;
  }
  return 0;
}

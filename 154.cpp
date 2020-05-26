#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

/*Nuestra solución para el problema 154 (Recycling)
/*tiene una complejidad de O(n²), pues llega máximo a tener 3 cíclos anidados
/*pero en este caso uno de los cíclos es constante*/

using namespace std;

struct max_city{
  int max;
  int city;
};

int main(){
  int acum, pos, cities = 0, i, j, k;
  char *ch;
  string line;
  string bins[5];
  struct max_city max;

  cin >> line;
  while (line != "#") {
    if(line[0] != 'e'){
      ch = find(&line[0], &line[line.size() - 1], 'r');
      pos = ch - &line[0];
      pos += 2;
      bins[0] += line[pos];

      ch = find(&line[0], &line[line.size() - 1], 'o');
      pos = ch - &line[0];
      pos += 2;
      bins[1] += line[pos];

      ch = find(&line[0], &line[line.size() - 1], 'y');
      pos = ch - &line[0];
      pos += 2;
      bins[2] += line[pos];

      ch = find(&line[0], &line[line.size() - 1], 'g');
      pos = ch - &line[0];
      pos += 2;
      bins[3] += line[pos];

      ch = find(&line[0], &line[line.size() - 1], 'b');
      pos = ch - &line[0];
      pos += 2;
      bins[4] += line[pos];

      cities++;
    }
    cin >> line;
    if(line[0] == 'e'){
      max.max = 0;
      max.city = 0;
      for (i = 0; i < cities; i++) {
        acum = 0;
        vector<char> vec;
        for (j = 0; j < 5; j++) {
          k = 0;
          while (bins[j][k]) {
            vec.push_back(bins[j][k]);
            k++;
          }
          acum += count(vec.begin(), vec.end(), vec[i]);
          vec.clear();
        }
        if(max.max < acum){
          max.max = acum;
          max.city = i;
        }
      }

      cout << max.city + 1 << endl;
      for (i = 0; i < 5; i++) {
        bins[i].clear();
      }
      cities = 0;
    }
  }
  return 0;
}

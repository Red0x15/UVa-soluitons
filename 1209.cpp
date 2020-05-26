#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

/*Nuestra solución para el problema 1209 (Wordfish)
/*tiene una complejidad de O(n²) ya que llega a tener máximo dos cíclos anidados
/*cuando hace las comparaciones entre las permutaciones de una palabra*/

using namespace std;

struct p_word{
  string word;
  int largest_min;
};

int main(){
  int i, j, k, min, max_min, w_count, cont;

  string word;
  string palabras[21];
  struct p_word procesed[21];
  vector<char> vec;

  while (cin >> word) {
    vec.clear();
    for (i = 0; i < 21; i++) {
      palabras[i].clear();
      procesed[i].word.clear();
    }
    max_min = 0;
    i = 0;
    while (word[i]) {
      vec.push_back(word[i]);
      i++;
    }

    i = 0;
    while (prev_permutation(vec.begin(), vec.end()) && i < 10)
    i++;

    cont = 0;
    i = 0;
    while (next_permutation(vec.begin(), vec.end()) && i < 21) {
      for (vector<char>::iterator it = vec.begin(); it != vec.end(); it++){
        palabras[i] += *it;
      }
      i++;
    }

    cont = i;
    if(cont != 0){
      i = 0;
      while (i < cont) {
        j = 0;
      	min = 30;
      	while(j < palabras[i].size() - 1){
      		k = j + 1;
      		if(min > abs(palabras[i][j] - palabras[i][k]))min = abs(palabras[i][j] - palabras[i][k]);
      		j++;
        }
        procesed[i].word = palabras[i];
        procesed[i].largest_min = min;
        i++;
      	if(max_min < min)max_min = min;
      }

      i = 0;
      w_count = 0;
      while (i < cont) {
        if(procesed[i].largest_min == max_min){
          palabras[w_count] = procesed[i].word;
          w_count++;
        }
        i++;
      }

      sort(palabras, palabras + w_count);
      cout << palabras[0] << max_min << endl;
    }
    else{
      cout << word << "1" << endl;
    }
    word.clear();
  }
  return 0;
}

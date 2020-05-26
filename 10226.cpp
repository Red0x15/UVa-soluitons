#include <iostream>
#include <map>
using namespace std;

int main(){
  int cases, n_trees, exception = 0;
  string tree;
  scanf("%d\n", &cases);
  while (cases--) {
    n_trees = 0;
    map<string, int> forest;
    getline(cin, tree);
    while (tree.size()) {
      n_trees++;
      forest[tree]++;
      getline(cin, tree);
    }
    for (map<string,int>::iterator it = forest.begin(); it != forest.end(); it++) {
      cout << it->first << ' ';
      printf("%.4f\n", ((float)it->second / (float)n_trees) * 100);
    }
    if (cases)cout << endl;
  }
  return 0;
}

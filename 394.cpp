#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct dimention{
  int low;
  int up;
};
typedef dimention Dimention;


class Space{
  int base;
  int b_size;
  int dim;
  vector<Dimention> bounds;
public:
  int *constants;
  Space(int n_base, int n_b_size, int n_dim, vector<Dimention> n_bounds){
    base = n_base;
    b_size = n_b_size;
    dim = n_dim;
    bounds = n_bounds;
    constants = new int[dim + 1];
    constants[dim] = b_size;
    for (int i = dim - 1; 0 < i; i--) {
      constants[i] = constants[i + 1] * (bounds[i].up - bounds[i].low + 1);
    }
    constants[0] = base;
    for (int i = 1; i < dim + 1; i++) {
      constants[0] -= (constants[i] * bounds[i - 1].low);
    }
  }
  int getDim(){
    return dim;
  }
};

int main(){
  int arrays, querys, j, ind, add;
  string t_name;
  int t_base, t_b_size, t_dim;
  int t_low, t_up;
  vector<Dimention> t_bounds;
  map<string, Space *> DataFile;

  scanf("%d %d", &arrays, &querys);
  for (int i = 0; i < arrays; i++) {
    t_bounds.clear();
    cin >> t_name >> t_base >> t_b_size >> t_dim;
    for (j = 0; j < t_dim; j++) {
      cin >> t_low >> t_up;
      t_bounds.push_back(*new Dimention{t_low, t_up});
    }
    DataFile[t_name] = new Space(t_base, t_b_size, t_dim, t_bounds);
  }
  for (int i = 0; i < querys; i++) {
    cin >> t_name;
    add = DataFile[t_name]->constants[0];
    cout << t_name << '[';
    for (j = 1; j < DataFile[t_name]->getDim() + 1; j++) {
      cin >> ind; cout << ind;
      if(j != DataFile[t_name]->getDim())
        cout << ", ";
      add += DataFile[t_name]->constants[j] * ind;
    }
    cout << "] = " << add << endl;
  }
  return 0;
}

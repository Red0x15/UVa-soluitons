#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstring>

/*Nuestra solución al problema 10698 tiene una complejidad
/*de O(n) ya que no presenta ciclos anidados pero si cíclos
/*que dependen de n*/

using namespace std;

class team{
  public:
    string name;
    int scored;
    int suffered;
    int points;
    int n_games;
    string percentage;
    int pos;

    team(){
      name = "";
      scored = 0;
      suffered = 0;
      points = 0;
      n_games = 0;
      percentage = "";
      pos = 0;
    };
    team(string n_name){
      name = n_name;
    }


    bool operator ==(const team &t2) const{
      return name == t2.name;
    }

    bool operator <(const team &t2) const{
      if (points == t2.points){
        if ((scored - suffered) == (t2.scored - t2.suffered)){
          if (scored == t2.scored){
            return strcasecmp(name.c_str(), t2.name.c_str()) < 0;
          }
          return (t2.scored < scored);
        }
        return (t2.scored - t2.suffered) < (scored - suffered);
      }
      return (t2.points < points);
    }
};


string true_itos(int x){
  int len;
  string ans;
  if (x == 1){
    return "1";
  }
  if (x == -1){
    return "-1";
  }
  if (x < 0){
    ans += "-";
    x = abs(x);
  }
  else if (!x){
    return "0";
  }
  len = ceil(log10(x));
  if (((double)len) == log10(x)){len++;}
  while (len--) {
    ans += (x % 10) + '0';
    x /= 10;
  }
  reverse(&ans[0], &ans[ans.size()]);
  return ans;
}


string itos(int per){
  int len;
  string ans;
  if (per == 1){
    return "0.01";
  }
  len = ceil(log10(per));
  if (((double)len) == log10(per)){len++;}
  while (len--) {
    ans += (per % 10) + '0';
    per /= 10;
  }
  reverse(&ans[0], &ans[ans.size()]);
  for (int i = ans.size(); i < 3; i++) {
    ans.insert(0, "0");
  }
  ans.insert(ans.size() - 2, ".");
  return ans;
}


int main(){
    int i;
    int t, g, g_home, g_visit, aux_per;
    int first = 0;
    string aux1, aux2;
    vector<team>::iterator home, visit;

    while (1) {
      cin >> t >> g;
      if (t == 0 && g == 0){
        break;
      }
      vector<team> table(t);
      for (i = 0; i < t; i++) {
        cin >> table[i].name;
      }

      for (i = 0; i < g; i++) {
        cin >> aux1;
        cin >> g_home;
        cin >> aux2;
        cin >> g_visit;
        cin >> aux2;

        home = find(table.begin(), table.end(), team(aux1));
        visit = find(table.begin(), table.end(), team(aux2));
        home->n_games += 1;
        visit->n_games += 1;

        home->scored += g_home;
        home->suffered += g_visit;

        visit->scored += g_visit;
        visit->suffered += g_home;

        if (g_home < g_visit){
          visit->points += 3;
        }
        else if (g_home > g_visit) {
          home->points += 3;
        }
        else{
          visit->points += 1;
          home->points += 1;
        }
      }

      for (home = table.begin(); home != table.end(); home++) {
        if (home->n_games){
          aux_per = (home->points * 10000) / (3 * home->n_games);
          if (aux_per == 0){
            home->percentage = "0.00";
          }
          else{
            home->percentage = itos(aux_per);
          }
        }
        else{
          home->percentage = "N/A";
        }
      }

      sort(table.begin(), table.end());

      if (first){
        cout << endl;
      }
      else{
        first = 1;
      }

      i = 1;
      home = table.begin();
      visit = table.begin();
      visit->pos = i;
      visit++;
      i++;
      while (visit != table.end()) {
        if (home->points != visit->points ||
          (home->scored - home->suffered) != (visit->scored - visit->suffered) ||
          home->scored != visit->scored){
          visit->pos = i;
        }
        i++;
        home++;
        visit++;
      }



      for (home = table.begin(); home != table.end(); home++) {
        if (home->pos){
          if (home->pos != 1){
            aux_per = ceil(log10(home->pos));
            if (((double)aux_per) == log10(home->pos)){aux_per++;}
          }
          else{
            aux_per = 1;
          }
          aux_per = 3 - aux_per;
          if(aux_per < 0)aux_per = 0;
        }
        else{
          aux_per = 4;
        }
        if (aux_per > 1){
          cout << ' ';
          aux_per--;
        }
        if (home->pos){
          cout << home->pos << ".";
        }
        while (aux_per--) {
          cout << ' ';
        }

        aux_per = 15 - home->name.size();
        if (aux_per < 0) aux_per = 0;

        while (aux_per--) {
          cout << ' ';
        }
        cout << home->name;

        aux1 = true_itos(home->points);
        aux_per = 4 - aux1.size();
        if (aux_per < 0) aux_per = 0;
        while (aux_per--) {
          cout << ' ';
        }
        cout << home->points;

        aux1 = true_itos(home->n_games);
        aux_per = 4 - aux1.size();
        if (aux_per < 0) aux_per = 0;
        while (aux_per--) {
          cout << ' ';
        }
        cout << home->n_games;

        aux1 = true_itos(home->scored);
        aux_per = 4 - aux1.size();
        if (aux_per < 0) aux_per = 0;
        while (aux_per--) {
          cout << ' ';
        }
        cout << home->scored;

        aux1 = true_itos(home->suffered);
        aux_per = 4 - aux1.size();
        if (aux_per < 0) aux_per = 0;
        while (aux_per--) {
          cout << ' ';
        }
        cout << home->suffered;

        aux1 = true_itos(home->scored - home->suffered);
        aux_per = 4 - aux1.size();
        if (aux_per < 0) aux_per = 0;
        while (aux_per--) {
          cout << ' ';
        }
        cout << home->scored - home->suffered;

        aux_per = 7 - home->percentage.size();
        if (aux_per < 0) aux_per = 0;
        while (aux_per--) {
          cout << ' ';
        }
        cout << home->percentage << endl;
      }

      table.clear();
    }
    return 0;
}

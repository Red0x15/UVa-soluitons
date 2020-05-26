#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct query{
  int qnum;
  int period;
};typedef query Query;

bool comparer(const Query q1, const Query q2){
  if (q1.period == q2.period){
    return q1.qnum < q2.qnum;
  }
  else
    return q1.period < q2.period;
}

int main(){
  string reg;
  int t_qnum, t_period;
  int k, j, max, nq = 0;
  vector<Query> queries;
  cin >> reg;
  while (reg != "#") {
    scanf("%d %d", &t_qnum, &t_period);
    queries.push_back(Query{t_qnum, t_period});
    nq++;
    cin >> reg;
  }
  scanf("%d", &k);
  sort(queries.begin(), queries.end(), comparer);
  max = k * queries.begin()->period;
  for (int i = 0; i < nq; i++) {
    j = 2;
    while (j <= k && (queries[i].period * j) <= max) {
      queries.push_back(Query{queries[i].qnum, queries[i].period * j});
      j++;
    }
  }
  sort(queries.begin(), queries.end(), comparer);
  j = 0;
  while (j < k) {
    printf("%d\n", queries[j].qnum);
    j++;
  }
  return 0;
}

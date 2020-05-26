#include <stdio.h>

int main(){
  long int query;
  while (scanf("%ld", &query) != EOF) {
    if(query == 2){
      query = 0;
    }
    else{
      query = (query + 1) / 2;
      query = 3 * ((2 * query * query) - 1) - 6;
    }
    printf("%ld\n", query);
  }
  return 0;
}

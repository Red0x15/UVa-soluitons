#include <stdio.h>
#include <stdlib.h>

/*Nuestra soluciín al problema 10487 de UVa tiene una complejidad de O(n^2).
Ya que en el analisis para hayar la suma más cercana a la búsqueda, dentro de
cada conjunto de números, se da un cíclo anidado.*/

int main(){
  int cases = 1, closest, n, nums[1000], m, query, i, j;
  while (scanf("%d", &n)) {
    if (n == 0) return 0;
    printf("Case %d:\n", cases);
    cases++;
    for (i = 0; i < n; i++) {
      scanf("%d", &nums[i]);
    }
    scanf("%d", &m);
    while (m-- > 0) {
      if(n == 1){
        closest = nums[0];
      }
      else{
        closest = nums[0]+ nums[1];
      }
      scanf("%d", &query);
      for (i = 0; i < (n - 1); i++) {
        for (j = i + 1; j < n; j++) {
          if(abs(nums[i] + nums[j] - query) < abs(closest - query))closest = abs(nums[i] + nums[j]);
        }
      }
      printf("Closest sum to %d is %d.\n", query, closest);
    }
  }
}

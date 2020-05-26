#include <stdio.h>
#include <math.h>

int main() {
    int cases, n;
    long int ans;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d", &n);
        if(n <= 0) {
          printf("0\n");
        }
        else{
          ans = 0;
          int j = 1, k = n, f, s;
          while(k){
            j = n/k;
            f = n/j;
            s = n/(j+1);
            ans += (long)j*(f-s);
            k -= f-s;
          }
          printf("%ld\n", ans);
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(){
    int h1, m1, h2, m2, ans;
    while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2) != EOF){
        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
          return 0;
        if((h1 == h2 && m1 > m2) ||(h2 < h1 && h2 == 0)){
          h2 += 23;
          m1 -= 60;
        }
        else if(h2 < h1){
          h2 = 24 - abs(h2 - h1);
          h1 = 0;
        }
        ans = (h2 - h1)*60 + (m2 - m1);
        printf("%d\n", ans);
    }
    return 0;
}

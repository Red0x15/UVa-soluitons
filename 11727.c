#include <stdio.h>

int main(){
    int cases, n1, n2, n3, mid;
    scanf("%d", &cases); cases = 0;
    while (scanf("%d %d %d", &n1, &n2, &n3) != EOF)
    {
        cases++;
        if (n1 < n2){
            if (n1 > n3){
                mid = n1;
            }
            else{
                if (n3 < n2){
                    mid = n3;
                }  
                else{
                    mid = n2;
                }
            }
        }
        else{
            if (n2 > n3){
                mid = n2;
            }
            else{
                if (n3 < n1){
                    mid = n3;
                }  
                else{
                    mid = n1;
                }
            }
        }
        printf("Case %d: %d\n", cases, mid);
    }
    return 0;
}
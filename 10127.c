#include <stdio.h>

int main(){
    long int query;
    int stop, lMod, measure, i;
    while (scanf("%ld", &query) != EOF){
        stop = 1; lMod = 1; measure = 10 % query; i = 1;
        while((stop % query)){
            lMod = (lMod * measure) % query;
            stop = (stop + lMod) % query;
            i++;
        }
        printf("%d\n", i);
    }
    return 0;
}
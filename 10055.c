#include <stdio.h>
#include <math.h>

int main(){
    double hash, enemies;
    while (scanf("%lf %lf", &hash, &enemies) != EOF)
    {
        printf("%.0lf\n", fabs(hash - enemies));
    }
    
    return 0;
}
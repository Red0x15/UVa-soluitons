#include <stdio.h>

int main()
{
    int cases, first, second;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d %d", &first, &second);
        if (first < second)
            printf("<\n");
        else if(first == second)
            printf("=\n");
        else
            printf(">\n");
    }
    printf("\n");
    return 0;
}

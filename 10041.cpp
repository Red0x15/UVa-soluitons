#include <iostream>

int main(){
    int cases, min, max, num;
    char ch;

    scanf("%d", &cases);
    while (cases--){
        min = 0; max = 0;
        scanf("%d", &num);
        ch = ' ';
        while (ch != '\n'){
            if (num < min)
                min = num;
            if (num > max)
                max = num;

            scanf("%d", &num);
            if (scanf("%c", &ch) == EOF)
                break;
        }
        printf("%d\n", (max - min));
    }
    return 0;
}
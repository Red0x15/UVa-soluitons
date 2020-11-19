/* UVa 12150 Pole Position */
#include <stdio.h>

void print_arr(int* arr, int n, int check){
    int i = 0;
    if(check){
        for(i; i < n-1; i++)
            printf("%d ", arr[i]);
        printf("%d\n", arr[i]);
    }
    else
        printf("-1\n");
}

void clean(int* arr, int n){
    int i = 0;
    while(i < n){
        arr[i] = 0;
        i++;
    }
}

int main(){
    int n, c, p, i, abs, pole[1000], check;
    scanf("%d", &n);
    while(n){
        clean(pole, n);
        check = 1;
        i = 0;
        while(i < n){
            scanf("%d %d", &c, &p);
            abs = i+p;
            if(abs >= 0 && abs < n){
                if(!pole[abs])
                    pole[abs] = c;
                else
                    check = 0;
            }
            else
                check = 0;
            i++;
        }
        print_arr(pole, n, check);
        scanf("%d", &n);
    }
    return 0;
}

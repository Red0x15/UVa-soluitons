#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int nCase = 1;
    double query, two;
    scanf("%lf", &query);
    while (query > 0){
        two = ceil(log2(query));
        printf("Case %d: %.0lf\n", nCase, two);
        nCase++;
        scanf("%lf", &query);
    }
    return 0;
}

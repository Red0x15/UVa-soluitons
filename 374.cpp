#include <iostream>

using namespace std;

int bigMod(int base, int ex, int mod){
    if(mod == 1) return 0;
    if(ex == 0) return 1;
    
    if(ex % 2 == 0){
        int ant =bigMod(base, ex / 2, mod);
        return (ant * ant)% mod;
    }
    else
        return (base%mod * bigMod(base, ex - 1, mod))% mod;
}

int main(){
    int base, ex, mod, ans;
    while(scanf("%d %d %d", &base, &ex, &mod) != EOF){
        ans = bigMod(base, ex, mod);
        printf("%d\n", ans);
    }
	return 0;
}
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    int n, k, m, total, cost, aux;
    string text, ans;
    char ch;
    
    scanf("%d", &n);
    while(n--){

        map<char, int> table;
        scanf("%d", &k);

        while(k--){
            
            scanf("%c %d", &ch, &cost);
            table[ch] = cost;
        }
        
        total = 0;
        scanf("%d", &m);
        while(m--){

            getline(cin, text);
            string::iterator it;
            for (it = text.begin(); it != text.end(); it++)
                total += table[*it];
        }
        
        ans = to_string(total);
        while(ans.length() < 3){
            ans = "0" + ans;
        }
        
        string::iterator it;
        int l = ans.length();
        for (it = ans.begin(), aux = 0; it != ans.end(); it++, aux ++)
            if (aux != l - 3)
                cout << *it;
            else
                cout << *it << ".";
        cout << "$" << endl;
    }
}
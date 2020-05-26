#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
    int nFroshes, course, max, maxTimes;

    scanf("%d", &nFroshes);
    while (nFroshes)
    {   
        map<set<int, greater<int>>, int> table;
        map<set<int, greater<int>>, int>::iterator it;

        while (nFroshes--)
        {
            set<int, greater<int>> combination;
            for (int i = 0; i < 5; i++)
            {
                scanf("%d", &course);
                combination.insert(course);
            }
            table[combination]++;
        }
        
        max = 1;
        for(it = table.begin(); it != table.end(); it++){
            if (it->second > max)
                max = it->second;
        }

        maxTimes = 0;
        for(it = table.begin(); it != table.end(); it++){
            if (it->second == max)
                maxTimes += max;
        }
        cout << maxTimes << endl;
        scanf("%d", &nFroshes);
    }
    return 0;
}
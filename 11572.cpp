#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int cases, nFlakes, start, finish, max, box[2000000];
    int *found;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d", &nFlakes);
        finish = 0;
        while(finish < nFlakes){
            scanf("%d", &box[finish]);
            finish++;
        }

        max = 0;
        start = 0;
        finish = 0;
        while(finish < nFlakes){
            found = find(box + start, box + finish, box[finish]);
            if (found != box + finish){
                if (max < finish - start)
                    max = finish - start;
                start = int(found - box + 1);
            }
            finish++;
        }
        

        if (max < (finish - start) || max == 0)
            max = (finish - start);
        printf("%d\n", max);

        finish = 0;
        while(finish < nFlakes){
            box[finish] = 0;
            finish++;
        }
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

int main(){
  int cases, i, mC, fC;
  char tracks[160];
  scanf("%d\n", &cases);
  while (cases--) {
    mC = 0; fC = 0;
    scanf("%[^\n]s", tracks); getchar();
    for (i = 0; i < strlen(tracks); i++) {
      if (tracks[i] == 'M'){
        mC++;
      }
      if (tracks[i] == 'F'){
        fC++;
      }
    }
    if (mC == fC && mC > 1 && fC > 1) {
      printf("LOOP\n");
    }
    else{
      printf("NO LOOP\n");
    }
  }
  return 0;
}

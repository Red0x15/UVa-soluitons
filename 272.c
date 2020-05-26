#include <stdio.h>

int main(){
	char ch;
	int swapper = 0;
	while(scanf("%c", &ch) != EOF){
		if(ch == '\"'){
			if (!swapper){
			    printf("``");
			    swapper++;
			}
			else{
				printf("''");
				swapper--;
			}
		}
		else{
			printf("%c", ch);
		}
	}
	return 0;
}

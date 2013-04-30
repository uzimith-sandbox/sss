#include <stdio.h>
int main() {
	long count,x,y,i,j,ii,jj;
	long field[102][102];
	char c;

	count = 1;
	while(1) {
		scanf("%ld %ld",&x,&y);

		if(x == 0 && y == 0) break;
		if(count != 1) {
		  printf("\n");
		}
		for(i = 0; i <= x; i++) for(j = 0; j <= y; j++) field[i][j] = 0;

		for(i = 1; i <= x; i++) {
			for(j = 1; j <= y; j++) {
				scanf(" %c",&c);
				if(c == '*') {
					field[i][j] = -100;
					for(ii = -1; ii <= 1; ii++) for(jj = -1; jj <= 1; jj++)	field[i-ii][j-jj]++;
				}
			}
		}

		printf("Field #%ld:\n",count);
		for(i = 1; i <= x; i++) {
			for(j = 1; j <= y; j++) {
				if(field[i][j] < 0) {
					printf("*");
				} else {
					printf("%ld",field[i][j]);
				}
			}
			printf("\n");
		}
		count++;
	}
	return 0;
}

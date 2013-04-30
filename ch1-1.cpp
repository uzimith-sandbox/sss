#include <stdio.h>

int main() {
  unsigned int i,n,x,y,start,end,max,count;
  
  while(scanf("%i %i",&x,&y) !=EOF) {
    max = 0;
    if(x < y) {
      start = x;
      end = y;
    } else {
      start = y;
      end = x;
    }
    for(i = start; i<= end; i++) {
      count = 1;
      for(n = i; n != 1;) {
	if(n%2 == 0) {
	  n /= 2;
	} else {
	  n = 3*n+1;
	}
	count++;
      }
      if(max < count) max = count;
    }
    printf("%d %d %d\n",x,y,max);
  }
}

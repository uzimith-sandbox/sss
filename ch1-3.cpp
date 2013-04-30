#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int n,i;
  double exchange,total,avg,negativeSum,positiveSum,money[1000];
  while(1) {
    scanf(" %d",&n);
    if(n==0) break;

    total = 0;
    for(i = 0; i < n; i++) {
      scanf(" %lf",&money[i]);
      total += money[i];
    }
    avg = total / n;

    negativeSum = 0;
    positiveSum = 0;
    for(i = 0; i < n; i++) {
      if(avg < money[i]) {
	negativeSum += floor((money[i] - avg)*100)/100;
      } else {
	positiveSum += floor((avg - money[i])*100)/100;
      }
    }

    exchange = (negativeSum < positiveSum) ? positiveSum : negativeSum;

    printf("$%.2lf\n",exchange);
  }
}

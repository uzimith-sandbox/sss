#include <stdio.h>
#include <string.h>

int reg[10];
int ram[1000];
int pointer;

int init() {
  int i;
  for (i = 0; i < 10; i++) reg[i] = 0;
  for (i = 0; i < 1000; i++) ram[i] = 0;
}

int interpreter () {
  int a,b,c;
  a = ram[pointer] / 100;
  b = ram[pointer] / 10 % 10;
  c = ram[pointer] % 10;
  pointer++;
  switch(a) {
  case 1:
    return 0;
    break;
  case 2:
    reg[b] = c;
    break;
  case 3:
    reg[b] += c;
    reg[b] %= 1000;
    break;
  case 4:
    reg[b] *= c;
    reg[b] %= 1000;
    break;
  case 5:
    reg[b] = reg[c];
    break;
  case 6:
    reg[b] += reg[c];
    reg[b] %= 1000;
    break;
  case 7:
    reg[b] *= reg[c];
    reg[b] %= 1000;
    break;
  case 8:
    reg[b] = ram[reg[c]];
    break;
  case 9:
    ram[reg[c]] = reg[b];
    break;
  case 0:
    if (reg[c] != 0) {
      pointer = reg[b];
    }
    break;
  }
  return 1;
}

int main() {
  int cases,count;
  char str[4];
  scanf("%d\n\n",&cases);
  while(cases--) {
    init();
    pointer = 0;

    while(gets(str) != NULL && strcmp(str, "") != 0){
      ram[pointer] = 100*(str[0]-'0')+10*(str[1]-'0') + str[2]-'0';
      pointer++;
    }

    count = 1;
    pointer = 0;
    while(interpreter()) count++;
    if(cases == 0){
      printf("%d\n",count);
    } else {
      printf("%d\n\n",count);
    }
  }
  return 0;
}


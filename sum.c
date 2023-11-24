#include <stdio.h>

int main() {
  printf("Hello World!\n");
  int i;

for (i = 0; i < 10; i++) {
  if (i == 4) {
    break;
  }
  printf("%d\n", i);
}
  return 0;
}

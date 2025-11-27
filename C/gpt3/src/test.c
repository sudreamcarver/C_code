#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int num;
  while (true) {
    printf("enter a num:");
    scanf("%d", &num);

    if (num % 2 == 0) {
      printf("even");
      sleep(1);
    } else {
      printf("odd");
      sleep(1);
    }
  }
}

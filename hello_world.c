#include <stdio.h>
#include <stdbool.h>

void test(int *x)
{
  *x = 1024;
}
int main(void)
{
  int x = 0;
  printf("x = %d.\n", x);
  test(&x);
  printf("x = %d.\n", x);
  return 0;
}
// cosx的泰勒展开
#include <math.h>
#define PI 3.1415926

int factorial(int n)
{
  int res = 1;
  for (int i = 1; i <= n; i++)
    res *= i;
  return res;
}

double item(int i, int x)
{
  return pow(-1, i) * pow(x, i * 2) / factorial(i * 2);
}

double cos(double x)
{
  int n = 1;
  double res = 0, itemData = 1;
  const double LOW = 1e-5;
  while (1 / factorial(2 * n) >= LOW)
  {
    res += itemData;
    itemData = item(n, x);
    n++;
  }
  res += itemData;
  return res;
}

int main(void)
{
  double res = cos(0);
  return 0;
}
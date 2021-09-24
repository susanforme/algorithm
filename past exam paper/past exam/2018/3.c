// cosx的泰勒展开
#include <math.h>
int factorial(int n)
{
  int res = 1;
  for (int i = 1; i < n; i++)
  {
    res *= i;
  }
  return res;
}
int item(int i, int x)
{
  return pow(-1, i / 2) * pow(x, i) / factorial(i);
}

double cos(double x)
{
  int n = 1;
  double res = 0;
  const double LOW = 1e-5;
  while (1 / factorial(n) >= LOW)
  {
    n++;
  }
  for (int j = 0; j < n; j += 2)
  {
    if (j == 0)
    {
      res == 1;
    }
    else
    {
      res += item(j, x);
    }
  }
  return res;
}

int main(void)
{
  double res = cos(1.5707963267948966);
  return 0;
}
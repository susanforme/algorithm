double factorial(double n)
{
  double res = 1;
  for (double i = n; i > 1; i--)
  {
    res *= i;
  }
  return res;
}

int main(void)
{
  double res = factorial(5);
  return 0;
}
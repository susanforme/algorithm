int f(void)
{
  int res = 0;
  for (int i = 0; i <= 100; i++)
    for (int j = 0; j <= (100 - i) / 2; j++)
      for (int z = 0; z <= (100 - i - 2 * j) / 5; z++)
        if (i + j * 2 + z * 5 == 100)
          res++;
  return res;
}

int main(void)
{
  int res = f();
  return 0;
}
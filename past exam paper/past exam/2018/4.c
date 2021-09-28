#define COLUMN 4
#include <stdio.h>

void inputData(int (*data)[COLUMN], int len)
{
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < COLUMN; j++)
    {
      printf("请输入第%d行，%d行的数据。\n", i + 1, j + 1);
      scanf("%d", &data[i][j]);
    }
  }
}
void printData(int (*data)[COLUMN], int len)
{
  for (int j = 0; j < COLUMN; j++)
  {
    for (int i = len - 1; i >= 0; i--)
    {
      if (i != 0)
        printf("%d ", data[i][j]);
      else
        printf("%d", data[i][j]);
    }
    puts(".");
  }
}

int main(void)
{
  int len = 4, data[len][COLUMN];
  inputData(data, len);
  printData(data, len);
  return 0;
}
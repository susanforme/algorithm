#include <stdio.h>
#include <stdbool.h>
// 判断是否是闰年
bool isBigMonth(int month)
{
  return !(month == 4 || month == 6 || month == 9 || month == 11);
}
int how_many_days(void)
{
  int day, year, month;
  // 是否为闰年
  bool run = false;
  puts("请输入年份。");
  scanf("%d", &year);
  puts("请输入月份。");
  scanf("%d", &month);
  puts("请输入日。");
  scanf("%d", &day);
  run = year % 4 == 0;
  for (int i = 1; i < month; i++)
  {
    if (i == 2)
      day += 28 + run;
    else
      day += 30 + isBigMonth(i);
  }
  return day;
}

int main(void)
{
  int days = how_many_days();
  return 0;
}
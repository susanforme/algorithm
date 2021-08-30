#define STAGE_PRICE_ONE 0.5
#define STAGE_PRICE_TWO 0.4
#define STAGE_PRICE_THREE 0.3

double get_fee(double g)
{
  if (g <= 50)
    return g * STAGE_PRICE_ONE;
  return g > 100 ? g * STAGE_PRICE_THREE : g * STAGE_PRICE_TWO;
}

int main(void)
{
  double q = get_fee(123);
  return 0;
}
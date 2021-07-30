// 二分查找
// 适用于有序的顺序表

#define MAX_SIZE 100

typedef int ElemType;
typedef struct
{
  ElemType data[MAX_SIZE];
  int len;
} SSTable;

void init(SSTable *t)
{
  t->len = 0;
}
void insert(SSTable *t, ElemType v)
{
  t->data[t->len++] = v;
}

int binary_search(SSTable t, ElemType key)
{
  int head = 0, rear = t.len - 1;
  while (head <= rear)
  {
    int mid = (head + rear) / 2;
    if (key == t.data[mid])
    {
      return mid;
    }
    else if (key < t.data[mid])
    {
      rear = mid - 1;
    }
    else
    {
      head = mid + 1;
    }
  }
  return -1;
}

int main(void)
{
  SSTable table;
  int search_res;
  init(&table);
  insert(&table, 1);
  insert(&table, 5);
  insert(&table, 8);
  insert(&table, 9);
  insert(&table, 12);
  insert(&table, 15);
  insert(&table, 16);
  insert(&table, 18);
  search_res = binary_search(table, 12);
  return 0;
}
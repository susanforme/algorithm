// 循环队列
#include <stdbool.h>
#define MAXSIZE 5

// 顺序存储 循环队列
typedef int ElementType;
typedef struct CycleQueue
{
  ElementType data[MAXSIZE];
  ElementType rear, front;
  int len;
} CycleQueue;

void init_queue(CycleQueue *q)
{
  q->front = q->rear = 0;
}

bool is_empty(CycleQueue q)
{
  return q.len == 0;
}

bool en_queue(CycleQueue *q, ElementType e)
{
  if (q->len == MAXSIZE)
  {
    return false;
  }
  q->data[q->rear] = e;
  q->rear = (q->rear + 1) % MAXSIZE;
  q->len++;
  return true;
}

bool de_queue(CycleQueue *q, ElementType *x)
{
  if (is_empty(*q))
  {
    return false;
  }
  *x = q->data[q->front];
  q->front = (q->front + 1) % MAXSIZE;
  q->len--;
  return true;
}

int main(void)
{
  CycleQueue q;
  ElementType dele_v;
  init_queue(&q);
  en_queue(&q, 3);
  en_queue(&q, 4);
  en_queue(&q, 1);
  en_queue(&q, 2);
  de_queue(&q, &dele_v);
  de_queue(&q, &dele_v);
  en_queue(&q, 7);
  en_queue(&q, 6);
  en_queue(&q, 9);
  return 0;
}
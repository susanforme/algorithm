#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 10

typedef struct
{
  int data[MAXSIZE];
  int front, rear;
} SqQueue;

void init_queue(SqQueue *s)
{
  // 初始化为0
  s->front = s->rear = 0;
}

bool is_empty(SqQueue *s)
{
  return s->rear == s->front;
}

// 入队
bool en_queue(SqQueue *s, int x)
{
  if (s->rear == MAXSIZE - 1)
  {
    return false;
  }
  // 万一是第九个则有越界可能
  // s->data[s->rear++] = x;

  // 取模 循环队列
  s->data[s->rear] = x;
  s->rear = (s->rear + 1) % MAXSIZE;
  return true;
}

// 出队
bool de_queue(SqQueue *s, int *x)
{
  if (is_empty(s))
  {
    return false;
  }
  // *x = s->data[s->front++];
  *x = s->data[s->front++];
  s->front = (s->front + 1) % MAXSIZE;
  return true;
}

int main(void)
{
  SqQueue queue;
  int delete_value;
  init_queue(&queue);
  en_queue(&queue, 1);
  en_queue(&queue, 2);
  en_queue(&queue, 3);
  de_queue(&queue, &delete_value);
  return 0;
}
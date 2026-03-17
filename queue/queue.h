#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue queue;

Queue* queue_init(int capacity);
int queue_is_empty(const Queue* queue);
int queue_is_full(const Queue* queue);
int queue_enqueue(Queue* queue, int value);
int queue_dequeue(Queue* queue, int* out);
int queue_size(const Queue* queue);
int queue_destroy(Queue* queue);
void queue_clear(Queue* queue);

#endif

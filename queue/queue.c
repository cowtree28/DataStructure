#include <stdlib.h>

typedef struct {
    int* arr;
    int front;
    int rear;
    int capacity;
}Queue;

Queue* queue_init(int capacity) {
    if (capacity <= 0)
        return NULL;
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }

    queue->arr = (int*)malloc(sizeof(int) * capacity);
    if (queue->arr == NULL) {
        free(queue);
        return NULL;
    }

    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int queue_is_empty(const Queue* queue) {
    return queue->front == queue->rear;
}

int queue_is_full(const Queue* queue) {
    return queue->rear == queue->capacity - 1
}

int queue_enqueue(Queue* queue, int value) {
    if (queue_is_full(queue))
        return -1;
    queue->arr[++queue->rear] = value;
    return 0;
}

int queue_dequeue(Queue* queue, int* out) {
    if (queue_is_full(queue))
        return -1;
    *out = queue->arr[++queue->front];
    return 0;
}

int queue_size(const Queue* queue) {
    return queue->rear - queue->front;
}

int queue_destroy(Queue* queue) {
    free(queue->arr);
    free(queue);
    return 0;
}

void queue_clear(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

#include "TAD_3.h"

struct queue {
    Element items[QUEUE_MAX_SIZE];
    int rear, front, size;
};

void init(Queue* queue) {
    Queue q;
    q = malloc(sizeof(struct queue));
    q->rear = -1;
    q->front = -1;
    q->size = 0;
    *queue = q;
}

bool is_full(Queue queue) {
    return queue->size == QUEUE_MAX_SIZE;
}

bool is_empty(Queue queue) {
    return queue->size == 0;
}

bool enqueue(Queue queue, Element new_element) {
    bool answer = false;
    if (!is_full(queue)) {
        queue->rear = (queue->rear + 1) % QUEUE_MAX_SIZE;
        queue->items[queue->rear] = new_element;
        queue->size += 1;
        answer = true;
    }
    return answer;
}

Element dequeue(Queue queue) {
    Element answer = NULL;

    if (!is_empty(queue)) {
        queue->front = (queue->front + 1) % QUEUE_MAX_SIZE;
        queue->size -= 1;
        answer = queue->items[queue->front];
    }
    return answer;
}
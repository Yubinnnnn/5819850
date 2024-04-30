#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

void enqueue(QueueType* q, element item) {
    if (is_full(q)) {
        printf("Queue is full.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void print_queue(QueueType* q) {
    printf("Queue(front=%d, rear=%d): ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%d ", q->data[i]);
            if (i == q->rear) break;
        } while (i != q->front);
    }
    printf("\n");
}

int main() {
    QueueType queue;
    init_queue(&queue);
    int choice, item;

    while (1) {
        printf("\n메뉴를 선택하세요:\n");
        printf("1. 숫자를 입력 받아서 원형 큐에 삽입\n");
        printf("2. 원형 큐에서 하나를 꺼내서 출력\n");
        printf("3. 원형 큐를 화면에 출력\n");
        printf("4. 종료\n");
        printf("선택: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("삽입할 숫자를 입력하세요: ");
            scanf_s("%d", &item);
            enqueue(&queue, item);
            break;
        case 2:
            printf("꺼낸 숫자: %d\n", dequeue(&queue));
            break;
        case 3:
            print_queue(&queue);
            break;
        case 4:
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 선택입니다. 다시 선택해주세요.\n");
        }
    }

    return 0;
}

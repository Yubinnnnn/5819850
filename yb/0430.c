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
        printf("\n�޴��� �����ϼ���:\n");
        printf("1. ���ڸ� �Է� �޾Ƽ� ���� ť�� ����\n");
        printf("2. ���� ť���� �ϳ��� ������ ���\n");
        printf("3. ���� ť�� ȭ�鿡 ���\n");
        printf("4. ����\n");
        printf("����: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("������ ���ڸ� �Է��ϼ���: ");
            scanf_s("%d", &item);
            enqueue(&queue, item);
            break;
        case 2:
            printf("���� ����: %d\n", dequeue(&queue));
            break;
        case 3:
            print_queue(&queue);
            break;
        case 4:
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n");
        }
    }

    return 0;
}

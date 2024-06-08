#include <stdio.h>
#include <stdlib.h>

// ��� ����ü ����
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// ����Ʈ ����ü ����
typedef struct CircularDoublyLinkedList {
    Node* head;
} CircularDoublyLinkedList;

// �Լ� ����
CircularDoublyLinkedList* createList();
Node* createNode(int data);
void addFirst(CircularDoublyLinkedList* list, int data);
void addLast(CircularDoublyLinkedList* list, int data);
void deleteFirst(CircularDoublyLinkedList* list);
void deleteLast(CircularDoublyLinkedList* list);
void printList(CircularDoublyLinkedList* list);
void freeList(CircularDoublyLinkedList* list);

int main() {
    CircularDoublyLinkedList* list = createList();
    int choice, data;

    while (1) {
        printf("\n�޴�:\n");
        printf("1. ���� �Է� �޾Ƽ� ����Ʈ ó���� �߰�\n");
        printf("2. ���� �Է� �޾Ƽ� ����Ʈ �������� �߰�\n");
        printf("3. ����Ʈ ó�� ��� ����\n");
        printf("4. ����Ʈ ������ ��� ����\n");
        printf("5. ����Ʈ ����Ʈ\n");
        printf("6. ����\n");
        printf("����: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("�߰��� ����: ");
            scanf_s("%d", &data);
            addFirst(list, data);
            break;
        case 2:
            printf("�߰��� ����: ");
            scanf_s("%d", &data);
            addLast(list, data);
            break;
        case 3:
            deleteFirst(list);
            break;
        case 4:
            deleteLast(list);
            break;
        case 5:
            printList(list);
            break;
        case 6:
            freeList(list);
            return 0;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }
}

// ����Ʈ ���� �Լ�
CircularDoublyLinkedList* createList() {
    CircularDoublyLinkedList* list = (CircularDoublyLinkedList*)malloc(sizeof(CircularDoublyLinkedList));
    list->head = NULL;
    return list;
}

// ��� ���� �Լ�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// ����Ʈ ó���� �߰� �Լ�
void addFirst(CircularDoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        Node* tail = list->head->prev;
        newNode->next = list->head;
        newNode->prev = tail;
        tail->next = newNode;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

// ����Ʈ �������� �߰� �Լ�
void addLast(CircularDoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        Node* tail = list->head->prev;
        newNode->next = list->head;
        newNode->prev = tail;
        tail->next = newNode;
        list->head->prev = newNode;
    }
}

// ����Ʈ ó�� ��� ���� �Լ�
void deleteFirst(CircularDoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
        return;
    }

    Node* temp = list->head;
    if (list->head->next == list->head) {
        list->head = NULL;
    }
    else {
        Node* tail = list->head->prev;
        list->head = list->head->next;
        tail->next = list->head;
        list->head->prev = tail;
    }
    free(temp);
}

// ����Ʈ ������ ��� ���� �Լ�
void deleteLast(CircularDoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
        return;
    }

    Node* tail = list->head->prev;
    if (list->head->next == list->head) {
        list->head = NULL;
    }
    else {
        Node* prevNode = tail->prev;
        prevNode->next = list->head;
        list->head->prev = prevNode;
    }
    free(tail);
}

// ����Ʈ ����Ʈ �Լ�
void printList(CircularDoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
        return;
    }

    Node* current = list->head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("\n");
}

// ����Ʈ ���� �Լ�
void freeList(CircularDoublyLinkedList* list) {
    if (list->head == NULL) {
        free(list);
        return;
    }

    Node* current = list->head;
    Node* nextNode;
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != list->head);

    free(list);
}

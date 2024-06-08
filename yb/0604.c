#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// 리스트 구조체 정의
typedef struct CircularDoublyLinkedList {
    Node* head;
} CircularDoublyLinkedList;

// 함수 선언
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
        printf("\n메뉴:\n");
        printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
        printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
        printf("3. 리스트 처음 노드 삭제\n");
        printf("4. 리스트 마지막 노드 삭제\n");
        printf("5. 리스트 프린트\n");
        printf("6. 종료\n");
        printf("선택: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("추가할 숫자: ");
            scanf_s("%d", &data);
            addFirst(list, data);
            break;
        case 2:
            printf("추가할 숫자: ");
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
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }
}

// 리스트 생성 함수
CircularDoublyLinkedList* createList() {
    CircularDoublyLinkedList* list = (CircularDoublyLinkedList*)malloc(sizeof(CircularDoublyLinkedList));
    list->head = NULL;
    return list;
}

// 노드 생성 함수
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// 리스트 처음에 추가 함수
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

// 리스트 마지막에 추가 함수
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

// 리스트 처음 노드 삭제 함수
void deleteFirst(CircularDoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("리스트가 비어 있습니다.\n");
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

// 리스트 마지막 노드 삭제 함수
void deleteLast(CircularDoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("리스트가 비어 있습니다.\n");
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

// 리스트 프린트 함수
void printList(CircularDoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }

    Node* current = list->head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("\n");
}

// 리스트 해제 함수
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

#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 단순 연결 리스트 구조체 정의
typedef struct {
    Node* head;
} LinkedList;

// 새로운 노드 생성 함수
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 리스트에 숫자 추가 함수
void insert(LinkedList* list, int data, int position, int* moveCount) {
    Node* newNode = createNode(data);
    if (position == 0 || list->head == NULL) {
        newNode->next = list->head;
        list->head = newNode;
        *moveCount = 0;
        return;
    }
    Node* temp = list->head;
    int count = 0;
    while (temp->next != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    *moveCount = count + 1;
}

// 리스트에서 노드 삭제 함수
void delete(LinkedList* list, int position, int* moveCount) {
    if (list->head == NULL)
        return;
    Node* temp = list->head;
    if (position == 0) {
        list->head = temp->next;
        free(temp);
        *moveCount = 0;
        return;
    }
    int count = 0;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL)
        return;
    Node* nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
    *moveCount = count + 1;
}

// 리스트 출력 함수
// 리스트 출력 함수
void display(LinkedList* list) {
    Node* temp = list->head;
    printf("리스트: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("->");
        else
            printf("->Null");
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    LinkedList list = { NULL };
    int choice, data, position, moveCount;

    while (1) {
        printf("\n메뉴:\n");
        printf("1. 리스트에 추가\n");
        printf("2. 리스트에서 삭제\n");
        printf("3. 리스트 출력\n");
        printf("4. 프로그램 종료\n");

        printf("선택: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("추가할 숫자 입력: ");
            scanf_s("%d", &data);
            printf("추가할 위치 입력: ");
            scanf_s("%d", &position);
            insert(&list, data, position, &moveCount);
            printf("이동한 횟수: %d\n", moveCount);
            break;
        case 2:
            printf("삭제할 위치 입력: ");
            scanf_s("%d", &position);
            delete(&list, position, &moveCount);
            printf("이동한 횟수: %d\n", moveCount);
            break;
        case 3:
            display(&list);
            break;
        case 0:
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("올바른 메뉴를 선택하세요.\n");
        }
    }

    return 0;
}

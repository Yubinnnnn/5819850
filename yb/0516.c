#include <stdio.h>
#include <stdlib.h>

// ��� ����ü ����
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// �ܼ� ���� ����Ʈ ����ü ����
typedef struct {
    Node* head;
} LinkedList;

// ���ο� ��� ���� �Լ�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ����Ʈ�� ���� �߰� �Լ�
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

// ����Ʈ���� ��� ���� �Լ�
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

// ����Ʈ ��� �Լ�
// ����Ʈ ��� �Լ�
void display(LinkedList* list) {
    Node* temp = list->head;
    printf("����Ʈ: ");
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
        printf("\n�޴�:\n");
        printf("1. ����Ʈ�� �߰�\n");
        printf("2. ����Ʈ���� ����\n");
        printf("3. ����Ʈ ���\n");
        printf("4. ���α׷� ����\n");

        printf("����: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("�߰��� ���� �Է�: ");
            scanf_s("%d", &data);
            printf("�߰��� ��ġ �Է�: ");
            scanf_s("%d", &position);
            insert(&list, data, position, &moveCount);
            printf("�̵��� Ƚ��: %d\n", moveCount);
            break;
        case 2:
            printf("������ ��ġ �Է�: ");
            scanf_s("%d", &position);
            delete(&list, position, &moveCount);
            printf("�̵��� Ƚ��: %d\n", moveCount);
            break;
        case 3:
            display(&list);
            break;
        case 0:
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
        default:
            printf("�ùٸ� �޴��� �����ϼ���.\n");
        }
    }

    return 0;
}

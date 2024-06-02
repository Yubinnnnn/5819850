#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

int is_empty() {
    return head == NULL;
}

void add_to_beginning(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    if (is_empty()) {
        head = new_node;
        new_node->next = head;
    }
    else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
        head = new_node;
    }
}

void add_to_end(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    if (is_empty()) {
        head = new_node;
        new_node->next = head;
    }
    else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
}

void delete_from_beginning() {
    if (!is_empty()) {
        if (head->next == head) {
            free(head);
            head = NULL;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            Node* to_delete = head;
            head = head->next;
            temp->next = head;
            free(to_delete);
        }
    }
}

void delete_from_end() {
    if (!is_empty()) {
        if (head->next == head) {
            free(head);
            head = NULL;
        }
        else {
            Node* temp = head;
            while (temp->next->next != head) {
                temp = temp->next;
            }
            Node* to_delete = temp->next;
            temp->next = head;
            free(to_delete);
        }
    }
}

void print_list() {
    if (!is_empty()) {
        Node* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
    else {
        printf("List is empty.\n");
    }
}

int main() {
    int choice, data;
    while (1) {
        printf("\nMenu\n");
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
            printf("숫자 입력: ");
            scanf_s("%d", &data);
            add_to_beginning(data);
            break;
        case 2:
            printf("숫자 입력: ");
            scanf_s("%d", &data);
            add_to_end(data);
            break;
        case 3:
            delete_from_beginning();
            break;
        case 4:
            delete_from_end();
            break;
        case 5:
            print_list();
            break;
        case 6:
            exit(0);
        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }
    return 0;
}

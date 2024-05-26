#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 30

typedef char element[NAME_LENGTH];

typedef struct listNode {
    element data;
    struct listNode* link;
} ListNode;

ListNode* insert_last(ListNode* head, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    ListNode* temp = head;
    strcpy(p->data, value);
    p->link = NULL;

    if (head == NULL) {
        return p;
    }

    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = p;
    return head;
}

ListNode* delete(ListNode* head, element value, ListNode** deleted_head) {
    ListNode* temp = head;
    ListNode* prev = NULL;

    while (temp != NULL && strcmp(temp->data, value) != 0) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("해당 과일이 없습니다.\n");
        return head;
    }

    if (prev == NULL) {
        head = temp->link;
    }
    else {
        prev->link = temp->link;
    }

    // 새롭게 삭제된 노드를 deleted_head 리스트의 끝에 추가
    ListNode* deleted_temp = *deleted_head;
    if (deleted_temp == NULL) {
        *deleted_head = temp;
        temp->link = NULL;
    }
    else {
        while (deleted_temp->link != NULL) {
            deleted_temp = deleted_temp->link;
        }
        deleted_temp->link = temp;
        temp->link = NULL;
    }

    printf("과일이 삭제되었습니다.\n");
    return head;
}

void print_list(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        printf("%s ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int find_fruit(ListNode* head, element value) {
    ListNode* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data, value) == 0) {
            return 1;
        }
        temp = temp->link;
    }
    return 0;
}

void print_menu() {
    printf("\n메뉴:\n");
    printf("1: 리스트의 매 마지막에 새로운 과일 추가\n");
    printf("2: 리스트에 있는 과일을 삭제\n");
    printf("3: 삭제된 과일 목록 출력\n");
    printf("4: 종료\n");
    printf("선택: ");
}

int main() {
    ListNode* head = NULL;
    ListNode* deleted_head = NULL;
    element fruits[] = { "Mango", "Orange", "Apple", "Grape", "Cherry", "Plum", "Guava", "Raspberry", "Banana", "Peach" };
    int fruit_count = 10;

    for (int i = 0; i < fruit_count; i++) {
        head = insert_last(head, fruits[i]);
    }

    while (1) {
        print_menu();
        int choice;
        scanf_s("%d", &choice);

        if (choice == 4) {
            break;
        }

        if (choice == 1) {
            element new_fruit;
            printf("추가할 과일 이름을 입력하세요: ");
            scanf_s("%s", new_fruit);

            if (find_fruit(head, new_fruit)) {
                printf("이미 존재하는 과일입니다.\n");
            }
            else {
                head = insert_last(head, new_fruit);
                printf("과일이 추가되었습니다.\n");
            }

        }
        else if (choice == 2) {
            element del_fruit;
            printf("삭제할 과일 이름을 입력하세요: ");
            scanf_s("%s", del_fruit);

            head = delete(head, del_fruit, &deleted_head);

        }
        else if (choice == 3) {
            if (deleted_head == NULL) {
                printf("삭제된 과일이 없습니다.\n");
            }
            else {
                printf("삭제된 과일 목록:\n");
                print_list(deleted_head);
            }

        }
        else {
            printf("잘못된 선택입니다. 다시 입력해주세요.\n");
        }
    }

    return 0;
}

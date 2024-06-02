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
            printf("���� �Է�: ");
            scanf_s("%d", &data);
            add_to_beginning(data);
            break;
        case 2:
            printf("���� �Է�: ");
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
            printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }
    return 0;
}

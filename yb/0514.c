#include <stdio.h>

// �迭�� ũ�⸦ ����
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
}ArrayListType;

// ����Ʈ ��� �Լ�
void print_list(int arr[], int size) {
    printf("����Ʈ ���: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ���� ���� �Լ�
void insert(int arr[], int* size, int index, int value) {
    if (*size >= MAX_LIST_SIZE) {
        printf("����Ʈ�� ���� á���ϴ�.\n");
        return;
    }

    if (index < 0 || index > *size) {
        printf("��ȿ���� ���� ��ġ�Դϴ�.\n");
        return;
    }

    // ������ �̵� Ƚ�� ���
    printf("�̵� Ƚ��: %d\n", *size - index);

    // ���� ��ġ ������ �����͸� �ڷ� �̵�
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    // ���ο� �� ����
    arr[index] = value;
    (*size)++;
    printf("�����Ͱ� ���ԵǾ����ϴ�.\n");
}

// ���� ���� �Լ�
void delete(int arr[], int* size, int index) {
    if (index < 0 || index >= *size) {
        printf("��ȿ���� ���� ��ġ�Դϴ�.\n");
        return;
    }

    // ������ �̵� Ƚ�� ���
    printf("�̵� Ƚ��: %d\n", *size - index - 1);

    // ���� ��ġ ������ �����͸� ������ �̵�
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("�����Ͱ� �����Ǿ����ϴ�.\n");
}

int main() {
    int arr[MAX_LIST_SIZE];
    int size = 0;

    while (1) {
        printf("\n�޴�:\n");
        printf("1. ����Ʈ�� �߰�\n");
        printf("2. ����Ʈ���� ����\n");
        printf("3. ����Ʈ ���\n");
        printf("4. ���α׷� ����\n");

        int choice;
        printf("�޴��� �����ϼ���: ");
        scanf_s("%d", &choice);

        int value, index;
        switch (choice) {
        case 1:
            printf("�߰��� ���ڸ� �Է��ϼ���: ");
            scanf_s("%d", &value);
            printf("�߰��� ��ġ�� �Է��ϼ���: ");
            scanf_s("%d", &index);
            insert(arr, &size, index, value);
            break;
        case 2:
            printf("������ ��ġ�� �Է��ϼ���: ");
            scanf_s("%d", &index);
            delete(arr, &size, index);
            break;
        case 3:
            print_list(arr, size);
            break;
        case 4:
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }

    return 0;
}

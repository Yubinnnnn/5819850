#include <stdio.h>

// 배열의 크기를 정의
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
}ArrayListType;

// 리스트 출력 함수
void print_list(int arr[], int size) {
    printf("리스트 출력: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 숫자 삽입 함수
void insert(int arr[], int* size, int index, int value) {
    if (*size >= MAX_LIST_SIZE) {
        printf("리스트가 가득 찼습니다.\n");
        return;
    }

    if (index < 0 || index > *size) {
        printf("유효하지 않은 위치입니다.\n");
        return;
    }

    // 데이터 이동 횟수 출력
    printf("이동 횟수: %d\n", *size - index);

    // 삽입 위치 이후의 데이터를 뒤로 이동
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    // 새로운 값 삽입
    arr[index] = value;
    (*size)++;
    printf("데이터가 삽입되었습니다.\n");
}

// 숫자 삭제 함수
void delete(int arr[], int* size, int index) {
    if (index < 0 || index >= *size) {
        printf("유효하지 않은 위치입니다.\n");
        return;
    }

    // 데이터 이동 횟수 출력
    printf("이동 횟수: %d\n", *size - index - 1);

    // 삭제 위치 이후의 데이터를 앞으로 이동
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("데이터가 삭제되었습니다.\n");
}

int main() {
    int arr[MAX_LIST_SIZE];
    int size = 0;

    while (1) {
        printf("\n메뉴:\n");
        printf("1. 리스트에 추가\n");
        printf("2. 리스트에서 삭제\n");
        printf("3. 리스트 출력\n");
        printf("4. 프로그램 종료\n");

        int choice;
        printf("메뉴를 선택하세요: ");
        scanf_s("%d", &choice);

        int value, index;
        switch (choice) {
        case 1:
            printf("추가할 숫자를 입력하세요: ");
            scanf_s("%d", &value);
            printf("추가할 위치를 입력하세요: ");
            scanf_s("%d", &index);
            insert(arr, &size, index, value);
            break;
        case 2:
            printf("삭제할 위치를 입력하세요: ");
            scanf_s("%d", &index);
            delete(arr, &size, index);
            break;
        case 3:
            print_list(arr, size);
            break;
        case 4:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}

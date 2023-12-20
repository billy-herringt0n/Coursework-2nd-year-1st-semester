#include "Header.h"

void addSp(Node** arr_sp, int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (arr[i][j] != 0) {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->inf = j + 1;
                newNode->next = arr_sp[i];
                arr_sp[i] = newNode;
            }
        }
    }
}

void printSp(Node** arr_sp, int rows) {
    for (int i = 0; i < rows; i++) {
        Node* current = arr_sp[i];
        if (current == NULL) {

        }
        else {
            printf("������� %d ������ �: ", i + 1);
            while (current != NULL) {
                printf("%d ", current->inf);
                current = current->next;
            }
            printf("\n");
        }
    }
}

// ������� ��� ����� ���� � ���������
int inputNumber() {
    char input[255];
    int number;
    int isValidInput = 0;

    do {
        isValidInput = 1; // ������������, ��� ���� ���������
        scanf("%s", input);

        // ��������� ������ ������ � ������
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isdigit(input[i])) {
                isValidInput = 0; // ������������ ����, ���� ������ �� �����
                printf("������! ������� ������ �����.\n");
                printf("�������� ��������: ");
                break;
            }
        }

        // ������� �����
        while (getchar() != '\n');

    } while (!isValidInput);

    // ����������� ������ � �����
    sscanf(input, "%d", &number);

    return number;
}

void colorGraph(int** arr, int rows, int* colors) {
    // ������������� ������� ������
    for (int i = 0; i < rows; ++i) {
        colors[i] = -1;
    }

    // ������ �� ���� �������� �����
    for (int node = 0; node < rows; node++) {
        // ��������, �������� �� ���� ��� ������� �������
        bool* available = (bool*)malloc(rows * sizeof(bool));
        for (int i = 0; i < rows; ++i) {
            available[i] = true;
        }

        for (int neighbor = 0; neighbor < rows; neighbor++) {
            if (arr[node][neighbor] && colors[neighbor] != -1) {
                available[colors[neighbor]] = false;
            }
        }

        // ������� ����������� ��������� ����
        for (int color = 0; color < rows; color++) {
            if (available[color]) {
                colors[node] = color;
                break;
            }
        }
    }
}
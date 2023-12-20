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
            printf("Вершина %d смежна с: ", i + 1);
            while (current != NULL) {
                printf("%d ", current->inf);
                current = current->next;
            }
            printf("\n");
        }
    }
}

// Функция для ввода цифр с проверкой
int inputNumber() {
    char input[255];
    int number;
    int isValidInput = 0;

    do {
        isValidInput = 1; // Предполагаем, что ввод корректен
        scanf("%s", input);

        // Проверяем каждый символ в строке
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isdigit(input[i])) {
                isValidInput = 0; // Некорректный ввод, если символ не цифра
                printf("Ошибка! Введите только цифры.\n");
                printf("Выберите действие: ");
                break;
            }
        }

        // Очищаем буфер
        while (getchar() != '\n');

    } while (!isValidInput);

    // Преобразуем строку в число
    sscanf(input, "%d", &number);

    return number;
}

void colorGraph(int** arr, int rows, int* colors) {
    // Инициализация массива цветов
    for (int i = 0; i < rows; ++i) {
        colors[i] = -1;
    }

    // Проход по всем вершинам графа
    for (int node = 0; node < rows; node++) {
        // Проверка, свободен ли цвет для текущей вершины
        bool* available = (bool*)malloc(rows * sizeof(bool));
        for (int i = 0; i < rows; ++i) {
            available[i] = true;
        }

        for (int neighbor = 0; neighbor < rows; neighbor++) {
            if (arr[node][neighbor] && colors[neighbor] != -1) {
                available[colors[neighbor]] = false;
            }
        }

        // Находим минимальный доступный цвет
        for (int color = 0; color < rows; color++) {
            if (available[color]) {
                colors[node] = color;
                break;
            }
        }
    }
}
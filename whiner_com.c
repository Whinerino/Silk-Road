#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *m = NULL, *h = NULL, i, j, n, k = 1, c = 0, l, tmp, v, max;
    char s[512], *str;
    FILE *f;
    
    // Открываем файл для чтения
    f = fopen("data.dat", "r");
    if (f == NULL) {
        // Если файл не открылся, создаем файл data.res с ERROR и завершаем программу
        FILE *fout = fopen("data.res", "w");
        if (fout != NULL) {
            fprintf(fout, "ERROR\n");
            fclose(fout);
        }
        return -1;
    }
    
    // Читаем количество столбцов из первой строки
    if (fscanf(f, "%d\n", &n) != 1) {
        fclose(f);
        FILE *fout = fopen("data.res", "w");
        if (fout != NULL) {
            fprintf(fout, "ERROR\n");
            fclose(fout);
        }
        return -2;
    }
    
    // Выделяем начальную память для одной строки
    m = (int*)malloc(sizeof(int) * n);
    
    // Читаем строки из файла
    while (fgets(s, sizeof(s), f) != NULL) {
        str = s;
        
        // Если массив заполнен, увеличиваем память в 2 раза
        if (k == c) {
            k *= 2;
            m = (int*)realloc(m, sizeof(int) * n * k);
        }
        
        // Читаем числа из строки
        for (i = 0; i < n; i++) {
            if (sscanf(str, "%d%n", &m[i + c * n], &l) != 1) {
                // Если чисел меньше, чем столбцов - ERROR
                free(m);
                fclose(f);
                FILE *fout = fopen("data.res", "w");
                if (fout != NULL) {
                    fprintf(fout, "ERROR\n");
                    fclose(fout);
                }
                return -3;
            }
            str += l;
        }
        
        // Проверяем, что в строке нет лишних чисел
        if (sscanf(str, "%d%n", &tmp, &l) == 1) {
            // Если чисел больше, чем столбцов - ERROR
            free(m);
            fclose(f);
            FILE *fout = fopen("data.res", "w");
            if (fout != NULL) {
                fprintf(fout, "ERROR\n");
                fclose(fout);
            }
            return -4;
        }
        
        c++; // Увеличиваем счетчик строк
    }
    
    fclose(f); // Закрываем входной файл
    
    // Сортировка строк по убыванию первого элемента
    for (i = 0; i < c; i++) {
        for (j = 0; j < c - 1; j++) {
            if (m[j * n] < m[(j + 1) * n]) {
                // Меняем строки местами
                for (v = 0; v < n; v++) {
                    tmp = m[j * n + v];
                    m[j * n + v] = m[(j + 1) * n + v];
                    m[(j + 1) * n + v] = tmp;
                }
            }
        }
    }
    
    // Выделяем память для массива максимальных элементов
    h = (int*)malloc(sizeof(int) * c);
    
    // Находим максимальный элемент в каждой строке
    for (i = 0; i < c; i++) {
        max = m[i * n]; // Начинаем с первого элемента строки
        for (j = 0; j < n; j++) {
            if (m[i * n + j] > max) {
                max = m[i * n + j];
            }
        }
        h[i] = max;
    }
    
    // Сортировка массива максимальных элементов по убыванию
    for (i = 0; i < c; i++) {
        for (j = 0; j < c - 1; j++) {
            if (h[j] < h[j + 1]) {
                tmp = h[j];
                h[j] = h[j + 1];
                h[j + 1] = tmp;
            }
        }
    }
    
    // Открываем файл для записи результатов
    FILE *fout = fopen("data.res", "w");
    if (fout == NULL) {
        free(m);
        free(h);
        return -5;
    }
    
    // Записываем отсортированную матрицу
    for (i = 0; i < c; i++) {
        for (j = 0; j < n; j++) {
            fprintf(fout, "%d ", m[i * n + j]);
        }
        fprintf(fout, "\n");
    }
    
    // Записываем отсортированный массив максимальных элементов
    for (i = 0; i < c; i++) {
        fprintf(fout, "%d ", h[i]);
    }
    fprintf(fout, "\n");
    
    // Закрываем файл и освобождаем память
    fclose(fout);
    free(h);
    free(m);
    
    return 0;
}
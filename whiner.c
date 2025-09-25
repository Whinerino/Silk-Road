#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *m = NULL, *h = NULL, i, j, n, k = 1, c = 0, l, tmp, v, max;
    char s[512], *str;
    FILE *f;

    f = fopen("data.dat", "r");
    if (f == NULL) {
        FILE *fout = fopen("data.res", "w");
        if (fout != NULL) {
            fprintf(fout, "ERROR\n");
            fclose(fout);
        }
        return -1;
    }

    if (fscanf(f, "%d\n", &n) != 1) {
        fclose(f);
        FILE *fout = fopen("data.res", "w");
        if (fout != NULL) {
            fprintf(fout, "ERROR\n");
            fclose(fout);
        }
        return -2;
    }

    m = (int*)malloc(sizeof(int) * n);

    while (fgets(s, sizeof(s), f) != NULL) {
        str = s;

        if (k == c) {
            k *= 2;
            m = (int*)realloc(m, sizeof(int) * n * k);
        }

        for (i = 0; i < n; i++) {
            if (sscanf(str, "%d%n", &m[i + c * n], &l) != 1) {
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

        if (sscanf(str, "%d%n", &tmp, &l) == 1) {
            free(m);
            fclose(f);
            FILE *fout = fopen("data.res", "w");
            if (fout != NULL) {
                fprintf(fout, "ERROR\n");
                fclose(fout);
            }
            return -4;
        }

        c++;
    }

    fclose(f);

    for (i = 0; i < c; i++) {
        for (j = 0; j < c - 1; j++) {
            if (m[j * n] < m[(j + 1) * n]) {
                for (v = 0; v < n; v++) {
                    tmp = m[j * n + v];
                    m[j * n + v] = m[(j + 1) * n + v];
                    m[(j + 1) * n + v] = tmp;
                }
            }
        }
    }

    h = (int*)malloc(sizeof(int) * c);

    for (i = 0; i < c; i++) {
        max = m[i * n];
        for (j = 0; j < n; j++) {
            if (m[i * n + j] > max) {
                max = m[i * n + j];
            }
        }
        h[i] = max;
    }

    for (i = 0; i < c; i++) {
        for (j = 0; j < c - 1; j++) {
            if (h[j] < h[j + 1]) {
                tmp = h[j];
                h[j] = h[j + 1];
                h[j + 1] = tmp;
            }
        }
    }

    FILE *fout = fopen("data.res", "w");
    if (fout == NULL) {
        free(m);
        free(h);
        return -5;
    }

    for (i = 0; i < c; i++) {
        for (j = 0; j < n; j++) {
            fprintf(fout, "%d ", m[i * n + j]);
        }
        fprintf(fout, "\n");
    }

    for (i = 0; i < c; i++) {
        fprintf(fout, "%d ", h[i]);
    }
    fprintf(fout, "\n");

    fclose(fout);
    free(h);
    free(m);

    return 0;
}

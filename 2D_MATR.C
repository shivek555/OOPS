#include <stdio.h>

void add(int m, int n, int a[10][10], int b[10][10]) {
    int sum, i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            sum = a[i][j] + b[i][j];
            printf("%d\t", sum);
        }
        printf("\n");
    }
}

void multiply(int m, int n, int p, int q, int a[10][10], int b[10][10]) {
    int sum, i, j, k;

    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            sum = 0;
            for (k = 0; k < p; k++)
                sum += a[i][k] * b[k][j];
            printf("%d\t", sum);
        }
        printf("\n");
    }
}

void subtract(int m, int n, int a[10][10], int b[10][10]) {
    int sub, i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            sub = a[i][j] - b[i][j];
            printf("%d\t", sub);
        }
        printf("\n");
    }
}

double determinant(int m, int n, int a[10][10]) {
    int i, j, k, l, sgn;
    double det = 0;

    if (m == 2 && n == 2) {
        det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    } else if (m == 3 && n == 3) {
        for (k = 0; k < n; k++) {
            sgn = 1 - 2 * (k % 2);
            det += sgn * a[0][k] * (a[1][(k + 1) % n] * a[2][(k + 2) % n] - a[1][k] * (a[0][(k + 1) % n] * a[2][(k + 2) % n] - a[0][(k + 1) % n] * a[2][k]));
        }
    } else {
        printf("Determinant calculation is not supported for this matrix size.\n");
        return 0;
    }

    return det;
}

int main() {
    int m, n, p, q, choice;
    int a[10][10], b[10][10];
    double det;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &m, &n);

    printf("Enter the elements of first matrix:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the elements of second matrix:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &b[i][j]);

    printf("Enter the operation choice (1: addition, 2: multiplication, 3: subtraction, 4: determinant): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add(m, n, a, b);
            break;
        case 2:
            multiply(m, n, m, n, a, b);
            break;
        case 3:
            subtract(m, n, a, b);
            break;
        case 4:
            det = determinant(m, n, a);
            printf("Determinant of thematrix is:%lf\n", det);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
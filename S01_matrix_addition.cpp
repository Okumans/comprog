#include <math.h>
#include <stdio.h>

int main() {
  int n, m, i, j, k;
  int matrix1[100][100];
  int matrix2[100][100];
  int matrix_sum[100][100];

  scanf("%d %d", &m, &n);

  // input matrix1
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &matrix1[i][j]);
    }
  }

  // input matrix2
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &matrix2[i][j]);
    }
  }

  // Add
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      matrix_sum[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }

  // print
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", matrix_sum[i][j]);
    }
    printf("\n");
  }
  return 0;
}

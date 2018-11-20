#include<stdio.h>

void printMatrix(int Matrix[5][5]);
void sortMatrix(int Matrix[5][5]);
void extraTasks(int Matrix[5][5]);

int main(void)
{
  printf("Input matrix' elements:\n");
  int matrix[5][5];
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      printf("element[%d][%d]= ", i + 1, j + 1);
      scanf("%d", &matrix[i][j]);
    }
  printf("\n\nYour matrix is:\n");
  printMatrix(matrix);
  sortMatrix(matrix);
  printf("Your sorted matrix is:\n");
  printMatrix(matrix);
  extraTasks(matrix);
}

void printMatrix(int Matrix[5][5])
{
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++)
      printf("%4d", Matrix[i][j]);
    printf("\n");
  }
  printf("\n");
}

void sortMatrix(int Matrix[5][5])
{
  int temp, Void;
  for (int i = 0; i < 5; i++)
    for (int j = 1; j < 5; j++) {
      temp = Matrix[i][j];
      Void = j - 1;
      while ((temp > Matrix[i][Void]) && (Void >= 0)) {
        Matrix[i][Void + 1] = Matrix[i][Void];
        Void -= 1;
      }
      Matrix[i][Void + 1] = temp;
    }
}

void extraTasks(int Matrix[5][5]) {
  double sum = 0.0, aValue, d = 1.0;
  int s = 0, k;
  for (int j = 3, i = 0; j >= 0; j--) {
    k = i;
    for (k; k >= 0; k--) {
      sum = sum + Matrix[k][j];
      s++;
    }
    i++;
    aValue = sum / s;
    printf("average value is %3.5lf\n", aValue);
    sum = 0.0;
    d = d * aValue;
    s = 0;
  }
  printf("product of average values is %3.2lf\n\n", d);

}

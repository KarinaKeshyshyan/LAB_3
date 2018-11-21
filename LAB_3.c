#include<stdio.h>
#define matrixSize 5
void printMatrix(int Matrix[matrixSize][matrixSize]);
void sortMatrix(int Matrix[matrixSize][matrixSize]);
void extraTasks(int Matrix[matrixSize][matrixSize]);

int main(void)
{
	printf("Input matrix' elements:\n");
	int matrix[matrixSize][matrixSize];
	for (int column = 0; column < 5; column++)
		for (int line = 0; line < 5; line++) {
			printf("element[%d][%d]= ", column + 1, line + 1);
			scanf_s("%d", &matrix[column][line]);
		}
	printf("\n\nYour matrix is:\n");
	printMatrix(matrix);
	sortMatrix(matrix);
	printf("Your sorted matrix is:\n");
	printMatrix(matrix);
	extraTasks(matrix);
	getchar();
}

void printMatrix(int Matrix[matrixSize][matrixSize])
{
	for (int column = 0; column < 5; column++) {
		for (int line = 0; line < 5; line++)
			printf("%4d", Matrix[column][line]);
		printf("\n");
	}
	printf("\n");
}

void sortMatrix(int Matrix[matrixSize][matrixSize])
{
	int temp, Void;
	for (int column = 0; column < 5; column++)
		for (int line = 1; line < 5; line++) {
			temp = Matrix[column][line];
			Void = line - 1;
			while ((temp > Matrix[column][Void]) && (Void >= 0)) {
				Matrix[column][Void + 1] = Matrix[column][Void];
				Void -= 1;
			}
			Matrix[column][Void + 1] = temp;
		}
}

void extraTasks(int Matrix[matrixSize][matrixSize]) {
	double sum = 0.0, aValue, d = 1.0;
	int s = 0, k;
	for (int line = 3, column = 0; line >= 0; line--) {
		k = column;
		for (k; k >= 0; k--) {
			sum = sum + Matrix[k][line];
			s++;
		}
		column++;
		aValue = sum / s;
		printf("average value is %3.5lf\n", aValue);
		sum = 0.0;
		d = d * aValue;
		s = 0;
	}
}
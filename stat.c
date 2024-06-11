#include <stdio.h>
#define NMAX 10
int input(int *a, int *n, int *check);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
  int n, data[NMAX], check = 0;
  input(data, &n, &check);
  if (check == 0) {
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(n));
  }
  return 0;
}

int input(int *a, int *n, int *check) {
  printf("Напиши сколько элементов будешь вводить: ");
  if (scanf("%d", n) == 1 && getchar() == '\n') {
    for (int i = 0; i < *n; i++) {
      printf("Введи число %d: ", i + 1);
      if (scanf("%d", &a[i]) != 1 || getchar() != '\n') {
        printf("n/a\n");
        *check = 1;
        break;
      }
    }
  } else {
    printf("n/a\n");
    *check = 1;
  }
  return 0;
}

void output(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int max(int *a, int n) {
  int max = *a;
  for (int i = 0; i < n; i++) {
    if (max < a[i]) {
      max = a[i];
    }
  }
  return max;
}

int min(int *a, int n) {
  int min = *a;
  for (int i = 0; i < n; i++) {
    if (min > a[i]) {
      min = a[i];
    }
  }
  return min;
}

double mean(int *a, int n) {
  double summ = 0;
  for (int i = 0; i < n; i++) {
    summ += a[i];
  }
  return (summ / n);
}

double variance(int n) { return ((n * n) - 1) / 12.0; }

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
  printf("%d %d %f %f\n", max_v, min_v, mean_v, variance_v);
}
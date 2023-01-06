int main() {
    int N;
    double a;
    double sum = 0;

    // Опитування користувача
  do {
    printf("Enter N: ");
    scanf("%d", &N);
  } while(N<1);
    printf("Enter a: ");
    scanf("%lf", &a);

    // Обрахунок суми
    double term = a;
    for (int n = 1; n <= N; n++) {
        sum += term / n;
        term *= a;
    }

    // Виведення результату
    printf("Sum = %lf\n", sum);

    return 0;
}

int main() {
    int N;
    double a;
    double sum = 0;

    // ���������� �����������
  do {
    printf("Enter N: ");
    scanf("%d", &N);
  } while(N<1);
    printf("Enter a: ");
    scanf("%lf", &a);

    // ��������� ����
    double term = a;
    for (int n = 1; n <= N; n++) {
        sum += term / n;
        term *= a;
    }

    // ��������� ����������
    printf("Sum = %lf\n", sum);

    return 0;
}

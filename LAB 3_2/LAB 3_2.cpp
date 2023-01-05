#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double chord(double x1, double x2, double epsilonilon, unsigned int iteration, unsigned int N);
double half_div(double x1, double x2, double epsilon, unsigned int iteration, unsigned int N);
double func(double);

int main()
{
    double x1, x2, epsilon, time;
    unsigned int variant, need_iterations, N;
    time_t start, end;
    while (1)
    {
        do
        {
            printf("Choose Method:\n1 = Metod Chord\n2 = Half-Division method\n");
            scanf("%u", &variant);
        } while (variant != 1 && variant != 2);
        do
        {
            printf("Show count of iteranions?\n1 = Yes\n2 = No\n");
            scanf("%u", &need_iterations);
            system("cls");
            if (need_iterations == 1)
            {
                do
                {
                    printf("Enter:\nN(>=1): ");
                    scanf("%u", &N);
                } while (N < 1);
            }
            else N = 1;
        } while (need_iterations != 1 && need_iterations != 2);
        printf("\nX1:");
        scanf("%lf", &x1);
        printf("\nX2:");
        scanf("%lf", &x2);
        printf("\nepsilonilon(>0.00001):");
        scanf("%lf", &epsilon);
        system("cls");
        while (func(x1) * func(x2) > 0 || epsilon < 0.00001)
        {
            if (func(x1) * func(x2) > 0)
            {
                printf("\nNo answers\nEnter:\nX1:");
                scanf("%lf", &x1);
                printf("\nx2:");
                scanf("%lf", &x2);
            }
            else if (epsilon < 0.00001)
            {
                printf("epsilonilon to low\nEnter:\nepsilonilon:");
                scanf("%lf", &epsilon);
            }
        }
        start = clock();
        switch (variant)
        {
        case 1:
            printf("Xi = %.10lf\n", chord(x1, x2, epsilon, need_iterations, N));
            break;
        case 2:
            printf("Xi = %.10lf\n", half_div(x1, x2, epsilon, need_iterations, N));
            break;
        }
        end = clock();
        time = (end - start);
        if (need_iterations == 2) printf("\tUsed Time: %.lfms\n", time);
        return 0;
    }
}

double func(double x)
{
    double y;
    y = 0.25 * pow(x - 25, 2) + pow(x + 25, 3) / 100;
    return y;
}

double chord(double x1, double x2, double epsilon, unsigned int need_iterations, unsigned int N)
{
    double xi;
    while (fabs(func(xi)) > epsilon)
    {
        xi = (func(x2) * x1 - func(x1) * x2) / (func(x2) - func(x1));
        if (func(xi) * func(x1) > 0) x1 = xi;
        else x2 = xi;
        if (need_iterations == 1)
        {
            printf("Xi = %.10lf\n", xi);
            unsigned int i;
            i++;
            if (i >= N)
            {
                i = 0;
            }
        }
    }
    return xi;
}

double half_div(double x1, double x2, double epsilon, unsigned int need_iterations, unsigned int N)
{
    double xi;
    while (fabs(x2 - x1) >= epsilon)
    {
        xi = (x1 + x2) / 2;
        if (func(xi) == 0) break;
        else if (func(xi) * func(x1) > 0) x1 = xi;
        else x2 = xi;
        if (need_iterations == 1)
        {
            printf("Xi = %.10lf\n", xi);
            unsigned int i;
            i++;
            if (i >= N)
            {
                i = 0;
            }
        }
    }
    return xi;


}
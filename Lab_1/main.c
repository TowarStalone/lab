#include <stdio.h>
#include <stdlib.h>
#define Name "Oleksii"
#define LastName "Mukhanov"
#define GroupName "PE-22"
#define Faculty "RTF"
#define University "Igor Sikorsky Kyiv Politehnic Institute"
int main()
{

 unsigned int semestr;
 float nmtscore;
 int mark1;
 int mark2;
 int mark3;
 int mark4;
 int mark5;
 double averagemark;
 unsigned int age;
printf("%s %s Follow commands:\n", Name, LastName);
 printf("Enter semestr:");
 scanf("%u", &semestr);
 printf("Enter your competitive score: ");
 scanf("%f", &nmtscore);
 printf("Enter mark #1: ");
 scanf("%d", &mark1);
 printf("Enter mark #2:");
 scanf("%d", &mark2);
 printf("Enter mark #3:");
 scanf("%d", &mark3);
 printf("Enter mark #4:");
 scanf("%d", &mark4);
 printf("Enter mark #5:");
 scanf("%d", &mark5);
 printf("Enter your age: ");
 scanf("%u", &age);
 averagemark = (double)(mark1 + mark2 + mark3+mark4+mark5) / 5;
 system("cls");
 printf("%s", University);
 printf("\n%s", Faculty);
 printf("\n%s", GroupName);
 printf("\n***************");
 printf("\n Student: %s %s", Name, LastName );
 printf("\n Age: %u", age);
 printf("\n Semestr: %u", semestr);
 printf("\n===============");
 printf("\n Competetive score: %.1f", nmtscore);
 printf("\n Average mark = %.2lf", averagemark);
 printf("\n");
 return 0;

}

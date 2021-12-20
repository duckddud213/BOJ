#include <stdio.h>

int main()
{
    long long S;
    long long a, b;

    scanf("%lld", &S);

    a = 1;
    while ((a * (a + 1)) / 2 <= S)
    {
        a++;
    }
    printf("%lld", a - 1);
}
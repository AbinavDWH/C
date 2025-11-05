#include <stdio.h>

int main() {
    int b,ep,md;
    printf("Base:");
    scanf("%d",&b);
    printf("\nExp :");
    scanf("%d",&ep);
    printf("\nMOD :",md);
    scanf("%d",&md);

    __int128 base = b;
    __int128 exp = ep;
    __int128 mod = md;
    __int128 result = 1;

    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }

    long long out = (long long)result;
    printf("%lld\n", out);
}

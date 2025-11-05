#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b) {
        long long tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%lld\n", gcd(a, b));
}

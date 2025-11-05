#include <stdio.h>

int main() {
    __int128 base = 3;
    __int128 exp = 100;
    __int128 mod = 101;
    __int128 result = 1;

    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }

    // printing __int128 is tricky:
    long long out = (long long)result; // safe if small enough
    printf("%lld\n", out);
}

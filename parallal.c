#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 8

typedef __int128 i128;

i128 *dp;
int n;

typedef struct {
    int start;
    int end;
} Task;

// Convert __int128 to decimal string
void print_i128(i128 x) {
    if (x == 0) {
        printf("0");
        return;
    }

    char buf[50];
    int idx = 0;
    int neg = 0;

    if (x < 0) {
        neg = 1;
        x = -x;
    }

    while (x > 0) {
        buf[idx++] = '0' + (x % 10);
        x /= 10;
    }

    if (neg) printf("-");

    for (int i = idx - 1; i >= 0; i--)
        printf("%c", buf[i]);
}

void* worker(void* arg) {
    Task* t = (Task*)arg;

    for (int i = t->start; i <= t->end; i++) {
        dp[i] = dp[i-1] + dp[i-3];
    }

    return NULL;
}

int main() {
    scanf("%d", &n);

    if (n < 2) {
        printf("1\n");
        return 0;
    }

    dp = calloc(n+1, sizeof(i128));
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = dp[1] + 0;  // dp[-1] treated as 0

    pthread_t th[THREADS];
    Task tasks[THREADS];

    int chunk = (n + THREADS - 1) / THREADS;

    for (int i = 0; i < THREADS; i++) {
        tasks[i].start = 3 + i * chunk;
        tasks[i].end   = (i+1)*chunk + 2;
        if (tasks[i].end > n) tasks[i].end = n;

        pthread_create(&th[i], NULL, worker, &tasks[i]);
    }

    for (int i = 0; i < THREADS; i++)
        pthread_join(th[i], NULL);

    print_i128(dp[n]);
    printf("\n");

    free(dp);
    return 0;
}

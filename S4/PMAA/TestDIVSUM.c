#include <stdio.h>

unsigned int divisor_summation(unsigned int n) {
    unsigned int summation = 1; // 1 is always a divisor of any number
    for (unsigned int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            summation += i;
            if (i != n / i) {
                summation += n / i;
            }
        }
    }
    return summation;
}

int main() {
    int num_test_cases;
    scanf("%d", &num_test_cases);

    // Process each test case
    for (int i = 0; i < num_test_cases; i++) {
        unsigned int n;
        scanf("%u", &n);
        printf("%u\n", divisor_summation(n));
    }

    return 0;
}

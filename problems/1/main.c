#include <stdio.h>

int sum_of_multiples_of_3_and_5(int start, int end, int step) {
    int result = 0;
    for (int s = start; s < end; s += step) {
        if (s % 3 == 0 || s % 5 == 0) {
            result += s;
        }
    }
    return result;
}

int main(void) {
    int test = sum_of_multiples_of_3_and_5(0, 10, 1);
    printf("  TEST = %d\n", test);

    int result = sum_of_multiples_of_3_and_5(0, 1000, 1);
    printf("RESULT = %d\n", result);

    return 0;
}

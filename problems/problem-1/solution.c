#include <stdio.h>

#include "../../utils.h"

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
	result_of(sum_of_multiples_of_3_and_5(0,   10, 1), "%d");
	result_of(sum_of_multiples_of_3_and_5(0, 1000, 1), "%d");
    return 0;
}

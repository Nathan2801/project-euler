// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143?

#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#include "../../utils.h"

// You can read it like: (base^exp) % mod;
// This method avoid overflows and turn the operation
// from O(exp) to O(log exp).
uint64_t pow_mod(uint64_t base, int64_t exp, int64_t mod) {
	uint64_t result = 1;
	base %= mod;
	while (exp > 0) {
		if (exp & 1) {
			result = (result * base) % mod;
		}
		base = (base * base) % mod;
		exp >>= 1;
	}
	return result;
}

bool fermet_primality_test(uint64_t n, uint64_t k) {
	if (n <= 1 || n == 4) {
		return false;
	} else if (n <= 3) {
		return true;
	}

	for (uint64_t i = 0; i < k; i++) {
		uint64_t a = 2 + rand() % (n - 3);
		if (pow_mod(a, n - 1, n) != 1) {
			return false;
		}
	}
	return true;
}

int64_t largest_prime_factor_of(int64_t n) {
	for (int64_t i = 2; i < n / 2; i++) {
		int64_t y = n / i;
		if (n % y == 0) {
			if (fermet_primality_test(y, 2)) {
				return y;
			}
		}
	}
	return 0;
}

int main(void) {
	srand(time(NULL)); // Runtime randomness for primality test.
	result_of(largest_prime_factor_of(13195), "%lld");
	result_of(largest_prime_factor_of(600851475143), "%lld");
	return 0;
}

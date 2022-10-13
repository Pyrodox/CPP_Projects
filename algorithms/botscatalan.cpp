#include <iostream>
#include <cassert>
#include <vector>

const int MOD = 1e9 + 7;

long long pow(long long base, long long exp) {
	assert(exp >= 0);
	base %= MOD;
	long long res = 1;
	while (exp > 0) {
		if (exp % 2 == 1)  // if n is odd
			res = res * base % MOD;
		base = base * base % MOD;
		exp /= 2;
	}
	return res;
}

long long mod_inv(long long n) {
	return pow(n, MOD - 2);
}

int main() {
	int max_moves;
	std::cin >> max_moves;

	long long total_states = 1;
	long long curr_level = 1;
	for (int l = 1; l <= max_moves; l++) {
		curr_level = (curr_level * 2) % MOD;
		total_states = (total_states + curr_level) % MOD;
	}

	// we have to multiply by 2 to get the actual # of one-child vertices
	long long half_one_child_num = 1;
	for (int l = max_moves + 1; l <= 2 * max_moves; l++) {
		curr_level = (2 * curr_level - 2 * half_one_child_num) % MOD;
		total_states = (total_states + curr_level) % MOD;

		half_one_child_num = (half_one_child_num * l) % MOD;
		half_one_child_num = (half_one_child_num * mod_inv(l - max_moves)) % MOD;
	}
	std::cout << (total_states + MOD) % MOD << std::endl;
}
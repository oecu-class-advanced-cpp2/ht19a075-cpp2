// sample01.cpp
#include <iostream>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。
using namespace std;

/* --------------------------------------------------------------- */
/*
* nth_prime
*
* 与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
* 素数を返す。
*
* TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
* ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */

// 動作：素数判定
// 戻り値：素数true, 素数でないfalse
bool is_prime(int n) {
	if (n == 0 || n == 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

// 動作：与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の素数を返す。
int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	int num;  // 数列
	int COUNT_N = 0;  // 素数の出た回数をカウント
	for (int i = 0;; i++) {
		num = i*d + a;
		// 素数の時の処理
		if (is_prime(num) == true) {
			COUNT_N++;
			if (COUNT_N == n) return num;
		}
	}
}

int main() {
	cout << nth_prime(367, 186, 151) << endl;
	cout << nth_prime(179, 10, 203) << endl;
	cout << nth_prime(271, 37, 39) << endl;
	cout << nth_prime(103, 230, 1) << endl;
	cout << nth_prime(27, 104, 185) << endl;
	cout << nth_prime(253, 50, 85) << endl;
	cout << nth_prime(1, 1, 1) << endl;
	cout << nth_prime(9075, 337, 210) << endl;
	cout << nth_prime(307, 24, 79) << endl;
	cout << nth_prime(331, 221, 177) << endl;
	cout << nth_prime(259, 170, 40) << endl;
	cout << nth_prime(269, 58, 102) << endl;

	return 0;
}
// ex-1-main.cpp 「ディレクトリの算術級数定理」
// 2021/12/9 ht19a075 古澤僚崇
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

int t_count = 0;  // 問題回数のカウント

// 動作: 出力結果と正解の比較を行う関数
void correct_check(unsigned int ans) {
	int correct[12] = { 92809, 6709, 12037, 103, 93523, 14503, 2, 899429, 5107, 412717, 22699, 25673 };
	if (ans == correct[t_count]) {
		cout << "正解" << " ";
	}
	else {
		cout << "不正解" << " ";
	}
	t_count++;
}

// 動作: 適切な入力がなかった場合の処理（不適切な値の表示）
bool unsigned_int_check(double k) {
	if (k < 0 || ceil(k) != floor(k)) {
		cout << "不適切な数字が含まれている." << "不適切は数値は:";
		t_count++;
		return false;
	}
	return true;
}

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
double nth_prime(double a, double d, double n) {
	int num;  // 数列
	int COUNT_N = 0;  // 素数の出た回数をカウント
	if (unsigned_int_check(a) == false) return a;  // aが適切な値かの判別
	if (unsigned_int_check(d) == false) return d;  // dが適切な値かの判別
	if (unsigned_int_check(n) == false) return n;  // nが適切な値かの判別
	for (int i = 0;; i++) {
		num = i*d + a;
		// 素数の時の処理
		if (is_prime(num) == true) {
			COUNT_N++;
			if (COUNT_N == n) {
				correct_check(num);
				return num;
			}
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

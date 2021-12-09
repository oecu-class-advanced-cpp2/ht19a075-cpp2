// ex-1-main.cpp �u�f�B���N�g���̎Z�p�����藝�v
// 2021/12/9 ht19a075 ���V����
#include <iostream>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B
using namespace std;

/* --------------------------------------------------------------- */
/*
* nth_prime
*
* �^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ�
* �f����Ԃ��B
*
* TODO: ���� nth_prime �֐�����������B�K�v�ł���Α��Ɋ֐���
* �t�@�C�����쐬����B
*/
/* -------------------------------------------------------------- */

int t_count = 0;  // ���񐔂̃J�E���g

// ����: �o�͌��ʂƐ����̔�r���s���֐�
void correct_check(unsigned int ans) {
	int correct[12] = { 92809, 6709, 12037, 103, 93523, 14503, 2, 899429, 5107, 412717, 22699, 25673 };
	if (ans == correct[t_count]) {
		cout << "����" << " ";
	}
	else {
		cout << "�s����" << " ";
	}
	t_count++;
}

// ����: �K�؂ȓ��͂��Ȃ������ꍇ�̏����i�s�K�؂Ȓl�̕\���j
bool unsigned_int_check(double k) {
	if (k < 0 || ceil(k) != floor(k)) {
		cout << "�s�K�؂Ȑ������܂܂�Ă���." << "�s�K�؂͐��l��:";
		t_count++;
		return false;
	}
	return true;
}

// ����F�f������
// �߂�l�F�f��true, �f���łȂ�false
bool is_prime(int n) {
	if (n == 0 || n == 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

// ����F�^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ̑f����Ԃ��B
double nth_prime(double a, double d, double n) {
	int num;  // ����
	int COUNT_N = 0;  // �f���̏o���񐔂��J�E���g
	if (unsigned_int_check(a) == false) return a;  // a���K�؂Ȓl���̔���
	if (unsigned_int_check(d) == false) return d;  // d���K�؂Ȓl���̔���
	if (unsigned_int_check(n) == false) return n;  // n���K�؂Ȓl���̔���
	for (int i = 0;; i++) {
		num = i*d + a;
		// �f���̎��̏���
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

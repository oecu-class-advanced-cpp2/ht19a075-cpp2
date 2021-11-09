// sample01.cpp
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

// �f������
// return �f���̎�true
bool is_prime(int n) {
	int flag = 0;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			flag = 1;
			break;
		}
	}
	if (flag == 0 && n > 1) return true;
	else return false; 
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	int COUNT_N = 0;
	int num;
	// �f�����ǂ����𔻒�
	for (int i = 0;; i++) {
		num = (a + i*d);
		if (num == 1)continue;
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
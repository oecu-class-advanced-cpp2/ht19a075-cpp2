//ex-2-main.cpp ���V����
#include <iostream>
#include <string>
#include <algorithm>

namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi

	mcxi �L�@����͂���N���X�ł��B
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	public:
		/* ----------------------------------------------------------------- */
		/*
		mcxi

		�w�肳�ꂽ���������͂��āA�I�u�W�F�N�g�����������܂��B
		�ȉ��̏ꍇ�ɂ͗�O���n�o����܂��B

		1. [2-9,m,c,x,i] �ȊO�̕������o�������ꍇ
		2. 2 ���������Đ��� (2-9) ���o�������ꍇ
		3. m, c, x, i �����̏����ŏo�����Ȃ������ꍇ
		�������A�Ⴆ�� mx �̂悤�ɁA����̕������X�L�b�v���鎖�͋��e
		����܂��B
		*/
		/* ----------------------------------------------------------------- */

		mcxi(const std::string& s) : value_(0) {
			int num = 0;
			int k = 10000;
			for (auto pos = s.begin(); pos != s.end(); ++pos) {
				if (*pos >= '2' && *pos <= '9') {
					if (num != 0) std::cout << "2 ���������Đ��� (2-9) ���܂܂�Ă��܂��B" << std::endl;  // 2 ���������Đ��� (2-9) ���o�������ꍇ
					num = *pos - '0';
				}
				else {
					int u = unit(*pos);
					if (u > k) std::cout << "m, c, x, i �����̏����ŏo�����Ȃ������B" << std::endl;  // m, c, x, i �����̏����ŏo�����Ȃ������ꍇ
					if (u == -1) {
						std::cout << "[2 - 9, m, c, x, i] �ȊO�̕������܂܂�Ă��܂��B" << std::endl;  // [2-9,m,c,x,i] �ȊO�̕������o�������ꍇ
					}else {
						k = u;
					}
					value_ += std::max(num, 1) * u;
					num = 0;
				}
			}
		}

		/* ----------------------------------------------------------------- */
		/*
		operator+

		2 �̃I�u�W�F�N�g�̉��Z���ʂ��擾���܂��B
		*/
		/* ----------------------------------------------------------------- */
		mcxi operator+(const mcxi& rhs) { //value�̑����Z������B
			mcxi tc(rhs);
			tc.value_ = this->value_ + rhs.value_;
			return tc;
		}

		/* ----------------------------------------------------------------- */
		/*
		to_string

		���݂̒l�� mcxi �L�@�ɕϊ����܂��B
		*/
		/* ----------------------------------------------------------------- */
		std::string to_string() const { //value��mcxi�ɂ���B1000�Ŋ���B100�Ŋ���B.....
			std::string str;
			int cal = value_;
			if (cal / 1000 >= 1) {
				if (cal / 1000 == 1) {
					str += "m";
					cal -= 1000;
				}
				else {
					str += std::to_string(cal / 1000) + "m";
					cal -= (cal / 1000) * 1000;
				}
			};
			if (cal / 100 >= 1) {
				if (cal / 100 == 1) {
					str += "c";
					cal -= 100;
				}
				else {
					str += std::to_string(cal / 100) + "c";
					cal -= (cal / 100) * 100;
				}
			};
			if (cal / 10 >= 1) {
				if (cal / 10 == 1) {
					str += "x";
					cal -= 10;
				}
				else {
					str += std::to_string(cal / 10) + "x";
					cal -= (cal / 10) * 10;
				}
			};
			if (cal % 10 >= 1) {
				if (cal % 10 == 1) {
					str += "i";
				}
				else {
					str += std::to_string(cal % 10) + "i";
				}
			};
			return str;
		}

		std::string judgement_mcxi(std::string ss, int &Count_t) {  // ���𔻒�֐�
			std::string judgement[10] = { "3x", "x", "6cx", "5m9c9x9i", "m", "9m9c9x9i", "mi", "mi", "mx", "9m9c9x9i"};
			if (ss == judgement[Count_t]) {
				Count_t++;
				return "����";
			}
			else {
				Count_t++;
				return "�s����";
			}
		}

	private:
		int unit(char c) {
			switch (c) {
			case 'm': return 1000;
			case 'c': return  100;
			case 'x': return   10;
			case 'i': return    1;
			}
			return -1;
		}

	private:
		int value_;
	};
}

int main() {
	int Count_t = 0;
	cpp2::mcxi a0("txi");// xi
	cpp2::mcxi b0("x9i");
	auto result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string() << " " << result0.judgement_mcxi(result0.to_string(), Count_t) << std::endl;

	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	auto result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() << " " << result1.judgement_mcxi(result1.to_string(), Count_t) << std::endl;

	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	auto result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << " " << result2.judgement_mcxi(result2.to_string(), Count_t) << std::endl;

	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	auto result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << " " << result3.judgement_mcxi(result3.to_string(), Count_t) << std::endl;

	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	auto result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() << " " << result4.judgement_mcxi(result4.to_string(), Count_t) << std::endl;

	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9c8m9x8i");// 9m9c9x8i
	auto result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << " " << result5.judgement_mcxi(result5.to_string(), Count_t) << std::endl;

	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	auto result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << " " << result6.judgement_mcxi(result6.to_string(), Count_t) << std::endl;

	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	auto result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() << " " << result7.judgement_mcxi(result7.to_string(), Count_t) << std::endl;

	cpp2::mcxi a8("m97i");// m9i
	cpp2::mcxi b8("i");
	auto result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << " " << result8.judgement_mcxi(result8.to_string(), Count_t) << std::endl;

	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	auto result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string() << " " << result9.judgement_mcxi(result9.to_string(), Count_t) << std::endl;
}

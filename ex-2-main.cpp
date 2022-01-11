//ex-2-main.cpp 古澤僚崇
#include <iostream>
#include <string>
#include <algorithm>

namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi

	mcxi 記法を解析するクラスです。
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	public:
		/* ----------------------------------------------------------------- */
		/*
		mcxi

		指定された文字列を解析して、オブジェクトを初期化します。
		以下の場合には例外が創出されます。

		1. [2-9,m,c,x,i] 以外の文字が出現した場合
		2. 2 文字続けて数字 (2-9) が出現した場合
		3. m, c, x, i がこの順序で出現しなかった場合
		ただし、例えば mx のように、特定の文字をスキップする事は許容
		されます。
		*/
		/* ----------------------------------------------------------------- */

		mcxi(const std::string& s) : value_(0) {
			int num = 0;
			int k = 10000;
			for (auto pos = s.begin(); pos != s.end(); ++pos) {
				if (*pos >= '2' && *pos <= '9') {
					if (num != 0) std::cout << "2 文字続けて数字 (2-9) が含まれています。" << std::endl;  // 2 文字続けて数字 (2-9) が出現した場合
					num = *pos - '0';
				}
				else {
					int u = unit(*pos);
					if (u > k) std::cout << "m, c, x, i がこの順序で出現しなかった。" << std::endl;  // m, c, x, i がこの順序で出現しなかった場合
					if (u == -1) {
						std::cout << "[2 - 9, m, c, x, i] 以外の文字が含まれています。" << std::endl;  // [2-9,m,c,x,i] 以外の文字が出現した場合
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

		2 つのオブジェクトの加算結果を取得します。
		*/
		/* ----------------------------------------------------------------- */
		mcxi operator+(const mcxi& rhs) { //valueの足し算をする。
			mcxi tc(rhs);
			tc.value_ = this->value_ + rhs.value_;
			return tc;
		}

		/* ----------------------------------------------------------------- */
		/*
		to_string

		現在の値を mcxi 記法に変換します。
		*/
		/* ----------------------------------------------------------------- */
		std::string to_string() const { //valueをmcxiにする。1000で割る。100で割る。.....
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

		std::string judgement_mcxi(std::string ss, int &Count_t) {  // 正解判定関数
			std::string judgement[10] = { "3x", "x", "6cx", "5m9c9x9i", "m", "9m9c9x9i", "mi", "mi", "mx", "9m9c9x9i"};
			if (ss == judgement[Count_t]) {
				Count_t++;
				return "正解";
			}
			else {
				Count_t++;
				return "不正解";
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

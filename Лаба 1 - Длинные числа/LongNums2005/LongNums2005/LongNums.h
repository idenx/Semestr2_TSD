// Программа для умножения длинных чисел, 8 Вариант
// ИУ7-32, Исаев Денис
#pragma once

const char POINT  = '.';
const int MAXIMUM_NUMBER_LENGTH = 35;
const int MAXIMUM_ORDERED_NUMBER_LENGTH = 30;
const int ERROR_LENGTH = 64;

public class LongNums
{
    unsigned short int aDigits[MAXIMUM_NUMBER_LENGTH];
	int exponent_level;
	bool sign;


	void read_from_string(char* sNum);
	void create_null_obj();
	void normalize();
	void round(int rounded_length);
	void add_left_zero();
	int mantiss_length();
	void check_exp_level();

	static int str_to_int(char* int_num, bool *error);
    static short int parse_digit(char digit);
    static char parse_char(int digit);
	static LongNums sum(LongNums A, LongNums B);
	static LongNums multiply_long_to_digit(LongNums A, int digit);
public:
	char* error;
	LongNums(void);
	LongNums(char* sNum);
	~LongNums(void);
	static LongNums multiply(LongNums A, LongNums B);
	char* toString();

};


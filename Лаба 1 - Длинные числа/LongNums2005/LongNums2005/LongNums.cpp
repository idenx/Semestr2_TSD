// Программа для умножения длинных чисел, 8 Вариант
// ИУ7-32, Исаев Денис

#include "StdAfx.h"
#include "LongNums.h"
#include <stdlib.h>
#include "string.h"

LongNums::LongNums(void)
{
	this->create_null_obj();
}



LongNums::LongNums(char* sNum)
{
	this->create_null_obj();
	this->read_from_string(sNum);
	this->normalize();
}

void LongNums::create_null_obj() {
	for (int i = 0; i < MAXIMUM_NUMBER_LENGTH; i++) {
		this->aDigits[i] = 0;
	}
	this->exponent_level = 0;
	this->sign = false;
	this->error = new char[ERROR_LENGTH];
}

void LongNums::normalize() {
	int shift = 0;
	while(aDigits[shift] == 0) {
		shift++;
	}

	exponent_level -= shift;

	for (int j = 0; j <= MAXIMUM_NUMBER_LENGTH - shift - 1; j++) {
		aDigits[j] = aDigits[j + shift];
	}

}

void LongNums::round(int rounded_length) {
	for (int j = MAXIMUM_NUMBER_LENGTH - 1; j >= rounded_length; j--) {
		if (aDigits[j] < 5) {
			aDigits[j] = 0;
			continue;
		}
		for (int i = j - 1; i >= 0; i--) {
			if (aDigits[i] != 9) {
				aDigits[i]++;
				break;
			}
			else {
				if (i == 0) {
					aDigits[i] = 1;
					exponent_level++;
					break;
				}
				else {
					aDigits[i] = 0;
				}
			}
		}
		aDigits[j] = 0;
	}
}

LongNums::~LongNums(void)
{
	//delete [] error;
}

void LongNums::read_from_string(char* sNum) {
	bool err = false;
	//Считываем знак числа
	if (sNum[0] == '-') {
		sign = true;
		sNum++;
	}
	if (sNum[0] == '+') {
		sign = false;
		sNum++;
	}
	// Находим позицию точки и экспоненты в числе (если их нет, то позцияи равна нулю)
	char *stStart = sNum, *expStart = 0, *point_pos = 0;
	while(*sNum != '\0') {
		if (*sNum == POINT) {
			point_pos = sNum;
		}
		if ((*sNum == 'e') || (*sNum == 'E')){
			expStart = sNum;
			expStart++;
		}
		sNum++;
	}

	sNum = stStart;

	if (point_pos != 0) {
		if (expStart != 0) {

			// 1) Если в числе есть точка и экспонента
			exponent_level = str_to_int(expStart, &err) + (point_pos - sNum);
			if (err) {
				error = "input error";
				return;
			}
			for (int i = 0, j = 0; sNum[i] != ' '; i++) {
				if (sNum[i] != POINT) {
					if (parse_digit(sNum[i]) != -1) {
						aDigits[j] = parse_digit(sNum[i]); }
					else {
						error = "input error";
						return;						
					}
					j++;
				}
			}
		}
		else {

			// 2) Если в числе есть точка и нет экспоненты
			exponent_level = point_pos - sNum;
			for (int i = 0, j = 0; sNum[i] != '\0'; i++) {
				if (sNum[i] != POINT) {
					if (parse_digit(sNum[i]) != -1) {
						aDigits[j] = parse_digit(sNum[i]); }
					else {
						error = "input error";
						return;						
					}
					j++;
				}
			}
		}
	}
	else {

		// 3) Если в числе нет точки и экспоненты
		if (expStart == 0) {
			exponent_level = strlen(sNum);
			for (int i = 0; i < exponent_level; i++) {
				if (parse_digit(sNum[i]) != -1) {
					aDigits[i] = parse_digit(sNum[i]); }
				else {
					error = "input error";
					return;						
				}
			}
		}
		else {

			// 4) Если в числе нет точки и есть экспонента	
			err = false;
			exponent_level = (expStart - sNum - 2) + str_to_int(expStart, &err);
			if (err) {
				error = "input error";
				return;
			}
			for (int i = 0, j = 0; sNum[i] != ' '; i++) {
				if (sNum[i] != POINT) {
					if (parse_digit(sNum[i]) != -1) {
						aDigits[j] = parse_digit(sNum[i]); }
					else {
						error = "input error";
						return;						
					}
					j++;
				}
			}
		}

	}

}

short int LongNums::parse_digit(char digit) {
	switch (digit) {
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		return -1;
	}
}

int LongNums::mantiss_length() {
	int result = 0;
	while (aDigits[result] != 0) {
		result++;
	}
	return result;
}

void LongNums::add_left_zero() {
	this->round(MAXIMUM_NUMBER_LENGTH - 1);
	for (int i = MAXIMUM_NUMBER_LENGTH - 1; i > 0; i--) {
		aDigits[i] = aDigits[i - 1];
	}
	aDigits[0] = 0;
}

LongNums LongNums::sum(LongNums A, LongNums B) {
	LongNums result;
	result.exponent_level = A.exponent_level;
	int increment = 0;
	for (int i = MAXIMUM_NUMBER_LENGTH - 1; i >= 0; i--) {
		result.aDigits[i] = (A.aDigits[i] + B.aDigits[i] + increment) % 10;
		increment = (A.aDigits[i] + B.aDigits[i] + increment) / 10;
	}
	if (increment != 0) {
		result.add_left_zero();
		result.aDigits[0] = increment;
		result.exponent_level++;
	}

	//result.normalize();
	return result;
}

LongNums LongNums::multiply(LongNums A, LongNums B) {
	LongNums result, temp;
	int A_len = A.mantiss_length();
	int B_len = B.mantiss_length();
	int A_degree = A.exponent_level;
	int B_degree = B.exponent_level;
	int max_len = A_len + B_len;
	temp = multiply_long_to_digit(A, B.aDigits[0]);
	int tmplen = temp.mantiss_length() + (B_len - 1) - (A_len + B_len);
	int max_shift = (B_len - 1) + temp.exponent_level - A.exponent_level;
	for (int i = MAXIMUM_NUMBER_LENGTH - 1; i >= 0; i--) {
		if (B.aDigits[i] != 0) {
			temp = multiply_long_to_digit(A, B.aDigits[i]);

			int current_shift = max_shift <= 0 ? 0 : max_shift - (temp.exponent_level - A.exponent_level);

			max_shift--;
			for (int i = 1; i <= current_shift ; i++) {
				temp.add_left_zero();
			}

			result = sum(result, temp);
		}
	}

	result.exponent_level = A_degree + B_degree + tmplen;
	if (A.sign) {
		if (B.sign) {
			result.sign = false; }
		else {
			result.sign = true; }
	}
	else {
		if (B.sign) {
			result.sign = true; }
		else {
			result.sign = false; }
	}
	result.normalize();
	
	result.check_exp_level();
	return result;
}

LongNums LongNums::multiply_long_to_digit(LongNums A, int digit) {
	LongNums result;
	result.exponent_level = A.exponent_level;
	int increment = 0;
	for (int i = MAXIMUM_NUMBER_LENGTH - 1; i >= 0; i--) {
		result.aDigits[i] = (A.aDigits[i] * digit + increment) % 10;
		increment = (A.aDigits[i] * digit + increment) / 10;
	}
	if (increment != 0) {
		result.add_left_zero();
		result.aDigits[0] = increment;
		result.exponent_level++;
	}

	result.normalize();
	return result;
}

char* LongNums::toString() {
	this->normalize();
	this->round(MAXIMUM_ORDERED_NUMBER_LENGTH);
	int size = this->mantiss_length();
	char *result = new char[size + 10];
	if (size == 0) {
		result = "0";
		return result;
	}

	char *result_copy = result;
	if (sign) {
		*result = '-'; result++; }
	*result = '0'; result++;
	*result = POINT; result++;
	for (int i = 0; i < size; i++, result++) {
		*result = parse_char(aDigits[i]);
	}
	*result = ' ';
	result++;
	*result = 'e';
	result++;

	char buf[7];
	char* temp = _itoa(exponent_level, buf, 10);
	for (int i = 0; i < strlen(temp); i++, result++) {
		*result = temp[i];
	}

	*result = '\0';
	return result_copy;
}

char LongNums::parse_char(int digit) {
	switch (digit) {
	case 0:
		return '0';
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	default:
		return '*';
	}
}


int LongNums::str_to_int(char* int_num, bool *error) {
	int result = 0;
	for (int i = 0; i < strlen(int_num); i++) {
		*error = true;	
		for (char ch = '0'; ch <= '9'; ch++) {
			if (int_num[i] == ch) {
				*error = false;
				break;
			}
		}
		if (*error) {
			if (int_num[0] == '-' || int_num[0] == '+') {
				*error = false; 
			}
			else {
				return 0;
			}
		}
	}

	try {
		result = atoi(int_num);
	}
	catch(int i) {
		*error = true;
	}
	return result;

}

void LongNums::check_exp_level() {
	if (abs(exponent_level) > 99999)
		error = "exp_of";
	if (aDigits[0] == 0) 
		exponent_level = 0;
}
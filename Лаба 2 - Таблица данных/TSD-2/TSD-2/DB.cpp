#include "DB.h"
#include <string.h>
#include "stdlib.h"
#include <stdio.h>
#include <io.h>
#include <time.h>
using namespace std;


bool TDatabase::add_subscriber(char* name, char* surname, char* phone, char* address, status_type status,
	short int birth_day, short int birth_month, short int birth_year) {
		TSubscriber *result = new TSubscriber;
		
		result->id = db_size;
		strncpy_s(result->name, name, NAME_LENGTH);
		strncpy_s(result->surname, surname, SURNAME_LENGTH);
		strncpy_s(result->phone, phone, PHONE_LENGTH);
		strncpy_s(result->address, address, ADDRESS_LENGTH);
		result->status = status/* == 0 ? PERSONAL : OFFICIAL*/;
		result->birth_day = birth_day;
		result->birth_month = birth_month;
		result->birth_year = birth_year;

		return this->add_subscriber(result);

}

void TDatabase::gen_base() {
	FILE* names = fopen("names.txt", "r");
	FILE* surnames = fopen("surnames.txt", "r");
	FILE* prof = fopen("prof.txt", "r");
	FILE* comp = fopen("companies.txt", "r");
	FILE* adr = fopen("adr.txt", "r");

	char* anames[255];
	char* asurnames[1270];
	char* aprof[305];
	char* acomp[80];
	char* aadr[1500];

	int i = 0;
	while (!feof(names)) {
		anames[i] = new char[50];
		fgets(anames[i], 100, names);
		i++;
	}
	int names_num = i;

	i = 0;
	while (!feof(surnames)) {
		asurnames[i] = new char[50];
		fgets(asurnames[i], 100, surnames);
		i++;
	}
	int surnames_num = i;

	i = 0;
	while (!feof(prof)) {
		aprof[i] = new char[50];
		fgets(aprof[i], 100, prof);
		i++;
	}
	int prof_num = i;

	i = 0;
	while (!feof(comp)) {
		acomp[i] = new char[50];
		fgets(acomp[i], 100, comp);
		i++;
	}
	int comp_num = i;

	i = 0;
	while (!feof(adr)) {
		aadr[i] = new char[50];
		fgets(aadr[i], 100, adr);
		i++;
	}
	int adr_num = i;

	FILE* f = fopen("db_gen.dat", "wb");

	TSubscriber* man = new TSubscriber[305];
	// Создание базы:
	char* tmp;
	int num = 12345;
	for (int i = 0; i < 300; i++) {

	
		tmp = anames[i % 230];
		for (int j = 0; j < strlen(tmp); j++) {
			man->name[j] = tmp[j];
		}
		man->name[strlen(tmp) - 1] = '\0';
		 
		tmp = asurnames[i];
		for (int j = 0; j < strlen(tmp); j++) {
			man->surname[j] = tmp[j];
		}
		man->surname[strlen(tmp) - 1] = '\0';

		man->phone[0] = '8';
		man->phone[1] = '9';
		man->phone[2] = '2';
		man->phone[3] = '6';
		char buf[2];

		for (int j = 0; j < 7; j++) {
			itoa((num % (i + j + 1)) % 10, buf, 10);
			man->phone[j + 4] = buf[0];
		}
		man->phone[11] = '\0';

		tmp = aadr[i];
		for (int j = 0; j < strlen(tmp); j++) {
			man->address[j] = tmp[j];
		}
		man->address[strlen(tmp) - 1] = '\0';

		int status = i % 2;

		if (status == 0) {
			man->status = PERSONAL;
			man->birth_day = i % 28 + 1;
			man->birth_month = i % 11 + 1;
			man->birth_year = 1900 + (i % 100);
		}
		else {
			man->status = OFFICIAL;
			tmp = aprof[i % 280];
			for (int j = 0; j < strlen(tmp); j++) {
				man->post[j] = tmp[j];
			}
			man->post[strlen(tmp) - 1] = '\0';


			tmp = acomp[i % 68];
			for (int j = 0; j < strlen(tmp); j++) {
				man->company[j] = tmp[j];
			}
			man->company[strlen(tmp) - 1] = '\0';
		}

		
			fwrite(man, sizeof(TSubscriber), 1, f);
			man++;
	}
	fclose(f);
}

bool TDatabase::add_subscriber(char* name, char* surname, char* phone, char* address, status_type status,
	char* post, char* company) {
		TSubscriber *result = new TSubscriber;

		result->id = db_size;
		strncpy_s(result->name, name, NAME_LENGTH);
		strncpy_s(result->surname, surname, SURNAME_LENGTH);
		strncpy_s(result->phone, phone, PHONE_LENGTH);
		strncpy_s(result->address, address, ADDRESS_LENGTH);
		strncpy_s(result->post, post, POST_LENGTH);
		strncpy_s(result->company, company, COMPANY_LENGTH);
		result->status = status;	
		
		return this->add_subscriber(result);

}

bool TDatabase::add_subscriber(TSubscriber* subscriber){
	if (this->space_size == this->db_size){
		this->space_size *= KOEFFICIENT;
		this->space_size++;

		// Добавляем в дин. массив структур
		TSubscriber* tmp = new TSubscriber[this->space_size];
		for (int i = 0; i < this->db_size; i++) {
			tmp[i] = this->db[i];
		}

		this->db_size++;
		tmp[this->db_size - 1] = *subscriber;
		delete [] this->db;
		this->db = tmp;

		// Добавляем в таблицу ключей
		TKeyTable* newTable = new TKeyTable[this->space_size];
		for (int i = 0; i < this->db_size - 1; i++) {
			newTable[i] = this->key_table[i];
		}
		delete [] this->key_table;
		
		TKeyTable tempTable;
		tempTable.id = subscriber->id;
		strncpy_s(tempTable.surname, subscriber->surname, SURNAME_LENGTH);
		newTable[this->db_size - 1] = tempTable;

		this->key_table = newTable;

		// Удалить аргумент
	}
	else {
		// Добавляем в дин. массив структур
		this->db_size++;
		this->db[this->db_size - 1] = *subscriber;

		// Добавляем в таблицу ключей
		TKeyTable tmp3;
		tmp3.id = subscriber->id;
		strncpy_s(tmp3.surname, subscriber->surname, SURNAME_LENGTH);
		this->key_table[this->db_size - 1] = tmp3;
	}

	return true;
}

TDatabase::TDatabase() {
	this->db = new TSubscriber;
	this->key_table = new TKeyTable;
	this->db_size = 0;
	this->space_size = 0;
}

TDatabase::~TDatabase() {
	delete [] this->db;
	delete [] this->key_table;
}

bool TDatabase::delete_subscriber(int id) {

	// здесь удаление из таблицы ключей
	for (int i = id; i < db_size - 1; i++) {
		key_table[i] = key_table[i + 1]; 
	}
	db_size--;


	return true;
}

bool TDatabase::save_to_file(FILE *db_file) {
//	fwrite(db, sizeof(TSubscriber), db_size, db_file);

	for (int i = 0, k = 0; i < db_size; i++) {
		k = key_table[i].id;
		fwrite(db + k, sizeof(TSubscriber), 1, db_file);
	}

	return true;
}

bool TDatabase::open_from_file(FILE *db_file) {
	int status = 0;
	TSubscriber* tmp = new TSubscriber[350];
	int num = filelength(fileno(db_file)) / sizeof(TSubscriber);

	for (int i = 0; i < num; i++) {	
		fread(tmp, sizeof(TSubscriber), 1, db_file);
		tmp->id = db_size;
		add_subscriber(tmp);
		tmp++;
	}
	return true;
}

void TDatabase::Create() {
	db = new TSubscriber;
	key_table = new TKeyTable;
	db_size = 0;
	this->space_size = 0;
}

TDatabase* TDatabase::get_copy(){
	TDatabase *result = new TDatabase;
	int size = this->db_size;
	result->db = new TSubscriber[size];
	for (int i = 0; i < size; i++) {
		result->db[i] = this->db[i];
	}

	result->key_table = new TKeyTable[size];
	for (int i = 0; i < size; i++) {
		result->key_table[i] = this->key_table[i];
	}
	result->db_size = size;
	result->space_size = this->space_size;
	return result;
}

int compare_tables (TKeyTable *a, TKeyTable *b)
{
	char *s1, *s2;
	s1 = new char[30];
	char tmp = 'a';
	for (int i = 0; tmp != '\0'; i++) {
		tmp = a->surname[i];
		s1[i] = tmp;
	}
	s2 = new char[30];
	tmp = 'a';
	for (int i = 0; tmp != '\0'; i++) {
		tmp = b->surname[i];
		s2[i] = tmp;
	}


	int res = strcmp(s1, s2); // Сделать безопасную версию функции
	delete [] s1;
	delete [] s2;
	return res;
}


int compare_subscribers (TSubscriber *a, TSubscriber *b)
{
	char *s1, *s2;
	s1 = new char[30];
	char tmp = 'a';
	for (int i = 0; tmp != '\0'; i++) {
		tmp = a->surname[i];
		s1[i] = tmp;
	}
	s2 = new char[30];
	tmp = 'a';
	for (int i = 0; tmp != '\0'; i++) {
		tmp = b->surname[i];
		s2[i] = tmp;
	}

	int res = strncmp(s1, s2, SURNAME_LENGTH); // Сделать безопасную версию функции
	delete [] s1;
	delete [] s2;
	return res;
}

bool TDatabase::quick_sort() {
	test_quick_sort_with_table(key_table, db_size - 1);
	return true;
}

void TDatabase::test_quick_sort_without_table(TSubscriber* a, int size) {
	// На входе - массив a[], a[N] - его последний элемент.

	int i = 0, j = size; 		// поставить указатели на исходные места
	TSubscriber* temp = new TSubscriber;
	TSubscriber* p = new TSubscriber;

	*p = a[size / 2];		// центральный элемент

	// процедура разделения
	do {
		while (compare_subscribers(&(a[i]), p) < 0) i++;
		while (compare_subscribers(&(a[j]), p) > 0) j--;

		if (i <= j) {
			*temp = a[i]; a[i] = a[j]; a[j] = *temp;
			i++; j--;
		}
	} while (i<=j);

	delete temp;
	delete p;


	// рекурсивные вызовы, если есть, что сортировать 
	if (j > 0) this->test_quick_sort_without_table(a, j);
	if (size > i) this->test_quick_sort_without_table(a + i, size - i);
}

void TDatabase::test_quick_sort_with_table(TKeyTable* a, int size) {
	// На входе - массив a[], a[N] - его последний элемент.
	
	int i = 0, j = size; 		// поставить указатели на исходные места
	TKeyTable* temp = new TKeyTable;
	TKeyTable* p = new TKeyTable;

	*p = a[size / 2];		// центральный элемент

	// процедура разделения
	do {
		while (compare_tables(&(a[i]), p) < 0) i++;
		while (compare_tables(&(a[j]), p) > 0) j--;

		if (i <= j) {
			*temp = a[i]; a[i] = a[j]; a[j] = *temp;
			i++; j--;
		}
	} while (i<=j);

	delete temp;
	delete p;

	// рекурсивные вызовы, если есть, что сортировать 
	if (j > 0) this->test_quick_sort_with_table(a, j);
	if (size > i) this->test_quick_sort_with_table(a + i, size - i);
}

bool TDatabase::test_selection_sort_with_table(){
	for (int i = 0; i < db_size - 1; ++i) {
		int min_i = i;
		for (int j = i + 1; j < db_size; ++j) {
			if (compare_tables(&(key_table[min_i]), &(key_table[j])) > 0) {
				min_i = j;
			}
		}
		TKeyTable temp = key_table[i];
		key_table[i] = key_table[min_i];
		key_table[min_i] = temp;
	}
	return true;

}

bool TDatabase::test_selection_sort_without_table() {
	for (int i = 0; i < db_size - 1; ++i) {
		int min_i = i;
		for (int j = i + 1; j < db_size; ++j) {
			if (compare_subscribers(&(db[min_i]), &(db[j])) > 0) {
				min_i = j;
			}
		}
		TSubscriber temp = db[i];
		db[i] = db[min_i];
		db[min_i] = temp;
	}
	return true;
}

bool TDatabase::selection_sort() {
	return test_selection_sort_with_table();
}

bool TDatabase::shake() {
	TKeyTable tmp;
	TSubscriber temp;
	for (int i = 0, rnd1 = 0; i < db_size; i++) {
		rnd1 = rand() % db_size;
		
		tmp = key_table[i];
		key_table[i] = key_table[rnd1];
		key_table[rnd1] = tmp;
	}
	return true;
}
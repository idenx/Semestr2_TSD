
enum error_type {
	EMPTY_INPUT,
	DAY_INCORRECT_INPUT,
	MONTH_INCORRECT_INPUT,
	YEAR_INCORRECT_INPUT
};

const float KOEFFICIENT = 1.3;
enum status_type {PERSONAL, OFFICIAL};
const int NAME_LENGTH = 30;
const int SURNAME_LENGTH = 30;
const int PHONE_LENGTH = 12;
const int ADDRESS_LENGTH = 100;
const int POST_LENGTH = 30;
const int COMPANY_LENGTH = 30;

#include <iosfwd>
using namespace std;

typedef struct TSubscriber {
	int id;
	char name[NAME_LENGTH];
	char surname[SURNAME_LENGTH];
	char phone[PHONE_LENGTH];
	char address[ADDRESS_LENGTH];
	status_type status;
	union {
		struct {
			short int birth_day;
			short int birth_month;
			short int birth_year;
		};
		struct {
			char post[POST_LENGTH];
			char company[POST_LENGTH];
		};
	};
};

typedef struct TKeyTable {
	int id;
	char surname[SURNAME_LENGTH];
};

public class TDatabase {
	bool TDatabase::add_subscriber(TSubscriber* subscriber);
	int space_size;
public:

	TSubscriber* db;
	TKeyTable* key_table;
	int db_size;


	// Методы класса
	TDatabase();
	~TDatabase();
	void Create();
	TDatabase* get_copy();

 	bool save_to_file(FILE* db_file);
  	bool open_from_file(FILE* db_file);
	bool add_subscriber(char* name, char* surname, char* phone, char* address, status_type status,
		short int birth_day, short int birth_month, short int birth_year);

	bool add_subscriber(char* name, char* surname, char* phone, char* address, status_type status,
		char* post, char* company);

	bool delete_subscriber(int id);

	// Сортировка
	void test_quick_sort_without_table(TSubscriber* a, int size);
	void test_quick_sort_with_table(TKeyTable* a, int size);
	bool test_selection_sort_without_table();
	bool test_selection_sort_with_table();

	bool shake();
	bool quick_sort();
	bool selection_sort();

	void gen_base();
};

int compare_tables (TKeyTable *a, TKeyTable *b);

int compare_subscribers (TSubscriber *a, TSubscriber *b);

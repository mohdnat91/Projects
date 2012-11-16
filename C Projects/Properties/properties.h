#include <stdbool.h> //bool

typedef char* string;

typedef struct tuple{
	string key;
	string value;
};

typedef struct properties{
	const string filepath;

	const char delimiter;
	const char comment;

	tuple *entries;
	int entry_count;

	bool error;
	string error_msg;
};
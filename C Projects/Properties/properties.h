#include <stdbool.h> //bool

typedef struct tuple{
	char *key;
	char *value;
} tuple;

typedef struct properties{
	const char *filepath;

	tuple *entries;
	int entry_count;

	bool error;
	char *error_msg;
} properties;

properties *properties_new(const char *filepath, char delimiter, char comment);
char *properties_get(properties *p, const char *key);
void properties_free(properties *p);
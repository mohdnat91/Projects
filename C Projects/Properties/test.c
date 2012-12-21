#include "properties.h"
#include <stdio.h>

int main(){
	char file[] = "in";
	properties *p = properties_new(file, '=', '#');
	printf("value of A: %s\n", properties_get(p, "A"));
	printf("value of Q: %s\n", properties_get(p, "Q"));
	printf("value of J: %s\n", properties_get(p, "Hello"));

	properties_free(p);
}
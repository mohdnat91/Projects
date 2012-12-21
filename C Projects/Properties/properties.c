#include <stdlib.h> 	//malloc, free
#include <stdio.h> 		//FILE
#include <string.h>		//strcmp
#include "properties.h"

properties *properties_new(const char *filepath, char delimiter, char comment){
	char term_delimiter[2] = {delimiter, 0};

	FILE *file = fopen(filepath, "r");

	properties *p = malloc(sizeof(properties));
	p->filepath = filepath;

	char buffer[200] = {0};
	int count = 0;
	while(fgets(buffer,sizeof(buffer),file) != NULL){
		int len = strlen(buffer)-1;
      	if(buffer[len] == '\n') 
        	buffer[len] = 0;

        if(buffer[0] == comment) continue;

        count++;
	}

	p->entries = malloc(count*sizeof(tuple));
	p->entry_count = 0;
	p->error = false;
	p->error_msg = NULL;

	rewind(file);

	while(fgets(buffer,199,file) != NULL){
		int len = strlen(buffer)-1;
      	if(buffer[len] == '\n') 
        	buffer[len] = 0;

        buffer[199] = 0;

        if(buffer[0] == comment) continue;

        char *tok = strtok(buffer, term_delimiter);
        p->entries[p->entry_count].key = malloc(strlen(tok)*sizeof(char)+1);
        strcpy(p->entries[p->entry_count].key, tok);

        tok = strtok(NULL, term_delimiter);
       	p->entries[p->entry_count].value = malloc(strlen(tok)*sizeof(char)+1);
        strcpy(p->entries[p->entry_count].value, tok);

        p->entry_count++;
	}

	fclose(file);
	return p;
}

void properties_free(properties *p){
	for(int i = 0; i < p->entry_count; i++){
		free(p->entries[i].key);
		free(p->entries[i].value);
	}
	free(p->entries);
	free(p);
}

char *properties_get(properties *p, const char *key){
	for(int i = 0; i < p->entry_count; i++){
		if(!strcmp(key, p->entries[i].key)) return p->entries[i].value;
	}
	return NULL;
}
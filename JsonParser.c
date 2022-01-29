#include <stdio.h>
#include <json-c/json.h>
#include <stdbool.h>

int main(int argc, char **argv){
	FILE *fp;
	char buffer[1024];
	
	struct json_object *parsed_json;
	struct json_object *word;
	struct json_object *origin;
	
	struct json_object *definitions;
	struct json_object *definition;
	struct json_object *defTemp;
	
	size_t n_definitions;
	size_t i;
	
	bool exists;
	
	fp = fopen("head.json", "r");
	fread(buffer, 1024, 1, fp);
	fclose(fp);
	
	parsed_json = json_tokener_parse(buffer);
	
	exists = json_object_object_get_ex(parsed_json, "word", &word);
	if(exists == false){
		printf("word doesnt exist\n");
	}
	
	exists = json_object_object_get_ex(parsed_json, "origin", &origin);
	if(exists == false){
		printf("origin doesnt exist\n");
	}
	
	exists = json_object_object_get_ex(parsed_json, "definitions", &definitions);
	if(exists == false){
		printf("definitions doesnt exist\n");
	}
	
	exists = json_object_object_get_ex(parsed_json, "definition", &definition);
	if(exists == true){
		printf("definition doesnt exist\n");
	}
	
	exists = json_object_object_get_ex(parsed_json, "definition", &definition);
	if(exists == true){
		printf("definition doesnt exist\n");
	}
	
	printf("parsed_json.to_string()=%s\n",json_object_to_json_string(parsed_json));
	
	
	printf("Word: %s\n", json_object_get_string(word));
	printf("\nOrigin: %s\n", json_object_get_string(origin));
	
	
	
	n_definitions = json_object_array_length(definitions);
	printf("\nFound %lu definitions\n", n_definitions);
	
	
	for(i=0; i<n_definitions; i++){
		defTemp = json_object_array_get_idx(definitions, i);
		if(json_object_object_get_ex(defTemp, "definition", &definition)){
			printf("%lu. %s\n", i+1, json_object_get_string(definition));
		}
		else{
			definition = json_object_array_get_idx(definitions, i);
			printf("%lu. %s\n", i+1, json_object_get_string(definition));
		}
	}
	
	return 1;
}

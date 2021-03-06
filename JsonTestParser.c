#include <stdio.h>
#include <json-c/json.h>

int main(int argc, char **argv){
	FILE *fp;
	char buffer[2048];
	
	struct json_object *parsed_json;
	struct json_object *name;
	struct json_object *age;
	
	struct json_object *friends;
	struct json_object *friend;
	struct json_object *friendtemp;
	
	size_t n_friends;
	size_t i;
	
	fp = fopen("test.json", "r");
	fread(buffer, 1024, 1, fp);
	fclose(fp);
	
	parsed_json = json_tokener_parse(buffer);
	
	json_object_object_get_ex(parsed_json, "name", &name);
	json_object_object_get_ex(parsed_json, "age", &age);
	json_object_object_get_ex(parsed_json, "friends", &friends);
	
	printf("Name: %s\n", json_object_get_string(name));
	printf("Age: %s\n", json_object_get_string(age));
	
	n_friends = json_object_array_length(friends);
	printf("Found %lu friends\n", n_friends);
	
	for(i=0; i<n_friends; i++){
		
		friendtemp = json_object_array_get_idx(friends, i);
		if(json_object_object_get_ex(friendtemp, "friend", &friend)){
		//json_object_object_get_ex(friendtemp, "friend", &friend);
		printf("%lu. %s\n", i+1, json_object_get_string(friend));
		}
		else{
			friend = json_object_array_get_idx(friends, i);
			printf("%lu. %s\n", i+1, json_object_get_string(friend));
		}
	}
	
	return 1;
}

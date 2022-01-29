#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <json-c/json.h>


void help();
void info();

int main(int argc, char** argv){
	if (argc == 1){
		info();
	}
	if (strcmp(argv[1], "--help") == 0){
		help();
	}
	else{
	
		CURL *curl;
		CURLcode res;
		
		char url[] = "https://api.dictionaryapi.dev/api/v2/entries/en/";
		
		char word[10];
		
		strcpy(word, argv[1]);
		
		strcat(url, word);
		printf("%s",url);
		//printf("Starting check");
		
		
		curl = curl_easy_init();
		if(curl) {
			curl_easy_setopt(curl, CURLOPT_URL, url);
		
			res = curl_easy_perform(curl);
			
			//printf("checking website");
		
			if(res != CURLE_OK){
				fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
			}
			
			curl_easy_cleanup(curl);
		}
	
	//printf("didnt check");
	}
	return 1;
}

void info(){
	printf("Invalid command.\nTry --help for help.\n");
}

void help(){
	printf("Help options.\nVerbose options: -v\n");
}


#include <iostream>
#include <cstdio>
#include <io.h>  /* open */
#include <fcntl.h>
using namespace std;
int main() {

	FILE* fp = fopen("my.txt", "w"); 
    const char* phrase = "Mama myla ramu";
    int written = fwrite(phrase, 1, strlen(phrase), fp);
    fclose(fp);
}

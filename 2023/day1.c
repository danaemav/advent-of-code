#include <stdio.h>
#include <stdlib.h>

void find_calibration(int content, int result){
    
}



int main(void){
    FILE *fp = fopen(stdin, "r");
    if (fp1 == NULL) {   // check if file opened correctly //
        fprintf(stderr, "Error: cannot open file\n");
        exit(1);
    }

    // find size of file by using the steam //
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    int *content = malloc((size + 1) * sizeof(int));    // store the content of the file //
    if (content == NULL){
        printf("Memory allocation error.\n");
        exit(1);
    }

    // read content of the file //
    if (fread(content, sizeof(int), size, fp) != size) {
        fprintf(stderr, "Error at reading file.\n");
        free(content);
        exit(1);
    }
    content[size] = 0;



}
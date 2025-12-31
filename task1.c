#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char text[200];
    char ch;

    /* 1. Create and Write to a File */
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("File cannot be created.\n");
        return 1;
    }

    printf("Enter text to write into the file:\n");
    fgets(text, sizeof(text), stdin);
    fputs(text, fp);
    fclose(fp);

    /* 2. Append Data to the File */
    fp = fopen("data.txt", "a");
    if (fp == NULL) {
        printf("File cannot be opened for appending.\n");
        return 1;
    }

    printf("\nEnter text to append into the file:\n");
    fgets(text, sizeof(text), stdin);
    fputs(text, fp);
    fclose(fp);

    /* 3. Read Data from the File */
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("File cannot be opened for reading.\n");
        return 1;
    }

    printf("\nContents of the file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);

    return 0;
}

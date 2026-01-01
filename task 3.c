#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char word[]) {
    char keywords[6][10] = {"int", "float", "if", "else", "while", "return"};
    for(int i = 0; i < 6; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char ch, buffer[20];
    int i = 0;

    FILE *fp;
    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {

        // Operator check
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=') {
            printf("Operator: %c\n", ch);
        }

        // Identifier or keyword
        else if (isalnum(ch)) {
            buffer[i++] = ch;
        }

        else if ((ch == ' ' || ch == '\n') && i != 0) {
            buffer[i] = '\0';
            i = 0;

            if (isKeyword(buffer))
                printf("Keyword: %s\n", buffer);
            else
                printf("Identifier: %s\n", buffer);
        }
    }

    fclose(fp);
    return 0;
}


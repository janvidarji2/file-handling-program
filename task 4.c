#include <stdio.h>
#include <string.h>

// Compression function
void compress(char str[]) {
    int count;
    for(int i = 0; i < strlen(str); i++) {
        count = 1;
        while (i < strlen(str) - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        printf("%c%d", str[i], count);
    }
    printf("\n");
}

// Decompression function
void decompress(char str[]) {
    for (int i = 0; i < strlen(str); i += 2) {
        char ch = str[i];
        int count = str[i + 1] - '0';

        for (int j = 0; j < count; j++)
            printf("%c", ch);
    }
    printf("\n");
}

int main() {
    char str[100];
    int choice;

    printf("1. Compress\n2. Decompress\nEnter choice: ");
    scanf("%d", &choice);

    printf("Enter string: ");
    scanf("%s", str);

    if (choice == 1)
        compress(str);
    else if (choice == 2)
        decompress(str);
    else
        printf("Invalid choice\n");

    return 0;
}


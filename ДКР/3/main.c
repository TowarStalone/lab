#include <stdio.h>

int main()
{
// Open the text file for reading
FILE* fp = fopen("text.txt", "r");
// Check if the file was opened successfully
if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
}

// Initialize a counter to keep track of the number of punctuation marks
int count = 0;

// Read the file character by character
char c;
while ((c = fgetc(fp)) != EOF) {
    // Check if the character is a punctuation mark
    if (c == '!' || c == ',' || c == '.' || c == '-' || c == '?' || c == ':' || c == ';') {
        count++;
    }
}

// Close the file
fclose(fp);

// Print the count
printf("Number of punctuation marks: %d\n", count);

return 0;
}

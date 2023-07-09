#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "w+");  // Open the file in write mode

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    fprintf(file, "Hello, World!\n");  // Write data to the file
    fprintf(file, "This is a simple example.\n");

    // Move the file pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);

    char buffer[100];  // Buffer to store read data

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);  // Print the read data
    }

    fclose(file);  // Close the file

    return 0;
}

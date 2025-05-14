#include <stdio.h>
#include <string.h>

int main() {
    // Open the object file
    FILE *obj = fopen("object.txt", "r");
    char buffer[200];  // To store each line of the input
    char type;
    unsigned int start, length;
    char obj_code[100];

    // Check if the file opened correctly
    if (!obj) {
        printf("Error opening file.\n");
        return 1;
    } else {
        printf("File opened successfully.\n");
    }

    // Read each line from the file
    while (fgets(buffer, sizeof(buffer), obj) != NULL) {
        // First character determines the record type ('H', 'T', 'E')
        sscanf(buffer, "%c", &type);
        printf("Record Type: %c\n", type);  // Debugging print

        if (type == 'T') {
            // Parse the text record
            sscanf(buffer, "T^%06x^%02x^%[^\n]", &start, &length, obj_code);

            //printf("Parsed Text Record - Start: %06x, Length: %02x, Object Codes: %s\n", start, length, obj_code);  
            
            // Tokenize the object code based on '^'
            char *token = strtok(obj_code, "^");
            unsigned int current_addr = start;

            // Loop through each object code in the line
            while (token != NULL) {
                printf("%06x %s\n", current_addr, token);  // Print the address and corresponding object code
                
                // Increment the address by 3 (as each object code represents 3 bytes)
                current_addr += 3;
                
                
                // Get the next object code
                token = strtok(NULL, "^");
            }
        } else if (type == 'E') {
            // End record encountered, stop processing
            printf("End record encountered.\n");
            break;
        }
    }

    fclose(obj);  // Close the file
    return 0;
}


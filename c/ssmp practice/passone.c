#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants

#define MAX_LINE_LENGTH 100
#define MAX_LABEL_LENGTH 10
#define MAX_OPCODE_LENGTH 10
#define MAX_OPERAND_LENGTH 10
#define MAX_SYMBOLS 100


// Define a structure for OPTAB entries

typedef struct
{
    char opcode[MAX_OPCODE_LENGTH];
    char code[3];
} OptabEntry;


// Define a structure for symbol table (SYMTAB) entries

typedef struct
{
    char label[MAX_LABEL_LENGTH];
    int locctr;
} SymtabEntry;


// Function to check if an opcode is valid

int is_valid_opcode(OptabEntry optab[], int optab_size, char *opcode)
{
    for (int i = 0; i < optab_size; i++)
    {
        if (strcmp(optab[i].opcode, opcode) == 0)
        {
            return 1;
        }
    }
    return 0;
}


// Function to get the instruction length

int get_instruction_length(char *opcode, char *operand)
{
    if (strcmp(opcode, "BYTE") == 0) return (strlen(operand)-3);
    if (strcmp(opcode, "RESB") == 0) return (atoi(operand) * 1);
    if (strcmp(opcode, "RESW") == 0) return (atoi(operand) * 3);
    if (strcmp(opcode, "WORD") == 0) return 3;
    return 3;  // For normal instructions
}


// Function to add a symbol to the SYMTAB

int add_symbol(SymtabEntry symtab[], int symtab_size, char *label, int locctr)
{
    for (int i = 0; i < symtab_size; i++)
    {
        if (strcmp(symtab[i].label, label) == 0)
        {
            return -1; // Duplicate symbol
        }
    }
    strcpy(symtab[symtab_size].label, label);
    symtab[symtab_size].locctr = locctr;
    return symtab_size + 1;
}


int main()
{
    FILE *input_file, *optab_file, *intermediate_file, *length_file, *symtab_file;
    char line[MAX_LINE_LENGTH], label[MAX_LABEL_LENGTH], opcode[MAX_OPCODE_LENGTH], operand[MAX_OPERAND_LENGTH];
    int LOCCTR = 0, starting_address = 0, program_length = 0;

    // Symbol table
    SymtabEntry symtab[MAX_SYMBOLS];

    int symtab_size = 0;
    // Open input.txt

    input_file = fopen("input.txt", "r");

    if (input_file == NULL)
    {
        printf("Error: Cannot open input.txt\n");
        return 1;
    }

    // Open optab.txt

    optab_file = fopen("optab.txt", "r");

    if (optab_file == NULL)
    {
        printf("Error: Cannot open optab.txt\n");
        fclose(input_file);
        return 1;
    }

    // Load optab into memory

    OptabEntry optab[10];
    int optab_size = 0;
    while (fscanf(optab_file, "%s %s", optab[optab_size].opcode, optab[optab_size].code) != EOF)
    {
        optab_size++;
    }
    fclose(optab_file);

    // Open intermediate.txt, length.txt, and symtab.txt for writing

    intermediate_file = fopen("intermediate.txt", "w");
    length_file = fopen("length.txt", "w");
    symtab_file = fopen("symtab.txt", "w");

    // Read the first line and set starting address

    fscanf(input_file, "%s %s %s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0)
    {
        starting_address = (int)strtol(operand, NULL, 16);
        LOCCTR = starting_address;
        fprintf(intermediate_file, "%04X\t%s\t%s\t%s\n", LOCCTR, label, opcode, operand);
        fscanf(input_file, "%s %s %s", label, opcode, operand);
    }
    else
    {
        LOCCTR = 0;
    }

    // Process the remaining lines
    while (strcmp(opcode, "END") != 0)
    {
        if (label[0] != '-') {  // Check for label and add it to SYMTAB
            symtab_size = add_symbol(symtab, symtab_size, label, LOCCTR);
            if (symtab_size == -1)
            {
                printf("Error: Duplicate symbol %s\n", label);
                break;
            }
        }
       
        fprintf(intermediate_file, "%04X\t%s\t%s\t%s\n", LOCCTR, label[0] == '-' ? "\t" : label, opcode, operand);

        // Check if the opcode is valid

        if (is_valid_opcode(optab, optab_size, opcode))
        {
            LOCCTR += get_instruction_length(opcode, operand);

        }
        else if (strcmp(opcode, "BYTE") == 0 || strcmp(opcode, "WORD")== 0 || strcmp(opcode, "RESB") == 0 || strcmp(opcode, "RESW") == 0) 
        {

            LOCCTR += get_instruction_length(opcode, operand);
            
        }
        else
        {
            printf("Error: Invalid opcode %s\n", opcode);
        }
        // Read next line
        fscanf(input_file, "%s %s %s", label, opcode, operand);
    }

    // Output the last line (END statement)
    fprintf(intermediate_file, "%04X\t%s\t%s\t%s\n",LOCCTR, label, opcode, operand);

    // Calculate program length
    program_length = LOCCTR - starting_address;
    fprintf(length_file, "%02X\n", program_length);


    // Write the symbol table to symtab.txt
    for (int i = 0; i < symtab_size; i++)
    {
        fprintf(symtab_file, "%s\t%04X\n", symtab[i].label, symtab[i].locctr);
    }
    // Close files
    fclose(input_file);
    fclose(intermediate_file);
    fclose(length_file);
    fclose(symtab_file);

    printf("Pass 1 completed. Intermediate file, symtab.txt, and length.txt generated.\n");
    return 0;
}

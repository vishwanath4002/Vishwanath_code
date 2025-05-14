//tips - be careful with file pointers
//read everything as strings, even numbers, convert later
//sprintf - int to string
//strtol - string to long

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *fp_intermediate, *fp_length, *fp_object;
char header[30], end[10], label[10], symbol[4], starting_address[10], program_length[5], opcode[10], text[50], loc[5];
char objectcode[10], machinecode_op[2], symbol_address[10], t_length[2], letter, constant[5], ascii2[5], str_length[10];
int i, length, text_length, found1, found2, ascii, hex_symbol;

int findopcode();
void findsymboladdress();

//header record - H^name^starting-address^length
//text record - T^starting-address-of-objcode-for-that-text-rec^length-of-text-record^machinecodes
//end record - E^starting-address

void main()
{
    //open files in necessary modes
    fp_intermediate = fopen("intermediate.txt", "r");
    fp_length = fopen("length.txt", "r");
    fp_object = fopen("object.txt", "w");

    //read first line from intermediate file
    fscanf(fp_intermediate, "%*s %*s %s %s %s", label, opcode, symbol); //store name(label), opcode, starting address(symbol)
    strcpy(starting_address, symbol);

    //header record and end record
    strcpy(header, "H^");
    strcpy(end, "E^");
    strcat(header, label);
    strcat(header, "^");
    //concatenating zeroes to the beginning of the starting address (symbol) till we get 3 bytes (6 half bytes)
    //both header and end record
    for(i=0; i<6-strlen(starting_address); i++ )
    {
        strcat(header, "0");
        strcat(end, "0");
    }
    strcat(header, starting_address); //concatenate starting address to header record
    strcat(end, starting_address); //concatenate starting address to end record

    //read length of the program from length.txt
    fscanf(fp_length, "%s", program_length);
    strcat(header, "^");
    //concatenating zeroes to the beginning of the program length till we get 3 bytes (6 half bytes)
    for(i=0; i<6-strlen(program_length); i++ )
        strcat(header, "0");
    strcat(header, program_length);
    strcat(header,"\n");

    fputs(header, fp_object);

    //initialize first text record
    strcpy(text, "T^"); 
    //concatenating zeroes to the beginning of the starting address (symbol) till we get 3 bytes (6 half bytes)
    for(i=0; i<6-strlen(starting_address); i++ )
        strcat(text, "0");
    strcat(text, starting_address);
    strcat(text, "^00"); //leave length field empty
    text_length = 0X0;

    //read next line
    fscanf(fp_intermediate, "%s %X %s %s %s", loc, &length, label, opcode, symbol);

    while(strcmp(opcode,"END")!=0) //till the last line
    {
        //object code creation
        strcpy(objectcode, "");
        found1 = findopcode();
        if(found1 == 1)
        {
        	findsymboladdress();
        	strcat(objectcode, machinecode_op);
        	strcat(objectcode, symbol_address);
        }
        else if(strcmp(opcode,"BYTE")==0)
        {
        	for(i=2;i<strlen(symbol)-1;i++)
        	{
        		letter = symbol[i]; //extract each alphabet after C' and before '
        		ascii = letter; //ascii code
                sprintf(ascii2, "%X", ascii);
                strcat(objectcode, ascii2);
        	}
        }
        else if(strcmp(opcode,"WORD")==0)
        {
            hex_symbol = (int)strtol(symbol, NULL, 10); //convert to dec int
            sprintf(symbol, "%X", hex_symbol); //convert back to string but store hex value
            //concatenating zeroes to the beginning of the object code till we get 3 bytes (6 half bytes)
            for(i=0; i<6-strlen(symbol); i++ )
                strcat(objectcode, "0");
            strcat(objectcode, symbol);
        }
        else //RESB, RESW - no obj code
            goto skip;

        //copying it to text record
        if(length + text_length > 0X9) //9 bytes max in one text record
        {
            //write text record to obj file
            strcat(text, "\n");
            sprintf(t_length, "%X", text_length);
            text[10] = t_length[0]; //length of text rec
            fputs(text, fp_object);

            //initialize new text record
            strcpy(text, "T^");

            //concatenating zeroes
            for(i=0; i<6-strlen(loc); i++)
                strcat(text,"0");
            strcat(text,loc); //starting address of object code for this text record
            strcat(text,"^00"); //keep the length field empty for now

            text_length = 0X0; 
        }

        //concatenate obj code to current text record
        strcat(text, "^");
        strcat(text, objectcode);
        text_length += length;

        skip:
        //read next line
        fscanf(fp_intermediate, "%s %s %s %s %s", loc, str_length, label, opcode, symbol);
        length = (int)strtol(str_length, NULL, 16);

        //printf("%s %X %s %s %s\n",loc, length, label, opcode, symbol);
    }
    //write last text rec to obj file
    strcat(text, "\n");
    sprintf(t_length, "%X", text_length);
    text[10] = t_length[0]; //length of text rec
    fputs(text, fp_object);
    fputs(end, fp_object);

    fclose(fp_object);
    fclose(fp_intermediate);
    fclose(fp_length);
}

int findopcode()
{
    char word1[10];
    int found1 = 0;
    FILE *fp_optab = fopen("optab.txt", "r");
    while(!feof(fp_optab))
    {
        fscanf(fp_optab, "%s %s", word1, machinecode_op);
        if(strcmp(word1, opcode) == 0)
        {
            found1 = 1;
            break; //machine code obtained at this line is the required one
        }
    }
    fclose(fp_optab);
    return found1;
}

void findsymboladdress()
{
    char word2[10];
    int found2 = 0;
    FILE *fp_symtab = fopen("symtab.txt", "r");
    while(!feof(fp_symtab))
    {
        fscanf(fp_symtab, "%s %s", word2, symbol_address);
        if(strcmp(word2, symbol) == 0)
        {
            found2 = 1;
            break; //symbol address obtained at this line is the required one
        }
    }
    if(found2 == 0) //no operand
        strcpy(symbol_address, "0000");
    fclose(fp_symtab);
}

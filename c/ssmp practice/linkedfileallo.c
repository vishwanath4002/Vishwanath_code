#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 10
#define MAX_BLOCKS 100

typedef struct 
{
    char name[20];
    int startBlock;
    int size;
} File;

File files[MAX_FILES];

int memory[MAX_BLOCKS];
int fileCount = 0;
int totalBlocks;

int exceed=0;

void initializeMemory() 
{
    for (int i=0; i<MAX_BLOCKS; i++) 
    {
        memory[i] = -1;
    }
}

int getRandomFreeBlock() 
{
    int block;
    int attempts = 0;
    do 
    {
        block = rand() % totalBlocks; 
    } while (memory[block] != -1);
    return block;
}

int allocateBlocks(int numBlocks) 
{
    int prevBlock = -1;
    int firstBlock = -1;
    for (int i=0; i<numBlocks; i++) 
    {
        int block = getRandomFreeBlock();
        if (block == -1 || exceed >= totalBlocks) 
        {
            return -1;
        }
        if (firstBlock == -1) 
        {
            firstBlock = block; 
        }
        if (prevBlock != -1) 
        {
            memory[prevBlock] = block;
        }
        prevBlock = block;
    }
    memory[prevBlock] = -2; 
    return firstBlock;
}

void createFile(char name[], int size) 
{
    if (fileCount >= MAX_FILES) 
    {
        printf("\nNo more files can be created.\n");
        return;
    }
    exceed=exceed+size;
    int startBlock = allocateBlocks(size);
    if (startBlock == -1) 
    {
        printf("\nNot enough free blocks to allocate the file.\n");
        return;
    }
    files[fileCount].startBlock = startBlock;
    files[fileCount].size = size;
    strcpy(files[fileCount].name, name);
    fileCount++;
    printf("\nFile '%s' created successfully with starting block %d.\n", name, startBlock);
}

void displayAllocationTable() 
{
    printf("\nAllocation Table");
    printf("\nFile Name\tSize\tStart Block\tBlocks");
    for (int i=0; i<fileCount; i++) 
    {
        printf("\n%s\t\t%d\t%d\t\t", files[i].name, files[i].size, files[i].startBlock);
        int block = files[i].startBlock;
        while (block != -2) 
        {
            printf("%d ", block);
            block = memory[block];
        }
    }
    printf("\n");
}

void main() 
{
    srand(time(NULL)); 
    printf("Linked File Allocation\n");
    initializeMemory();

    int memSize, blockSize;
    printf("\nEnter the total memory size in KB= ");
    scanf("%d", &memSize);
    printf("\nEnter the size of each block in KB= ");
    scanf("%d", &blockSize);
    totalBlocks = memSize / blockSize;
    printf("\nThe total number of blocks available= %d\n", totalBlocks);

    int ch;
    char fileName[20];
    int fileSize;

    do {
        printf("\nMenu:\n1.Create a file\n2.Display allocation table\n3.Exit");
        printf("\nEnter your choice= ");
        scanf("%d", &ch);

        switch(ch) 
        {
            case 1:
                printf("\nEnter the file name= ");
                scanf("%s", fileName);
                printf("\nEnter the number of blocks needed by the file= ");
                scanf("%d", &fileSize);
                createFile(fileName, fileSize);
                break;
            case 2:
                displayAllocationTable();
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }while(ch!=3);
}



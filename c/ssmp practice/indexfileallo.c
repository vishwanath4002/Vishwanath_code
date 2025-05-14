#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 10
#define MAX_BLOCKS 100

typedef struct {
    char name[20];
    int indexBlock;
    int size;
    int blocks[MAX_BLOCKS];
} File;

File files[MAX_FILES];
int memory[MAX_BLOCKS];
int fileCount = 0;
int totalBlocks;

int exceed = 0;

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
    do 
    {
        block = rand() % totalBlocks;
    }while (memory[block] != -1);
    
    return block;
}

void createFile(char name[], int size) 
{
    if (fileCount >= MAX_FILES) 
    {
        printf("\nNo more files can be created.\n");
        return;
    }
    exceed += size;
    int indexBlock = getRandomFreeBlock();
    if (indexBlock == -1 || exceed > totalBlocks) 
    {
        printf("\nNot enough free blocks to allocate the file.\n");
        return;
    }
   
    memory[indexBlock] = -2; 
    files[fileCount].indexBlock = indexBlock;
    files[fileCount].size = size;
    strcpy(files[fileCount].name, name);
   
    for (int i=0; i<size; i++) 
    {
        int block = getRandomFreeBlock();
        if (block == -1) 
        {
            printf("\nNot enough free blocks to allocate the file.\n");
            memory[indexBlock] = -1; 
            exceed -= size;
            return;
        }
        memory[block] = indexBlock; 
        files[fileCount].blocks[i] = block;
    }
   
    fileCount++;
    printf("\nFile '%s' created successfully with index block %d.\n", name, indexBlock);
}

void displayAllocationTable() 
{
    printf("\nAllocation Table:");
    printf("\nIndex Block\tFile Name\tSize\tBlocks Allocated");
    for (int i=0; i<fileCount; i++) 
    {
        printf("\n%d\t\t%s\t\t%d\t", files[i].indexBlock, files[i].name, files[i].size);
        for (int j=0; j<files[i].size; j++) 
        {
            printf("%d ", files[i].blocks[j]);
        }
    }
    printf("\n");
}

int main() 
{
    srand(time(NULL)); 
    printf("\nIndexed File Allocation\n");

    initializeMemory();

    int memSize, blockSize;
    printf("\nEnter the total memory size in KB= ");
    scanf("%d", &memSize);
    printf("\nEnter the size of each block in KB= ");
    scanf("%d", &blockSize);
    totalBlocks = memSize / blockSize;
    printf("\nThe total number of blocks availabl= %d\n", totalBlocks);

    int ch;
    char fileName[20];
    int fileSize;

    do 
    {
		printf("\nMenu:\n1.Create a file\n2.Display allocation table\n3.Exit");
        printf("\nEnter your choice= ");
        scanf("%d", &ch);

        switch (ch) 
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

    return 0;
}

#include <stdio.h>

int mem[100]={-1};
char names[10][10];
int sizes[10];
int memorysize, blocksize, totalblocks;
int current=0;
int count;

int flag=0;

void allocate(int cnt, int size)
{
    if (current == totalblocks)
    {
        flag = 1;
        printf("\nMemory full. File cannot be allocated.\n");
        return;
    }
    else if ((current + size) > totalblocks)
    {
        printf("\nFile size too big, file cannot be allocated.\n");
        return;
    }
    else
    {
        for (int i=0; i<size; i++)
        {
            mem[current] = cnt;
            current++;
        }
        if (current == totalblocks)
        {
            flag = 1;
        }
        printf("\nFile has been allocated.");
        count++;
    }
}

void display()
{
    int current_display = 0;
    if (count == 0)
    {
        printf("\nNo files allocated.\n");
        return;
    }
    printf("\nAllocation table\n----------------\n");
    printf("File name\tSize\tBlocks Allocated\n");
    for (int i=0; i<count; i++)
    {
        printf("%s\t\t%d\t", names[i], sizes[i]);
        for (int j=0; j<sizes[i]; j++)
        {
            if(mem[current_display]==i)
            {
                printf("%d ", current_display);
                current_display++;
            }
        }
        printf("\n");
    }
}

void main()
{
    int ch;
    printf("Enter the size of memory in KB : ");
    scanf("%d", &memorysize);
    printf("Enter the size of each block in KB : ");
    scanf("%d", &blocksize);
    totalblocks = memorysize/blocksize;
    printf("Total number of blocks : %d", totalblocks);
    count = 0;
    do
    {
        if (flag == 1)
        {
            printf("\nMemory full. Cannot allocate more files.\n");
            display();
            return;
        }
        printf("\n%d %d", count, current);
        printf("\n1.Insert file\t2.Display allocation table\t3.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                printf("Enter the name of the file : ");
                scanf("%s", names[count]);
                printf("Enter the size of the file in number of blocks : ");
                scanf("%d", &sizes[count]);
                allocate(count, sizes[count]);
                break;
            
            case 2:
                display();
                break;
            
            case 3:
                return;
                break;

            default:
                printf("Invalid entry.");
                break;
        }
    } while (ch != 3);
}
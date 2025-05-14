#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char files[15][15];
int filecount=0;

void createFile(char filename[15])
{
    strcpy(files[filecount],filename);
    filecount++;
}

int searchFile(char filename[15])
{
    int found=-1;

    for (int i=0;i<filecount;i++)
    {
        if(strcmp(files[i],filename)==0)
        {
            found=i;
            break;
        }
    }

    return found;
}

void deleteFile(char filename[15])
{
    if(filecount==0)
    {
        printf("\nDirectory is empty.\n");
        return;
    }

    int found=searchFile(filename);

    if(found!=-1)
    {
        for (int i=found-1;i<filecount-1;i++)
        {
            strcpy(files[i],files[i+1]);
        }
        filecount--;
        printf("\nFile deleted.\n");
    }
    printf("\nFile not found.\n");
}

void displayFiles()
{
    for(int i=0;i<filecount;i++)
    {
        printf("%s\t",files[i]);
    }
}

void main()
{
    int ch;
    char filename[15];
    do
    {
        printf("\nRoot directory contents :\n");
        displayFiles();
        printf("\n--------------------------------------------------------------------------------\n");
        printf("\n1.Create file\n2.Delete file\n3.Search for a file\n4.Exit\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("\nEnter the name of the file : ");
            scanf("%s",filename);
            createFile(filename);
            break;
        
        case 2:
            printf("\nEnter the name of the file : ");
            scanf("%s",filename);
            deleteFile(filename);
            break;
        
        case 3:
            printf("\nEnter the name of the file : ");
            scanf("%s",filename);
            if(searchFile(filename)!=-1)
            {
                printf("\nFile found.\n");
            }
            break;
        
        case 4:
            break;
        
        default:
            printf("\nInvalid entry.\n");
            break;
        }
    } while (ch!=4);
}
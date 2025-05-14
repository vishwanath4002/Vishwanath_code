#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct directory
{
	char directoryname[20];
	char files[10][20];
	int filecount;
}l[10];

int deletedirectory(char dirname[20], int dircount)
{
	int found=0;
	for(int i=1;i<dircount;i++)
	{
		if(strcmp(l[i].directoryname,dirname)==0)
		{
			found=i;
		}
	}
	if (found==0)
	{
		printf("\nDirectory not found.\n");
		return dircount;
	}
	else
	{
		for(int i=found;i<dircount-1;i++)
		{
			l[i]=l[i+1];
		}
		printf("\nDirectory was deleted.\n");
		return dircount-1;
	}
}

void deletefile(char filename[20], int dir)
{
	int found=-1;
	for(int i=0;i<l[dir].filecount;i++)
	{
		if(strcmp(l[dir].files[i],filename)==0)
		{
			found=i;
		}
	}
	if(found==-1)
	{
		printf("\nFile not found.\n");
		return;
	}
	else
	{
		for(int i=found-1;i<l[dir].filecount-1;i++)
		{
			strcpy(l[dir].files[i],l[dir].files[i+1]);
		}
		printf("\nThe file was deleted.\n");
		l[dir].filecount--;
		return;
	}
}

int createdirectory(int dircount, char dirname[20])
{
	strcpy(l[dircount].directoryname,dirname);
	printf("\nDirectory was created.\n");
	return dircount+1;
}

void createfile(int dirnum, char filename[20])
{
	int count=l[dirnum].filecount;
	strcpy(l[dirnum].files[count],filename);
	printf("\nFile was created.\n");
	l[dirnum].filecount++;
	return;
}

void searchfile(char filename[20],int dircount)
{
	char path[20];
	strcpy(path,"~/root");
	for(int i=0;i<dircount;i++)
	{
		int filec=l[i].filecount;
		for(int j=0;j<filec;j++)
		{
			if(strcmp(l[i].files[j],filename)==0)
			{
				if(i!=0)
				{
					strcat(path,"/");
					strcat(path,l[i].directoryname);	
				}
				printf("\nFile path is : %s\n",path);
				return;
			}
		}
	}
	printf("\nFile not found.\n");
}

int searchdirectory(char dirname[20],int dircount)
{
	for(int i=0;i<dircount;i++)
	{
		if(strcmp(dirname,l[i].directoryname)==0)
		{
			printf("\nDirectory found.\n");
			return i;
		}
	}
	printf("\nDirectory not found.\n");
}

void displaydirectory(int dirnum)
{
	for(int i=0;i<l[dirnum].filecount;i++)
	{
		printf("%s\t",l[dirnum].files[i]);
	}
	printf("\n");
}

void main()
{
	int dircount=1;
	strcpy(l[0].directoryname,"root");
	for(int i=0;i<10;i++)
	{
		l[i].filecount=0;
	}
	
	int ch;
	do
	{	
		printf("---------------------------------------------------\nroot\n");
		
		displaydirectory(0);
		
		for(int i=1;i<dircount;i++)
		{
			printf("%s",l[i].directoryname);
		}
		
		printf("\n\n1. Create a file\n2. Create a directory\n3. Open a directory\n4. Delete a file\n5. Delete a directory\n6. Search file\n7. Search directory\n8. Exit\n\nEnter your choice : ");
		scanf("%d",&ch);
		
		char name[20];
		char dirname[20];
		
		switch(ch)
		{
			case 1:
				printf("\nEnter file name : ");
				scanf("%s",name);
				//strcpy(l[0].files[l[0].filecount],name);
				//l[0].filecount++;
				createfile(0,name);
				break;
			
			case 2:
				printf("\nEnter directory name : ");
				scanf("%s",dirname);
				dircount=createdirectory(dircount,dirname);
				break;
			
			case 3:
				printf("\nEnter the directory name : ");
				scanf("%s",dirname);
				int dirnum=0;
				dirnum=searchdirectory(dirname,dircount);
				
				int ch2;
				do
				{
					printf("\n%s\n",dirname);
					displaydirectory(dirnum);
					printf("\n1. Create a file\t2. Delete a file\t3. Go back\nEnter your choice : ");
					scanf("%d",&ch2);
					
					switch(ch2)
					{
						case 1:
							printf("\nEnter file name : ");
							scanf("%s",name);
							createfile(dirnum,name);
							break;
						
						case 2:
							printf("\nEnter file name : ");
							scanf("%s",name);
							deletefile(name,dirnum);
							break;
						
						case 3:
							break;
							
						default:
							printf("\nInvalid entry.\n");
							break;
					}
				}while(ch2!=3);
				
				break;
			
			case 4:
				printf("\nEnter file name : ");
				scanf("%s",name);
				deletefile(name,0);
				break;
			
			case 5:
				printf("\nEnter directory name : ");
				scanf("%s",dirname);
				dircount=deletedirectory(dirname,dircount);
				break;
			
			case 6:
				printf("\nEnter file name : ");
				scanf("%s",name);
				searchfile(name,dircount);
				break;
			
			case 7:
				printf("\nEnter directory name : ");
				scanf("%s",dirname);
				searchdirectory(dirname,dircount);
				break;
				
			case 8:
				break;
			
			default:
				printf("\nInvalid entry.\n");
				break;
		}
	}while(ch!=8);
}

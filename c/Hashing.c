#include<stdio.h>
#include<stdlib.h>

int larray[50] = {0}, lmax = 10;
int qarray[50] = {0}, qmax = 10;

// Linear Probing Hashing where if supposed to fill index is filled go to index + 1
void linearHashing(int data)
{
	for (int i = 0; i < lmax; i++) {
		if (!larray[(data + i) % lmax]) {
			larray[(data + i) % lmax] = data;
			return;
		}
	}
	printf("Hash table is full\n");
}

// Quadratic Probing Hashing where if supposed to fill index is filled go to index + i^2
void quadHashing(int data)
{
	for (int i = 0; i < qmax; i++) {
		if (!qarray[(data + i * i) % qmax]) {
			qarray[(data + i * i) % qmax] = data;
			return;
		}
	}
	printf("Hash table is full\n");
}

void display(int amax, int a[]) {
	for (int i = 0; i < amax; i++) {
		printf("%d. %d\n", i, a[i]);
	}
}

void main()
{
    int choice1;
    do
    {
        int choice2;
        int data;
        printf("1.Linear probing\n2.Quadratic probing\n3.Exit\nEnter your choice : ");
        scanf("%d",&choice1);
        switch(choice1)
        {
            case 1:
                do
                {
                    printf("1.Hash\n2.Length\n3.Display\n4.Exit\nEnter your choice : ");
                    scanf("%d", &choice2);
                    switch (choice2)
                    {
                        case 1:
                            printf("Enter the data : ");
                            scanf("%d", &data);
                            linearHashing(data);
                            break;

                        case 2:
                            printf("Enter the length : ");
                            scanf("%d", &lmax);
                            break;

                        case 3:
                            display(lmax, larray);
                            break;

                        case 4:
                            break;
                        
                        default:
                            printf("Invalid\n");
                    }
                }while(choice2!=4);
                break;
            
            case 2:
                do
                {
                    printf("1.Hash\n2.Length\n3.Display\n4.Exit\nEnter your choice : ");
                    scanf("%d", &choice2);
                    switch (choice2)
                    {
                        case 1:
                            printf("Enter the data : ");
                            scanf("%d", &data);
                            quadHashing(data);
                            break;

                        case 2:
                            printf("Enter the length : ");
                            scanf("%d", &qmax);
                            break;

                        case 3:
                            display(qmax, qarray);
                            break;

                        case 4:
                            break;
                        
                        default:
                            printf("Invalid\n");
                    }
                }while(choice2!=4);
                break;
            
            case 3:
                break;
            
            default:
                printf("Invalid entry. Please try again.\n");
        }
    }while(choice1!=3);
}
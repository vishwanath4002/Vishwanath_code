#include <stdio.h>
#include <stdlib.h>

struct node
{
    int size;
    int remaining;
    int taken;
    int process;
    struct node *link;
};
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;


int n;
int processes[10], notcomplete1[10], notcomplete2[10], notcomplete3[10];
int nc1 = 0, nc2 = 0, nc3 = 0;

void insertAtEnd1(int value)
{
    struct node *ptr, *temp;
    temp = malloc(sizeof(struct node));

    temp->size = value;
    temp->remaining = value;
    temp->taken = 0;
    temp->link = NULL;

    ptr = head1;

    if ( ptr == NULL )
    {
        head1 = temp;
        return;
    }

    while ( ptr->link != NULL )
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void insertAtEnd2(int value)
{
    struct node *ptr, *temp;
    temp = malloc(sizeof(struct node));

    temp->size = value;
    temp->remaining = value;
    temp->taken = 0;
    temp->link = NULL;

    ptr = head2;

    if ( ptr == NULL )
    {
        head2 = temp;
        return;
    }

    while ( ptr->link != NULL )
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void insertAtEnd3(int value)
{
    struct node *ptr, *temp;
    temp = malloc(sizeof(struct node));

    temp->size = value;
    temp->remaining = value;
    temp->taken = 0;
    temp->link = NULL;

    ptr = head3;

    if ( ptr == NULL )
    {
        head3 = temp;
        return;
    }

    while ( ptr->link != NULL )
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

struct node* biggest()
{
    struct node *ptr = head2;
    struct node *big = head2;
    if ( big->taken == 1 )
    {
        while ( big != NULL )
        {
            if ( big->taken != 1 )
            {
                break;
            }
            big = big->link;
        }
    }
    ptr = big;

    while ( ptr != NULL)
    {
        if( (ptr->size > big->size) && (ptr->taken != 1) )
        {
            big = ptr;
        }
        ptr = ptr->link;
    }

    return big;
}

struct node* smallest( int s )
{
    struct node *ptr = head3;
    struct node *small = head3;
    if ( small->taken == 1 )
    {
        while ( small != NULL )
        {
            if ( (small->taken != 1) )
            {
                break;
            }
            small = small->link;
        }
    }
    ptr = small;

    while ( ptr != NULL)
    {
        if( (ptr->size < small->size) && (ptr->size >= s) && (ptr->taken != 1) )
        {
            small = ptr;
        }
        ptr = ptr->link;
    }

    return small;
}

void display ( int mode )
{
    struct node *ptr;
    int notcount;
    switch ( mode )
    {
        case 1:
            printf("First Fit\n");
            printf("``````````\n");
            ptr = head1;
            notcount = nc1;
            if (notcount !=0 )
                {
                    printf("Processes that could not be allocated are : ");
                    for ( int i = 0; i < notcount; i++)
                    {
                        printf("%d ",notcomplete1[i]);
                    }
                }
            break;
        
        case 2:
            printf("Worst Fit\n");
            printf("``````````\n");
            ptr = head2;
            notcount = nc2;
            if (notcount !=0 )
                {
                    printf("Processes that could not be allocated are : ");
                    for ( int i = 0; i < notcount; i++)
                    {
                        printf("%d ",notcomplete2[i]);
                    }
                }
            break;
        
        case 3:
            printf("Best Fit\n");
            printf("`````````\n");
            ptr = head3;
            notcount = nc3;
            if (notcount !=0 )
                {
                    printf("Processes that could not be allocated are : ");
                    for ( int i = 0; i < notcount; i++)
                    {
                        printf("%d ",notcomplete3[i]);
                    }
                }
            break;
    }

    printf("\nMemory partitions :\n");
    printf("Total Size | Allocated | Remaining | Process\n");
    printf("-----------+-----------+-----------+--------\n");

    while ( ptr != NULL)
    {
        if ( ptr->taken == 1 )
        {
            if( ptr->remaining < 100 && ptr->remaining > 10 )
            {
                printf("%d        | %d       | %d        | %d\n", ptr->size, ((ptr->size)-(ptr->remaining)), ptr->remaining, ptr->process);
            }
            else if( ptr->remaining < 10)
            {
                printf("%d        | %d       | %d         | %d\n", ptr->size, ((ptr->size)-(ptr->remaining)), ptr->remaining, ptr->process);
            }
            else
            {
                printf("%d        | %d       | %d       | %d\n", ptr->size, ((ptr->size)-(ptr->remaining)), ptr->remaining, ptr->process);
            }
        }
        else
        {
            printf("%d        | 0         | %d       | \n", ptr->size, ptr->remaining);
        }
        ptr = ptr->link;
    }
}

void firstFit()
{
    for ( int i = 0; i < n; i++)
    {
        int flag = 0;
        struct node *ptr = head1;
        while (ptr != NULL)
        {
            if ( (processes[i] <= ptr->size) && (ptr->taken != 1) )
            {
                ptr->remaining -= processes[i];
                ptr->taken = 1;
                ptr->process = i;
                flag = 1;
                break;
            }
            ptr = ptr->link;
        }
        if ( flag == 0 )
        {
            notcomplete1[nc1++] = i;
        }
    }
    
    display(1);
}

void worstFit()
{
    for ( int i = 0; i < n; i++)
    {
        int flag = 0;
        struct node *ptr = biggest();

        if ( processes[i] <= ptr->size )
        {
            ptr->remaining -= processes[i];
            ptr->taken = 1;
            ptr->process = i;
            flag = 1;
        }
               
        if ( flag == 0)
        {
            notcomplete2[nc2++] = i;
        }
    }
    
    display(2);
}

void bestFit()
{
    for ( int i = 0; i < n; i++)
    {
        int flag = 0;
        struct node *ptr = smallest(processes[i]);

        if ( processes[i] <= ptr->size )
        {
            ptr->remaining -= processes[i];
            ptr->taken = 1;
            ptr->process = i;
            flag = 1;
        }
               
        if ( flag == 0)
        {
            notcomplete3[nc3++] = i;
        }
    }
    
    display(3); 
}


void main()
{
    printf("Vishwanath Pradeep s4 CSE GAMMA\n\n");
    printf("Enter the number of memory partitions : ");
    scanf("%d",&n);
    printf("Enter the size of each memory partition :\n");
    for ( int i = 0; i < n; i++)
    {
        int size;
        printf("\nEnter the size : ");
        scanf("%d",&size);
        insertAtEnd1(size);
        insertAtEnd2(size);
        insertAtEnd3(size);
    }

    printf("Enter the memory requirements of each process :\n");
    for ( int i = 0; i < n; i++)
    {
        printf("Enter the memory requirement : ");
        scanf("%d", &processes[i]);
    }

    printf("\n");
    firstFit();
    printf("\n");
    worstFit();
    printf("\n");
    bestFit();
    printf("\n");
}
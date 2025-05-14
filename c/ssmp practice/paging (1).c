#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int main()
{
    int memory, frameSize;

    printf("\nEnter memory size : ");    
    scanf("%d", &memory);

    printf("Enter frame size : ");  
    scanf("%d", &frameSize);

    int frames = memory/frameSize;

    printf("\nNumber of frames : %d\n",frames);

    int memoryUnits[100] = {0};
    int processes[100] = {0};

    int count = 0;
    int availableFrames = frames;

    do
    {
        int ch;
        printf("\nMenu:\n1.Create process\n2.Delete process\n3.Display process\n4.Exit\nEnter your choice : ");  
        scanf("%d", &ch);
		int procSize,pid,framesRequired;
		bool deleted,processFound;
        switch (ch)
        {
            case 1:
                    procSize = 0;
                    printf("\nEnter process size : ");
                    scanf("%d", &procSize);

                    framesRequired = (procSize + frameSize - 1) / frameSize;
                    if (framesRequired > availableFrames)
                    {
                        printf("\nError- Not enough memory available.\n");
                        break;
                    }
                    else
                    {
                        printf("\nProcess Created.\n");

                        pid = 0;
                        printf("\nEnter process ID : ");
                        scanf("%d", &pid);

                        processes[count++] = pid;

                        for (int i=0; i<frames && framesRequired > 0; i++)
                        {
                            if (memoryUnits[i] == 0)
                            {
                                memoryUnits[i] = pid;
                                framesRequired--;
                                availableFrames--;
                            }
                        }
                    }
                    break;
           

            case 2:
                    pid = 0;
                    deleted = false;

                    printf("\nEnter process ID : ");
                    scanf("%d", &pid);

                    for (int i=0; i<frames; i++)
                    {
                        if (memoryUnits[i] == pid)
                        {
                            memoryUnits[i] = 0;
                            availableFrames++;  
                            deleted = true;
                        }
                    }
                    if (deleted)
                    {
                        printf("\nProcess %d deleted from memory.\n\n", pid);
                    }
                    else
                    {
                        printf("Process %d could not be found in memory.\n", pid);
                    }
                    break;
           
            case 3:
                    printf("\nDisplaying processes in memory :\n");
                    for (int i=0; i<count; i++)
                    {
                        processFound = false;
                        printf("Process ID %d occupies frames : ", processes[i]);
                        for (int j=0; j<frames; j++)
                        {
                            if (memoryUnits[j] == processes[i])
                            {
                                printf("%d ", j);
                                processFound = true;
                            }
                        }
                        if (!processFound)
                        {
                            printf("(Deleted)");
                        }
                        printf("\n");
                    }
                    break;

            case 4:
                    exit(0);

            default:
                    printf("\nInvalid choice.\nTry again.\n\n");
                    break;
        }
    }while (true);
    return 0;
}

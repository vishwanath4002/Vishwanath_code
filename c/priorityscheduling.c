#include <stdio.h>
#include <string.h>

struct Process
{
    char id[3];
    int burstTime;
    int arrivalTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    int priority;
    int processed;
};

void calculateTimes(struct Process processes[], int n)
{
    int currentTime = 0;
    int completedProcesses = 0;
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;

    while (completedProcesses < n)
    {
        int highestPriority = -1;
        int selectedProcess = -1;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrivalTime <= currentTime && !processes[i].processed)
            {
                if (highestPriority == -1 || processes[i].priority < highestPriority)
                {
                    highestPriority = processes[i].priority;
                    selectedProcess = i;
                }
            }
        }

        if (selectedProcess != -1)
        {
            processes[selectedProcess].completionTime = currentTime + processes[selectedProcess].burstTime;
            processes[selectedProcess].turnaroundTime = processes[selectedProcess].completionTime - processes[selectedProcess].arrivalTime;
            processes[selectedProcess].waitingTime = processes[selectedProcess].turnaroundTime - processes[selectedProcess].burstTime;

            totalWaitingTime += processes[selectedProcess].waitingTime;
            totalTurnaroundTime += processes[selectedProcess].turnaroundTime;

            currentTime = processes[selectedProcess].completionTime;
            processes[selectedProcess].processed = 1;
            completedProcesses++;
        }
        else
        {
            currentTime++;
        }
    }

    float averageWaitingTime = totalWaitingTime / n;
    float averageTurnaroundTime = totalTurnaroundTime / n;

    printf("\nProcess ID\t|Completion Time|Waiting Time\t|Turnaround Time\n");
    printf("----------------+---------------+---------------+----------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t|%d\t\t|%d\t\t|%d\n", processes[i].id, processes[i].completionTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time : %f\n", averageWaitingTime);
    printf("Average Turnaround Time : %f\n", averageTurnaroundTime);
}

void main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Process ID for process %d : ", i + 1);
        scanf("%s", processes[i].id);
        printf("Enter Burst Time for process %d : ", i + 1);
        scanf("%d", &processes[i].burstTime);
        printf("Enter Arrival Time for process %d : ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter Priority for process %d : ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].processed = 0;
    }

    calculateTimes(processes, n);
}
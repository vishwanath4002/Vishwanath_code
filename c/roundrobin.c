#include <stdio.h>

struct Process
{
    char id[3];
    int burstTime;
    int arrivalTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    int remainingTime;
};

void calculateTimes(struct Process processes[], int n, int quantum)
{
    int remainingProcesses = n;
    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (processes[i].remainingTime > 0)
            {
                int executeTime = (processes[i].remainingTime < quantum) ? processes[i].remainingTime : quantum;

                if (processes[i].arrivalTime <= currentTime)
                {
                    processes[i].remainingTime -= executeTime;
                    currentTime += executeTime;

                    if (processes[i].remainingTime == 0)
                    {
                        remainingProcesses--;
                        completedProcesses++;
                        processes[i].completionTime = currentTime;
                        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
                        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
                    }
                }
            }
        }
    }
}

void main()
{
    int n, quantum;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    printf("Enter the time quantum : ");
    scanf("%d", &quantum);

    struct Process processes[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Process ID for process %d : ", i + 1);
        scanf("%s", processes[i].id);
        printf("Enter Burst Time for process %d : ", i + 1);
        scanf("%d", &processes[i].burstTime);
        printf("Enter Arrival Time for process %d : ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        processes[i].remainingTime = processes[i].burstTime;
        printf("\n");
    }

    calculateTimes(processes, n, quantum);
    float avgwt = 0;
    float avgtat = 0;
    for (int i = 0; i < n; i++)
    {
        avgwt += processes[i].waitingTime;
        avgtat += processes[i].turnaroundTime;
    }
    avgwt /= n;
    avgtat /= n;

    printf("\nProcess ID\t|Completion Time|Waiting Time\t|Turnaround Time\n");
    printf("----------------+---------------+---------------+----------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t|%d\t\t|%d\t\t|%d\n", processes[i].id, processes[i].completionTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }
    printf("\nAverage Waiting Time : %f\nAverage Turnaround Time : %f", avgwt, avgtat);
}
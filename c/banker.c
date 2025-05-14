#include <stdio.h>

int main() {
    int processes, resources, i, j, k;
    printf("Enter number of processes: ");
    scanf("%d", &processes);
    printf("Enter number of resources: ");
    scanf("%d", &resources);

    int allocated[processes][resources], max[processes][resources], need[processes][resources];
    int available[resources], work[resources], finish[processes];

    printf("Enter allocated resources for each process:\n");
    for (i = 0; i < processes; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < resources; j++) {
            scanf("%d", &allocated[i][j]);
        }
    }

    printf("Enter maximum resources for each process:\n");
    for (i = 0; i < processes; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocated[i][j];
        }
        finish[i] = 0;
    }

    printf("Enter available resources:\n");
    for (i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }

    int safe = 0, count = 0;
    int sequence[processes];
    while (count < processes) {
        safe = 0;
        for (i = 0; i < processes; i++) {
            if (finish[i] == 0) {
                int canExecute = 1;
                for (j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        canExecute = 0;
                        break;
                    }
                }
                if (canExecute) {
                    for (k = 0; k < resources; k++) {
                        work[k] += allocated[i][k];
                    }
                    finish[i] = 1;
                    sequence[count] = i;
                    count++;
                    safe = 1;
                }
            }
        }
        if (!safe) {
            break;
        }
    }

    if (count == processes) {
        printf("The system is in a safe state.\n");
        printf("Safe sequence: ");
        for (i = 0; i < processes; i++) {
            printf("%d ", sequence[i]);
        }
        printf("\n");
    } else {
        printf("The system is in an unsafe state.\n");
    }

    return 0;
}

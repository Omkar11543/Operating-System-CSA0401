#include <stdio.h>
#define NUM_PROCESSES 4
#define NUM_RESOURCES 3

int claim[NUM_PROCESSES][NUM_RESOURCES] = {{3, 2, 2}, {6, 1, 3}, {3, 1, 4}, {4, 2, 2}};
int allocation[NUM_PROCESSES][NUM_RESOURCES] = {{1, 0, 0}, {6, 1, 2}, {2, 1, 1}, {0, 0, 2}};
int available[NUM_RESOURCES] = {9, 3, 6};
int need[NUM_PROCESSES][NUM_RESOURCES];

void calculateNeed()
{
    for (int i = 0; i < NUM_PROCESSES; i++)
        for (int j = 0; j < NUM_RESOURCES; j++)
            need[i][j] = claim[i][j] - allocation[i][j];
}

int isSafe()
{
    int work[NUM_RESOURCES];
    for (int i = 0; i < NUM_RESOURCES; i++)
        work[i] = available[i];
    int finish[NUM_PROCESSES];
    for (int i = 0; i < NUM_PROCESSES; i++)
        finish[i] = 0;
    int num_finish = 0;
    while (num_finish < NUM_PROCESSES)
    {
        int found = 0;
        for (int i = 0; i < NUM_PROCESSES; i++)
        {
            if (finish[i] == 0)
            {
                int j;
                for (j = 0; j < NUM_RESOURCES; j++)
                    if (need[i][j] > work[j])
                        break;
                if (j == NUM_RESOURCES)
                {
                    for (int k = 0; k < NUM_RESOURCES; k++)
                        work[k] += allocation[i][k];
                    finish[i] = 1;
                    found = 1;
                    num_finish++;
                }
            }
        }
        if (found == 0)
            return 0;
    }
    return 1;
}

int main()
{
    calculateNeed();
    if (isSafe())
        printf("The system is in a safe state\n");
    else
        printf("The system is in an unsafe state\n");
    return 0;
}

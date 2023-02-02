#include<stdio.h>

int current[3][3] = { {3,3,3}, {2,0,3}, {1,2,4} };
int max_claim[3][3] = { {3,6,8}, {4,3,3}, {3,4,4} };
int available[3] = {1,2,0};
int allocation[3] = {0,0,0};
int need[3][3];

void calculate_need()
{
    int i,j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            need[i][j] = max_claim[i][j] - current[i][j];
}

int is_safe()
{
    int i,j;
    calculate_need();
    int work[3];
    for (i = 0; i < 3; i++)
        work[i] = available[i];

    int finish[3] = {0,0,0};
    int count = 0;
    while (count < 3)
    {
        int found = 0;
        for (i = 0; i < 3; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < 3; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    for (j = 0; j < 3; j++)
                        work[j] += current[i][j];
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }
        if (found == 0)
        {
            printf("\nSystem is in Deadlock\n");
            return 0;
        }
    }
    printf("\nSystem is in Safe state\n");
    return 1;
}

int main()
{
    if (is_safe() == 0)
    {
        printf("\nDeadlocked processes are: ");
        int i;
        for (i = 0; i < 3; i++)
        {
            if (i== 0)
                printf("P%d ", i+1);
        }
    }
    return 0;
}

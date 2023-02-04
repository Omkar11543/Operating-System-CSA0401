#include <stdio.h>
float averageWaitingTime(int burstTime[], int n)
{
    int waitTime[n];
    waitTime[0] = 0;
    int totalWaitTime = 0;
    for (int i = 1; i < n; i++) {
        waitTime[i] = burstTime[i - 1] + waitTime[i - 1];
        totalWaitTime += waitTime[i];
    }
    return (float) totalWaitTime / n;
}
float averageTurnaroundTime(int burstTime[], int n)
{
    int waitTime[n];
    waitTime[0] = 0;
    int totalTurnaroundTime = burstTime[0];
    for (int i = 1; i < n; i++) {
        waitTime[i] = burstTime[i - 1] + waitTime[i - 1];
        totalTurnaroundTime += burstTime[i] + waitTime[i];
    }
    return (float) totalTurnaroundTime / n;
}

int main()
{
    int n = 3; 
    int burstTime[] = {2, 4, 8}; 
    float avgWaitTime = averageWaitingTime(burstTime, n);
    float avgTurnaroundTime = averageTurnaroundTime(burstTime, n);
    printf("Average waiting time: %.2f\n", avgWaitTime);
    printf("Average turnaround time: %.2f\n", avgTurnaroundTime);
    return 0;
}

#include<stdio.h>

int main()
{
    int n, i, head, abs, track[25], seek_time=0, diff;
    printf("Enter the number of tracks: ");
    scanf("%d", &n);
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the track position: ");
    for(i=0; i<n; i++)
        scanf("%d", &track[i]);

    for(i=0; i<n; i++)
    {
        diff = (head-track[i]);
        seek_time += diff;
        head = track[i];
    }

    printf("\nAverage Head Movement: %d", seek_time/n);
    return 0;
}

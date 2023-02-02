#include <stdio.h>
#include <stdlib.h>
#define NUM_PROCESSES 4

struct Process {
  int burst_time;
  int wait_time;
  int turnaround_time;
};

int compare(const void *a, const void *b) {
  int burst_time_a = ((struct Process*)a)->burst_time;
  int burst_time_b = ((struct Process*)b)->burst_time;
  return burst_time_a - burst_time_b;
}

int main() {
  int i;
  struct Process processes[NUM_PROCESSES];
  int burst_times[] = {6, 8, 7, 3};

  for (i = 0; i < NUM_PROCESSES; i++) {
    processes[i].burst_time = burst_times[i];
  }

  qsort(processes, NUM_PROCESSES, sizeof(struct Process), compare);

  processes[0].wait_time = 0;
  for (i = 1; i < NUM_PROCESSES; i++) {
    processes[i].wait_time = processes[i - 1].burst_time + processes[i - 1].wait_time;
  }

  float total_wait_time = 0;
  float total_turnaround_time = 0;
  for (i = 0; i < NUM_PROCESSES; i++) {
    processes[i].turnaround_time = processes[i].burst_time + processes[i].wait_time;
    total_wait_time += processes[i].wait_time;
    total_turnaround_time += processes[i].turnaround_time;
  }

  float avg_wait_time = total_wait_time / NUM_PROCESSES;
  float avg_turnaround_time = total_turnaround_time / NUM_PROCESSES;

  printf("Average Waiting Time: %.2f\n", avg_wait_time);
  printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

  return 0;
}

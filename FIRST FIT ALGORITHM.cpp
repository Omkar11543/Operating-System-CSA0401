#include <stdio.h>
#include <stdbool.h>
#define NUM_PARTITIONS 6
#define PARTITIONS_SIZE {300, 600, 350, 200, 750, 125}
#define NUM_PROCESSES 5
#define PROCESSES_SIZE {115, 500, 358, 200, 375}

int main() {
    int partitions[NUM_PARTITIONS] = PARTITIONS_SIZE;
    int processes[NUM_PROCESSES] = PROCESSES_SIZE;

    for (int i = 0; i < NUM_PROCESSES; i++) {
        bool placed = false;
        for (int j = 0; j < NUM_PARTITIONS; j++) {
            if (partitions[j] >= processes[i]) {
                printf("Process %d of size %d KB placed in partition %d of size %d KB\n",
                       i + 1, processes[i], j + 1, partitions[j]);
                partitions[j] -= processes[i];
                placed = true;
                break;
            }
        }
        if (!placed) {
            printf("Process %d of size %d KB could not be placed\n", i + 1, processes[i]);
        }
    }

    return 0;
}

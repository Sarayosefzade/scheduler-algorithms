#include <stdio.h>

struct process {
    int pid;
    int bursttime;
    int waitingtime;
};

int main(int argc, const char *argv[]) {
    int numofp;
    scanf("%d", &numofp);
    int i, quantum;
    struct process processes[numofp];
    int totalwait = 0;
    for (i = 0; i < numofp; i++) {
        processes[i].pid = i;
        scanf("%d", &processes[i].bursttime);
    }
    scanf("%d", &quantum);

    int completed = 0;
    int current_time = 0;
    while (completed < numofp) {
        for (i = 0; i < numofp; i++) {
            if (processes[i].bursttime > 0) {
                if (processes[i].bursttime <= quantum) {
                    current_time += processes[i].bursttime;
                    processes[i].waitingtime = current_time - processes[i].bursttime;
                    totalwait += processes[i].waitingtime;
                    processes[i].bursttime = 0;
                    completed++;
                    printf("%d\n", processes[i].pid);
                } else {
                    current_time += quantum;
                    processes[i].bursttime -= quantum;
                    processes[i].waitingtime = current_time - processes[i].bursttime;
                    printf("%d\n", processes[i].pid);
                }
            }
        }
    }

    float average_wait = (float)totalwait / (float)numofp;
    printf("Average waiting time = %f\n", average_wait);

    return 0;
}

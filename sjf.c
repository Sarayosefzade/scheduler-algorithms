#include <stdio.h>

struct process {
    int pid;
    int bursttime;
    int waitingtime;
    int turnaroundtime;
};

int main(int argc, const char* argv[]) {
    int numofp;
    int i, j, a, index;
    scanf("%d", &numofp);
    struct process processes[numofp];
    int totalwait = 0;
    int totaltat = 0;
    for (i = 0; i < numofp; i++) {
        processes[i].pid = i;
        scanf("%d", &processes[i].bursttime);
    }
    for (i = 0; i < numofp; i++) {
        index = i;
        for (j = i + 1; j < numofp; j++) {
            if (processes[j].bursttime < processes[index].bursttime) {
                index = j;
            }
        }
        a = processes[i].bursttime;
        processes[i].bursttime = processes[index].bursttime;
        processes[index].bursttime = a;
    }
    for (i = 0; i < numofp; i++) {
        if (i == 0) {
            processes[i].waitingtime = 0;
        } else {
            processes[i].waitingtime = processes[i - 1].bursttime + processes[i - 1].waitingtime;
        }

        processes[i].turnaroundtime = processes[i].waitingtime + processes[i].bursttime;

        totalwait += processes[i].waitingtime;
        totaltat += processes[i].turnaroundtime;
    }
    float average_tat = (float)totaltat / (float)numofp;
    float average_wait = (float)totalwait / (float)numofp;
    printf("average turn around time = %f\n", average_tat);
    printf("average waiting time = %f\n", average_wait);
    return 0;
}


#include <stdio.h>

struct process{
    int pid;
    int priority;
    int bursttime;
    int waitingtime;
    int turnaroundtime;
};

int main(int argc, const char * argv[]) {
    int numofp;
    scanf("%d", &numofp);
    int i,j,a, index;
    struct process processes[numofp];
    int totalwait = 0;
    int totaltat = 0;
    for(i = 0; i<numofp; i++){
        processes[i].pid = i;
        scanf("%d",&processes[i].bursttime);
        scanf("%d", &processes[i].priority);
    }
    for (i = 0; i < numofp; i++) {
        index = i;
        for (j = i + 1; j < numofp; j++) {
            if (processes[j].priority < processes[index].priority) {
                index = j;
            }
        }

        a = processes[i].priority;
        processes[i].priority = processes[index].priority;
        processes[index].priority = a;
    }

    // Calculate waiting time and turnaround time for each process
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

    // Print average waiting time and average turnaround time
    printf("Average turnaround time = %f\n", average_tat);
    printf("Average waiting time = %f\n", average_wait);
    return 0;
}

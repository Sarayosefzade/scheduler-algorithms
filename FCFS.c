#include <stdio.h>

struct process{
    int pid;
    int bursttime;
    int waitingtime;
    int turnaroundtime;
};

int main(int argc, const char * argv[]) {
    int numofp;
    scanf("%d", &numofp);
    int i;
    struct process processes[numofp];
    int totalwait = 0;
    int totaltat = 0;
    for(i = 0; i<numofp; i++){
        processes[i].pid = i;
        scanf("%d",&processes[0].bursttime);
        if(i == 0){
            processes[i].waitingtime = 0;
        }
        else{
            processes[i].waitingtime = processes[i-1].bursttime + processes[i-1].waitingtime;
        }
        processes[i].turnaroundtime = processes[i].waitingtime+processes[i].bursttime;

        totalwait = totalwait + processes[i].waitingtime;
        totaltat = totaltat + processes[i].turnaroundtime;
    }
    float average_tat = (float)totaltat/(float)numofp;
    float average_wait = (float)totalwait/(float)numofp;
    printf("average turn around time = %f",average_tat );
    printf("average waiting time = %f",average_wait );

    return 0;
}

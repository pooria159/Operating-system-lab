#include <stdio.h>
#include <stdbool.h>

struct process{
	int pid;
	int st, wt, tt;
	int finished;
}p[10];

int main(){
	int n, finishedProcess = 0;
	float sumSt, sumWt, sumTt = 0;
	printf("Input number of process: ");
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){
		int temp;
		printf("Enter process number %d service time: ", i);
		scanf("%d", &temp);
		p[i].pid = i+1;
		p[i].st = temp;
		p[i].finished = -1;
		sumSt += temp;
	}
	p[0].wt = 0;

	printf("Running Algorithm: \n");
	int time = 0;
	sumWt = 0;
	for (int i = 0; i < n; i++){
		int minIndex, minValue = 1000;
		for (int j = 0; j < n; j++){
			if (p[j].finished == -1 && p[j].st < minValue){
				minIndex = j;
				minValue = p[j].st;
			}
		}
		p[minIndex].finished = 1;
		time += p[minIndex].st;
		p[minIndex].tt = time;
		p[minIndex].wt = time - p[minIndex].st;
		sumWt += p[minIndex].wt;
	       	sumTt += p[minIndex].tt;		
		printf("process number %d: service time: %d waiting time: %d total time: %d\n", p[minIndex].pid, p[minIndex].st, p[minIndex].wt, p[minIndex].tt);

	}

	printf("Average service time: %f Average waiting time: %f Average total time: %f\n", sumSt/n, sumWt/n, sumTt/n);
	return 0;
	
	
}

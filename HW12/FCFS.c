#include <stdio.h>


struct process{
	int pid;
	int st, wt, tt;
}p[10];

int main(){
	int n;
	float sumSt, sumWt, sumTt = 0;
	printf("Input number of process: ");
	scanf("%d", &n);

	
	for (int i = 0; i < n; i++){
		int temp;
		printf("Enter process number %d service time: ", i);
		scanf("%d", &temp);
		p[i].pid = i;
		p[i].st = temp;
		sumSt += temp;
	}
	p[0].wt = 0;
	p[0].tt = p[0].st;
	sumTt = p[0].tt;

	printf("Running Algorithm: \n");

	printf("process number 0: service time: %d waiting time: %d total time: %d\n", p[0].st, p[0].wt, p[0].tt);
	for (int i = 1; i < n; i++){
		p[i].wt = p[i-1].st + p[i-1].wt;
		p[i].tt = p[i].st + p[i].wt;
		printf("process number %d: service time: %d waiting time: %d total time: %d\n", p[i].pid, p[i].st, p[i].wt, p[i].tt);
		sumWt += p[i].wt;
		sumTt += p[i].st;
	}

	printf("Average service time: %f Average waiting time: %f Average total time: %f\n", sumSt/n, sumWt/n, sumTt/n);
	return 0;
	
	
}

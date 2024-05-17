#include <stdio.h>
struct process
{
    int id, st, wt, tt, done;
};
int main()
{
    int n, q;
    printf("enter number of processes\n");
    scanf("%d", &n);
    struct process pro_list[n];
    for (int i = 0; i < n; i++)
    {
        int tmp;
        printf("enter service time of process %d\n", i + 1);
        scanf("%d", &tmp);
        pro_list[i].st = tmp;
        pro_list[i].id = i + 1;
        pro_list[i].tt += tmp;
        pro_list[i].wt = 0;
    }
    printf("enter time quantum\n");
    scanf("%d", &q);
    int sum_w = 0;
    int done_count = 0;
    int i = 0;
    while (done_count != n)
    {
        if (pro_list[i].done == 1)
        {
            i += 1;
            if (i == n)
                i = 0;
        }
        else
        {
            if (q <= pro_list[i].st)
            {
                pro_list[i].st -= q;
                printf("process %d is serviced %d seconds\n", pro_list[i].id, q);
                for (int j = 0; j < n; j++)
                {
                    if (j != i && pro_list[j].done != 1)
                        pro_list[j].wt += q;
                }
            }
            else
            {
                printf("process %d is serviced %d seconds\n", pro_list[i].id,pro_list[i].st);
                for (int j = 0; j < n; j++)
                {   
                    if (j != i && pro_list[j].done != 1)
                        pro_list[j].wt += pro_list[i].st;
                }
                pro_list[i].st = 0;
            }
            if (pro_list[i].st == 0 && pro_list[i].done != 1)
            {   
                done_count += 1;
                pro_list[i].done = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("process %d => wait= %d seconds\n", i + 1, pro_list[i].wt);
        sum_w += pro_list[i].wt;
    }
        printf("the average waiting time is %d\n", sum_w / n);
        return 0;
}

#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf(1, "Usage: SMLsanity <n>\n");
		exit();
	}
	int i, n, j = 0, k, retime, rutime, stime;
	int times[3][3];
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			times[i][j] = 0;
	n = atoi(argv[1]);
	int pid;
	for (i = 0; i < n; i++)
	{
		j = i % 3;
		pid = fork();
		if (pid == 0)
		{
			j = (getpid() - 4) % 3;
#ifdef SML
			switch (j)
			{
			case 0:
				chpr(getpid(), 1);
				break;
			case 1:
				chpr(getpid(), 2);
				break;
			case 2:
				chpr(getpid(), 3);
				break;
			}
#endif
			for (k = 0; k < 100; k++)
			{
				for (double z = 0; z < 10000.0; z += 0.1)
				{
					double x = x + 3.14 * 89.64;
				}
			}
			exit();
		}
		continue;
	}
	for (i = 0; i < n; i++)
	{
		pid = wait2(&retime, &rutime, &stime);
		int res = (pid - 4) % 3;
		switch (res)
		{
		case 0:
			printf(1, "Priority 1, pid: %d, ready: %d, running: %d, sleeping: %d, turnaround: %d\n", pid, retime, rutime, stime, retime + rutime + stime);
			times[0][0] += retime;
			times[0][1] += rutime;
			times[0][2] += stime;
			break;
		case 1:
			printf(1, "Priority 2, pid: %d, ready: %d, running: %d, sleeping: %d, turnaround: %d\n", pid, retime, rutime, stime, retime + rutime + stime);
			times[1][0] += retime;
			times[1][1] += rutime;
			times[1][2] += stime;
			break;
		case 2:
			printf(1, "Priority 3, pid: %d, ready: %d, running: %d, sleeping: %d, turnaround: %d\n", pid, retime, rutime, stime, retime + rutime + stime);
			times[2][0] += retime;
			times[2][1] += rutime;
			times[2][2] += stime;
			break;
		}
	}
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			times[i][j] /= n;
	printf(1, "\nPriority 1: Avg ready time: %d\tAvg running time: %d\tAvg sleeping time: %d\tAvg turnaround time: %d\n", times[0][0], times[0][1], times[0][2], times[0][0] + times[0][1] + times[0][2]);
	printf(1, "\nPriority 2: Avg ready time: %d\tAvg running time: %d\tAvg sleeping time: %d\tAvg turnaround time: %d\n", times[1][0], times[1][1], times[1][2], times[1][0] + times[1][1] + times[1][2]);
	printf(1, "\nPriority 3: Avg ready time: %d\tAvg running time: %d\tAvg sleeping time: %d\tAvg turnaround time: %d\n", times[2][0], times[2][1], times[2][2], times[2][0] + times[2][1] + times[2][2]);
	exit();
}

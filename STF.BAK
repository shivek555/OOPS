#include <stdio.h>
void main()
{
    int A[100][4];
    int i, j, n, total = 0, index, temp;
    printf("\nEnter number of process: ");
    scanf("%d", &n);
    printf("Enter Burst Time:\n");
    for (i = 0; i < n; i++) {
	printf("P%d: ", i + 1);
	scanf("%d", &A[i][1]);
	A[i][0] = i + 1;
    }
    // Sorting process according to their Burst Time.
    for (i = 0; i < n; i++) {
	index = i;
	for (j = i + 1; j < n; j++)
	    if (A[j][1] < A[index][1])
		index = j;
	temp = A[i][1];
	A[i][1] = A[index][1];
	A[index][1] = temp;

	temp = A[i][0];
	A[i][0] = A[index][0];
	A[index][0] = temp;
    }
    A[0][2] = 0;
    // Calculation of Waiting Times
    for (i = 1; i < n; i++) {
	A[i][2] = 0;
	for (j = 0; j < i; j++)
	    A[i][2] += A[j][1];
	total += A[i][2];
    }
    total = 0;
    printf("P     BT     WT     TAT\n");
    // Calculation of Turn Around Time and printing the
    // data.
    for (i = 0; i < n; i++) {
	A[i][3] = A[i][1] + A[i][2];
	total += A[i][3];
	printf("P%d     %d     %d      %d\n", A[i][0],
	       A[i][1], A[i][2], A[i][3]);
    }
   // avg_tat = (float)total / n;
  //  printf("Average Waiting Time= %f", avg_wt);
  //  printf("\nAverage Turnaround Time= %f", avg_tat);
}
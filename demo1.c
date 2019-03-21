#include <stdio.h>

int main() 
{
	
	
	 int arrival_time[10]={1,1,1,1,1,1,1,1,1,1}, burst_time[10], temp[10];
      int i, smallest, count = 0, time, limit;
      int wait_time[10],turnaround_time[10],completion[10], end;
      float average_waiting_time=0, average_turnaround_time=0;
	
	
	 FILE* file = fopen ("test.txt", "r");
  int h = 0,j,k;
  int array[100];
  fscanf (file, "%d", &h);    
  for (j=0; (!feof (file)); j++)
    {
     // printf ("%d\n", i);
      array[j] = h;
      fscanf (file, "%d", &h);      
    }
    for(k=0; k<j; k++)	{
    	printf("%d\n", array[k]);
	}
  fclose (file);  
  for(j=0;j<100;j++)
  {
  burst_time[j]=array[j];
  
}
for(j=0;burst_time[j]!='\0';j++)
printf("%d\n",burst_time[j]);
  
	
	
	
     
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &limit); 
      printf("\nEnter Details of %d Processes\n", limit);
      for(i = 0; i < limit; i++)
      {
            //printf("\nEnter Arrival Time:\t");
            //scanf("%d", &arrival_time[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      }
      burst_time[9] = 9999;  
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burst_time[smallest]--;
            if(burst_time[smallest] == 0)
            {           
                  count++;
                  end = time + 1;
                  completion[smallest] = end;
                  wait_time[smallest] = end - arrival_time[smallest] - temp[smallest];
				   turnaround_time[smallest] = end - arrival_time[smallest];
                  //wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
                  //turnaround_time = turnaround_time + end - arrival_time[smallest];
            }
      }
//      average_waiting_time = wait_time / limit; 
//      average_turnaround_time = turnaround_time / limit;

	printf("pid \t burst \t arrival \twaiting \tturnaround \tcompletion");
    
	for(i=0;i<limit;i++)
    {
    	printf("\n %d \t   %d \t %d\t\t%d   \t\t%d\t\t%d",i+1,temp[i],arrival_time[i],wait_time[i],turnaround_time[i],completion[i]);
   		average_waiting_time = average_waiting_time + wait_time[i];
   		average_turnaround_time = average_turnaround_time + turnaround_time[i];
    	
	}
	  
      printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time/limit);
      printf("Average Turnaround Time:\t%lf\n", average_turnaround_time/limit);  
      return 0;
}

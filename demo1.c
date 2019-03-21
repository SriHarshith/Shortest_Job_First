#include <stdio.h>
int main() 
{ 
	
	int arrival_time[10]={0}, burst_time[10]={0}, temp[10];
 	int i, smallest, count = 0, time, limit,count_infile=0;
    int wait_time[10],turnaround_time[10],completion[10], end;
    float average_waiting_time=0, average_turnaround_time=0;
    	
    int h = 0,j,k;
 	int array[100];
 	 	
	 FILE* file = fopen ("test.txt", "r");
  	 fscanf (file, "%d", &h);   //taking 1st number of file
  	 array[0] = h;				//storing at 1st position of array
	      
    for (j=1; (!feof (file)); j++)
     {
      fscanf (file, "%d", &h);   //taking 2nd element onwards till last element
      if(h>0)
	  array[j] = h;  			 //storing only +ve values in array  
	  else
	  j--;						//neglecting -ve values
     }
     
    for(k=0; k<j; k++)
    printf("%d\n", array[k]);  	 //printing elements of array
    limit=k;                         //count of elements in file
	printf("\n count of burst time array %d",limit);
	
    fclose (file);               //closing the file
    
    for(j=0;j<limit;j++)
    burst_time[j]=array[j];      //copy array elements to burst_time array
	
	for(j=0;j<limit;j++)
	printf("\n%d",burst_time[j]); //printing burst_time array elements

	printf("\nNumber of processes %d\n\n",limit); 

      for(i = 0; i <= limit; i++)
      {
            temp[i] = burst_time[i]; //copy burst_time to temp array
      }
      burst_time[9] = 9999;         //assigning a large value to last element
      for(time = 0; count != limit; time++)
      {
            smallest = 9;            //taking last element as smallest
            for(i = 0; i < limit; i++)
            {
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;//finding smallest burst time's process
                  }
            }
            burst_time[smallest]--;  //decreasing burst time value until it becomes 0
            if(burst_time[smallest] == 0)
            {           
                  count++;
                  end = time + 1;   //finding completion time
                  completion[smallest] = end;
				  turnaround_time[smallest] = end - arrival_time[smallest]; //T.A.T = C.T - A.T
				  wait_time[smallest] = turnaround_time[smallest] - temp[smallest]; // W.T = T.A.T - B.T
            }
      }

	//printf("  pid \t burst \t arrival \twaiting \tturnaround \tcompletion");
    printf("  pid \t Arrival Time \tBurst Time \tCompletion Time \tTurnaround Time \tWaiting Time");
    
	for(i=0;i<limit;i++)
    {
    	//printf("\n   %d \t   %d \t %d\t\t%d   \t\t%d\t\t%d",i+1,temp[i],arrival_time[i],wait_time[i],turnaround_time[i],completion[i]);
   		printf("\n   %d \t     %d \t\t  %d\t\t\t%d   \t\t\t%d\t\t    %d",i+1,arrival_time[i],temp[i],completion[i],turnaround_time[i],wait_time[i]);

	
		average_waiting_time = average_waiting_time + wait_time[i];  //finding sum 
   		average_turnaround_time = average_turnaround_time + turnaround_time[i];//finding sum 
    	
	}
	  
      printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time/limit);//printing average values
      printf("Average Turnaround Time:\t%lf\n", average_turnaround_time/limit);//printing average values  
      return 0;
}

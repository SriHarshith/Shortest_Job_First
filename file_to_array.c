#include<stdio.h>
main()
{
	  FILE* file = fopen ("test.txt", "r");
  int i = 0,j,k;
  int array[100];
  fscanf (file, "%d", &i); 
  array[0] = i; //for storing first value  
  for (j=1; (!feof (file)); j++)
    {
     // printf ("%d\n", i);
      fscanf (file, "%d", &i);
	  array[j] = i;  //for storing 2nd element onwards till last element    
    }
    for(k=0;k<j; k++)	{
    	printf("%d\n", array[k]);
	}
  fclose (file);  
}

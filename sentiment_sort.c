#include "sentiment_sort.h"


int main(int argc,char**argv)
{

	opterr = 0;
    char c, *array = NULL;
    int i, input[MAX_NUMBERS-1] , *output;
    
    while((c=getopt(argc,argv,"n:a:"))!= -1)
    	switch(c)
    {
    	case 'n':
    	    array = optarg;
    	    len = strtol(array,NULL,0);
    	    break;

    	case 'a':
    	    array = optarg;
    	    striptrailspace(array);
    	    convert(array,input);
    	    break;

    	case '?':
    	  if(optopt == 'a')
    	  	printf("Option \"-a\" expects an argument ex. \"1 2 -4 -5\" \n" );
    	  else if(optopt == 'n')
    	  	printf("Option \"-n\" expects an argument.\n" );
    	  else if (isprint (optopt))
          	printf ("Unknown option `-%c'.\n", optopt);
          else
          	printf ("Unknown option character `\\x%x'.\n", optopt);
            exit(-1);
    	  	break;     
    }   

    output = (int*)malloc(len*sizeof(output));
    sentimentSort(input ,len , output);
    printOutput(input, len, output);
          
return 0;
}

void printOutput(int *input, int len, int *output)
{
	int i;
	printf("\n-----------------------------------------------------------");
	printf("\nInput:\n");
    for(i=0;i<len;i++)
    	printf("%d\t", input[i]);

    printf("\nOutput:\n");
    for(i=0;i<len;i++)
    	printf("%d\t", output[i]);

    printf("\n-----------------------------------------------------------\n");

}

void convert(char*string, int*numbers)
{
    int i = 0;  
    char *end, *copy_input = string;

        while(*copy_input!='\0')
     	{
            numbers[i++] = strtol(copy_input, &end, 10);
            copy_input = end;
        }

        if(len == 0)
        	len = i-1;
}

void sentimentSort(int *input, int len, int *output)
{
    int copy_input[len], i, count[RANGE + 1];

    // The output character array that will have sorted sentiments
    for(i=0;i<len;i++)
    {
      copy_input[i] = input[i] - MIN;
    }
    // Create a count array to store count of inidividul characters and
    // initialize count array as 0
    memset(count, 0, sizeof(count));

    // Store count of each character
    for(i = 0; i<len; ++i)
        ++count[copy_input[i]];

    // Change count[i] so that count[i] now contains actual position of
    // this sentiment in output array
    // As negative sentiments are ranked higher than unbaised/median sentiments, 
    //they will be positioned further ahead in the array. 
    for (i = 0; i <= RANGE/2; ++i){

        if(i==0)
            count[RANGE] = count[RANGE] + count[0];
        else if(i==RANGE/2)
            count[RANGE/2] = count[RANGE/2] + count[RANGE/2+1];
        else
        {
        count[i] = count[i] + count[RANGE - i+1];
        count[RANGE - i] = count[RANGE - i] + count[i];
        }
    }
    
    // Build the output array
    for (i = 0; i<len; ++i)
    {
        output[count[copy_input[i]]-1] = copy_input[i] + MIN;
        --count[copy_input[i]];
    }
 
    
}

void striptrailspace( char *line )
{
    int i = strlen(line) - 1;
    while ( i > 0 )
    {
        if ( isspace(line[i]) )
        {
            line[i] = '\0';
        }
        else
        {
            break;
        }
        i--;
    }
}
#include<stdio.h>
#define INF 10000000


main()
{

	int i;
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
	
		int numOfElem;
		scanf("%d",&numOfElem);
		
		long int a[numOfElem];
		
		for(i=0; i<numOfElem; i++)
		scanf("%ld",&a[i]);
		
		long int min1 = a[0];
		int index=0;
	
		for(i=1; i<numOfElem; i++)
		{
		
			if( a[i]<min1 )
			{
				
				min1 = a[i];
				index=i;
				
			}	 
		
		}
		
		a[index] = INF;
		
		long int min2 = a[0];
		
		for(i=1; i<numOfElem; i++)
		{
		
			if( a[i]<min2 )
			{
				
				min2 = a[i];
				
			}	 
		
		}
		
		printf("%ld\n",min1+min2);
	
	}
	
	

}

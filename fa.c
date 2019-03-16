#include <stdio.h>
#include <string.h>
#define N_ALPHA 2

int main()
{
	/*Declaration*/
	int n_Q, n_alphabet, n_final,i,j,k=0,len,flag=0;
	int initial_state,final_state;
	int search(int a[], int x, int sz);
	char create_delta(char Q[], char alpha[]);
	
	
	/*Input for no of  states*/
	printf("Enter no of possible states: ");
	scanf("%d",&n_Q);
	
	/*States*/
	int Q[n_Q];
	for(i=0;i<n_Q;i++)
	{
		Q[i]=i;
	}
	
	printf("States are: ");
	for(i=0;i<n_Q;i++)
	{
		printf("%d ",Q[i]);
	}
	printf("\n");
	
	/*Input for no of alphabets*/
	/*printf("Enter no of alphabets: ");
	scanf("%d",&n_alphabet);*/
	
	
	/*Alphabets*/
	char alphabet[N_ALPHA+1];
	printf("Enter %d Alphabets (without spaces): ",N_ALPHA);
	scanf("%s",alphabet);
	
	/*Creating Mapping Function*/
	int mapping[n_Q][N_ALPHA];
	int delta(int map[][N_ALPHA], int current_state, char input_symbol,  char alpha[]/*, int Q[], char alpha[],int n_alpha*/);
	char temp;
	/*for(i=0;i<n_Q;i++)
	{
	
		for(j=0;j<n_alphabet;j++)
		{
			printf("Enter transition for delta( %c, %c): ",Q[i],alphabet[j]);
			temp=getchar();
			mapping[i][j]=temp;
			printf("Hii %c",mapping[i][j]);
			
		}
		
	}*/
	i=0;
	while(k<n_Q)
	{
		
		for(i=0;i<N_ALPHA;i++)
		{
			printf("Enter delta(%d-state, %c): ",Q[k], alphabet[i]);
			scanf("%d",&mapping[k][i]);
			if(search(Q,mapping[k][i],n_Q)==0)
			{
				printf("Entered state doen't exist!\n");
				printf("Proceeding further may cause an error!");
			
			}
		}
		k++;

	}

	/*Initial state*/
	//initial_state=getchar();
	printf("Enter initial state: ");
	scanf("%d",&initial_state);
	
	/*Count of Final states*/
	printf("Enter no of final states: ");
	scanf("%d",&n_final);
	if(n_final==0)
	{
		flag=1;
			printf("Here1!");
	}
	
	/*Final states*/
	int F[n_final];
	printf("Enter final states: ");
	if(n_final==0)
	{
		printf("------- (Zero no of final states)\n");
	}
	for(i=0;i<n_final;i++)
	{
		scanf("%d",&F[i]);
			if(search(Q,F[i],n_Q)==0)
			{
				printf("Entered state does't exist!\n");
				printf("WARNING: Proceeding further may cause an error!\n");
				
			}
	}
	

	
	/*Length of Input string*/
	
	printf("Enter Length of Input string: ");
	scanf("%d",&len);
	
	/*Input string*/
	char Input_String[len+1];
	printf("Enter Input String: ");
	scanf("%s",Input_String);
	
	final_state=initial_state;
	for(i=0;i<len;i++)
	{
		final_state=delta(mapping,final_state,Input_String[i], alphabet);
		printf("state= %d\n",final_state);
		if(final_state==-1)
		{
			
			flag=1;
			printf("Here!");
			break;
		}
	}
	
	if(search(F,final_state,n_final)==0||flag==1)
	{
		printf("Input String %s is NOT ACCEPTABLE to Finite Automata! ",Input_String);
	}
	else
	{
		printf("Input String %s is ACCEPTABLE to Finite Automata! ",Input_String);
	}
	
	
	
	
	
	
}
int delta(int map[][N_ALPHA], int current_state, char input_symbol, char alpha[])
{
	/*int x=n_alphabet;
	int i=strchr(Q,current_state);
	int j=strchr(alpha,input_symbol);
	
	return(map[i][j]);*/
	int ret_val;
	char *p=strchr(alpha, input_symbol);
	if(p==NULL)
	{
		ret_val=-1;
	}
	else
	{
		int i=(p-alpha)/sizeof(char);
			ret_val=(map[current_state][i]);
	}
	return(ret_val);
	

	
}
int search(int a[], int x, int sz)
{
	int i;
	int ret=0;
	for(i=0;i<sz;i++)
	{
		if(x==a[i])
		{
			ret=1;
			break;
		}
	}
	return(ret);
}


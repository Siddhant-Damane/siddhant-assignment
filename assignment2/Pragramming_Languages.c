#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct  restaurant_and_its_cost
{
	int   restaurant_ID;
	float  cost_to_restaurant;
	int cflag;
	struct  restaurant_and_its_cost *next;
}*head=NULL;

struct  restaurant_and_its_cost *current;



struct  list_of_good_restaurant
{
	int   restaurant_ID;
	float cost_to_restaurant;
	int cflag;
	struct  list_of_good_restaurant *next;
}*start=NULL;

struct  list_of_good_restaurant *last = NULL;


void  print_possible_restaurant()
{
	struct  restaurant_and_its_cost *temp;
	temp =head ;

	if(temp != NULL)
	{

		printf("printing list of possible restaurant\n");
		while (temp != NULL)
		{
			printf("restaurant_ID %d cost %f \n",temp->restaurant_ID,temp->cost_to_restaurant); 
			temp = temp->next;
		}
	}
	else
	{
			printf("No possible restaurants are available !!\n");
	}
}



void  add_to_list_of_good_restaurant(int   restaurant_ID , float cost_to_restaurant,int comboflag)
{

struct  list_of_good_restaurant *temp;

temp = (struct  list_of_good_restaurant *)malloc(sizeof(struct  list_of_good_restaurant));



temp->restaurant_ID =   restaurant_ID;
temp->cost_to_restaurant =   cost_to_restaurant;
temp->cflag = comboflag;


if(start == NULL)
{
	start = temp;
	start->next = NULL;
	last = start;
}


else
{
	last->next = temp;
	last = temp;
	temp->next = NULL;

}

}



void  add_possible_restaurant(int   restaurant_ID, float  cost_to_restaurant,int comboflag)
{

struct  restaurant_and_its_cost *new_node;

new_node=(struct   restaurant_and_its_cost *)malloc(sizeof(struct   restaurant_and_its_cost));

  
new_node->restaurant_ID =   restaurant_ID;
new_node->cost_to_restaurant =  cost_to_restaurant;
new_node->cflag = comboflag;
new_node->next=NULL;

if(head==NULL)
{
	head=new_node;
	current=new_node;
}
else
{
	current->next=new_node;
	current=new_node;
}


}



void  search_restaurant_with_min_cost()
{

float  first_restaurant_cost;
struct   restaurant_and_its_cost *temp = head;


float  minimum = 0;

while(temp != NULL)
{

	if(minimum != 0)
	{
		if(temp->cost_to_restaurant <=  minimum)
		{		

			//printf("found one more value\n");

			minimum = temp->cost_to_restaurant;

			add_to_list_of_good_restaurant(temp->restaurant_ID,temp->cost_to_restaurant,temp->cflag);

			//printf("no problem in calling fun\n");
		}
	}

	else 
	{

		minimum = temp->cost_to_restaurant;
		first_restaurant_cost =  minimum;

	}

	temp = temp->next;
}

if(minimum ==  first_restaurant_cost)
{
	add_to_list_of_good_restaurant(head->restaurant_ID,head->cost_to_restaurant,head->cflag);

}



}


void  print_good_restaurant()
{
struct  list_of_good_restaurant *temp = start;



if(temp != NULL )
{
	printf("Good restaurants are - \n");
	while(temp != NULL)
	{
	
		printf(" %d ",temp->restaurant_ID);
		printf(" %f ",temp->cost_to_restaurant);
		if(temp->cflag == 1)
		{
			printf(" *With extra free items");
		}
		temp = temp->next;
		printf("\n");

	}

	printf("\n");
}
else 
{
	printf("Sorry no restaurants are available for your query .. !!!\n");
}

}



int main(int argc,char* argv[]){



FILE *fp;

fp = fopen(argv[1],"r");


if( fp == NULL )
{
	printf("Error while opening the file %s.\n", argv[1]);
}



char* str = NULL;
char *token;
size_t n=0;
int read,count,pre_hotel_in_iteration = 0,argument_menu_count = argc -2,  same_pack =0,restaurant_ID =0;
const char s[3] = " , ";
float  cost_to_restaurant,menu_price =0,total_cost_for_this_hotel=0,f;
int comboflag =0;

while((read = getline(&str,&n,fp)) != -1)								//starts reading file line by line
{
	count=0;
	total_cost_for_this_hotel =0;
	str[strlen(str)-1] = 0;
	token = strtok(str, s);										//first token indicates restuarant id
	//printf( " %s is   restaurant_ID id\n", token );
	restaurant_ID  =atoi( token);
	if(restaurant_ID != pre_hotel_in_iteration)						//if reading data for new restuarant , reset values of variables
	{
		//printf("%d is new   restaurant_ID now\n",restaurant_ID);
		argument_menu_count = argc - 2;
		cost_to_restaurant =0;
	}
	token = strtok(NULL,s);									//next token is menu price
	
	sscanf(token, "%f", &f);
	//printf("%f is float value of token %s\n",f,token);
	menu_price = f;
	same_pack = 0;
	count =0;
	comboflag = 0;
	while( token != NULL ) 									// further tokens considered as menu
	{
		token = strtok(NULL,s);
		if(token != NULL)
		{	
			if(count++ > 0 && cost_to_restaurant != 0)								//if multiple menus are requested
			{
				
					same_pack = 1;
					comboflag = 1;
			}
			int  iterator = 2;
			while(iterator < argc)
			{
				if(!(strcmp(token, argv[iterator])))				
					{
					
					argument_menu_count = argument_menu_count - 1 ;
					if(!  same_pack)
					{
							cost_to_restaurant =  cost_to_restaurant +  menu_price;
						
					}
					else
					{
						//printf("same pack successfull\n");
					}
					break;
				}
				else
				{
						iterator++;	
				}
			}			
		}
	}
	if(argument_menu_count == 0 )
	{
		total_cost_for_this_hotel =  cost_to_restaurant ;
		//printf("total cost for   restaurant_ID %d is %d\n",,,restaurant_ID,cost); 
		add_possible_restaurant(restaurant_ID,cost_to_restaurant,comboflag);
		argument_menu_count = argc -2 ;
	}
	pre_hotel_in_iteration =   restaurant_ID;
}
fclose(fp);



print_possible_restaurant();


search_restaurant_with_min_cost();


print_good_restaurant();


}





#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

typedef struct type_apart{
	char address[30];
	int rooms;
	double price;
}apart;
apart* Ok_apartment_or_Not(apart* apart_unit, int amount, int MAX ,int*how_many ,int amount_apart);

int main()
{
	apart* apartments = NULL;

	apart* Qualified_for_me;

	int Min_Rooms;

	int MAX_price;


	int many;

	int how_many_apartments;
	printf(" Insert the amount of apartments you need : \n");
	scanf_s("%d", &how_many_apartments);

	apartments = (apart*)malloc(how_many_apartments * sizeof(apart));

	printf(" \n hello this is a program that you insert apartment and get which ones are qualifed for you  \n");
		for (int i = 0; i < how_many_apartments; i++)
		{
		printf("this is the %d apartment :\n",i+1);

		printf("Address ");

		scanf_s( "%s",apartments[i].address,30);

		printf("\n");

		printf(" how many rooms are  ");

		scanf_s("%d", &apartments[i].rooms);

		printf("\n");

		printf("the price of the apartment is : ");

		scanf_s("%lf", &apartments[i].price);

		printf("\n");


		}

	printf("Please  Insert the minimum amount of rooms you need \n");
	scanf_s("%d", &Min_Rooms);

	printf("Please Insert the Maximum price you can efford for the apartment \n");

	scanf_s("%d", &MAX_price);

	Qualified_for_me = Ok_apartment_or_Not(apartments, Min_Rooms, MAX_price,&many, how_many_apartments);

	printf("The apartments that are qualified for you are : \n");

		for (int i = 0; i < many; i++)
		{
			
			printf("the adress is :%s \n", Qualified_for_me[i].address);
			printf("the amount of rooms are :%d \n", Qualified_for_me[i].rooms);
			printf("the price is :%d \n", Qualified_for_me[i].rooms);
		}
		free(Qualified_for_me);
		Qualified_for_me = NULL;
		free(apartments);
		apartments = NULL;
	return 0;
}

apart* Ok_apartment_or_Not(apart* apart_unit, int amount, int MAX , int* how_many,int amount_apart)
{
	apart* Qualified_apart = NULL;
	int amount_qualified_apartment=0;
	for (int i = 0; i < amount_apart; i++)
	{
		if (apart_unit[i].price < MAX && apart_unit[i].rooms >= amount)
		{
			amount_qualified_apartment++;
		}
	}

	Qualified_apart = (apart*)malloc(amount_qualified_apartment * sizeof(apart));
	int j = 0;

	for (int i = 0; i < amount_apart; i++)
	{
		
		if (apart_unit[i].price < MAX && apart_unit[i].rooms >= amount)
		{
			Qualified_apart[j].price = apart_unit[i].price;

			for(int k=0;k<30|| (apart_unit[i].address[k] == '\0');k++)
				Qualified_apart[j].address[k] = apart_unit[i].address[k];

			Qualified_apart[j].rooms = apart_unit[i].rooms;
				j++;
		}
	}
	*how_many = j;

	return Qualified_apart;
}
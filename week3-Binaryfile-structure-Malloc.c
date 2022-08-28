#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

int main()
{
#ifdef que1
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		int num;
		printf("Enter a number");
		scanf("%d", &num);
		arr[i] = num;
	}
	
	FILE* f = fopen("c:\\C-Class-Exercises\\week3-Assignment.bin", "w");
	if (!f)
	{
		printf("Error");
		exit(1);
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			fwrite(&arr[i], sizeof(int), 1, f);
		}
		fclose(f);
		
	}
#endif

#ifdef que2

	int arr1[8];
	int sum1 = 0;
	for (int i = 0; i < 8; i++)
	{
		int num1;
		printf("Enter a number");
		scanf("%d", &num1);
		arr1[i] = num1;
		sum1 = sum1 + num1;
	}

	int arr2[4];
	int sum2 = 0;
	for (int i = 0; i < 4; i++)
	{
		int num2;
		printf("Enter a number");
		scanf("%d", &num2);
		arr2[i] = num2;
		sum2 = sum2 + num2;
	}

	FILE* f = fopen("c:\\C-Class-Exercises\\week3-Assignment2.bin", "w");
	if (!f)
	{
		printf("Error");
	}
	else
	{
		if (sum1 > sum2)
		{
			for (int  i = 0; i < 8; i++)
			{
				fwrite(&arr1[i], sizeof(int), 8, f);
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				fwrite(&arr2[i], sizeof(int), 4, f);
			}
		}
	}
	fclose(f);
#endif



	struct Item
	{
		int value;
		char name[100];
		short answer;
	};

	struct Item show1;
	struct Item show2;
	struct Item show3;
	show1.value;
	show1.name[100];
	show1.answer;
	show2.value;
	show2.name[100];
	show2.answer;
	show3.value;
	show3.name[100];
	show3.answer;

	printf("Enter 3 Value: ");
	scanf("%d %d %d", &show1.value, &show2.value, &show3.value);
	printf("Enter 3 Name: ");
	scanf("%s %s %s", show1.name, show2.name, show3.name);

	int len1 = strlen(show1.name);
	int len2 = strlen(show2.name);
	int len3 = strlen(show3.name);
	if (show1.value > 10 && len1 > 5)
	{
		show1.answer = 1;
	}
	else
	{
		show1.answer = 0;
	}

	if (show2.value > 10 && len2 > 5)
	{
		show2.answer = 1;
	}
	else
	{
		show2.answer = 0;
	}

	if (show3.value > 10 && len3 > 5)
	{
		show3.answer = 1;
	}
	else
	{
		show3.answer = 0;
	}

	

	FILE*f = fopen("c:\\C-Class-Exercises\\week3-Assignment3.bin", "w");
	if (!f)
	{
		printf("Error");
		exit(1);
	}
	else
	{
		fwrite(&show1, sizeof(struct Item), 1, f);
		fwrite(&show2, sizeof(struct Item), 1, f);
		fwrite(&show3, sizeof(struct Item), 1, f);
		fclose(f);
	}




	return 0;
}
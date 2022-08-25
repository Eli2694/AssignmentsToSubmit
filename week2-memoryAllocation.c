#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

void lastQuestSub();

int main_submit_memoryAlloc()
{

	lastQuestSub();
	return 0;
}

void lastQuestSub()
{
	FILE* f;
	f = fopen("c:\\haim\\data3.txt", "r");
	int number = 0;
	char ch = 0;
	int* pInt;
	int* pIntMalloc;

	char* pChar;
	char* pCharMalloc;

	if (f == NULL)
	{
		printf("Error in file openning");
		exit(1);
	}
	else
	{
		while (ch != EOF)
		{
			ch = fgetc(f);

			if (ch >= '0' && ch <= '9')
			{
				number = ch - '0';
			}

			if (ch == 'c')
			{
				pChar = malloc(sizeof(char) * number);
				pCharMalloc = pChar;
				for (int i = 0; i < number; i++)
				{
					printf("Enter A Charecter: ");
					scanf(" %c", pChar);
					pChar++;
				}
				free(pCharMalloc);
			}
			else if (ch == 'i')
			{
				pInt = malloc(sizeof(int) * number);
				pIntMalloc = pInt;
				for (int i = 0; i < number; i++)
				{
					printf("Enter A Number: ");
					scanf("%d", pInt);
					pInt++;
				}
				free(pIntMalloc);
			}
		}

	}
	fclose(f);
}
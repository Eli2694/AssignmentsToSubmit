#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)

#define FILE_NAME "file.log"





//Function - Specification
void Log(char massage[100]);
void LogError(char message[100]);
void LogEvent(char message[100]);

int main_log()
{
	LogEvent("START LOG");
	Log("eli");

	//A program must be written in MAIN that receives a number from the user. After receiving the number, write to the log which number the user entered
	char num[10];
	printf("Enter a number\n");
	scanf("%s", &num);
	char str[1000];
	sprintf(str, "the user enter the number %s", num);
	LogEvent(str);
	//******************************************************************************************************************************
	
	// A new file must be opened for writing and the numbers from 1 to the same number entered by the user must be written into it
	FILE* f1 = fopen(FILE_NAME, "a");
	if (!f1)
	{
		LogError("Fail did not open");
	}
	else
	{
		char userInput[100];
		char changeNumber[100];
		printf("Choose the top of sequnce numbers: ");
		scanf("%s", &userInput);
		for (int i = 0; i <= atoi(userInput); i++)
		{
			sprintf(changeNumber, " %d ", i);
			fputs(changeNumber, f1);
			fputs("\n", f1);
		}
		fclose(f1);
	}
	// ***************************************************************************************************************************

	//Time

	/*
	2022.11.01:233443 - Event - System is starting
	2022.11.01:233444 - Error - File Is Not opened
	2022.11.01:233445 - Event - System is ending
	*/
	/*
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);
	char myTime[100];
	sprintf(myTime, "%d%d%d", timeinfo->tm_year+1900, timeinfo->tm_mon+1, timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
	*/
	//*****************************************************************************************

	LogEvent("END LOG");
	return 0;
}

void Log(char massage[100])
{
	FILE* f = fopen(FILE_NAME, "a");
	fputs(massage, f);
	fputs("\n", f);
	fclose(f);
}

void LogError(char message[100])
{

	//Time
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);
	char myTime[100];
	sprintf(myTime, "%d/%d/%d/%d.%d.%d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
	
	//Create a string with function sprintf
	char str[100];
	sprintf(str, "%s - Error - %s", myTime, message);
	Log(str);
}

void LogEvent(char message[100])
{
	//Time
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);
	char myTime[100];
	sprintf(myTime, "%d/%d/%d/%d.%d.%d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

	//Create a string with function sprintf
	char str[100];
	sprintf(str, "%s - Event - %s",myTime, message);
	Log(str);
}
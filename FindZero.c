#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#ifdef WIN32
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS 1
#define NULL 0
#endif


#ifndef WIN32
#include<pthread.h>
#include<unistd.h>
#endif
using namespace std;


/*
    CLEARSCREEN()
*/
#ifndef WIN32 
#define CLEARSCREEN()\
{\
   \
    printf("\033c");         \
}
#endif 

#ifdef WIN32  

#define CLEARSCREEN()\
{\
   \
    system("CLS");         \
}
#endif



/*
      PAUSE()
*/
#ifdef WIN32
#define PAUSE()\
{\
   system("pause");\
}
#endif
#ifndef WIN32
#define PAUSE()\
{\
    while ((getchar()) != '\n');\
}
#endif

#ifdef WIN32
void uSleep(int waitTime)
{
	__int64 time1 = 0, time2 = 0, sysFreq = 0;

	QueryPerformanceCounter((LARGE_INTEGER *)&time1);
	QueryPerformanceFrequency((LARGE_INTEGER *)&sysFreq);
	do {
		QueryPerformanceCounter((LARGE_INTEGER *)&time2);

		//  }while((((time2-time1)*1.0)/sysFreq)<waitTime);
	} while ((time2 - time1) < waitTime);
}
#endif

#ifndef WIN32
void uSleep(int waitTime)
{
	usleep(waitTime);
}
#endif

int main()
{
	int lnPos = 0;
	char lcPlay = 'Y';
	int lnScore = 0;
	
	int lnTimer = 0;
	
	long long lnTimeer;
	lnTimeer = time((time_t*)NULL);
	srand(lnTimeer);
	int lnRandfake = 0;
	int lnRandLimit = 0;
	int lnRand = 0;
	long long lnTime = 100000;
	char lcBuffer[8] = { 0 };
	do
	{
		CLEARSCREEN();
		strncpy(lcBuffer, "_ _ _ _", 7);
		 lnRand = (rand() % 4) * 2;
		 lnRandLimit = rand() % 20;
		for (int lnCounter = 0; lnCounter <= lnRandLimit; lnCounter++)
		{
			lnRandfake = (rand() % 4) * 2;
			lcBuffer[lnRandfake] = '0';
			printf("%s \n",lcBuffer);
			uSleep(lnTime);
			strncpy(lcBuffer, "_ _ _ _", 7);
			CLEARSCREEN();
		}
		lcBuffer[lnRand] = '0';
		printf("%s \n",lcBuffer);
		uSleep(lnTime);
		CLEARSCREEN();
		printf("%s \n","_ _ _ _" );
		printf("%s \n","where is '0' located ?");
		scanf("%d",&lnPos);
		lnPos--;
		if (lcBuffer[lnPos * 2] == '0')
		{
			lnScore++;
			printf("%s \n", "buddy you have a great eye");
		}
		else
		{
			printf("%s \n","GAME OVER");
			break;
		}
		printf("%s \n","ENTER Y TO PLAY or any other to quit");
		scanf(" %c", &lcPlay);
		//lcPlay = getchar();
		while ((getchar()) != '\n');
		//printf("%c", lcPlay);
		lnTime = lnTime / 2;
	} while (lcPlay == 'Y');
	printf("%s %d \n","your score is ", lnScore );
	PAUSE();
}


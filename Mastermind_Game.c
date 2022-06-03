#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern void sleep(int seconds);
void simulateGame(void);
void howToPlay(void);
void selectDifficultyLevel(void);
void playGame(void);
void computeFeedback(char codeString[], char guessString[]);

#define NOVICE 1
#define STANDARD 2
#define EXPERT 3
#define CODE_MAX_LENGTH 10
#define MAX_ATTEMPTS 10
#define NOVICE_ATTEMPTS 10
#define STANDARD_ATTEMPTS 20
#define EXPERT_ATTEMPTS 30
#define NOVICE_CODE_LEN 4
#define STANDARD_CODE_LEN 5
#define EXPERT_CODE_LEN 6
#define TRUE 1
#define FALSE 0 

int difficultyLevel = NOVICE;
int secretLength = 4;
int numAttempts = NOVICE_ATTEMPTS;

int randomInteger(int low, int high)
{
  int k;
  double d;

  d = (double)rand()/(1.0 + (double)RAND_MAX);
  k = (int) (d*(high - low + 1));
  return (low + k);
}

void simulateGame() 
{
	char code[4] = {'R','O','V','G'};

	printf("Try guessing \n");
	sleep(5);
	printf("GVRP \n");
	sleep(2);

	printf("Sorry, your guess GVRP is not a match (B: %d, W: %d) \n", 2, 2);
	printf("Interpret B and W\n");
	
	printf("Try guessing \n");
	sleep(5);
	printf("ROGV \n");
	sleep(2);

	printf("Sorry, your guess ROGV is not a match (B: %d, W: %d) \n", 2, 2);
	
	printf("Try guessing \n");
	sleep(5);
	printf("ROVG \n");
	sleep(2);

	printf("YAY, your guess ROVG is a match (B: %d, W: %d) \n", 2, 2);
	return;
}

void howToPlay() 
{
	printf("\nHOW TO PLAY:\nThe computer creates a code which "
		"has to be quessed by the user.\nEach guess is made by the "  
		"user by typing first letter of the colors, for example, " 
		"G R Y P.\nOnce code is typed, the code maker (computer) " 
		"provides feedback by displaying m B and n W,\nwhere m and n "
		"can be a positive integer <= number of positions (for example 1 B, 2 W).\n"
		"B is displayed for each color from the guess which is correct "
		"in both color and position.\nW indicates the existence of a correct color, "
		"but placed in the wrong position.\nOnce feedback is provided, "
		"another guess is made by the user;\nguesses and feedback continue " 
		"to alternate until either the code breaker guesses correctly,\n"
		"or twelve (or ten, or eight) incorrect guesses are made, depending " 
		"on the difficulty level.\n\n");	
}

void selectDifficultyLevel() 
{
	int dl = 0;
	printf("Choose Difficulty Level\n");
	printf("1 for Novice\n2 for Standard and \n3 for Expert\n");
	scanf("%d",&dl);
	while(dl!= NOVICE && dl!= STANDARD && dl!= EXPERT)
	{
		printf("Your input is invalid. Try again...");
		scanf("%d",&dl);
	}
	if(dl == NOVICE)
	{
		printf("The difficulty level is set to Novice\n"
			"The colours available are: R O G Y P V.\n"
			"The secret code length is 4. You're good to go!\n\n");

		secretLength = NOVICE_CODE_LEN;
		numAttempts = NOVICE_ATTEMPTS;
		difficultyLevel = NOVICE;
	}
	if(dl == STANDARD)
	{
		printf("The difficulty level is set to Standard\n" 
			"The colours available are: R O G Y P V.\n"
			"The secret code length is 5. You're good to go!\n\n");

		secretLength = STANDARD_CODE_LEN;
		numAttempts = STANDARD_ATTEMPTS;
		difficultyLevel = STANDARD;
	}
	else if(dl == EXPERT)
	{
		printf("The difficulty level is set to Expert\n" 
			"The colours available are: R O G Y P V.\n"
			"The secret code length is 6. Brace yourself, champion!\n");

		secretLength = EXPERT_CODE_LEN;
		numAttempts = EXPERT_ATTEMPTS;
		difficultyLevel = EXPERT;
	}
}

void aboutGame() 
{
	printf("\nABOUT THE GAME:\nMaster Mind is a code-breaking game " 
		"for two players - a code maker and a code breaker.\n"
		"With four pegs and six colors, there are 6^4 = 1296 different " 
		"patterns (allowing duplicate colors).\nVarying the number of " 
		"colors and the number of holes results in\na spectrum of" 
		"Mastermind games of different levels of difficulty.\n"
		"In this program, computer plays the role of code maker and " 
		"user plays the role of code breaker.\nCode maker (computer) " 
		"creates a code consisting of 4 or more colors at specific " 
		"positions,\nbut does not reveal the code to code breaker " 
		"(user).\nCode breaker tries to guess the pattern, in both " 
		"order and color, within 'x'turns,\nwhere x is determined " 
		"based on the difficulty level.\n\n");
		printf("To get a feel, try to simulate the game -- press option 5\n\n");
}

void computeFeedback(char codeString[], char guessString[]) 
{
	int min, sum, cp=0, c=0, i;
	int l = strlen(codeString);
	char code[CODE_MAX_LENGTH], string[CODE_MAX_LENGTH];
	strcpy(code,codeString);
	strcpy(string,guessString);
	for (i=0;i<=(l-1);i++)
	{
		if (string[i]==code[i])
			cp++;
	}
	printf("\tB: %d\n", cp);
		
	int R1=0,R2=0,O1=0,O2=0,G1=0,G2=0,Y1=0,Y2=0,P1=0,P2=0,V1=0,V2=0;
	for (i=0;i<=(l-1);i++)
	{
		if (string[i]=='R') R1++;
		if (string[i]=='O') O1++;
		if (string[i]=='G') G1++;
		if (string[i]=='Y') Y1++;
		if (string[i]=='P') P1++;
		if (string[i]=='V') V1++;
		if (code[i]=='R') R2++;
		if (code[i]=='O') O2++;
		if (code[i]=='G') G2++;
		if (code[i]=='Y') Y2++;
		if (code[i]=='P') P2++;
		if (code[i]=='V') V2++;
	}
	sum=0;
	min=R1;
	if (R2<min) min=R2;	
	sum=sum+min;
	min=O1;
	if (O2<min) min=O2;	
	sum=sum+min;
	min=G1;
	if (G2<min) min=G2;	
	sum=sum+min;
	min=Y1;
	if (Y2<min) min=Y2;	
	sum=sum+min;
	min=P1;
	if (P2<min) min=P2;	
	sum=sum+min;
	min=V1;
	if (V2<min) min=V2;	
	sum=sum+min;

	c=sum-cp;
	printf("\tW: %d\n", c);
	c=0;
	cp=0;
}
void playGame() 
{
	// Loop until User quits, Runs out of tries or Cracks the code
	char flag = TRUE, v = FALSE;
	char codeString[CODE_MAX_LENGTH];
	char guessString[CODE_MAX_LENGTH];
	int turn = 1;
	int len = 0;

	int l = 0;
	if(difficultyLevel == NOVICE) 
		l = NOVICE_CODE_LEN;
	else if(difficultyLevel == STANDARD)
		l = STANDARD_CODE_LEN;
	else if(difficultyLevel == EXPERT)
		l = EXPERT_CODE_LEN;
	else
		l = NOVICE_CODE_LEN;

	for(int i = 0; i < CODE_MAX_LENGTH; i++) 
	{
		guessString[i] = '\0';
		codeString[i] = '\0';
	}
	//Valid color codes are R, O, G, Y, P, V
	for(int i = 0; i < l ; i++) 
	{
		int random = randomInteger(1, 6);

		switch(random) {
			case 1: 
				codeString[i] = 'R';
				break;
			case 2:
				codeString[i] = 'O';
				break;
			case 3:
				codeString[i] = 'G';
				break;
			case 4:
				codeString[i] = 'Y';
				break;
			case 5:
				codeString[i] = 'P';
				break;
			case 6:
				codeString[i] = 'V';
				break;
			default:
				codeString[i] = 'R';
				break;
		}
	}
	//printf("%s\n",codeString);

	printf("You are %s User \n", (difficultyLevel == 1) ? "NOVICE" : 
			(difficultyLevel == 2) ? ("STANDARD") : ("EXPERT"));
	printf("You have %d Attempts\n", numAttempts);

	while(flag == TRUE) 
	{
		if(turn > numAttempts) 
		{
			printf("Tough Luck. You are out of turns.\n");
			printf("The secret code was %s\n",codeString);
			return;
		}
		printf("This is your %d of %d attempts\n", turn, numAttempts);
		turn++;

		printf("Enter the guess string containing R, O, G, Y, P, V only\n");
		scanf("%s", guessString);

		if(strcmp(guessString, codeString) == 0) 
		{
			printf("CONGRATULATIONS!! You Won the game\n");
			return;
		}
		if(strcmp(guessString, "QUIT") == 0) 
		{
			printf("You have decided to QUIT this game. Try your luck next time... \n");
			printf("The secret code was %s\n",codeString);
			return;
		}

		len = strlen(guessString);
		if(difficultyLevel == NOVICE && len != NOVICE_CODE_LEN ||
			difficultyLevel == STANDARD && len != STANDARD_CODE_LEN ||
			difficultyLevel == EXPERT && len != EXPERT_CODE_LEN) 
		{
			printf("Level %d does not match code length entered - %d. Try again \n", 
					difficultyLevel, len);
			continue;
		}
		
		//printf("Setting V to FALSE\n");
		v = FALSE;
		for(int i = 0; i < len; i++) 
		{
			//printf("guessString[%d] = %c\n", i, guessString[i]);
			if(guessString[i] != 'R' && guessString[i] != 'O' && guessString[i] != 'G'
				&& guessString[i] != 'Y' && guessString[i] != 'P' && guessString[i] != 'V') 
			{
				printf("You have entered invalid color code %c at position %d\n", 
						guessString[i], i);
				printf("Setting V to TRUE\n");
				v = TRUE;
				//break;
			}
		}

		if(v == TRUE) 
		{
			printf("Due to invalid character continue with new input\n");
			continue;
		}
		//Feedback computation
		computeFeedback(codeString, guessString);
	}
}

int main()
{
	int choice = 0;
	char flag = TRUE;

	while(flag == TRUE) 
	{
		printf("\n\n\t\t\t\tWELCOME TO MASTERMIND!\n\t\t\t\t"
			"THE CODE BREAKING GAME!\n Choose one of the following:"
			"\n1.Play\n2.How to Play\n3.Difficulty\n4.About the Game\n"
			"5.Simulate the game\n6.Quit\n");

		scanf("%d",&choice);

		switch(choice) 
		{
			case 1:
				playGame();
				break;
			case 2:
				howToPlay();
				break;
			case 3:
				selectDifficultyLevel();
				break;
			case 4:
				aboutGame();
				break;
			case 5:
				simulateGame();
				break;
			case 6:
				flag = FALSE;
				break;
			default: 
				printf("Invalid input. Try again.");
		}
	}
	return 0;
}

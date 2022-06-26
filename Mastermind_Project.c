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

typedef struct
{
	int colors[4];
	int black;
	int white;
} guess;

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
	//A function to show a demonstration of the game
	char code[4] = {'R','O','V','G'};

	printf("Try guessing \n");
	sleep(5);
	printf("GVPY \n");
	sleep(2);

	printf("Sorry, your guess GVRP is not a match (B: %d, W: %d) \n", 0, 2);
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

	printf("YAY, your guess ROVG is a match (B: %d, W: %d) \n", 4, 0);
	return;
}

void aboutGame() 
{
	//A function to display some information about the game
	printf("\nABOUT THE GAME:\nMaster Mind is a code-breaking game " 
		"for two players - a code maker and a code breaker.\n"
		"With four pegs and six colors, there are 6^4 = 1296 different " 
		"patterns (allowing duplicate colors).\nVarying the number of " 
		"colors and the number of holes results in\na spectrum of " 
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

void howToPlay() 
{
	//A function to display the rules of the game
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
	//A function to let the user choose the difficulty level
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

void computeFeedback(char codeString[], char guessString[]) 
{
	//A function to compute and display the feedback for each guess
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
	//The function that contains the loop for the game
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

		switch(random) 
		{
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

	printf("You are %s User \n", (difficultyLevel == 1) ? "NOVICE" : 
			(difficultyLevel == 2) ? ("STANDARD") : ("EXPERT"));
	printf("You have %d Attempts\n", numAttempts);

	//Loop until User quits, Runs out of tries or Cracks the code
	while(flag == TRUE) 
	{
		if(turn > numAttempts) 
		{
			printf("Tough Luck. You are out of turns.\n");
			printf("The secret code was %s\n",codeString);
			return;
		}
		printf("This is your %d of %d attempts\n", turn, numAttempts);
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
		
		v = FALSE;
		for(int i = 0; i < len; i++) 
		{
			if(guessString[i] != 'R' && guessString[i] != 'O' && guessString[i] != 'G'
				&& guessString[i] != 'Y' && guessString[i] != 'P' && guessString[i] != 'V') 
			{
				printf("You have entered invalid color code %c at position %d\n", 
						guessString[i], i);
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
		turn++;
	}
}

void valuation(int *col1, int *col2, int *wp, int *bp)
{
	//A function to find the number of Black and White pegs to be given as feedback
	int color[6][2];
	int c;
	int white;
	int black;

	for(c=0; c<6; c++)
		color[c][0]=color[c][1]=0;

	for(c=0; c<4; c++)
	{
    		color[col1[c]][0]++;
    		color[col2[c]][1]++;
 	}	
  	white=0;
  	for(c=0; c<6; c++)
    		white+=color[c][(color[c][0]>color[c][1] ? 1 : 0)];

  	black=0;
  	for(c=0; c<4; c++)
   		black+=(col1[c]==col2[c] ? 1 : 0);
  	white-=black;
  	*wp=white;
  	*bp=black;
}

int search(int *colors, int depth, guess *gp, int guesses)
{
	//A function to search for the common colours in the guess and secret code
	int guess;
	int white, black;
	int c;
	if(depth==4)
	{
		for(guess=0; guess<guesses; guess++)
		{
			valuation(colors, gp[guess].colors, &white, &black);
			if(!(white==gp[guess].white && black==gp[guess].black))
				break;
    		}
    		return (guess<guesses ? 0 : 1);
  	}
  	for(c=0; c<6; c++)
  	{
    		colors[depth]=c;
    		if(search(colors, depth+1, gp, guesses))
      			return 1;
  	}
  	return 0;
}

int indexof(char *string, char character)
{
	//A function to find the first occurance of a character in a string
	char *p = strchr(string,character);
	if(p)
	{
		int i = p - string;
		return i;
	}
	else
		return -1;
}

void codeMaker()
{
	//The function that contains the code for the computer guessing the secret code
	srand((unsigned)time(NULL));
	char secret_code[100];
	char valid_colours[] = "ROGYPV";
	printf("You have chosen to be code maker!\n");
	printf("You have to make a secret code and the computer will guess the code in miniumum number of tries.\n");
	printf("The length of the secret code should be 4. The valid colours are R, O, G, Y, P and V.\n");
	printf("You can create a secret code with a combination of these colours, with or without repition.\n");

	int toguess[4];
	int c;
	int done=0;
	guess *gp=NULL, *cur;
	int guesses=0;
	int wrongstring;
	int len;
	do
	{
		printf("Enter the code: ");
		scanf("%s",secret_code);
		len = strlen(secret_code);
		wrongstring = 0;
		if(len!=4)
		{
			printf("The secret code length is invalid. Enter a code of length 4.\n");
			wrongstring = 1;
		}
		else
		{
			for(c=0; c<4; c++)
			{
				if(strchr(valid_colours,secret_code[c])==NULL)
				{
					printf("Color no. %d (value %c) is not valid.\n",(c+1),secret_code[c]);
					wrongstring = 1;
					break;
				}
				else
				{
					wrongstring = 0;
				}
			}
		}	
	} while (wrongstring != 0);
	printf("---------------------\n");
	printf(" turn :  code  : W/B \n");
	printf("---------------------\n");
	
	for(c=0; c<4; c++)
	{
		toguess[c] = indexof(valid_colours,secret_code[c]);
	}
	
	while(!done)
	{
		guesses++;
		gp=(guess *)realloc((void *)gp, guesses*sizeof(guess));
		cur=gp+(guesses-1);
		search(cur->colors, 0, gp, guesses-1);
		valuation(cur->colors, toguess, &(cur->white), &(cur->black));
		printf("#%d\t ",guesses);
		for(c=0; c<4; c++)
		{
			char colour1;
			int colour_pos = cur->colors[c];
			switch(colour_pos)
			{
				case 0: colour1 = 'R';
					break;
				case 1: colour1 = 'O';
					break;
				case 2: colour1 = 'G';
					break;
				case 3: colour1 = 'Y';
					break;
				case 4: colour1 = 'P';
					break;
				case 5: colour1 = 'V';
					break;
			}
			printf(" %c",colour1);
		}
		printf("  %d %d\n",cur->white, cur->black);
		done=(cur->black==4 ? 1 : 0);
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
			"\n1.Play the game as Code Breaker\n2.Be the Code Maker\n3.Difficulty\n4.About the Game\n"
			"5.How to Play\n6.Simulate the game\n7.Quit\n");

		scanf("%d",&choice);
		switch(choice) 
		{
			case 1:
				playGame();
				break;
			case 2:
				codeMaker();
				break;
			case 3:
				selectDifficultyLevel();
				break;
			case 4:
				aboutGame();
				break;
			case 5:
				howToPlay();
				break;
			case 6: 
				simulateGame();
				break;
			case 7:
				flag = FALSE;
				break;
			default: 
				printf("Invalid input. Try again.");
		}
	}
	return 0;
}

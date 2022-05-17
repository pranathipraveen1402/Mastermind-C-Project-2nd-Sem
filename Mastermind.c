#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int RandomInteger(int low, int high)
{
  int k;
  double d;

  d = (double)rand()/(1.0 + (double)RAND_MAX);
  k = (int) (d*(high - low + 1));
  return (low + k);
}

int main()
{
	int l=4,min,sum,choice;
	start: printf("\t\t\t\tWELCOME TO MASTERMIND!\n\t\t\t\tTHE CODE BREAKING GAME!\n Choose one of the following:\n1.Play\n2.How to Play\n3.Difficulty\n4.About the Game\n");
	scanf("%d",&choice);
	if (choice == 1)
	{
		printf("The colours available are: R O G Y P V.\nThe default difficulty level is Novice. The secret code length is 4.");
		play: srand((int)time(NULL));
		int i;
		int table[l];
		for (i=0;i<=(l-1);i++)
			table[i]=RandomInteger(1,6);
		char code[l];
		for (i=0;i<=(l-1);i++)
		{
			if (table[i]==1) code[i]='R';
			if (table[i]==2) code[i]='O';
			if (table[i]==3) code[i]='G';
			if (table[i]==4) code[i]='Y';
			if (table[i]==5) code[i]='P';
			if (table[i]==6) code[i]='V';
		}
	
		char string[100];
		int try=1, cp=0, c=0, flag=0;
		while (flag==0)
		{
			error : printf("Try %d:", try);
			scanf("%s", string);
			int length = strlen(string);
			if (string[0]=='S' && string[1]=='U' && string[2]=='R' && string[3]=='R' && string[4]=='E' && string[5]=='N' && string[6]=='D' && string[7]=='E' && string[8]=='R')
			{
				printf("You have lost the game. The secret code was %s\n", code);
				break;
			}
			if (length != l)
			{
				printf("Code sequence has to be exactly %d colors\n", l);
				goto error;
			}
			for (i=0;i<=(l-1);i++)
			{
				if (string[i]!='R' && string[i]!='O' && string[i]!='G' && string[i]!='Y' && string[i]!='P' && string[i]!='V')
				{
					printf("Error sequence, please try again\n");
					goto error;
				}
			}
			flag=1;
			for (i=0;i<=(l-1);i++)
			{
				if (string[i]!=code[i])
					flag=0;
			}
			if (flag==1)
			{
				printf("Congratulations! You have won the game after %d tries\n", try);
				break;
			}
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
			try++;	
		}
	}
	else if (choice == 2)
	{
		printf("\nHOW TO PLAY:\nThe computer creates a code which has to be quessed by the user.\nEach guess is made by the user by typing first letter of the colors, for example, G R Y P.\nOnce code is typed, the code maker (computer) provides feedback by displaying m B and n W,\nwhere m and n can be a positive integer <= number of positions (for example 1 B, 2 W).\nB is displayed for each color from the guess which is correct in both color and position.\nW indicates the existence of a correct color, but placed in the wrong position.\nOnce feedback is provided, another guess is made by the user;\nguesses and feedback continue to alternate until either the code breaker guesses correctly,\nor twelve (or ten, or eight) incorrect guesses are made, depending on the difficulty level.\n\n");
		goto start;
	}
	else if (choice == 3)
	{
		int dl;
        	printf("Choose Difficulty Level. Type:\n");
		printf("1 for Novice\n2 for Expert\n");
		scanf("%d",&dl);
        	while(dl!=1 && dl!=2)
        	{
            		printf("The input enterred is invalid. Enter again.");
            		scanf("%d",&dl);
        	}
        	if(dl==1)
        	{
			printf("The difficulty level is set to \"Novice\". The colours available are: R O G Y P V.\nThe secret code length is 4. You're good to go, newbie!\n\n");
		}
        	else if(dl==2)
        	{
			printf("The difficulty level is set to \"Expert\". The colours available are: R O G Y P V.\nThe secret code length is 6. Brace yourself, champion!\n\n");
			l = 6;
        	}
		goto play;
	}
	else if (choice == 4)
	{
		printf("\nABOUT THE GAME:\nMaster Mind is a code-breaking game for two players – a code maker and a code breaker.\nWith four pegs and six colors, there are 64 = 1296 different patterns (allowing duplicate colors).\nVarying the number of colors and the number of holes results in a spectrum of Mastermind games of different levels of difficulty.\nIn this program, computer plays the role of code maker and user plays the role of code breaker.\nCode maker (computer) creates a code consisting of 4 or more colors at specific positions, but does not reveal the code to code breaker (user).\nCode breaker tries to guess the pattern, in both order and color, within ‘x’ turns, where x is determined based on the difficulty level.\n\n");
		goto start;
	}
	else
	{
		printf("Invalid input.");
		goto start;
	}
	return 0;
}

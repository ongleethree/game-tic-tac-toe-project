#include <stdio.h>
#include <iostream>
#include <ctime>

void drawnBoard(char *space);
void play(char *space, char player);
void bot(char *space, char playerbot);
bool check_winner(char* space, char playerbot , char player);

using namespace std;

int number;
int number2;

int main()
{
	char space[9] = { ' ', ' ', '  ' , '  ','  ' ,'  ' , '  ', '  ', '  ' };
	char player = 'x';
	char playerbot = 'O';
	bool running = true;
	drawnBoard(space);


	while (running)
	{
		play(space,player);
		drawnBoard(space);
		if (check_winner(space, playerbot, player))
		{
			running = false;
			break;
		}
		bot(space, playerbot);
		drawnBoard(space);
		if (check_winner(space, playerbot, player))
		{
			running = false;
			break;
		}

	}
	return 0;
}
void drawnBoard(char *space)
{
	
	cout << "     |     |     " << "\r\n";
	cout << "  " << space[0] << "  |  " << space[1] << "  |  " << space[2] << "  |  " << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << "\r\n";
	cout << "  " << space[3] << "  |  " << space[4] << "  |  " << space[5] << "  |  " << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << "\r\n";
	cout << "  " << space[6] << "  |  " << space[7] << "  |  " << space[8] << "  |  " << endl;
	cout << "     |     |     " << "\r\n";


}

void play(char * space, char player)
{
	
	 while ( number > 0 || number < 8 )
	{
		cout << "enter number for spot 0-9 = ";
		cin >> number;
		number--;
		if (space[number] == ' ')
		{
			space[number] = player;
			break;
		}
	}
	
}

void bot(char* space, char playerbot)
{
	
	srand(time(0));
	while (true)
	{
		number2 = rand() % 9;
		if (space[number2] == ' ')
		{
			space[number2] = playerbot;
			break;
		}
	}
}
bool check_winner(char* space, char playerbot, char player)
{
	if (space[0]!=' ' && space[0] == space[1] && space[1] == space[2])
	 {
		
		space[0] == player ? cout << "YOU WIN \n" : cout << "You lose\n";
	 }
	else 
	if (space[0] != ' ' && space[0] == space[3] && space[3] == space[6])
	{
		space[0] == player ? cout << "YOU WIN \n" : cout << "You lose\n";
	}
	else
	
	if (space[1] != ' ' && space[1] == space[4] && space[4] == space[7])
	{
		space[1] == player ? cout << "YOU WIN \n" : cout << "You lose\n";
	}
	else
	
	    if (space[2] != ' ' && space[2] == space[5] && space[5] == space[8])
		{
			space[2] == player ? cout << "YOU WIN \n" : cout << "You lose\n";
	    }
		else
		if (space[6] != ' ' && space[6] == space[7] && space[7] == space[8])
		{
			space[6] == player ? cout << "YOU WIN \n" : cout << "You lose\n";
		}
		else
		if (space[3] != ' ' && space[3] == space[4] && space[4] == space[5])
		{
			space[3] == player ? cout << "YOU WIN \n" : cout << "You lose\n";
		}
		else
	
	return(0);
}
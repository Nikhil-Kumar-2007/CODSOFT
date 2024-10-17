#include <iostream>
#include <windows.h>
#include <limits>
#include <vector>
#include <string>
using namespace std;


void drawBoard (vector <char> board);
void set_name(string &player1, string &player2);
void aboutPlayer(char &choice1, char &choice2,  string player1, string player2, vector <char> board);
int move(vector <char> board);
void playAndWin(char choice1, char choice2, string player1, string player2, string name, vector <char> board);

int main ()
{
	system("color 6A");
	vector <char> board = {'1','2','3','4','5','6','7','8','9'};
    drawBoard(board);
	char choice1, choice2;
	string player1, player2, name;
	set_name(player1, player2);
	aboutPlayer(choice1, choice2, player1, player2, board);
    playAndWin(choice1, choice2, player1, player2, name, board);
	return 0;
}

void drawBoard (vector <char> board) 
{
	system("cls");
	cout << "\n\n================================================";
	cout << "\n\t\tTic - Tac - Toe\n";
	cout << "================================================\n\n";
    cout << "     |" << "     |" << "     \n";    
    cout << "  " << board[0] << "  |" << "  " << board[1] << "  |" << "  " << board[2] << "  \n"; 
    cout << "_____|" << "_____|" << "_____\n";
    cout << "     |" << "     |" << "     \n";    
    cout << "  " << board[3] << "  |" << "  " << board[4] << "  |" << "  " << board[5] << "  \n"; 
    cout << "_____|" << "_____|" << "_____\n";
    cout << "     |" << "     |" << "     \n";
    cout << "  " << board[6] << "  |" << "  " << board[7] << "  |" << "  " << board[8] << "  \n";
    cout << "     |" << "     |" << "     \n";    
    return;
}

int move (vector <char> board)
{
	if (board[0] == board[1] && board[1] == board[2])
		return 1;
	else if (board[3] == board[4] && board[4] == board[5])
		return 1;
	else if (board[6] == board[7] && board[7] == board[8])
		return 1;
    else if (board[0] == board[3] && board[3] == board[6])
		return 1;
	else if (board[1] == board[4] && board[4] == board[7])
		return 1;
	else if (board[2] == board[5] && board[5] == board[8])
		return 1;
	else if (board[0] == board[4] && board[4] == board[8])
		return 1;
	else if (board[2] == board[4] && board[4] == board[6])
		return 1;
	else if (board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4' && board[4] != '5' && board[5] != '6' && board[6] != '7' && board[7] != '8' && board[8] != '9')
		return 0;
	else 
	    return -1;
}

void set_name(string &player1, string &player2) 
{
	cout << endl << endl;
	system("pause");
	system("cls");
	cout << "\n\nEnter the name of first player : ";
	cin >> player1;
	cout << "\nEnter the name of second player2 : ";
	cin >> player2;
	system("cls");
	return;
}

void aboutPlayer (char &choice1, char &choice2,  string player1, string player2, vector <char> board)
{
	cout << "\n\npossible choises are : (x or o)\n";
	char ch;
    cout << "\n" << player1 << " enter your choise : ";
    cin >> ch;
    if (ch == 'x')
    {
    	choice1 = 'x';
    	choice2 = 'o';
    }
    else if (ch == 'o')
    {
    	choice1 = 'o';
    	choice2 = 'x';
    }
    else
    {
    	cout << "\nyou entered invallid choice!!\n\n\n";
		Sleep(800);
		system("cls");
    	aboutPlayer(choice1, choice2, player1, player2, board);
    }
    return;
}

void playAndWin(char choice1, char choice2,  string player1, string player2, string name, vector <char> board)
{
	int player = 1, num, i;
    char mark;
	drawBoard(board);
	do
	{
		if (player % 2 == 0)
		{
			player = 2;
			mark = choice2;
		}
		else 
		{
			player = 1;
			mark = choice1;
		}
		if (player == 1)
		    name = player1;
		else
		    name = player2;	
		cout << endl << name << "(" << mark << ")" << " enter a number : ";
		cin >> num;
	    if (num == 1 && board[0] == '1')
	        board[0] = mark;    	
        else if (num == 2 && board[1] == '2')
	        board[1] = mark;
	    else if (num == 3 && board[2] == '3')
	        board[2] = mark;
	    else if (num == 4 && board[3] == '4')
	        board[3] = mark;	
	    else if (num == 5 && board[4] == '5')
	        board[4] = mark;
	    else if (num == 6 && board[5] == '6')
	        board[5] = mark; 
	    else if (num == 7 && board[6] == '7')
	        board[6] = mark;
	    else if (num == 8 && board[7] == '8')
	        board[7] = mark;      
	    else if (num == 9 && board[8] == '9')
	        board[8] = mark;    
	    else
	    {
	    	cout << "you entered a wrong choice!!";
			Sleep(800);
			cin.clear();
	    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
	    	player--;
	    } 
	    player++; 
	    drawBoard(board);
     	i = move(board);
	} while (i == -1);
	--player;
	if (i == 1)
		cout << "\n\n==> \a" << name << " win" << endl << endl;
	else
		cout << "\n\n==> \a GAME DRAW !!" << endl << endl;
}
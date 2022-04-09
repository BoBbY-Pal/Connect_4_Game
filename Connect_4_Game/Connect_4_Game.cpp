#include<iostream>
#include<Windows.h>

using namespace std;

#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define WHITE   "\033[37m"      /* White */
#define YELLOW  "\033[33m"      /* Yellow */
#define MAGENTA "\033[35m"      /* Magenta */  
#define CYAN    "\033[36m"      /* Cyan */

char board[6][7];	//available for whole program

void WelcomeScreen()
{
    cout << BLUE;
    cout << GREEN  << "Rules:\n" << WHITE << "1. Two Player Game (Red {" << RED << "R" << WHITE << "} & Blue {" << BLUE << "B" << WHITE << "})\n2. Board Size is 6 rows x 7 Columns.\n3. A player wins if he/she is able to connect 4 dots horizontally, vertically or diagonally.\n4. Its a Draw if the board is fully filled.\n\n" << GREEN << "How To Play:\n" << WHITE <<"1. Game will always start with player-1 i.e. Red(R)\n2. In each turn choose the column number in which you want to drop the ball.\n3. rows will be filled from bottom to top in every column.\n\n";
};
void GameStarts()
{
    Sleep(1000);
    cout << YELLOW << R"(
                                                                               ___   _   __  __ ___   ___ _____ _   ___ _____ ___ 
                                                                              / __| /_\ |  \/  | __| / __|_   _/_\ | _ \_   _/ __|
                                                                             | (_ |/ _ \| |\/| | _|  \__ \ | |/ _ \|   / | | \__ \
                                                                              \___/_/ \_\_|  |_|___| |___/ |_/_/ \_\_|_\ |_| |___/
)"
<< "\n";
    Sleep(1600);
    system("cls");
};
void PrintTitle()
{

    cout << MAGENTA << R"(
                                                             $$$$$$\                                                      $$\                 ##\   ##\ 
                                                            $$  __$$\                                                     $$ |                ## |  ## |
                                                            $$ /  \__| @@@@@@\  $$$$$$$\  @@@@@@@\   $$$$$$\   $$$$$$$\ $$$$$$\               ## |  ## |
                                                            $$ |      @@  __@@\ $$  __$$\ @@  __@@\ $$  __$$\ $$  _____|\_$$  _|   |****\     ######## |
                                                            $$ |      @@ /  @@ |$$ |  $$ |@@ |  @@ |$$$$$$$$ |$$ /        $$ |     |****/     \_____#####|
                                                            $$ |  $$\ @@ |  @@ |$$ |  $$ |@@ |  @@ |$$   ____|$$ |        $$ |$$\                   ## |
                                                            \$$$$$$  |\@@@@@@  |$$ |  $$ |@@ |  @@ |\$$$$$$$\ \$$$$$$$\   \$$$$  |                  ## |
                                                             \______/  \______/ \__|  \__|\__|  \__| \_______| \_______|   \____/                   \__|
)"
<< "\n"
<< CYAN << "                                                                                                                                Made by @BoBbY"
<< "\n\n";
    cout << WHITE;
    Sleep(200);
}
void display()
{
    PrintTitle();
    //visualizing board    
    for (int a = 0; a <= 5; a++)
    {   //drawing square boxes
        for (int b = 0; b <= 6; b++) cout << char(218) << char(196) << char(191) << " ";
        cout << '\n';

        for (int b = 0; b <= 6; b++)
        {
            cout << char(179);
            if (board[a][b] == 22)
                cout << BLUE << board[a][b];
            else
                cout << RED << board[a][b];
            cout << WHITE;
            cout << char(179) << " ";
        }
        cout << '\n';

        for (int b = 0; b <= 6; b++) cout << char(192) << char(196) << char(217) << " ";
        cout << '\n';
    }
    cout << GREEN << " 1   2   3   4   5   6   7\n\n";
}
bool check(int row, int col)
{
    int vertical = 1;   //(|)
    int horizontal = 1; //(-)
    int diagonal1 = 1;  //(\)
    int diagonal2 = 1;  //(/)

    char player = board[row][col];

    int i;  //vertical

    int ii; //horizontal

    //check for vertical(|)
    for (i = row + 1; board[i][col] == player && i <= 5; i++, vertical++);//Check down

    for (i = row - 1; board[i][col] == player && i >= 0; i--, vertical++);//Check up

    if (vertical >= 4)return true;

    //check for horizontal(-)
    for (ii = col - 1; board[row][ii] == player && ii >= 0; ii--, horizontal++);//Check left

    for (ii = col + 1; board[row][ii] == player && ii <= 6; ii++, horizontal++);//Check right

    if (horizontal >= 4) return true;

    //check for diagonal 1 (\)
    for (i = row - 1, ii = col - 1; board[i][ii] == player && i >= 0 && ii >= 0; diagonal1++, i--, ii--);//up and left

    for (i = row + 1, ii = col + 1; board[i][ii] == player && i <= 5 && ii <= 6; diagonal1++, i++, ii++);//down and right

    if (diagonal1 >= 4) return true;

    //check for diagonal 2(/)
    for (i = row - 1, ii = col + 1; board[i][ii] == player && i >= 0 && ii <= 6; diagonal2++, i--, ii++);//up and right

    for (i = row + 1, ii = col - 1; board[i][ii] == player && i <= 5 && ii >= 0; diagonal2++, i++, ii--);//up and left

    if (diagonal2 >= 4) return true;

    return false;
}
int drop(int colChoice, char playerType)
{
    if (board[0][colChoice] == ' ')
    {   //if selected column is full or empty
        int i;
        for (i = 0; board[i][colChoice] == ' '; i++)
            if (i == 5)
            {
                board[i][colChoice] = playerType;
                return i;
            }

        i--;
        board[i][colChoice] = playerType;
        return i;
    }
    else
    {
        return -1;
    }
}

int main()
{
    WelcomeScreen();
    cout << CYAN;
    system("pause");
    system("cls");
    GameStarts();
  
    //fill board with whitespace
    for (int a = 0; a <= 5; a++)
    {
        for (int b = 0; b <= 6; b++)

            board[a][b] = ' ';
    }


    display();  //Displays for first time so players can see the board

    int colChoice;               // Will hold user column choice
    int row = 0;          // will hold drop position
    int charsPlaced = 0;    // Number of peices dropped so can end game if a draw
    bool gamewon = false;   // Will be changed to true when game is won and will exit while loop
    char playerType = 22;   //this will store which player is this & start as player 2 will change back to player 1

    while (!gamewon) //will stop when game is won, ! means 'NOT' makes the opposite be checked
    {    
        if (row != -1) {    //check if there was a error in the last drop
            if (playerType == 22) {   //if player 2 lastly dropped a piece so its player 1s turn
                cout << RED << "Player 1(RED)"<<WHITE<<" where do you wanna drop : ";
                playerType = 254;   //char of player's piece
            }
            else {
                cout << BLUE << "Player 2(BLUE) "<< WHITE << "where do you wanna drop: ";
                playerType = 22;    //char of player's piece
            }
        }

        while (true)    //will run untill 'break;'
        {    
            if (charsPlaced == 42) break;    //if draw
            cin >> colChoice;  //get user col input

            colChoice--; //take off 1 to account for arrays starting at 0 not 1

            if (colChoice <= 6 && colChoice >= 0) break;  //if within valid range stop loop

            else cout << "\nplease enter a value between 1 and 7 :"; //ask for input and loop again

            if (cin.fail()) //catch a non number
            {
                cin.clear();        //Stops cin trying to put its value in to row
                char c;         //Try entering a non number without this, 2 see what this does
                cin >> c;
            }
        }

        if (charsPlaced == 42) break;    //if draw
        row = drop(colChoice, playerType);  //drop the player & store the row 

        //if error -1 that means col is full
        if (row == -1) cout << "Column is full\nPlease enter anothor number between 1 and 7:";

        else {
            gamewon = check(row, colChoice);    //check if someone game won
            charsPlaced++;   // another character has been succesfully placed
            system("cls");  // This clears the screen works with windows
            display();     // displayed updated board
        }
    }
   
    if (charsPlaced == 42) {  //if draw
        cout << "No winner, Game draw\n";
        cout << CYAN;
        system("pause");
        cout << WHITE;
        return 0;
    }

    if (playerType == 22)    //if won by player 2
        cout  << "Game won by :" << BLUE <<" player 2(BLUE)\n";

    else
        cout << "Game won by :" << RED << " player 1(RED)\n";   //else won by player 1
    cout << CYAN;
    system("pause");    //pauses before exit so players can see who won, works with windows
    cout << WHITE;
    return 0;   //Exit application
}

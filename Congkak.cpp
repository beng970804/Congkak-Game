/**********|**********|**********|
Program: TT01_P2_ALFRED_LOO_WEE_HOW.cpp
Course: Bachelor of Computer Science
Year: 2016/17 Trimester 1
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
**********|**********|**********/
/*To compile:
g++ -std=c++11 -c TT01_P2_ALFRED_LOO_WEE_HOW.cpp -o TT01_P2_ALFRED_LOO_WEE_HOW.o
g++ -o TT01_P2_ALFRED_LOO_WEE_HOW.exe TT01_P2_ALFRED_LOO_WEE_HOW.o
.\TT01_P2_ALFRED_LOO_WEE_HOW
*/

#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<iomanip>
using namespace std;

struct player //player structure
{
    int house[7]; //variable of player house array
    int storehouse; //variable of storehouse
}player[2]; //create object of player array

void title(); //function declaration, print title
void initialise(); //function declaration, initialize value of player, house, and storehouse
void printBoard(); //function declaration, print board of congkak
int randomStart(); //function declaration, determine which player start first
void startPlay(); //function declaration, allow game to start
int inputCheck(int p); //function declaration, check the player choice
int alphabetCheck(int c); //function declaration, check if the player choice is an alphabet
int numberCheck(int c); //function declaration, check if the player choice is out of range
int zeroCheck(int p,int c); //function declaration, check if the house of player choice has zero seeds in it
void checkCondition(int p, int c); //function declaration, check condition of choice, determine which algorithm to be used
void calculateSeed(int p, int c); //function declaration, algorithm for choice of house 1-6
void calculateSeed7(int p, int c); //function declaration, algorithm for choice of house 7
void determineWinner(); //function declaration, determine the winner

int main()
{
    system("Color 0F"); //black background with white foreground
    title(); //function call, print title
    initialise(); //function call, initialize value of player, house, and storehouse
    printBoard(); //function call, print board of congkak
    startPlay(); //function call, allow game to start
    determineWinner(); //function call, determine the winner
}

void title() //function definition, print title
{
    cout << "\t\t       ====================\n"
         << "\t\t       The Game of Congkak\n"
         << "\t\t       ====================\n";
    return;
}

void initialise() //function definition, initialize value of player, house, and storehouse
{
    for (int j=0;j<2;j++)
    {
        player[j]; //create player array
    }

    for (int i=0;i<7;i++)
    {
        player[0].house[i] = 7; //initialize each house of player 1 by 7
        player[1].house[i] = 7; //initialize each house of player 2 by 7
    }

    player[0].storehouse = 0; //initialize storehouse of player 1 by 0
    player[1].storehouse = 0; //initialize storehouse of player 2 by 0

    return;
}

void printBoard() //function definition, print board of congkak
{
    //print board, setw() is used for better display of seeds
    cout << "\n\t\t             Player 1"
         << "\n"
         << "\n\t\t   - 1 - 2 - 3 - 4 - 5 - 6 - 7 -"
         << "\n\t\t   -----------------------------"
         << "\n\t\t   |" << setw(3) << player[0].house[0] << "|"  << setw(3) << player[0].house[1] << "|"  << setw(3) << player[0].house[2] << "|"  << setw(3) << player[0].house[3] << "|"  << setw(3) << player[0].house[4] << "|" << setw(3) << player[0].house[5] << "|"  << setw(3) << player[0].house[6] << "|"
         << "\n\t        " << setw(2) << player[1].storehouse << " ----------------------------- " << setw(2) << player[0].storehouse
         << "\n\t\t   |" << setw(3) << player[1].house[6] << "|"  << setw(3) << player[1].house[5] << "|"  << setw(3) << player[1].house[4] << "|"  << setw(3) << player[1].house[3] << "|"  << setw(3) << player[1].house[2] << "|" << setw(3) << player[1].house[1] << "|"  << setw(3) << player[1].house[0] << "|"
         << "\n\t\t   -----------------------------"
         << "\n\t\t   - 7 - 6 - 5 - 4 - 3 - 2 - 1 -"
         << "\n"
         << "\n\t\t             Player 2"
         << "\n";

    return;
}

int randomStart() //function definition, determine which player start first
{
    int x; //declare variable x
    srand(time(NULL));

    x = rand()%2+1; //assign random value between 1 and 2 to x

    return x;
}

void startPlay() //function definition, allow game to start
{
    int startPlayer=randomStart(); //assign value of function to variable
    int choice, finalChoice, sum; //declare variable
    int counter = 1; //assign value 1 to variable

    cout << "\nThe turn will start with Player " << startPlayer << ". " << endl; //show that which player will start first
    do
    {
        cout << "\nRound " << counter << " : ";
        cout << "\nPlayer " << startPlayer;
        cout << "\nPlease enter your location of seed (1 to 7): ";
        finalChoice = inputCheck(startPlayer); //assign value of function to variable
        if (finalChoice!=99)
        {
            checkCondition(startPlayer, finalChoice); //function call if condition met
        }
        counter++; //stack counter to show number of round
        sum = player[0].storehouse + player[1].storehouse; //sum of two storehouse for looping purpose

        cout << "\nRound " << counter << " : " ;
        if (startPlayer==1) //condition, function to run if starting player is 1
        {
            cout << "\nPlayer " << startPlayer+1;
            cout << "\nPlease enter your location of seed (1 to 7): ";
            finalChoice = inputCheck(startPlayer+1); //assign value of function to variable
            if (finalChoice!=99)
            {
                checkCondition(startPlayer+1, finalChoice); //function call if condition met
            }
            counter++; //stack counter to show number of round
            sum = player[0].storehouse + player[1].storehouse; //sum of two storehouse for looping purpose
        }

        if (startPlayer==2) //condition, function to run if starting player is 2
        {
            cout << "\nPlayer " << startPlayer-1;
            cout << "\nPlease enter your location of seed (1 to 7): ";
            finalChoice = inputCheck(startPlayer-1); //assign value of function to variable
            if (finalChoice!=99)
            {
                checkCondition(startPlayer-1, finalChoice); //function call if condition met
            }
            counter++; //stack counter to show number of round
            sum = player[0].storehouse + player[1].storehouse; //sum of two storehouse for looping purpose
        }
    } while (sum != 98);

    return;
}

int inputCheck(int p) //function definition, check the player choice
{
    bool x,y,z; //declare variable
    int a = p; //assign value to variable
    int choice, trueChoice; //declare variable
    cin >> choice; //user input their pick of house

    do
    {
        x = alphabetCheck(choice); //assign value of function, run alphabet check, e.g. a,b,c, d, etc
        y = numberCheck(choice); //assign value of function, run range of value check, accept value between 1and 7 only
        z = zeroCheck(p, choice); //assign value of function, check if the house of choice has zero seeds

        if ((x==1)&&(y==1)&&(z==1))
        {
            trueChoice = choice; //when all checking done are true/passed, assign value to the variable
        }

        if ((x==0)||(y==0)||(z==0))
        {
            cout << "You have entered wrong input! or The house is empty!";
            cout << "\nPlease enter your location of seed (1 to 7): ";
            cin.clear();
            cin >> choice; //if either one is false/failed, prompt user re-pick their choice
        }

        if (z==99)
        {
            trueChoice = 99; //return a value if neither 1 nor 0 is assigned to z
        }

    } while ((x!=1)||(y!=1)||(z!=1)); //repeat loop if either one of them is false/failed

    return trueChoice;
}

int alphabetCheck(int c) //function definition, check if the player choice is an alphabet
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        return 0; //if user didn't input integer, it will return value zero
    }
    else
    {
        return 1; //if user input integer, it will return value one
    }
}

int numberCheck(int c) //function definition, check if the player choice is out of range
{
    if ((c<1)||(c>7))
    {
        return 0; //if integer out of range, return value zero
    }
    else
    {
        return 1; //if integer within range, return value one
    }
}

int zeroCheck(int p, int c) //function definition, check if the house of player choice has zero seeds in it
{
    int temp = player[p-1].house[c-1]; //assign value of house to temporary variable
    int x(0); //initialize x by 0

    if (c>7)
    {
        return 0; //if the input greater than 7, which is 8(house 8 does not exist), return value zero
    }

    for (int i=0;i<7;i++)
    {
        if  (player[p-1].house[i] == 0)
        {
            x = 1; //check if every house is the same with zero seeds, assign value one
        }
        else
        {
            x = 0; //if at least one of the house has more than zero seed, assign value zero
            break;
        }
    }

    if (x==0)
    {
        if (temp==0)
        {
            return 0; //if x is zero and value of temporary is zero(house is empty), return value 0
        }
        else
        {
            return 1; //if x is zero but value of temporary is not zero(house is not empty), return value 1
        }
    }

    if (x==1)
    {
        return 99; //if x is one(every house is empty), return value if x is equal to one
    }
}

void checkCondition(int p, int c) //function definition, check condition of choice, determine which algorithm to be used
{
    int a = p; //assign value of p(player) to a
    int b = c; //assign value of c(player choice) to b
    if ((c > 0)&&(c < 6))
    {
        calculateSeed(a,b); //when choice is between 1 and 6, calculate with function(for house 1 to 6)
    }

    if (c == 7)
    {
        calculateSeed7(a,b); //when choice is 7, calculate with function(for house 7)
    }

    return;
}

void calculateSeed(int p, int c) //function definition, algorithm for choice of house 1-6
{
    int current = player[p-1].house[c-1]; //determine the seeds taken from house
    int x(0), y(0), z(0); //initialize variable with value zero

    player[p-1].house[c-1]=0; //when the house is chosen,the seeds are taken. leaving the house to be empty
    printBoard(); //function call, print board of congkak
    system("pause"); //get input from player to continue

    while (current>0) //if the seeds in hand are still remaining, run the following algorithm
    {
        player[p-1].house[c]++; //next house will increase the seed by one
        printBoard(); //function call, print board of congkak
        system("pause"); //get input from player to continue
        c++; //increase value of c by one
        current--; //decrease value of seeds in hand by one

        if((c>6)&&(current>0)) //if c is greater than 6(array size is seven, house[7] does not exist) and the seeds in hand are still remaining, run the following algorithm
        {
            player[p-1].storehouse++; //increase the storehouse of player by one
            printBoard(); //function call, print board of congkak
            system("pause"); //get input from player to continue
            current--; //decrease value of seeds in hand by one

            while (current>0) //if the seeds in hand are still remaining, run the following algorithm
            {
                if (p==1) //if current player is player 1, run the following algorithm
                {
                    player[p].house[x]++; //next house will increase the seed by one
                    printBoard(); //function call, print board of congkak
                    system("pause"); //get input from player to continue
                    x++; //increase value of x by one
                    current--; //decrease value of seeds in hand by one

                    if ((x>6)&&(current>0)) //if x is greater than 6(array size is seven, house[7] does not exist) and the seeds in hand are still remaining, run the following algorithm
                    {
                        while (current>0) //if the seeds in hand are still remaining, run the following algorithm
                        {
                            player[p-1].house[y]++; //next house will increase the seed by one
                            printBoard(); //function call, print board of congkak
                            system("pause"); //get input from player to continue
                            y++; //increase value of y by one
                            current--; //decrease value of seeds in hand by one

                            if((y>6)&&(current>0)) //if y is greater than 6(array size is seven, house[7] does not exist) and the seeds in hand are still remaining, run the following algorithm
                            {
                                player[p-1].storehouse++; //increase the storehouse of player by one
                                printBoard(); //function call, print board of congkak
                                system("pause"); //get input from player to continue
                                current--; //decrease value of seeds in hand by one

                                while (current>0) //if the seeds in hand are still remaining, run the following algorithm
                                {
                                    player[p].house[z]++; //next house will increase the seed by one
                                    printBoard(); //function call, print board of congkak
                                    system("pause"); //get input from player to continue
                                    z++; //increase value of z by one
                                    current--; //decrease value of seeds in hand by one
                                }
                            }
                        }
                    }
                }

                if (p==2) //if current player is player 2, run the following algorithm
                {
                    player[p-2].house[x]++; //next house will increase the seed by one
                    printBoard(); //function call, print board of congkak
                    system("pause"); //get input from player to continue
                    x++; //increase value of x by one
                    current--; //decrease value of seeds in hand by one

                    if ((x>6)&&(current>0)) //if x is greater than 6(array size is seven, house[7] does not exist) and the seeds in hand are still remaining, run the following algorithm
                    {
                        while (current>0) //if the seeds in hand are still remaining, run the following algorithm
                        {
                            player[p-1].house[y]++; //next house will increase the seed by one
                            printBoard(); //function call, print board of congkak
                            system("pause"); //get input from player to continue
                            y++; //increase value of y by one
                            current--; //decrease value of seeds in hand by one

                            if((y>6)&&(current>0)) //if y is greater than 6(array size is seven, house[7] does not exist) and the seeds in hand are still remaining, run the following algorithm
                            {
                                player[p-1].storehouse++; //increase the storehouse of player by one
                                printBoard(); //function call, print board of congkak
                                system("pause"); //get input from player to continue
                                current--; //decrease value of seeds in hand by one

                                while (current>0) //if the seeds in hand are still remaining, run the following algorithm
                                {
                                    player[p-2].house[z]++; //next house will increase the seed by one
                                    printBoard(); //function call, print board of congkak
                                    system("pause"); //get input from player to continue
                                    z++; //increase value of z by one
                                    current--; //decrease value of seeds in hand by one
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return;
}

void calculateSeed7(int p, int c) //function definition, algorithm for choice of house 7
{
    int current = player[p-1].house[c-1]; //determine the seeds taken from house
    int x(0), y(0), z(0); //initialize variable with value zero

    player[p-1].house[c-1]=0; //when the house is chosen,the seeds are taken. leaving the house to be empty
    printBoard(); //function call, print board of congkak
    system("pause"); //get input from player to continue

    while (current>0) //if the seeds in hand are still remaining, run the following algorithm
    {
        player[p-1].storehouse++; //increase the storehouse of player by one
        printBoard(); //function call, print board of congkak
        system("pause"); //get input from player to continue
        current--; //decrease value of seeds in hand by one

        while (current>0) //if the seeds in hand are still remaining, run the following algorithm
        {
            if (p==1) //if current player is player 1, run the following algorithm
            {
                player[p].house[x]++; //next house will increase the seed by one
                printBoard(); //function call, print board of congkak
                system("pause"); //get input from player to continue
                x++; //increase value of x by one
                current--; //decrease value of seeds in hand by one

                if ((x>6)&&(current>0)) //if x is greater than 6(array size is seven, house[7] does not exist) and the seeds in hand are still remaining, run the following algorithm
                {
                    while (current>0) //if the seeds in hand are still remaining, run the following algorithm
                    {
                        player[p-1].house[y]++; //next house will increase the seed by one
                        printBoard(); //function call, print board of congkak
                        system("pause"); //get input from player to continue
                        y++; //increase value of y by one
                        current--; //decrease value of seeds in hand by one

                        if((y>6)&&(current>0)) //if y is greater than 6(array size is seven, house[7] does not exist) and the seeds in hand are still remaining, run the following algorithm
                        {
                            player[p-1].storehouse++; //increase the storehouse of player by one
                            printBoard(); //function call, print board of congkak
                            system("pause"); //get input from player to continue
                            current--; //decrease value of seeds in hand by one

                            while (current>0) //if the seeds in hand are still remaining, run the following algorithm
                            {
                                player[p].house[z]++; //next house will increase the seed by one
                                printBoard(); //function call, print board of congkak
                                system("pause"); //get input from player to continue
                                z++; //increase value of z by one
                                current--; //decrease value of seeds in hand by one
                            }
                        }
                    }
                }
            }

            if (p==2) //if current player is player 2, run the following algorithm
            {
                player[p-2].house[x]++; //next house will increase the seed by one
                printBoard(); //function call, print board of congkak
                system("pause"); //get input from player to continue
                x++; //increase value of x by one
                current--; //decrease value of seeds in hand by one

                if ((x>6)&&(current>0)) //if x is greater than 6(array size is seven, house[7] does not exist) and the seeds in hand are still remaining, run the following algorithm
                {
                    while (current>0) //if the seeds in hand are still remaining, run the following algorithm
                    {
                        player[p-1].house[y]++; //next house will increase the seed by one
                        printBoard(); //function call, print board of congkak
                        system("pause"); //get input from player to continue
                        y++; //increase value of y by one
                        current--; //decrease value of seeds in hand by one

                        if((y>6)&&(current>0)) //if y is greater than 6(array size is seven, house[7] does not exist) and the seeds in hand are still remaining, run the following algorithm
                        {
                            player[p-1].storehouse++; //increase the storehouse of player by one
                            printBoard(); //function call, print board of congkak
                            system("pause"); //get input from player to continue
                            current--; //decrease value of seeds in hand by one

                            while (current>0) //if the seeds in hand are still remaining, run the following algorithm
                            {
                                player[p-2].house[z]++; //next house will increase the seed by one
                                printBoard(); //function call, print board of congkak
                                system("pause"); //get input from player to continue
                                z++; //increase value of z by one
                                current--; //decrease value of seeds in hand by one
                            }
                        }
                    }
                }
            }
        }
    }

    return;
}

void determineWinner() //function definition, determine the winner
{
    cout << "\nThe total seed in Player 1 storehouse is " << player[0].storehouse << " seeds."; //display total seed in player 1 storehouse
    cout << "\nThe total seed in Player 2 storehouse is " << player[1].storehouse << " seeds."; //display total seed in player 2 storehouse

    if (player[0].storehouse > player[1].storehouse)
    {
        cout << "\n\nCongratulations! The winner is Player 1." << endl; //if player 1 has more seeds in storehouse than player 2, the winner is player 1
    }

    if (player[0].storehouse < player[1].storehouse)
    {
        cout << "\n\nCongratulations! The winner is Player 2." << endl; //if player 2 has more seeds in storehouse than player 1, the winner is player 2
    }

    if (player[0].storehouse == player[1].storehouse)
    {
        cout << "\n\nThe game ends with a draw. Great game from both of you." << endl; //if both player storehouse is the same, the game ends withdraw
    }

    return;
}










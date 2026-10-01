#include <iostream>  // input output headerfile
#include <cstdlib>   // used to include rand() and srand() functions for generating random numbers
#include <ctime>     // for time() function used to generate random seed
using namespace std;
/*=========================
   Abstract Base Class
=========================*/
class Game {
public:
    Game() {}
    // Pure Virtual Function
    virtual void play() = 0;
    virtual ~Game() {}
};
/*=========================
      Base Class
=========================*/
class Player : public Game {
protected:
    string name;
public:
    Player(string n) {
        name = n;
        cout << "Enter your name : ";
        cin >> name; } // name of player
    // Function Overloading
    void show() {
        cout << "Player: " << name << endl; }
    void show(string message) {
        cout << message << " " << name << endl; }
    // Virtual Function
    virtual void play() {
        cout << "Player Playing\n"; }
    virtual ~Player() { }
};
/*=========================
  Hierarchical Inheritance
=========================*/
class ComputerPlayer : public Player {
public:
    ComputerPlayer() : Player("Computer") { } 
    void play() {
        cout << "Computer Ready\n"; }
    ~ComputerPlayer() {}
};
/*=========================
   Multilevel Inheritance
=========================*/
class HumanPlayer : public Player {
public:
    HumanPlayer(string n) : Player(n) {} 
    void play() {
        cout << "Human Ready\n"; }
    ~HumanPlayer() { } 
};
/*=========================
      Final Game Class
=========================*/
class RockPaperScissors : public HumanPlayer {
private:
    int userScore;     // to track user score
    int computerScore; // to track computer score
    int draws;         // to track draws
public:
    // to initialize score in constructor
    RockPaperScissors(string n) : HumanPlayer(n) {
        userScore = 0;
        computerScore = 0;
        draws = 0; }
    void play() {// Function Overriding
        char again;
        int userMove;
        do {
            show();
            show("Good Luck,");
            cout << "\n1. Rock";
            cout << "\n2. Paper";
            cout << "\n3. Scissors";
            cout << "\nEnter Choice: ";
            cin >> userMove;
            while (cin.fail() || userMove < 1 || userMove > 3) { // for input validation
                cout << "invalid choice!enter 1 or 2 or 3\n";
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> userMove; }
            cout << "\nComputer Chose: "; // computer choice
            int computerMove = rand() % 3 + 1; // logic computer uses to generate number randomly
            if (computerMove == 1)
                cout << "Rock\n";
            else if (computerMove == 2)
                cout << "Paper\n";
            else
                cout << "Scissors\n";
        /* =============================
              Game Logic & Score Update
           =============================*/
            if (userMove == computerMove) {
                cout << "Match Draw!\n";
                draws++; } // draws update
            else if ((userMove == 1 && computerMove == 3) ||
                     (userMove == 2 && computerMove == 1) ||
                     (userMove == 3 && computerMove == 2)) {
                cout << "You Win!\n";
                userScore++; } // user score update
            else {
                cout << "Computer Wins!\n";
                computerScore++; } //  computer score update
            cout << "\nPlay Again?(y/n):";
            cin >> again; }
        while (again == 'y');
        cout << "\n===============================\n";
        cout << "        FINAL SCOREBOARD       \n";
        cout << "===============================\n";
        cout << name << "'s Total Score : " << userScore << endl;
        cout << "Computer's Total Score : " << computerScore << endl;
        cout << "Total Draws            : " << draws << endl;
        // Overall Winner Announcement
        if (userScore > computerScore) {
            cout << "CONGRATULATIONS! You are the Overall Winner!\n"; }
        else if (computerScore > userScore) {
            cout << "Computer is the Overall Winner! Better luck next time.\n"; }
        else {
            cout << "The overall series is a TIE!\n"; }
        cout << "\nThanks for playing! Goodbye..."; }};
int main() {
    srand(time(0)); // time(0) used to initialize random seed so computer choice changes every time
    Game *game;// Runtime Polymorphism
    game = new RockPaperScissors("n");
    game->play();
    delete game;
    return 0; }

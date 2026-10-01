🪨📄✂️**Rock Paper Scissors – C++ OOP Console Game**
A console-based Rock, Paper, Scissors game written in C++ that showcases core Object-Oriented Programming concepts. Play against the computer, keep track of scores across rounds, and see a final scoreboard with the overall winner.
✨ Features
🎮 Play unlimited rounds against the computer
🎲 Random computer moves (seeded with time(0) so every game is different)
🛡️ Input validation – handles wrong numbers and non-numeric input without crashing
📊 Tracks your wins, the computer's wins, and draws
🔁 "Play Again?" option after every round
🏆 Final scoreboard with an overall winner announcement
👤 Personalised messages using the player's name
🧠 OOP Concepts Used
This project was built to demonstrate the following concepts:
**Concept**
Where it's used
**Abstraction**
Game is an abstract base class with a pure virtual function play()
**Encapsulation**
Scores (userScore, computerScore, draws) are private; name is protected
**Inheritance**
Game → Player → HumanPlayer → RockPaperScissors
Hierarchical Inheritance
ComputerPlayer and HumanPlayer both derive from Player
Multilevel Inheritance
Game → Player → HumanPlayer → RockPaperScissors
**Runtime Polymorphism**
Game* game = new RockPaperScissors(...) then game->play()
**Function Overloading**
show() and show(string message) in Player
**Function Overriding**
play() is overridden in ComputerPlayer, HumanPlayer and RockPaperScissors
**Virtual Destructors**
Ensures proper cleanup when deleting through a base class pointer
**Constructors**
Initialise names and scores
🏗️ Class Structure
Game (Abstract Base Class)
 └── Player
      ├── ComputerPlayer
      └── HumanPlayer
           └── RockPaperScissors  (Final Game Class)
Game – abstract class declaring virtual void play() = 0;
Player – stores the player's name, provides overloaded show() functions and a virtual play()
ComputerPlayer – represents the computer opponent
HumanPlayer – represents the human user
RockPaperScissors – contains the actual game loop, score tracking, and winner logic
**Getting Started**
Prerequisites
A C++ compiler (e.g., g++ / MinGW / TDM-GCC)
Or an IDE such as Dev-C++, Code::Blocks, or Visual Studio
Clone the repository
git clone https://github.com/<your-username>/<your-repo-name>.git
cd <your-repo-name>
Compile and run
Using g++:
g++ "stone paper scissors final project.cpp" -o rps
./rps          # Linux / macOS
rps.exe        # Windows
Using Dev-C++:
Open the .cpp file
Press F11 (Compile & Run)
💡 Tip: Rename the source file to main.cpp (no spaces) to make compiling easier.
🎮**How to Play**
Run the program and enter your name.
Choose your move:
1 → Rock
2 → Paper
3 → Scissors
The computer picks randomly and the result is shown.
Type y to play again, or any other key to quit.
View the Final Scoreboard and find out who won overall!
🖥️ **Sample Output**
Enter your name : Ali
Player: Ali
Good Luck, Ali

1. Rock
2. Paper
3. Scissors
Enter Choice: 1

Computer Chose: Scissors
You Win!

Play Again?(y/n):n

==================================
         FINAL SCOREBOARD
==================================
Ali's Total Score : 1
Computer's Total Score : 0
Total Draws       : 0
CONGRATULATIONS! You are the Overall Winner!

Thanks for playing! Goodbye...

If you enjoyed the project ,consider giving it a star

👤 Author
NEHAL JABEEN

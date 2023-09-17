/* CSCI 200: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Westly Bouchard
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * XXXXXXXX (MORE_COMPLETE_DESCRIPTION_HERE)
 */
// The include section adds extra definitions from the C++ standard library.
#include <cstdlib>
#include <iostream> // For cin, cout, etc.
#include <string>
#include <time.h>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

#define RNG_MIN 0
#define RNG_MAX 4

enum choices {Rock = 1, Paper = 0, Scissors = 4, Lizard = 2, Spock = 3};
enum winCondition {Computer, Player, Tie};

choices prompt(string prompt);
choices stringToEnumVariant(string c);
string enumToStringRepr(choices choice);

choices genComputerChoice();

winCondition chooseWinnerFromChoices(choices c1, choices c2);

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

  int wins(0), losses(0), ties(0);
  bool shouldContinue = true;
  char continueInput;

  do {
    cout << "Welcome one and all to a round of Rock, Paper, Scissors, Lizard, Spock! (Enter Rc, Pr, Sc, Lz, or Sp)" << endl;

    choices playerChoice = prompt("Player one: ");
    choices computerChoice = genComputerChoice();

    cout << endl << "Player choose " << enumToStringRepr(playerChoice) << endl;

    cout << "Computer choose " << enumToStringRepr(computerChoice) << endl << endl;

    winCondition winner = chooseWinnerFromChoices(computerChoice, playerChoice);

    if (winner == Computer) {
      string playerChoiceStr = enumToStringRepr(playerChoice);
      playerChoiceStr[0] = toupper(playerChoiceStr[0]);
      cout << enumToStringRepr(computerChoice) << " beats " << playerChoiceStr << endl;
      cout << "Computer Wins!" << endl;
      losses++;
    } else if (winner == Player) {
      string computerChoiceStr = enumToStringRepr(computerChoice);
      computerChoiceStr[0] = toupper(computerChoiceStr[0]);
      cout << enumToStringRepr(playerChoice) << " beats " << computerChoiceStr << endl;
      cout << "Player Wins!" << endl;
      wins++;
    } else {
      cout << "It's a tie!" << endl;
      ties++;
    }

    cout << "Do you want to play again? (Y/N) ";
    cin >> continueInput;

    if (tolower(continueInput) == 'n') {
      shouldContinue = false;
    }

  } while (shouldContinue);

  cout << "Thanks for playing!" << endl;
  cout << "You won " << wins << " game(s), lost " << losses << " game(s), and tied " << ties << " game(s).";

  return 0;
}

choices prompt(string prompt) {
  string response;

  cout << prompt;
  cin >> response;

  return stringToEnumVariant(response);
}

choices stringToEnumVariant(string c) {
  switch (c[0]) {
    case 'R':
      return Rock;
    
    case 'P':
      return Paper;

    case 'S':
      if (c[1] == 'c') {
        return Scissors;
      } else {
        return Spock;
      }

    case 'L':
      return Lizard;

    default:
      return Rock;
  }
}

string enumToStringRepr(choices choice) {
  switch (choice) {
    case Rock:
      return "Rock";

    case Paper:
      return "Paper";

    case Scissors:
      return "Scissors";

    case Lizard:
      return "Lizard";

    case Spock:
      return "Spock";
  }
}

choices genComputerChoice() {
  srand(time(0));

  rand();

  int rng = rand() % (RNG_MAX - RNG_MIN + 1) + RNG_MIN;

  return (choices)rng;
}

winCondition chooseWinnerFromChoices(choices computerChoice, choices playerChoice) {
  if (computerChoice == playerChoice) {
    return Tie;
  }

  if ((computerChoice + 1) % 5 == playerChoice || (computerChoice + 3) % 5 == playerChoice) {
    return Computer;
  } 

  return Player;
}

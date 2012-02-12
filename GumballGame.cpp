/**
 * @file GumballGame.cpp
 *
 * Implements a Game using gumballs where the goal of the game is to get a Yellow gumball
 * Author: Travis Kaufman
 * Class: Web Programming - Spring 2012
 * Version: 1.0.2 
 */

#include "GB_Global.h"
#include "GumballMachine.h"

vector<GUMBALL> findMaxColors(vector<GUMBALL>& chosen_colors);

int main() {
  cout << "+++ WELCOME TO THE CIMS GUMBALL MACHINE SIMULATOR!! +++" << endl;
  cout << "------------------------------------------" << endl;

  string gb_names[NUM_GB_COLORS] = {
    "Red", "Blue", "White", "Green", "Black", "Purple", "Cyan", "Magenta", "Yellow"
  };
  GumballMachine *machine = GumballMachine::getInstance();

  cout << "You are starting with the following Gumballs:" << endl;

  for (int i = 0; i < NUM_GB_COLORS-1; i++) {
  GUMBALL gb_cast = (GUMBALL)i;
  int gb_count = machine->fill(gb_cast);
  cout << gb_count << " " << gb_names[gb_cast] << endl;
  } // end for loop

  machine->getGumballs()->push_back(YELLOW);
  cout << "...and 1 yellow" << endl;

  cout << "------------------------------------------" << endl;

  cout << "Here are your random purchases:" << endl;

  int index = (int)machine->getGumballs()->size() - 1;
  random_shuffle(machine->getGumballs()->begin(), machine->getGumballs()->end());
  GUMBALL chosen = RED; // pick an arbitrary color
  short unsigned int gb_dispensed = 0;
  vector<GUMBALL> dispensed_gumballs;
  do {
    chosen = machine->dispense(index--); // index-- since we pop one off the gumball vector each time
    dispensed_gumballs.push_back(chosen);
    cout << gb_names[chosen] << endl;
    machine->getGumballs()->pop_back();
    gb_dispensed++;
  } while (chosen != YELLOW); // end do/while
  
  cout << "------------------------------------------" << endl;
  cout << "You purchased " << gb_dispensed << " gumballs for a total of $";
  printf("%.2f\n", (float)gb_dispensed * 0.25); // printf() still gives better formatting options

  vector<GUMBALL> most_purchased = findMaxColors(dispensed_gumballs);
  cout << "Most purchased: ";
  for (int i = 0; i < (int)most_purchased.size(); i++)
    cout << gb_names[most_purchased[i]] << " ";
  cout << endl; 

  delete machine;
  return 0;
} // end main()

vector<GUMBALL> findMaxColors(vector<GUMBALL>& chosen_colors) {
  int max = 0;
  vector<GUMBALL> max_gumballs;
  for (int i = 0; i < NUM_GB_COLORS; i++) {
    int appearances = (int) count(chosen_colors.begin(), chosen_colors.end(), (GUMBALL)i);
    if (appearances > max) {
      max = appearances;
      if (!max_gumballs.empty())
        max_gumballs.clear();
      max_gumballs.push_back((GUMBALL)i);
    } 
    else if (appearances == max) {
      max_gumballs.push_back((GUMBALL)i);
    }
  } // end for loop
  return max_gumballs;
} // end findMaxColors

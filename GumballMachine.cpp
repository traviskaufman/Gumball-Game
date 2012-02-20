/**
 * @file GumballMachine.cpp
 *
 * The Gumball Machine class. Essentially a wrapper for assigning methods to a vector.  
 */

#include "GB_Global.h"
#include "GumballMachine.h"

GumballMachine* m_Instance = NULL;

/**
 * Create an instance of the class
 * 
 * Ensures that only one instance of the class exists throughout program execution
 */

GumballMachine* GumballMachine::getInstance() {
  if (!m_Instance)
    m_Instance = new GumballMachine();
  return m_Instance;
} // getInstance()

/**
 * Fills up the gumball machine with a random amount of a certain gumball color
 *
 * Different types of gumballs will be limited by a range of values 
 *
 * @param GUMBALL gb_color
 *    The color of the gumball (as defined in the enum) you want to fill the machine with 
 */
int GumballMachine::fill(GUMBALL gb_color) {
  srand(time(NULL));
  int length = 0; 
  switch (gb_color) {
    case RED:
      length = randRange(5, 15);
      break;
    case BLUE:
      length = randRange(1, 10);
      break;
    case WHITE:
      length = randRange(6, 15);
      break;
    case GREEN:
      length = randRange(10, 25);
      break;
    case BLACK:
      length = randRange(2, 12);
      break;
    case PURPLE:
      length = randRange(5, 10);
      break;
    case CYAN:
      length = randRange(5, 12);
      break;
    case MAGENTA:
      length = randRange(1, 10);
      break;
    default:
      break;
  } // end switch

  for (int i = 0; i < length; i++) {
    m_Gumballs.push_back(gb_color);
  } 
  return length;
} // fill()

/**
 * Returns a random number x where floor ≤ x ≤ ceiling
 *
 * Helper function for creating gumballs...who knew Gumball machines were so smart!!
 *
 * @param const int floor
 *    The lowest integer that the function will return
 *
 * @param const int ceiling
 *    The highest integer that the function will return
 *
 * @return int
 *    Returns a random number between floor and ceiling
 */

int GumballMachine::randRange(const int gb_floor, const int gb_ceiling) {
  return (rand() % (gb_ceiling - gb_floor)) + gb_floor;
} // end randRange


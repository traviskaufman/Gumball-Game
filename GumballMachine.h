/**
 * @file GumballMachine.h
 *
 * The Gumball Machine class. Handles the initialization (filling), storage, and dispensing of gumballs. 
 */

class GumballMachine {
public:
  // factory methods
  static GumballMachine* getInstance();
  ~GumballMachine(){};
  // public methods
  int fill(GUMBALL);
  GUMBALL dispense(const int pos) const {return m_Gumballs.at(pos);}
  std::vector<GUMBALL>* getGumballs() {return &m_Gumballs;} 

  
private:
  // private initialization
  GumballMachine(){};
  // Class Singleton 
  static GumballMachine* m_instance;
  // private utility functions
  int randRange(const int floor, const int ceiling);
  // member variables
  std::vector<GUMBALL> m_Gumballs;
}; // class GumballMachine


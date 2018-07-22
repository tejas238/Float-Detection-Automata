//DFA.cpp by Tejas Menon, CS311, last edited on 5/31

#include <fstream>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

int TEMP = 1000;

class DFA 
{

 public:
 DFA();
 void update(char input); //updates the state when new input is passed in
 bool decision(); //returns a boolean depending on whether the current state is accepting or rejecting
 void reset(); //resets the state to 0
 ~DFA();

 private:
 int state; //current state
 int **tt; //transition table
 int *accept; //array of accepting states
};

DFA::DFA() {

 state = 0;
 tt = new int*[11]; //11 states in DFA
 for(int i=0;i<11;++i) {
  tt[i] = new int[8]; //8 types of characters
 }
 tt[0][0] = 0;
 tt[0][1] = 1;
 tt[0][2] = 1;
 tt[0][3] = 1;
 tt[0][4] = 2;
 tt[0][5] = 3;
 tt[0][6] = 4;
 tt[0][7] = 4;
 tt[1][0] = 1;
 tt[1][1] = 1;
 tt[1][2] = 1;
 tt[1][3] = 1;
 tt[1][4] = 1;
 tt[1][5] = 1;
 tt[1][6] = 1;
 tt[1][7] = 1;
 tt[2][0] = 10;
 tt[2][1] = 1;
 tt[2][2] = 5;
 tt[2][3] = 5;
 tt[2][4] = 2;
 tt[2][5] = 6;
 tt[2][6] = 1;
 tt[2][7] = 1;
 tt[3][0] = 1;
 tt[3][1] = 1;
 tt[3][2] = 1;
 tt[3][3] = 1;
 tt[3][4] = 7;
 tt[3][5] = 1;
 tt[3][6] = 1;
 tt[3][7] = 1;
 tt[4][0] = 1;
 tt[4][1] = 1;
 tt[4][2] = 1;
 tt[4][3] = 1;
 tt[4][4] = 2;
 tt[4][5] = 3;
 tt[4][6] = 1;
 tt[4][7] = 1;
 tt[5][0] = 1;
 tt[5][1] = 1;
 tt[5][2] = 1;
 tt[5][3] = 1;
 tt[5][4] = 8;
 tt[5][5] = 1;
 tt[5][6] = 9;
 tt[5][7] = 9;
 tt[6][0] = 10;
 tt[6][1] = 1;
 tt[6][2] = 5;
 tt[6][3] = 5;
 tt[6][4] = 6;
 tt[6][5] = 1;
 tt[6][6] = 1;
 tt[6][7] = 1;
 tt[7][0] = 10;
 tt[7][1] = 1;
 tt[7][2] = 5;
 tt[7][3] = 5;
 tt[7][4] = 7;
 tt[7][5] = 1;
 tt[7][6] = 1;
 tt[7][7] = 1;
 tt[8][0] = 10;
 tt[8][1] = 1;
 tt[8][2] = 1;
 tt[8][3] = 1;
 tt[8][4] = 8;
 tt[8][5] = 1;
 tt[8][6] = 1;
 tt[8][7] = 1;
 tt[9][0] = 1;
 tt[9][1] = 1;
 tt[9][2] = 1;
 tt[9][3] = 1;
 tt[9][4] = 8;
 tt[9][5] = 1;
 tt[9][6] = 1;
 tt[9][7] = 1;
 tt[10][0] = 10;
 tt[10][1] = 1;
 tt[10][2] = 1;
 tt[10][3] = 1;
 tt[10][3] = 1;
 tt[10][4] = 1;
 tt[10][5] = 1;
 tt[10][6] = 1;
 tt[10][7] = 1;

 accept = new int[5]; //5 accepting states
 accept[0] = 2;
 accept[1] = 6;
 accept[2] = 7;
 accept[3] = 8;
 accept[4] = 10;
}

void DFA::update(char input) {

 int numeric;
 if (input == ' ') numeric = 0;
 else if (input == 'e') numeric = 2;
 else if (input == 'E') numeric = 3;
 else if (input >= '0' && input <= '9') numeric = 4;
 else if (input == '.') numeric = 5;
 else if (input == '+') numeric = 6;
 else if (input == '-') numeric = 7;
 else numeric = 1;

 state = tt[state][numeric];
}

bool DFA::decision() {

 bool check=0;
 for(int i=0;i<5;++i) {
  if(accept[i] == state) check = 1;
 }
 return check;
}

void DFA::reset() {
 
 state = 0;
}

DFA::~DFA() { //deletes dynamically allocated data

 for(int i=0;i<11;++i) {
  delete[]tt[i];
 } 
 delete[]tt;
}

int main() 
{
 
 DFA floats;
 ifstream in_file;
 in_file.open("data.txt"); //please maintain the format shown in the sample data file

 while(in_file && !in_file.eof()) {
 
  char temp[TEMP];
  in_file.get(temp,TEMP,'\n');
  in_file.ignore(TEMP,'\n');
 
  for(int i=0;i<strlen(temp);++i) { //each character is fed into the DFA
   char ch = temp[i];
   floats.update(ch);
  }
  
  cout << temp << " "; 
  if (floats.decision()) cout << "A" << endl; //a final reject symbol is printed for the EOF character in the file
  else cout << "R" << endl;
  floats.reset();
 }
} 

#include <iostream>
#include <omp.h>
#include <map>

#include "readFiles.cpp"
#include "timer4300.cpp"

typedef long int myint;


////////////////////////////
// parallel code
////////////////////////////
void parallelF(myint* x, myint n){
  int candidate;
  long m;

  // declaring the voter count per each poltical candidate
  std::pair <int, int> key_ref;
  std::map <int, int> ballots;

  // construct a map to keep track of candidate votes
  for (int i = 0; i < 10; ++i){
    key_ref.first = i;
    key_ref.second = 0;
    ballots.insert(key_ref);
  }

  #pragma omp parallel
  {
    if(omp_get_thread_num() == 0){
      m = omp_get_num_threads();
    }
  }

  #pragma omp parallel num_threads(m)
  {
    long myId = omp_get_thread_num();
    long j = myId;
    while (j < n){
      ballots.find(x[j]) -> second += 1;
      j += m;
    }
  }

  // determines the maximum value of votes and report the candidate who won
  int winner, votes, max_votes = 0;

  for (int x = 0; x < 10; ++x){
    // votes for a given candidate
    votes = ballots.find(x) -> second;
    // tracks the rolling max number of votes and the subsequent winner
    if (votes > max_votes){
      max_votes = votes;
      winner =  x;
    }
  }

  std::cout << "The winner of the election is " << winner << " with " << max_votes << " votes\n";
}


////////////////////////////
// non-parallel code
////////////////////////////
void nonparallelF(myint* x, myint n){
  int candidate;

  // declaring the voter count per each poltical candidate
  std::pair <int, int> key_ref;
  std::map <int, int> ballots;

  // construct a map to keep track of candidate votes
  for (int i = 0; i < 10; ++i){
    key_ref.first = i;
    key_ref.second = 0;
    ballots.insert(key_ref);
  }

  // iterates through the entire x sequence and counts the total votes
  for (int j = 0; j < n; ++j){
    candidate = x[j];
    ballots.find(candidate) -> second += 1;
  }

  // determines the maximum value of votes and report the candidate who won
  int winner, votes, max_votes = 0;

  for (int x = 0; x < 10; ++x){
    // votes for a given candidate
    votes = ballots.find(x) -> second;
    
    // tracks the rolling max number of votes and the subsequent winner
    if (votes > max_votes){
      max_votes = votes;
      winner =  x;
    }
  }

  std::cout << "The winner of the election is " << winner << " with " << max_votes << " votes\n";
}


int main(){
  myint *x;
  myint n;

  // read the input from the file
  readSequenceFromFile("hw6_input.txt", &x, &n);

  Timer4300 tm, vm;

  // runtime for the nonparalel expression
  tm.start();
  nonparallelF(x, n);
  tm.end();
  std::cout << "The non-parallel function running time is: " << tm.getTime() << "\n";

  std::cout << "---------------------------------------\n";

  // runtime for the paralel expression
  vm.start();
  parallelF(x, n);
  vm.end();
  std::cout << "The parallel function running time is: " << tm.getTime() << "\n";

  delete[] x;
  return 0;
}

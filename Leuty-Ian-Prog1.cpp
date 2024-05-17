/*
Ian L
April_4_2024
CS162_001_Program1
ileuty@pdx.edu
This program is for practicing simple math problems.
These problems will be addition, subtraction, or multiplication 
of two numbers between zero and twenty. 
*/
//include needed libraries for random number generation.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct random_equation{	//create a structure to hold the mixed variable types 
			//involved in generating an equation.	
   int solution, num1, num2;
   char operation;
};

void create(random_equation &equ){ //create a function to initialize the structure
   srand(time(0)); //seed random number generator. 		
   int op{rand()%3}; //random number to determine operation	
   equ.num1 = rand()%21; //random numbers up to 20 using mod 
   equ.num2 = rand()%21;
   
   if (op == 0){ //control for initializing solution and operation based on random 'op'
   equ.solution = equ.num1 * equ.num2;
   equ.operation = 'x';
   }
   else if (op == 1){
   equ.solution = equ.num1 + equ.num2;
   equ.operation = '+';
   }
   else{
   equ.solution = equ.num1 - equ.num2;
   equ.operation = '-';
   }
}

int main(){ //main program
   random_equation equ;  //create a variable of type random_equation struct called 'equ' within main. 
   create(equ);  //call the function create to generate the random operator, numbers, 
   	      //and solution into structure of type random_equation that has been passed by refrence.
   int user_solution{0}, tokens{5}, attempt{0}, problem{1}, correct{0};
   char again{0};
   bool quit{false}, nice{false}, neg_attempt{false};
  
   cout << "\n\n\nWelcome to Math Practice!\n" //welcome the user, intorduce example problem 
        << "You'll recieve a simple random subtraction, addition, or multiplication problem.\n"		
        << "For example:\n\n";
   //display the random example equation and solution separately. 
   //explain the remaining rules for tokens and attempts.	
   cout << "Problem:\n" << equ.num1 << ' ' << equ.operation << ' ' << equ.num2 << " = ?"
        << "\nSolution:\n" << equ.solution << endl;
   cout << "\nYou'll start with 5 tokens.\n" 
        << "If you get the problem right, you'll move on to the next question.\n"
        << "For each problem, 3 attempts will be allowed before losing a token and moving on.\n"	
        << "Quit the game by entering 'n' before a new question.\n" << endl;
   
   while (quit == false){ //main loop. quit is false by default, 
           		  //only set to true if the user enters 'n'.	
      if (tokens > 0){ //if the user has more than 0 tokens,
      	       	       //give option to quit or continue. first user input as char 'y' or 'n'	  
         cout << "Continue? (y/n)\n" << '>';
      	 cin >> again;
      	 cout << "\n";	 
      	
      	 if (again == 'y' || again == 'Y'){ //control: yes, no, please enter y/n.
      	    nice = false; //nice means they got the problem right.
      			  // is rest every time a new question loop begins
      	    attempt = 1;  // attempt also reset to 1 every time
            cout << "\n";
      	    cout << "Tokens: " << tokens << endl; //remind user of tokens
      	    cout << "\n";				
      	    cout << "Here is problem number " << problem << ".\n\n"; //remind user of problem 									     //count
      	    create(equ);
      	    cout << equ.num1 << ' ' << equ.operation << ' ' << equ.num2 << " = ? " << endl;
       
      	    while (attempt <= 3 && nice == false){ //loop while attempt 3 or less 
						   //and no correct answer
      	       cout << "\nAttempt " << attempt << endl; // remind user of attempt count
      	       cout << "Enter your solution.\n" << '>'; //prompt for solution
      	       cin >> user_solution;
      		
      	       if (user_solution == equ.solution){ //check if answer is correct
      	          cout << "\n";
      		  cout << "Nice! That's correct.\n" << endl; //congratulate user if correct
      		  ++problem; //increment problem and correct counters
      		  ++correct;
      		  nice = true; //break attempt loop
      	       }
      	       else if (equ.solution >= 0 && user_solution < 0 && neg_attempt == false){
	          cout << "\nThe solution is not a negative number.\n" 
		       << "You will receive a free attempt...this time."  << endl;
		  neg_attempt=true; 
	       }
	       else if (equ.solution >= 0 && user_solution < 0 && neg_attempt == true){
	          cout << "\nYou were warned, the solution is not negative.\n"
		       << "Incorrect negative entries now count as an attempt." << endl;
		  ++attempt; //increment attempt
	       }
      	       else{ //if incorrect notify user.
      	          cout << "\nThat's not the right answer." << endl;
      		  ++attempt; //increment attempt
      	       }	
      	       if (attempt <= 3 && user_solution != equ.solution){ //if stil less than 3 attempts
      		  cout << "\nTry again." << endl; //tell them to try again, loop repeats
      	       }
      	       if (attempt > 3){ //if all 3 attempts used tell user they lost a token. 
      		  cout << "No more attempts for this problem. You've lost a token."  << endl;
      	          -- tokens; //decrement tokens
      		  ++ problem; //increment problem number
      	       }
      	    }
      	 }
      
      	 else if (again == 'n' || again == 'N'){ //user chooses not to continue
            cout << "Goodbye!\n"; //goodbye and correct/total
      	    cout << "You answered " << correct << " out of " << problem-1 << " problems correctly within 3 tries." << endl;
            quit = true; //break loop
      	 }
      	 else{ //user enters an invalid choice, tell them why
      	    cout << "Please enter either 'y' or 'n'.\n" << endl;
      	 }
      }
      
      else{ //no more tokens. inform user, correct/total
         cout << "You are out of tokens. You answered " << correct 
      	      << " out of " << problem << " problems correctly within 3 tries.\n";
      	
	/* cout << "Resetting..." << endl; //reset the game
      	 tokens = 5;
      	 problem = 1;
      	 correct = 0; //with these variable reset, they will enter the token check loop
	      	      //and be given the option to quit or continue the new game
		      // I removed this portion to make sure my program matches the rubric */
	 quit = true;
      }	
   }
   return 0;
}	

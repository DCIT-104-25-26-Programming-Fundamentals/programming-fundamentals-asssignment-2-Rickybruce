// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double addition(double a,double b){
    return a+b;
}
 double subtraction(double a,double b){
    return a-b;
}
double multiplication(double a,double b){
    return a*b;
}
double division(double a,double b){
    return a/b;
}
int modul(int a,int b){
    return a % b;
}
double exponentiation(double a,double b){
    return std::pow(a, b);
}

int main(){
   int n;
   cout << fixed << setprecision(2);
    cout<<
    " ========================================\n"
    "      SIMPLE CALCULATOR\n"
    " =========================================\n"
   "1. Addition\n"
   "2. Subtraction\n"
   "3. Multiplication\n"
   "4. Division\n"
   "5. Modulus\n"
   "6. Exponentiation\n"
   "7. Quit\n"
   "Select an operation (1-7): ";

    while(n != 7){
        cout<<"Select an operation (1-7): ";
        cin>>n;
        if (n == 7){
        cout<<"Goodbye"<<endl;
        break;
        }
        if (n < 1 || n > 7) {
            cout << "Error: Invalid operation choice." << endl;
            continue;
        }

        double firstNum,secondNum;
        cout<<"Enter first number : ";
        cin>>firstNum;
        cout<<"Enter second number: ";
        cin>>secondNum;

        if(n==1){
            cout << "Result: " << firstNum << " + " << secondNum << " == " << addition(firstNum, secondNum) << endl;
        }
        else if(n==2){
            cout << "Result: " << firstNum << " - " << secondNum << " == " << subtraction(firstNum, secondNum) << endl;
        }
        else if(n==3){
            cout << "Result: " << firstNum << " * " << secondNum << " == " << multiplication(firstNum, secondNum) << endl;
        }else if(n == 4){
            if( secondNum == 0){
                cout<<"Error: Cannot divide by zero.";
            }else{
               cout << "Result: " << firstNum << " / " << secondNum << " == " << division(firstNum, secondNum) << endl;
            }
        }else if(n==5){
           if (static_cast<int>(secondNum) == 0) {
                cout << "Error: Cannot perform modulus by zero." << endl;
            } else {
                cout << "Result: " << static_cast<int>(firstNum) << " % " << static_cast<int>(secondNum) 
                     << " == " << modul(static_cast<int>(firstNum), static_cast<int>(secondNum)) << endl;
            }
        }else if(n==6){
            cout << "Result: " << firstNum << " ^ " << secondNum << " == " << exponentiation(firstNum, secondNum) << endl;
            }

}
return 0;
}
// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

std:: vector<int> fibonacci_seq(int n){
    std::vector<int> seq;
    for(int i= 0 ; i<n ; i++){
        if(i==0){
            seq.push_back(0);
        }
        else if(i==1){
            seq.push_back(1);
        }
        else{
            seq.push_back(seq[i-2]+seq[i-1]);
        }
    }
    return seq;
}
bool fib_ver(int n){
    if (n == 0 || n == 1) return true;
    std:: vector<int> fib_seq = fibonacci_seq(n);
    for(int i =0 ; i< n ; i++){
        if(n == fib_seq[i]){
            return true ;
            break;
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"How many terms? ";
    cin>>n;

    if(n <= 0){
        cout<<"Number must be a positive non zero integer";
        return 1;
    }
    std:: vector<int> fib_seq = fibonacci_seq(n);
    std:: string fib_seq_out = "";
    for (int i =0 ; i < n ;i++){
        fib_seq_out += std::to_string(fib_seq[i]);

        if( i< n-1 ){
            fib_seq_out += ", ";
        }
    }
    std::cout <<"Fiboncci sequence: "<<fib_seq_out<<std::endl;

    int j;
    cout<<"Enter a number to check: ";
    cin>>j;
    if(j < 0){
        cout<<"Number must be a positive integer";
        return 1;
    }else if(fib_ver(j)){
        cout<<j<<" is a Fibonacci number.";
    }else{
        cout<<j<<" is NOT a Fibonacci number.";
    }




    return 0;
}

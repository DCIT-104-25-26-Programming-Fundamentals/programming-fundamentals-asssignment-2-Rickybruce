// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int sum(const vector<int> &nums, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += nums[i];
    }
    return total;
}
double average(const vector<int> &nums, int n)
{
    double average = (sum(nums, n) * 1.0) / n;
    return average;
}
int maximum(const vector<int> &nums, int n)
{
    int Maximum = nums[0];
    for (int i = 0; i < n; i++)
    {
        if (Maximum < nums[i])
        {
            Maximum = nums[i];
        }
    }
    return Maximum;
}
int minimum(const vector<int> &nums, int n)
{
    int Minimum = nums[0];
    for (int i = 0; i < n; i++)
    {
        if (Minimum > nums[i])
        {
            Minimum = nums[i];
        }
    }
    return Minimum;
}
int main()
{
    int n;
    cout << "How many numbers? ";
    if (!(cin >> n))
    {
        cout << "Error : Invalid input";
        return 1;
    }
    if (n <= 0)
    {
        cout << "Error: number must be a positive non-zero integer ";
        return 1;
    }
    vector<int> nums;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cout << "Enter number " << i << ": ";
        cin >> num;
        nums.push_back(num);
    }
    cout << "Result" << endl;
    cout << "Sum :        " << sum(nums, n) << endl;
    cout << "Average :    " << fixed << setprecision(2) << average(nums, n) << endl;
    cout << "Maximum :    " << maximum(nums, n) << endl;
    cout << "Minimum :    " << minimum(nums, n) << endl;
    return 0;
}

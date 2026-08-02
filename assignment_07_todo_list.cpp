// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;
string add_todo(vector<string>& todos) {
    string new_todo;
    cout<<"Enter task: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, new_todo);
    todos.push_back(new_todo);
    return new_todo;
}
string view_all_todos(vector<string>& todos){
    string output = "Your Tasks: \n";
    size_t length = todos.size();
    if(todos.empty()){
        output ="";
        output = "Hey, you don't have any active task to perform";
    }
    else{
        for(int i =1; i<=length ; i++){
           output += to_string(i) + ". " + todos[i - 1] + "\n";
        }
    }
    return output;
}
string delete_todo(vector<string>& todos, int todo_num) {
    if (todos.empty()) {
        return "Your to-do list is already empty!";
    }
    if  (todo_num < 1 || todo_num > static_cast<int>(todos.size())) {
        return "Error: Invalid task number!";
    }
    string deleted_task = todos [todo_num - 1];
    todos.erase(todos.begin() +  (todo_num - 1));
    return "Successfully deleted: \"" + deleted_task + "\"";
}

int main(){
    vector<string>todos;
    int n;
    cout<<
    " ========================================\n"
    "      TO-DO LIST MENU\n"
    " =========================================\n"
   "1. Add task\n"
   "2. View tasks\n"
   "3. Delete task\n"
   "4. Quit\n";

   while(true){
    cout<<"Enter your choice (1-4): ";
    cin>>n;
    if (cin.fail()) {
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Error: Invalid input. Please enter a number.\n";
            continue;
        }
    if(n==4){
        cout<<"Goodbye";
        break;
    }
    if (n < 1 || n > 4) {
            cout << "Error: Invalid input choice.\n";
            continue;
    }
    if(n==1){
    string output = add_todo(todos);
      cout<<"Task added: \"" <<output<<"\"\n";
    }
    else if(n==2){
        cout<<view_all_todos(todos);
    }
    else if(n==3){
        int todo_num;
        cout<<"Enter task number to delete: ";
        cin>>todo_num;
       cout<<delete_todo(todos,todo_num)<<endl;
    }
       }

    return 0;
}
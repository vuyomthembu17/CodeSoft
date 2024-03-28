#include <iostream>
#include <string>

using namespace std;

void print_task(string task[], int task_count)
{
    cout << "Task to Do: " << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < task_count; i++)
    {
        cout << "Task " << i + 1 << " : " << task[i] << endl;
    }
    cout << "----------------------------------------" << endl;
}

int main()
{
    string tasks[10]; // Removed the unnecessary initialization

    int task_count = 0;
    int option = -1;
    while (option != 0) // The menu will be under the while loop
    {
        cout << "------Welcome to our Do List------" << endl;
        cout << "1 --- Add A New Task ---" << endl;
        cout << "2 --- View The Tasks ---" << endl;
        cout << "3 --- Delete Task ---" << endl;
        cout << "0 --- End Program ---" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
        {
            if (task_count > 9)
            {
                cout << "Task List Full" << endl;
            }
            else
            {
                cout << "Enter New Task: ";
                cin.ignore(); // Added cin.ignore() to clear the input buffer
                getline(cin, tasks[task_count]); // Corrected the array name from task to tasks
                task_count++;
            }
            break;
        }
        case 2:
            system("cls");
            print_task(tasks, task_count); // Corrected the array name from task to tasks
            break;

        case 3:
        {
            system("cls");
            print_task(tasks, task_count); // Corrected the array name from task to tasks
            int del_task = 0;
            cout << "Enter task to delete: ";
            cin >> del_task;

            if (del_task < 1 || del_task > task_count) // Corrected the condition for del_task range
            {
                cout << "You entered an unknown task value" << endl;
                break;
            }
            for (int i = del_task - 1; i < task_count - 1; i++) // Corrected the loop bounds
            {
                tasks[i] = tasks[i + 1]; // Corrected the array name from task to tasks
            }
            task_count = task_count - 1;
            break;
        }
        case 0: // Corrected the case label from o to 0
            cout << "\n\t\t-------------------END PROGRAM-----------------" << endl;
            break;

        default:
            cout << "Invalid Value" << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <queue>
#include <string>

using namespace std;






struct Task
{
    int id;
    string description;
    int priority;
};









int inputNumber(string message)
{
    int number;

    cout << message;

    while (!(cin >> number))
    {
        cout << "Invalid input. Enter a number: ";

        cin.clear();
        cin.ignore(1000, '\n');
    }

    return number;
}









class TaskQueue
{
private:
    queue<Task> tasks;

public:
    void enqueue(Task task)
    {
        tasks.push(task);
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        tasks.pop();
        cout << "Task removed\n";
    }

    Task front()
    {
        return tasks.front();
    }

    bool isEmpty()
    {
        return tasks.empty();
    }

    string toString()
    {
        if (isEmpty())
        {
            return "Queue is empty\n";
        }

        queue<Task> temp = tasks;
        string result;

        while (!temp.empty())
        {
            Task current = temp.front();

            result += "ID: " + to_string(current.id);
            result += ", Description: " + current.description;
            result += ", Priority: " + to_string(current.priority);
            result += "\n";

            temp.pop();
        }

        return result;
    }
};










int main()
{
    TaskQueue q;
    int choice;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Add task\n";
        cout << "2. Remove first task\n";
        cout << "3. Show first task\n";
        cout << "4. Show queue\n";
        cout << "0. Exit\n";

        choice = inputNumber("Your choice: ");

        switch (choice)
        {
        case 1:
        {
            Task task;

            task.id = inputNumber("Enter ID: ");

            cin.ignore(1000, '\n');

            cout << "Enter description: ";
            getline(cin, task.description);

            task.priority = inputNumber("Enter priority: ");

            q.enqueue(task);

            cout << "Task added\n";
            break;
        }

        case 2:
            q.dequeue();
            break;

        case 3:
            if (q.isEmpty())
            {
                cout << "Queue is empty\n";
            }
            else
            {
                Task first = q.front();

                cout << "ID: " << first.id << endl;
                cout << "Description: " << first.description << endl;
                cout << "Priority: " << first.priority << endl;
            }
            break;

        case 4:
            cout << "\nQueue contents:\n";
            cout << q.toString();
            break;

        case 0:
            cout << "Program terminated\n";
            break;

        default:
            cout << "Invalid menu item\n";
        }

    } while (choice != 0);

    return 0;
}
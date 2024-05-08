#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string name;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    string task;
    cout << "Enter a task: ";
    getline(cin, task);
    Task newTask;
    newTask.name = task;
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task '" << task << "' added!" << endl;
}

void viewTasks() {
    cout << "To-do list:" << endl;
    for (int i = 0; i<tasks.size(); i++) {
        string status = tasks[i].completed? "Completed" : "Pending";
        cout << i + 1 << ". " << tasks[i].name << " (" << status << ")" << endl;
    }
}

void markTaskAsCompleted() {
    int taskNum;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNum;
    if (taskNum > 0 && taskNum<=tasks.size()) {
        tasks[taskNum - 1].completed = true;
        cout << "Task " << taskNum << " marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void removeTask() {
    int taskNum;
    cout << "Enter the task number to remove: ";
    cin >> taskNum;
    if (taskNum > 0 && taskNum<=tasks.size()) {
        tasks.erase(tasks.begin() + taskNum - 1);
        cout << "Task " << taskNum << " removed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    while (true) {
        cout << "\nTo-do list manager" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Mark task as completed" << endl;
        cout << "4. Remove task" << endl;
        cout << "5. Quit" << endl;
        int choice;
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout<<"\nThank you for using My To-Do List Application...! \n";
                return 0;
            default:
                cout << "Invalid option!" << endl;
        }
    }
    return 0;
}
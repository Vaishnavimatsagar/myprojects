#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskDescription) {
        tasks.emplace_back(taskDescription); // Corrected line
        cout << "Task added: " << taskDescription << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }

        cout << "Your Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". [" 
                 << (tasks[i].completed ? "X" : " ") 
                 << "] " 
                 << tasks[i].description 
                 << endl;
        }
    }

    void markTaskAsCompleted(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks[index - 1].completed = true;
        cout << "Task marked as completed: " << tasks[index - 1].description << endl;
    }

    void removeTask(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        cout << "Task removed: " << tasks[index - 1].description << endl;
        tasks.erase(tasks.begin() + index - 1);
    }
};

int main() {
    TodoList todoList;
    int choice;
    string taskDescription;

    do {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); // Clear the newline character from the input buffer
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;

            case 2:
                todoList.viewTasks();
                break;

            case 3:
                int completeIndex;
                cout << "Enter task number to mark as completed: ";
                cin >> completeIndex;
                todoList.markTaskAsCompleted(completeIndex);
                break;

            case 4:
                int removeIndex;
                cout << "Enter task number to remove: ";
                cin >> removeIndex;
                todoList.removeTask(removeIndex);
                break;

            case 5:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}


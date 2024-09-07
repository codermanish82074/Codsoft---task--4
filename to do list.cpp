#include <iostream>
#include <vector>
#include <string>

void displayMenu() {
    std::cout << "\nTo-Do List Menu:\n";
    std::cout << "1. Add a task\n";
    std::cout << "2. View all tasks\n";
    std::cout << "3. Remove a task\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void addTask(std::vector<std::string>& tasks) {
    std::cin.ignore(); 
    std::string task;
    std::cout << "Enter task description: ";
    std::getline(std::cin, task);
    tasks.push_back(task);
    std::cout << "Task added successfully.\n";
}

void viewTasks(const std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list.\n";
        return;
    }
    std::cout << "Current tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i] << '\n';
    }
}

void removeTask(std::vector<std::string>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) {
        return;
    }
    size_t taskNumber;
    std::cout << "Enter the number of the task to remove: ";
    std::cin >> taskNumber;
    
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task removed successfully.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

int main() {
    std::vector<std::string> tasks;
    int choice = 0;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                removeTask(tasks);
                break;
            case 4:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}


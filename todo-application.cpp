#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Task {
public:
    Task(const std::string& description) : description(description), completed(false) {}

    std::string getDescription() const { return description; }
    bool isCompleted() const { return completed; }
    void markCompleted() { completed = true; }

private:
    std::string description;
    bool completed;
};

class TodoList {
public:
    void addTask(const std::string& description) {
        tasks.push_back(Task(description));
        std::cout << "Task added successfully.\n";
    }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markCompleted();
            std::cout << "Task marked as completed.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list.\n";
            return;
        }

        std::cout << "Current tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            if (tasks[i].isCompleted()) {
                std::cout << "[X] ";
            } else {
                std::cout << "[ ] ";
            }
            std::cout << tasks[i].getDescription() << "\n";
        }
    }

private:
    std::vector<Task> tasks;
};

int main() {
    TodoList todoList;
    std::string input;
    
    while (true) {
        std::cout << "\n==== Todo List Application ====\n";
        std::cout << "1. Add a task\n";
        std::cout << "2. Mark a task as completed\n";
        std::cout << "3. View tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        
        std::getline(std::cin, input);
        int choice = std::stoi(input);

        switch (choice) {
            case 1: {
                std::cout << "Enter task description: ";
                std::string description;
                std::getline(std::cin, description);
                todoList.addTask(description);
                break;
            }
            case 2: {
                std::cout << "Enter task number to mark as completed: ";
                std::getline(std::cin, input);
                int index = std::stoi(input) - 1;
                todoList.markTaskCompleted(index);
                break;
            }
            case 3:
                todoList.viewTasks();
                break;
            case 4:
                std::cout << "Exiting the application. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
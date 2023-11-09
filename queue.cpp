#include "queue.h"

// Implementation of enqueue method
void CustomQueue::enqueue(int value) {
    myQueue.push(value);
}

// Implementation of dequeue method
int CustomQueue::dequeue() {
    if (!myQueue.empty()) {
        int frontElement = myQueue.front();
        myQueue.pop();
        return frontElement;
    }
    return -1; // Return -1 to indicate an empty queue.
}

// Implementation of front method
int CustomQueue::front() {
    if (!myQueue.empty()) {
        return myQueue.front();
    }
    return -1; // Return -1 to indicate an empty queue.
}

// Implementation of isEmpty method
bool CustomQueue::isEmpty() {
    return myQueue.empty();
}

// Implementation of size method
int CustomQueue::size() {
    return myQueue.size();
}

// Implementation of printQueue method
void CustomQueue::printQueue() {
    std::cout << "Queue: ";
    std::queue<int> tempQueue = myQueue;

    // Iterate through the temporary queue to print each element.
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << " ";
        tempQueue.pop();
    }

    std::cout << std::endl;
}

// Entry point of the program
int main() {
    CustomQueue myCustomQueue; // Create an instance of the CustomQueue class.

    // Main menu loop
    while (true) {
        // Display the menu options
        std::cout << "Queue Menu:\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Front\n";
        std::cout << "4. IsEmpty\n";
        std::cout << "5. Size\n";
        std::cout << "6. Print Full Queue\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        // Input validation for menu choice
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please try again.\n";
            continue;
        }

        // Switch statement to handle user choices
        switch (choice) {
            case 1: {
                int value;
                // Prompt user to enter a value for enqueue operation
                std::cout << "Enter value to enqueue: ";
                // Input validation for enqueue operation
                if (!(std::cin >> value)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a valid integer.\n";
                    continue;
                }
                // Perform enqueue operation
                myCustomQueue.enqueue(value);
                break;
            }
            case 2: {
                // Perform dequeue operation
                int result = myCustomQueue.dequeue();
                if (result != -1) {
                    std::cout << "Dequeued element: " << result << std::endl;
                } else {
                    std::cout << "Queue is empty. Cannot dequeue." << std::endl;
                }
                break;
            }
            case 3: {
                // Perform front operation
                int result = myCustomQueue.front();
                if (result != -1) {
                    std::cout << "Front element: " << result << std::endl;
                } else {
                    std::cout << "Queue is empty. No front element." << std::endl;
                }
                break;
            }
            case 4:
                // Check if the queue is empty
                std::cout << "Is empty? " << (myCustomQueue.isEmpty() ? "Yes" : "No") << std::endl;
                break;
            case 5:
                // Display the size of the queue
                std::cout << "Queue size: " << myCustomQueue.size() << std::endl;
                break;
            case 6:
                // Print the full queue
                myCustomQueue.printQueue();
                break;
            case 7:
                // Exit the program
                std::cout << "Exiting program.\n";
                return 0;
            default:
                // Handle invalid choices
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
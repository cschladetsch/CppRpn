#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <functional>

class StackCalculator {
private:
    std::stack<double> data_stack;

    void push(double value) {
        data_stack.push(value);
    }

    double pop() {
        if (data_stack.empty()) {
            throw std::runtime_error("Error: Stack is empty.");
        }
        double top = data_stack.top();
        data_stack.pop();
        return top;
    }

    void perform_binary_operation(const std::function<double(double, double)>& op) {
        if (data_stack.size() < 2) {
            throw std::runtime_error("Error: Not enough elements on the stack.");
        }
        double b = pop();
        double a = pop();
        push(op(a, b));
    }

public:
    void execute(const std::string& command) {
        try {
            if (command == "+") {
                perform_binary_operation(std::plus<>());
            } else if (command == "-") {
                perform_binary_operation(std::minus<>());
            } else if (command == "*") {
                perform_binary_operation(std::multiplies<>());
            } else if (command == "/") {
                perform_binary_operation([](double a, double b) {
                    if (b == 0) throw std::runtime_error("Error: Division by zero.");
                    return a / b;
                });
            } else if (command == "clear") {
                while (!data_stack.empty()) data_stack.pop();
            } else if (command == "print") {
                print_stack();
            } else {
                // Assume the command is a number
                double value = std::stod(command);
                push(value);
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void print_stack() const {
        std::stack<double> temp = data_stack; // Copy to preserve stack
        std::cout << "Data Stack:\n";
        int index = 0;
        while (!temp.empty()) {
            std::cout << "[" << index++ << "] " << std::fixed << std::setprecision(2) << temp.top() << "\n";
            temp.pop();
        }
        if (index == 0) std::cout << "[empty]\n";
    }
};

void repl(StackCalculator& calculator) {
    std::string input;
    std::cout << "Enter commands (type 'exit' to quit):\n";
    while (true) {
        std::cout << "λ ";
        std::getline(std::cin, input);
        if (input == "exit") break;
        calculator.execute(input);
    }
}

int main() {
    StackCalculator calculator;
    repl(calculator);
    return 0;
}


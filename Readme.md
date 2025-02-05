# Stack-Based Calculator

## Description
This is a simple **stack-based calculator** implemented in C++. It supports basic arithmetic operations using Reverse Polish Notation (RPN).

## Features
- Supports addition (`+`), subtraction (`-`), multiplication (`*`), and division (`/`).
- Handles errors such as stack underflow and division by zero.
- Allows clearing the stack (`clear`) and printing the stack (`print`).
- Implements a Read-Eval-Print Loop (REPL) for interactive use.

## Usage
### **Compilation**
To compile the program, use:
```bash
g++ -o stack_calculator main.cpp -std=c++17
```

### **Running the Program**
Run the compiled binary:
```bash
./stack_calculator
```

### **Interactive Commands**
Once the program is running, you can enter the following commands:

| Command  | Description |
|----------|-------------|
| `number` | Pushes a number onto the stack. Example: `5.0` |
| `+`      | Adds the top two elements on the stack. |
| `-`      | Subtracts the top element from the second-top element. |
| `*`      | Multiplies the top two elements on the stack. |
| `/`      | Divides the second-top element by the top element. (Handles division by zero) |
| `clear`  | Clears the stack. |
| `print`  | Displays the current stack. |
| `exit`   | Exits the program. |

### **Example Usage**
```plaintext
Enter commands (type 'exit' to quit):
λ 10
λ 5
λ +
λ print
Data Stack:
[0] 15.00
λ 2
λ /
λ print
Data Stack:
[0] 7.50
λ clear
λ print
[empty]
λ exit
```

## Code Structure
- `StackCalculator`: Manages the stack and executes commands.
- `repl()`: Implements the interactive Read-Eval-Print Loop.
- `main()`: Initializes the calculator and starts the REPL.

## Dependencies
- Requires **C++17** or later for compilation.

## License
This project is open-source and available under the **MIT License**.


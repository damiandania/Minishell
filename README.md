<p>
<img src="https://github.com/damiandania/damiandania/blob/main/Pics/Minishell.png"
    alt="Project pic" width="150" height="150"/>
</p>

# Minishell 🐚

**Minishell** is a simple shell implementation project. The goal is to create a minimalistic shell that can execute commands, handle pipes, redirections, and manage environment variables.

## Features

- **Command Execution:** Execute basic shell commands.
- **Pipes and Redirections:** Handle pipes (`|`) and redirections (`<`, `>`).
- **Environment Variables:** Manage and use environment variables.
- **Built-in Commands:** Implement built-in commands like `cd`, `echo`, `env`, `exit`, etc.

## Technologies Used

- **C:** The shell is implemented in C.

## Installation

1. **Clone this repository:**
    ```bash
    git clone https://github.com/damiandania/Minishell.git
    ```

2. **Navigate to the project directory:**
    ```bash
    cd Minishell
    ```

3. **Build the project:**
    ```bash
    make
    ```

4. **Run the shell:**
    ```bash
    ./minishell
    ```

## Usage

Once the shell is running, you can execute commands just like in a regular shell. For example:

```sh
$ ls -l
$ echo "Hello, World!"
$ export PATH=$PATH:/my/custom/path
$ cd /path/to/directory
$ exit

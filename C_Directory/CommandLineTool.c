#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

// Forward declarations of command execution functions
void helloCommand(void);
void helpCommand(void);
void exitCommand(void);

// Command structure
typedef struct {
    const char* name;
    void (*function)(void);
} Command;

// List of available commands
Command commands[] = {
    {"hello", helloCommand},
    {"help", helpCommand},
    {"exit", exitCommand},
    // Add more commands here
};

// Helper function to get the number of commands
int getNumCommands() {
    return sizeof(commands) / sizeof(Command);
}

// Command execution functions
void helloCommand() {
    printf("Hello, World!\n");
}

void helpCommand() {
    printf("Available commands:\n");
    for (int i = 0; i < getNumCommands(); i++) {
        printf("  - %s\n", commands[i].name);
    }
}

void exitCommand() {
    printf("Exiting the operating system...\n");
    exit(0);
}

// Find the command function based on the command name
void (*findCommand(const char* command))(void) {
    for (int i = 0; i < getNumCommands(); i++) {
        if (strcmp(command, commands[i].name) == 0) {
            return commands[i].function;
        }
    }
    return NULL;
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf(">> ");
        fgets(command, sizeof(command), stdin);

        // Remove the newline character from the command
        command[strcspn(command, "\n")] = '\0';

        void (*commandFunction)(void) = findCommand(command);
        if (commandFunction != NULL) {
            commandFunction();
        } else {
            printf("Unknown command. Type 'help' to see available commands.\n");
        }
    }

    return 0;
}

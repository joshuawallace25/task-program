#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 100

struct Task {
    char description[MAX_TASK_LENGTH];
    int completed;
};

int main() {
    struct Task tasks[MAX_TASKS];
    int taskCount = 0;

    while (1) {
        printf("Task Application\n");
        printf("1. Add a task\n");
        printf("2. List tasks\n");
        printf("3. Mark task as completed\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (taskCount < MAX_TASKS) {
                    printf("Enter task description: ");
                    getchar();  // Consume newline
                    fgets(tasks[taskCount].description, MAX_TASK_LENGTH, stdin);
                    tasks[taskCount].description[strlen(tasks[taskCount].description) - 1] = '\0';  // Remove the trailing newline
                    tasks[taskCount].completed = 0;
                    taskCount++;
                    printf("Task added successfully.\n");
                } else {
                    printf("Task list is full. Cannot add more tasks.\n");
                }
                break;
            case 2:
                printf("Task List:\n");
                for (int i = 0; i < taskCount; i++) {
                    printf("%d. %s - %s\n", i + 1, tasks[i].completed ? "[X]" : "[ ]", tasks[i].description);
                }
                break;
            case 3:
                if (taskCount > 0) {
                    printf("Enter the task number to mark as completed: ");
                    int taskNumber;
                    scanf("%d", &taskNumber);
                    if (taskNumber >= 1 && taskNumber <= taskCount) {
                        tasks[taskNumber - 1].completed = 1;
                        printf("Task marked as completed.\n");
                    } else {
                        printf("Invalid task number.\n");
                    }
                } else {
                    printf("No tasks available to mark as completed.\n");
                }
                break;
            case 4:
                printf("Exiting the task application.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FILE_NAME "tasks.txt"
#define MAX_TASK_LENGTH 256
#define MAX_TASKS 100

// Structure to represent a task
typedef struct
{
    int id;
    char description[MAX_TASK_LENGTH];
    int completed;
} Task;

void addTask();
void viewTasks();
void markTaskAsDone();
void deleteTask();
void saveTasks(Task tasks[], int count);
void loadTasks(Task tasks[], int *count);

void addTask()
{

    Task tasks[MAX_TASKS]; // new array
    int count = 0;
    loadTasks(tasks, &count); // put tasks into the tasks array from to file

    if (count >= MAX_TASKS)
    {
        printf("Task list is full!\n");
        return;
    }

    printf("Enter task description: ");
    fgets(tasks[count].description, MAX_TASK_LENGTH, stdin);
    tasks[count].description[strcspn(tasks[count].description, "\n")] = 0; // Remove newline
    tasks[count].id = rand() % 999 + 100;                                  // generate random id
    tasks[count].completed = 0;

    count++;
    saveTasks(tasks, count);
    printf("Task added successfully!\n");
}

void viewTasks()
{
    Task tasks[MAX_TASKS];
    int count = 0;
    loadTasks(tasks, &count);

    if (count == 0)
    {
        printf("No tasks found.\n");
        return;
    }
    printf("\n******************************************************\n");
    printf("\n***************      Task  List        ***************\n");
    printf("\nNo.     Id              Completion                   Job\n");
    for(int i=0;i<count;i++)
    {
    printf("\n%d       %d               %s                   %s\n",i+1,tasks[i].id,tasks[i].completed? "done":"todo",tasks[i].description);
    }
}

void markTaskAsDone()
{
    Task tasks[MAX_TASKS];
    int count = 0;
    loadTasks(tasks, &count); // put tasks into the tasks array

    if (count == 0) // condition if the file is empty ?
    {
        printf("No tasks available to mark as done.\n");
        return;
    }

    int id;
    printf("\n************************************************\n");
    printf("Enter task ID to mark as done: ");
    scanf("%d", &id);
    // getchar();
    for (int i = 0; i < count; i++)
    {
        if (tasks[i].id == id)
        {
            tasks[i].completed = 1;
            saveTasks(tasks, count);
            printf("Task marked as completed!\n");
            return;
        }
    }

    printf("Task not found!\n");
}
void deleteTask()
{
    Task tasks[MAX_TASKS];
    int count = 0;
    loadTasks(tasks, &count); // put tasks into the tasks array

    if (count == 0) // condition if the file is empty ?
    {
        printf("No tasks available to delete.\n");
        return;
    }

    int id;
    printf("\n************************************************\n");
    printf("Enter task ID to delete: ");
    scanf("%d", &id);
    // getchar();
    for (int i = 0; i < count; i++)
    {
        if (tasks[i].id == id)
        {
            for (int j = i; j < count - 1; j++)
            {
                tasks[j] = tasks[j + 1];
            }
            count--;
            saveTasks(tasks, count);
            printf("Task deleted!\n");
            return;
        }
    }
}
// Function to save tasks to a file
void saveTasks(Task tasks[], int count)
{
    FILE *file = fopen(FILE_NAME, "w");
    if (!file)
    {
        printf("Error saving tasks!\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d,%d,%s\n", tasks[i].id, tasks[i].completed, tasks[i].description);
    }
    fclose(file);
}
// Function to load tasks from a file
void loadTasks(Task tasks[], int *count)
{
    FILE *file = fopen(FILE_NAME, "r");
    if (!file)
    {
        return;
    }

    *count = 0;
    while (fscanf(file, "%d,%d,%255[^\n]\n", &tasks[*count].id, &tasks[*count].completed, tasks[*count].description) != EOF)
    {
        (*count)++;
    }

    fclose(file);
}

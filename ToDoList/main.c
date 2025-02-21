#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

int main()
{
    int choice;
    while (1)
    {
        printf("\n********************Task Manager****************\n");
        printf("----------------------------------------------------------\n");
        printf("-----------------1. Add Task            -----------------\n");
        printf("-----------------2. View Tasks          -----------------\n");
        printf("-----------------3. Mark Task as Done   -----------------\n");
        printf("-----------------4. Delete Task         -----------------\n");
        printf("-----------------5. Exit                -----------------\n");
        printf("----------------------------------------------------------\n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            addTask();
            break;

        case 2:
            viewTasks();
            break;

        case 3:
            markTaskAsDone();
            break;

        case 4:
            deleteTask();
            break;

        case 5:
            printf("Exiting the program\n");
            exit(0);
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }

    return 0;
}
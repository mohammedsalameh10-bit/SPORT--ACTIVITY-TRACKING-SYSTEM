#include <stdio.h>
#include <string.h>

#define MAX 100

struct Activity {
    char type[20];
    float duration;
    float distance;
};

struct Activity activities[MAX];
int count = 0;

// Add Activity
void addActivity() {
    if (count >= MAX) {
        printf("Storage full!\n");
        return;
    }

    printf("Enter activity type: ");
    scanf("%19s", activities[count].type);

    printf("Enter duration (minutes): ");
    scanf("%f", &activities[count].duration);

    printf("Enter distance (km): ");
    scanf("%f", &activities[count].distance);

    count++;
    printf("Activity added successfully!\n");
}

// Show Statistics
void showStats() {
    if (count == 0) {
        printf("No activities recorded.\n");
        return;
    }

    float totalDuration = 0;
    float totalDistance = 0;

    for (int i = 0; i < count; i++) {
        totalDuration += activities[i].duration;
        totalDistance += activities[i].distance;
    }

    printf("\n--- Statistics ---\n");
    printf("Total activities: %d\n", count);
    printf("Average duration: %.2f minutes\n", totalDuration / count);
    printf("Total distance: %.2f km\n", totalDistance);
}

int main() {
    int choice;

    do {
        printf("\n--- Sports Activity Tracker ---\n");
        printf("1. Add Activity\n");
        printf("2. Show Statistics\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addActivity();
                break;
            case 2:
                showStats();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}

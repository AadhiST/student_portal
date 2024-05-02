#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[50];
    int age;
    float marks;
    struct student *next;
};

struct student *head = NULL;

void add_student() {
    struct student *new_student = (struct student *)malloc(sizeof(struct student));
    printf("Enter student ID: ");
    scanf("%d", &new_student->id);
    printf("Enter student name: ");
    scanf("%s", new_student->name);
    printf("Enter student age: ");
    scanf("%d", &new_student->age);
    printf("Enter student marks: ");
    scanf("%f", &new_student->marks);
    new_student->next = head;
    head = new_student;
    printf("Student added successfully!\n");
}

void modify_student() {
    int id;
    printf("Enter student ID to modify: ");
    scanf("%d", &id);
    struct student *current = head;
    while (current != NULL) {
        if (current->id == id) {
            printf("Enter new name: ");
            scanf("%s", current->name);
            printf("Enter new age: ");
            scanf("%d", &current->age);
            printf("Enter new marks: ");
            scanf("%f", &current->marks);
            printf("Student modified successfully!\n");
            return;
        }
        current = current->next;
    }
    printf("Student with ID %d not found!\n", id);
}

void delete_student() {
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    struct student *current = head;
    struct student *previous = NULL;
    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Student deleted successfully!\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Student with ID %d not found!\n", id);
}

void list_students() {
    struct student *current = head;
    while (current != NULL) {
        printf("ID: %d, Name: %s, Age: %d, Marks: %.2f\n", current->id, current->name, current->age, current->marks);
        current = current->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add student\n");
        printf("2. Modify student\n");
        printf("3. Delete student\n");
        printf("4. List students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                modify_student();
                break;
            case 3:
                delete_student();
                break;
            case 4:
                list_students();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

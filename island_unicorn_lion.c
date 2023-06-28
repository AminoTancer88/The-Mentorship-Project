// This code is for the The Mentorship Project 
#include <stdio.h>
#include <string.h> 
 
// Global variables  
// Define global array to store mentor's information 
char *mentors[50]; 
// Define global array to store mentees's information 
char *mentees[50]; 
 
// Function to add a new mentor to the mentorship program 
void addMentor() {
    int index = 0; 
    char name[20];
    char countryOfOrigin[20];
    char profession[20];
    int age;
    char gender[6];
    char email[50];
    
    printf("Enter mentor name: ");
    scanf("%s", name);
    printf("Enter mentor's country of origin: ");
    scanf("%s", countryOfOrigin);
    printf("Enter mentor's profession: ");
    scanf("%s", profession);
    printf("Enter mentor's age: ");
    scanf("%d", &age);
    printf("Enter mentor's gender: ");
    scanf("%s", gender);
    printf("Enter mentor's email address: ");
    scanf("%s", email);
    
    // Store mentor's information inside global array 
    mentors[index++] = name;
    mentors[index++] = countryOfOrigin;
    mentors[index++] = profession;
    mentors[index++] = age;
    mentors[index++] = gender;
    mentors[index++] = email;
}
 
// Function to add a new mentee to the mentorship program
void addMentee() {
    int index = 0;
    char name[20];
    char countryOfOrigin[20];
    int age;
    char gender[6];
    char email[50];
    char interests[50];
 
    printf("Enter mentee name: ");
    scanf("%s", name);
    printf("Enter mentee's country of origin: ");
    scanf("%s", countryOfOrigin);
    printf("Enter mentee's age: ");
    scanf("%d", &age);
    printf("Enter mentee's gender: ");
    scanf("%s", gender);
    printf("Enter mentee's email address: ");
    scanf("%s", email);
    printf("Enter mentee's interests: ");
    scanf("%s", interests);
 
    // Store mentee's information inside global array
    mentees[index++] = name;
    mentees[index++] = countryOfOrigin;
    mentees[index++] = age;
    mentees[index++] = gender;
    mentees[index++] = email;
    mentees[index++] = interests;
}
 
// Function to remove a mentor from the mentorship program
void removeMentor() {
    char name[20];
    printf("Enter mentor name: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < 50; i++) {
        if (strcmp(mentors[i], name) == 0) {
            mentors[i] = "";
            printf("Mentor %s removed.\n", name);
            break;
        }
    }
    if (i == 50) {
        printf("Mentor not found.\n");
    }
}
 
// Function to remove a mentee from the mentorship program
void removeMentee() {
    char name[20];
    printf("Enter mentee name: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < 50; i++) {
        if (strcmp(mentees[i], name) == 0) {
            mentees[i] = "";
            printf("Mentee %s removed.\n", name);
            break;
        }
    }
    if (i == 50) {
        printf("Mentee not found.\n");
    }
}
 
// Function to display all mentors in the mentorship program
void displayMentors() {
    int i;
    printf("Mentors:\n");
    for (i = 0; i < 50; i++) {
        if (mentors[i] != "") {
            printf("Name: %s\n", mentors[i]);
            printf("Country of Origin: %s\n", mentors[i+1]);
            printf("Profession: %s\n", mentors[i+2]);
            printf("Age: %d\n", mentors[i+3]);
            printf("Gender: %s\n", mentors[i+4]);
            printf("Email: %s\n\n", mentors[i+5]);
        }
    }
}
 
// Function to display all mentees in the mentorship program
void displayMentees() {
    int i;
    printf("Mentees:\n");
    for (i = 0; i < 50; i++) {
        if (mentees[i] != "") {
            printf("Name: %s\n", mentees[i]);
            printf("Country of Origin: %s\n", mentees[i+1]);
            printf("Age: %d\n", mentees[i+2]);
            printf("Gender: %s\n", mentees[i+3]);
            printf("Email: %s\n", mentees[i+4]);
            printf("Interests: %s\n\n", mentees[i+5]);
        }
    }
}
 
// Function to match a mentor and mentee to the mentorship program
void matchMentorMentee() {
    int i, j;
    char mentorName[20], menteeName[20];
    printf("Enter mentor name: ");
    scanf("%s", mentorName);
    printf("Enter mentee name: ");
    scanf("%s", menteeName);
    for (i = 0; i < 50; i++) {
        if (strcmp(mentors[i], mentorName) == 0) {
            for (j = 0; j < 50; j++) {
                if (strcmp(mentees[j], menteeName) == 0) {
                    printf("Mentor %s and mentee %s have been matched!\n", mentorName, menteeName);
                    break;
                }
            }
            break;
        }
    }
    if (i == 50 || j == 50) {
        printf("Mentor or mentee not found.\n");
    }
}
 
// Main Function 
int main() {
    int choice;
    printf("Welcome to The Mentorship Project!\n");
    do {
        printf("\nMENU\n");
        printf("1. Add Mentor\n");
        printf("2. Add Mentee\n");
        printf("3. Remove Mentor\n");
        printf("4. Remove Mentee\n");
        printf("5. Display All Mentors\n");
        printf("6. Display All Mentees\n");
        printf("7. Match Mentor and Mentee\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMentor();
                break;            
            case 2:
                addMentee();
                break;
            case 3:
                removeMentor();
                break;
            case 4:
                removeMentee();
                break;
            case 5:
                displayMentors();
                break;
            case 6:
                displayMentees();
                break;
            case 7:
                matchMentorMentee();
                break;
            case 8:
                printf("Bye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 8);
    return 0;
}
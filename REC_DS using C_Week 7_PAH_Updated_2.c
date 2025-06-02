// In a school, students' marks are recorded along with their roll numbers for a particular exam. Develop a program to manage this information using a dictionary. 



// The program should allow the teacher to input the number of students, their roll numbers, and corresponding marks. After input, it should display the roll numbers and marks of all students in ascending order of their roll numbers.

// Input format :
// The first line consists of an integer N, representing the number of student entries.

// Each of the next N lines consists of a string R and an integer M, separated by a space, representing a roll number (key) and marks (value) of the student.

// Output format :
// The output displays the roll numbers and marks of all students line by line in ascending order of their roll numbers.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ M ≤ 100

// Length of R = 4

// The keys (Roll numbers) are case-sensitive.

// Sample test cases :
// Input 1 :
// 4
// A104 85
// A102 78
// A103 92
// A101 69
// Output 1 :
// A101 69
// A102 78
// A103 92
// A104 85
// Input 2 :
// 5
// A109 82
// A104 70
// A100 88
// A101 69
// A110 90
// Output 2 :
// A100 88
// A101 69
// A104 70
// A109 82
// A110 90





#include <stdio.h>
#include <string.h>

// Structure to store student information
typedef struct {
    char rollNumber[5];
    int marks;
} Student;

// Function to sort the students by roll number in ascending order
void sortStudents(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(students[j].rollNumber, students[j + 1].rollNumber) > 0) {
                // Swap the students
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n); // Input the number of students

    Student students[n];

    // Input student data
    for (int i = 0; i < n; i++) {
        scanf("%s %d", students[i].rollNumber, &students[i].marks);
    }

    // Sort the students by roll number
    sortStudents(students, n);

    // Output the sorted student data
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", students[i].rollNumber, students[i].marks);
    }

    return 0;
}


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int numberOfStudents = 10;
int studentID;
int average;
int studentGrades[10];
int studentIDnumbers[10];
char letterGrades[10];
int aStudents;
int bStudents;
int cStudents;
int dStudents;
int fStudents;


int LetterGrade();

int main() {
  aStudents = 0;
  bStudents = 0;
  cStudents = 0;
  dStudents = 0;
  fStudents = 0;



  for (int i = 0; i < numberOfStudents; i++) {
    studentID = 0;
    average = 0;
    puts("Please enter Student ID#");
    scanf("%i", &studentID);
    studentIDnumbers[i] = studentID;
    puts("Please enter Student's average:");
    scanf("%i", &average);
    studentGrades[i] = average;
  }

  // For each student in the class, uses a switch statement to assign grade
  // letter and add to a third array.
  for (int i = 0; i < numberOfStudents; i++) {
    switch (studentGrades[i]) {
    case 90 ... 100:
      printf("Student %i recieved an A with a grade of %2i\n",
             studentIDnumbers[i], studentGrades[i]);
      letterGrades[i] = 'A';
      break;
    case 80 ... 89:
      printf("Student %i received a B with a grade of %2i.\n",
             studentIDnumbers[i], studentGrades[i]);
      letterGrades[i] = 'B';
      break;
    case 70 ... 79:

      printf("Student %i received a C with a grade of %2i. \n",
             studentIDnumbers[i], studentGrades[i]);
      letterGrades[i] = 'C';
      break;
    case 60 ... 69:
      printf("Student %i received a D with a grade of %2i\n",
             studentIDnumbers[i], studentGrades[i]);

      letterGrades[i] = 'D';
    default:
      printf("Student %i received an F with a grade of %2i.\n",
             studentIDnumbers[i], studentGrades[i]);
      letterGrades[i] = 'F';
      break;
    }
  }

  LetterGrade();
}

// For every student in the class, checks their letter grade and adds it to a
// running total. Prints out the total of every letter grade for the class.
int LetterGrade() {

  for (int i = 0; i < numberOfStudents; i++) {
    switch (letterGrades[i]) {
    case 'A':
      aStudents++;
      break;
    case 'B':
      bStudents++;
      break;
    case 'C':
      cStudents++;
      break;
    case 'D':
      dStudents++;
      break;
    case 'F':
      fStudents++;
      break;
    }
  }
  printf("Number of students with an A: %i \n", aStudents);
  printf("Number of students with a B: %i \n", bStudents);
  printf("Number of students with a C: %i \n", cStudents);
  printf("Number of students with a D: %i \n", dStudents);
  printf("Number of students with an F: %i \n", fStudents);
  return 0;
}

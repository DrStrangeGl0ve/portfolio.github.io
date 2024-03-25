#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Declaring averageValue and addedValue variables globally so they reset
// between main() loops.
float averageValue;
float addedValues;

// Declaring and initializing all functions necessary for program before the
// main.

/* Swaps the value of two items in the array by pointing
 to their locations and swapping the values stored there.*/
void ReversePointers(float *firstLocation, float *secondLocation) {
  int newLocation = *firstLocation;
  *firstLocation = *secondLocation;
  *secondLocation = newLocation;
}

/* Uses the original array and index positions to repeatedly swap the items in
each index position using the function from above.*/

void ReverseArray(float valueCollection[], int arraySize) {

  float *firstLocation = valueCollection;
  float *secondLocation = valueCollection + arraySize - 1;

  while (firstLocation < secondLocation) {
    ReversePointers(firstLocation, secondLocation);
    firstLocation++;
    secondLocation--;
  }
}

/* Collects all added user values, divides by length of the array, and returns
 the average*/

float CalculateAverage(float averageValue, float addedValues, int size) {
  averageValue = addedValues / size;
  return averageValue;
}

/*Prints index position, value, and distance from average for every value in
array*/

float FindDeviation(float array[], float average, int size) {
  float deviation;
  printf("%s%16s%21s\n", "Index", "Value", "Deviation");
  for (int i = 0; i < size; i++) {
    deviation = average - array[i];
    if (deviation < 0) {
      deviation = -deviation;
    }

    printf("[%i]%17.2f%17.2f\n", i, array[i], deviation);
  }
  return deviation;
}

int main() {
  // Declare and initialize variable needed to hold values for averaging.
  // Declare and initialize variable to determine array size. This is also the
  // sentinel value checker.
  int arraySize;
  printf("How many values would you like to place in your array? Enter -1 to "
         "end the program.\n");
  scanf("%i", &arraySize);
  // Continue loop while sentinel value is not chosen.
  while (arraySize != -1) {
    addedValues = 0;
    averageValue = 0;

    float valueCollection[arraySize];
    // Declares and initializes new array based on user value for length.
    /* Each time the loop runs, the user value is added to the array.
     Also adds the values to a running total to be used for average later. */
    for (size_t i = 0; i < arraySize; i++) {
      printf("Enter a value: ");
      scanf("%2f", &valueCollection[i]);
      addedValues += valueCollection[i];
    }
    int *length = &arraySize;
    // Prints the initial values input by user in array.
    printf("Initial array is: {");
    for (int i = 0; i < arraySize; i++) {
      /*If-statement just determines is we need to put a comma or not
       based on the index position */
      if (i == 0) {
        printf("%.2f", valueCollection[i]);
      } else {
        printf(", %.2f", valueCollection[i]);
      }
    }
    printf("}\n");

    // Reverses the array using the starting and ending indices in the array.
    ReverseArray(valueCollection, arraySize);
    // Prints the newly reversed array.
    printf("Reversed Array is: {");
    for (int i = 0; i < arraySize; i++) {
      /* If statement just determines if we need to include a comma or not
       based on the index position.*/
      if (i == 0) {
        printf("%.2f", valueCollection[i]);
      } else {
        printf(", %.2f", valueCollection[i]);
      }
    }
    printf("}\n");
    /* Displays the average by returning the result of the CalculateAverage
  function into the print function.*/
    printf("Average Value of the array is: %.2f \n",
           CalculateAverage(averageValue, addedValues, arraySize));

    /*Outputs the distance of each value from the average by returning the
    results of the FindDeviation function into the printf function.*/
    printf("Distance of each number in reversed array from the average: \n");
    FindDeviation(valueCollection,
                  CalculateAverage(averageValue, addedValues, arraySize),
                  arraySize);
    printf("How many values would you like to place in your array? Enter -1 to "
           "end the program.\n");
    scanf("%i", &arraySize);
  }
}

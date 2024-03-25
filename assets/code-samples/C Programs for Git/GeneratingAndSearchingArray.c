#include <stdio.h>
#include <stdlib.h>

int valueCollection[7];
int searchedValue;
int arraySize = 7;
int containsValue = 0;

int FindValue();

int main() {

  // Filling the array with values. Each time the loop runs,
  // the index position is multiplied by 5, added to the array,
  // and incremented to the next index.
  // When it reaches the maximum array length, the loop ends.
  for (int i = 0; i < arraySize; i++) {
    valueCollection[i] = i * 5;
  }

  // Running the function to search the array.
  FindValue();
  return 0;
}

/
int FindValue() {
  // Prompting user to give us a value to search.
  printf("Type a number to find in the array: \n");
  scanf("%i", &searchedValue);
  // Looping through the array to find a match. If we find a match, we break the
  // loop, toggle our containsValue switch, and print the resulting index
  // position.
  for (int i = 0; i < arraySize; i++) {
    if (valueCollection[i] == searchedValue) {
      containsValue = 1;
      printf("I found your value in index %d \n", i);
    }
  }
  // If we didn't find a value, the containsValue switch doesn't change,
  // and we will print our default message.
  if (containsValue == 0) {
    printf("Your value was not found in this array.\n");
  }
  return 0;
}

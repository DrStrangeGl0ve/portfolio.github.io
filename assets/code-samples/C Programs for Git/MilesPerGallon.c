
#include <stdio.h>
#include <stdlib.h>

int main() {

  float gallonsUsed;
  float milesDriven;
  float milesPerGallon;
  float combinedMilesPerGallon = 0;
  float totalMeasuredTanks = 0;
  float averageMilesPerGallon;

  printf("Enter the gallons used (-1 to end): \n");
  scanf("%f", &gallonsUsed);

  while (gallonsUsed != -1) {

    printf("Enter the miles driven: \n");
    scanf("%f", &milesDriven);
    milesPerGallon = milesDriven / gallonsUsed;
    printf("The miles/gallon for this tank was %.2f \n", milesPerGallon);
    combinedMilesPerGallon += milesPerGallon;
    totalMeasuredTanks++;

    printf("Enter the gallons used (-1 to end): \n");
    scanf("%f", &gallonsUsed);
  }

  averageMilesPerGallon = combinedMilesPerGallon / totalMeasuredTanks;
  printf("Average miles-per-gallon for all tanks is %.2f \n",
         averageMilesPerGallon);
  return 0;
  system("pause");
}

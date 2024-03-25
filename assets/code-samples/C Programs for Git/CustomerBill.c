#include <stdio.h>
#include <stdlib.h>




//Intended to calculate the total cost of a customer bill depending on the amount of specific items purchased. Includes sales tax for Texas.

 




//declaring calculation function
int CalculateBill();



int main() {

    

    //using calculation function
    CalculateBill();
    //stops program so viewer has time to look at results.
    system("pause");
    return 0;

}

//inititializing calculation function
int CalculateBill() {

//local variables storing data for quantity sold, unit cost, total cost, tax, subtotal, and total. Possibly too many variables, but I like the flexibility.
    float tvTotalPrice;
    float vcrTotalPrice;
    float remoteTotalPrice;
    float cdPlayerTotalPrice;
    float recorderTotalPrice;
    float salesTax;
    float subtotal;;
    float totalCost;
    int tvQuantity;
    int vcrQuantity;
    int remoteQuantity;
    int cdPlayerQuantity;
    int recorderQuantity;
    const float tvUnitPrice = 400.00f;
    const float vcrUnitPrice = 220.00f;
    const float remoteUnitPrice = 35.20f;
    const float cdPlayerUnitPrice = 300.00f;
    const float recorderUnitPrice = 150.00f;
    const float taxRate = .0825f;
    print_f("How many TV's were sold? \n");
    scan_f("%d", &tvQuantity);
    tvTotalPrice = tvQuantity * tvUnitPrice;
//checks for quantity sold and calculates total paid for tvs. Same below for other products.
    print_f("How many VCRs were sold? \n");
    scan_f("%d", &vcrQuantity);
    vcrTotalPrice = vcrQuantity * vcrUnitPrice;
    print_f("How many remote controllers were sold? \n");
    scan_f("%d", &remoteQuantity);
    remoteTotalPrice = remoteQuantity * remoteUnitPrice;
    print_f("How many CD Players were sold? \n");
    scan_f("%d", &cdPlayerQuantity);
    cdPlayerTotalPrice = cdPlayerQuantity * cdPlayerUnitPrice;
    print_f("How many tape recorders were sold? \n");
    scan_f("%d", &recorderQuantity);
    print_f("\n");
    recorderTotalPrice = recorderQuantity * recorderUnitPrice;
//calculates subtotal, sales tax, and total. Then prints the remainder of the reciept.
    subtotal = tvTotalPrice +  vcrTotalPrice + remoteTotalPrice + cdPlayerTotalPrice + recorderTotalPrice;
    salesTax = subtotal * taxRate;
    totalCost = subtotal + salesTax;
    

//prints a reciept listing categories including quantity, item name, price, and total price. There has to be an easier way to do this.
//I used %3i when injecting the integers for quantity so that I could retain alignment for up to 999 unit sales. I could go further if necessary. 

    print_f("Quantity             Item                Price               Total Price \n");
    print_f("_________________________________________________________________________\n");
    print_f("_________________________________________________________________________\n");
    print_f("%3i                    Television          $%.2f             $%.2f \n", tvQuantity, tvUnitPrice, tvTotalPrice);
    print_f("%3i                    VCR                 $%.2f             $%.2f \n", vcrQuantity, vcrUnitPrice, vcrTotalPrice);
    print_f("%3i                    Remote Controller   $%.2f              $%.2f \n", remoteQuantity, remoteUnitPrice, remoteTotalPrice);
    print_f("%3i                    CD Player           $%.2f             $%.2f \n", cdPlayerQuantity, cdPlayerUnitPrice, cdPlayerTotalPrice);
    print_f("%3i                    Tape Recorder       $%.2f             $%.2f \n", recorderQuantity, recorderUnitPrice, recorderTotalPrice);
    print_f("_________________________________________________________________________\n");
    print_f("                                     Subtotal:               $%.2f \n", subtotal);
    
    print_f("                                     Tax:                    $%.2f \n", salesTax);
   
    print_f("                                     Total:                  $%.2f \n", totalCost);

    return 0;
}


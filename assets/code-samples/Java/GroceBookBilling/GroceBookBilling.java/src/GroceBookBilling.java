import java.util.Scanner;
//Creates a class GroceBookBilling to calculate cost of book receipt using overloaded methods.
//Did some extra work to make sure that it always rounded and output the correct cent.
public class GroceBookBilling {
    private static final double taxRate = 0.0825;
    //tax rate won't be changing, so it's a constant.

    //First declaration of the method only requires price of the book. Outputs price with tax.
    public double computeBill(double price) {
        return Math.round((price + (price * taxRate)) * 100.0) / 100.0;
    }
    //Second declaration of the method requires price and quantity of the book. Outputs price with tax.
    public double computeBill(double price, int quantity) {
        return Math.round((price * quantity + (price * quantity * taxRate)) * 100.0) / 100.0;
    }
    //Third declaration of the method requires price, quantity, and coupon value. Outputs price with tax.
    public double computeBill(double price, int quantity, double coupon) {
        double subtotal;
        subtotal = (price * quantity) - coupon;
        return Math.round((subtotal + (subtotal * taxRate)) * 100.0) / 100.0;
    }
    //Main method tests the class by calling the function with different parameters and outputting the results to the console.
    public static void main(String[] args) {
        Scanner userInput = new Scanner(System.in);
        GroceBookBilling bookBilling = new GroceBookBilling();

        System.out.println("Enter the price of the photo book:");
        double price;
        price = userInput.nextDouble();
        System.out.println("The total due for one book is: " + String.format("%.2f", bookBilling.computeBill(price)));

        System.out.println("Enter the quantity:");
        int quantity;
        quantity = userInput.nextInt();
        System.out.println("The total due for " + quantity + " books is: " + String.format("%.2f",  bookBilling.computeBill(price, quantity)));

        System.out.println("Enter the coupon value:");
        double coupon;
        coupon = userInput.nextDouble();
        System.out.println("The total due for " + quantity + " books with coupon is: " + String.format("%.2f", bookBilling.computeBill(price, quantity, coupon)));
        //Closes the scanner to prevent memory leakage.
        userInput.close();
    }
}
"use strict";
const $ = selector => document.querySelector(selector);

/*********************
*  helper functions  *
**********************/
const calculateCelsius = temp => (temp - 32) * 5 / 9;
const calculateFahrenheit = temp => temp * 9 / 5 + 32;

// changes the labels of the boxes and clears the result box when radio buttons are clicked.
const toggleDisplay = (label1Text, label2Text) => {
    $("#degree_label_1").textContent = label1Text;
    $("#degree_label_2").textContent = label2Text;
    $("#degrees_computed").value = "";
    $("#degrees_entered").value = ""; 
     
}

/****************************
*  event handler functions  *
*****************************/

const convertTemp = () => {
    const temp = parseFloat($("#degrees_entered").value);
    const conversionType = document.querySelector('input[name="conversion_type"]:checked').id;
    const message = $("#message");
    const result = $("#degrees_computed");

    //validates the input to confirm that it is a number, if not prompts to try again and clears the result box.
    if (isNaN(temp)) {
        message.textContent = "Please enter a valid number.";
        result.value = "";
    } else {
        //ensures that no error message is given when a valid number is entered.
        message.textContent = "";
        //converts the temperature using the correct function if the correct radio button is selected.
        //assumes Fahrenheit if no change is made.
        if (conversionType === "to_celsius") {
            result.value = calculateCelsius(temp).toFixed(0);
        } else if (conversionType === "to_fahrenheit") {
            result.value = calculateFahrenheit(temp).toFixed(0);
        }
    }
};
// change the labels and clear the result box
const toCelsius = () => toggleDisplay("Enter F degrees:", "Degrees Celsius:");
const toFahrenheit = () => toggleDisplay("Enter C degrees:", "Degrees Fahrenheit:");

document.addEventListener("DOMContentLoaded", () => {
    // clear input and result when page loads
    $("#degrees_entered").value = "";
    $("#degrees_computed").value = "";
    
    // event handlers for clicked buttons
    $("#convert").addEventListener("click", convertTemp);
    $("#to_celsius").addEventListener("click", toCelsius);
    $("#to_fahrenheit").addEventListener("click", toFahrenheit);

    //clears the input and output boxes when clicked
    $("#degrees_entered").addEventListener("click", () => {
        $("#degrees_entered").value = "";
        $("#degrees_computed").value = "";
    });

    
});
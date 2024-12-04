"use strict";

const $ = selector => document.querySelector(selector);

const getErrorMsg = lbl => `${lbl} must be a valid number greater than zero.`;

const focusAndSelect = selector => {
    const elem = $(selector);
    elem.focus();
    elem.select();
};

const processEntries = () => {
    const miles = parseFloat($("#miles").value);
    const gallons = parseFloat($("#gallons").value);

    if (isNaN(miles) || miles <= 0) {
        alert(getErrorMsg("Miles driven"));
        focusAndSelect("#miles");
    } else if (isNaN(gallons) || gallons <= 0) {
        alert(getErrorMsg("Gallons of gas used"));
        focusAndSelect("#gallons");
    } else {
        $("#mpg").value = (miles / gallons).toFixed(2);
    }
};

var clearEntries = () => {
    $("#miles").value = "";
    $("#gallons").value = "";
    $("#mpg").value = "";
};

document.addEventListener("DOMContentLoaded", () => {

    //Added listeners to clear a the miles and Gallons boxes if the user clicks on them.
    //This will allow the user to enter new values without having to delete the old ones.
    $("#miles").addEventListener("focus", () => {
        $("#miles").value = "";
    });
    $("#gallons").addEventListener("focus", () => {
        $("#gallons").value = "";
    });
    
    //Added listeners to each element to clear all text boxes on double click.
    $("#mpg").addEventListener("dblclick", clearEntries);
    $("#miles").addEventListener("dblclick", clearEntries);
    $("#gallons").addEventListener("dblclick", clearEntries);
    

    // Calculate MPG when focus leaves the Gallons of Gas Used text box
    $("#gallons").addEventListener("blur", processEntries);
});
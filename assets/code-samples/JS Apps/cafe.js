
const menu = [
    'images/espresso_info.jpg',
    'images/latte_info.jpg',
    'images/cappuccino_info.jpg',
    'images/coffee_info.jpg',
    'images/biscotti_info.jpg',
    'images/scone_info.jpg'
];

menu.forEach(src => {
    const menuImage = new Image();
    menuImage.src = src;
});


document.addEventListener('DOMContentLoaded', () => {
    const menuItems = document.querySelectorAll('#menu img');
    const orderButton = document.getElementById('place_order');
    const clearButton = document.getElementById('clear_order');
    menuItems.forEach(item => {
        item.addEventListener('mouseover', defaultMenuImage);
        item.addEventListener('mouseout', infoMenuImage);
        item.addEventListener('click', addToOrder);
    });
    clearButton.addEventListener('click', () => {
        clearOrder();
    });
    orderButton.addEventListener('click', () => {
        window.location.href = "/checkout.html";
        
    });
    
});

function defaultMenuImage(event) {
    const menuImage = event.target;
    menuImage.dataset.defaultImage = menuImage.src; 
    menuImage.src = menuImage.id; 
}

function infoMenuImage(event) {
    const menuImage = event.target;
    menuImage.src = menuImage.dataset.defaultImage; 
}

function addToOrder(event) {
    const menuImage = event.target;
    const itemName = menuImage.alt;
    const itemPrice = getPrice(menuImage.id);
    const orderSelect = document.getElementById('order');
    const newItem = document.createElement('option');
    newItem.text = `$${itemPrice.toFixed(2)} - ${itemName}`;
    newItem.value = itemPrice; 
    orderSelect.add(newItem);
    updateTotal(itemPrice);
}

function getPrice(menuID) {
    switch (menuID) {
        case 'images/espresso_info.jpg':
            return 1.95;
        case 'images/latte_info.jpg':
            return 2.95;
        case 'images/cappuccino_info.jpg':
            return 3.45;
        case 'images/coffee_info.jpg':
            return 1.75;
        case 'images/biscotti_info.jpg':
            return 1.95;
        case 'images/scone_info.jpg':
            return 2.95;
        default:
            return 0.00;
    }
}

let total = 0;

function updateTotal(itemPrice) {
    total += itemPrice;
    document.getElementById('total').textContent = `Total: $${total.toFixed(2)}`;
}

function clearOrder() {
    const orderSelect = document.getElementById('order');
    while (orderSelect.length > 0) {
        orderSelect.remove(0);
    }
    total = 0;
    document.getElementById('total').textContent = 'Total: $0.00';
}
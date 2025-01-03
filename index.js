document.addEventListener('DOMContentLoaded', function() {
    const buttons = document.querySelectorAll('.portfolio__button-group .button');
    
    buttons.forEach(button => {
        button.addEventListener('click', function(event) {
            event.preventDefault(); 
            
            // Remove any existing collapsible container
            const existingContainer = document.querySelector('.collapsible-container');
            if (existingContainer) {
                existingContainer.remove();
            }

            // Create a new collapsible container
            const collapsibleContainer = document.createElement('div');
            collapsibleContainer.classList.add('collapsible-container');
            collapsibleContainer.innerHTML = `
                <button id="minimize-button" class="button button--default minimize-button">X</button>
                <div id="content"></div>
            `;

            // Insert the collapsible container after the clicked button's section
            button.closest('.portfolio__button-group').after(collapsibleContainer);

            // Add event listener for the minimize button
            const minimizeButton = collapsibleContainer.querySelector('#minimize-button');
            minimizeButton.addEventListener('click', function() {
                collapsibleContainer.style.display = 'none';
            });

            // Update the filePath based on the button clicked
            let filePath;
            switch (button.textContent.trim()) {
                // Java Cases
                case 'WATER WELL':
                    filePath = 'assets/code-samples/Java/Waterwell.txt';
                    break;
                case 'BOOK BILLING':
                    filePath = 'assets/code-samples/Java/GroceBookBilling.txt';
                    break;
                case 'GRADEBOOK':
                    filePath = 'assets/code-samples/Java/Gradebook.txt';
                    break;
                // Python Cases
                case 'NUMBER RANGE':
                    filePath = 'assets/code-samples/Python/number_range.py';
                    break;
                case 'RIOT GAME DATA':
                    filePath = 'assets/code-samples/Python/game_data.py';
                    break;
                case 'FLASK DEPLOYMENT':
                    filePath = 'assets/code-samples/Python/flask.py';
                    break;
                // JavaScript Cases
                case 'STORE PAGE':
                    filePath = 'assets/code-samples/JS Apps/cafe.js';
                    break;
                // C Cases
                case 'BUILD & SEARCH ARRAY':
                    filePath = 'assets/code-samples/C Programs for Git/GeneratingAndSearchingArray.c';
                    break;
                case 'CUSTOMER BILL':
                    filePath = 'assets/code-samples/C Programs for Git/CustomerBill.c';
                    break;
                case 'PAYROLL BY POSITION':
                    filePath = 'assets/code-samples/C Programs for Git/PayrollPositions.c';
                    break;
                case 'REVERSE & AVERAGE ARRAY':
                    filePath = 'assets/code-samples/C Programs for Git/ReversingAndAveragingArrays.c';
                    break;
                case 'MPG':
                    filePath = 'assets/code-samples/C Programs for Git/MilesPerGallon.c';
                    break;
                default:
                    filePath = ''; 
                
            }

            if (filePath) {
                fetch(filePath)
                    .then(response => response.text())
                    .then(data => {
                        const content = collapsibleContainer.querySelector('#content');
                        content.innerHTML = `<pre><code>${escapeHtml(data)}</code></pre>`;
                        collapsibleContainer.style.display = 'block';
                    })
                    .catch(error => console.error('Error fetching the file:', error));
            } else if (button.textContent.trim() === 'MPG APP') {
                collapsibleContainer.id = 'mpg-app';
                const content = collapsibleContainer.querySelector('#content');
                content.innerHTML = `
                    <main>
                        <h1>Miles Per Gallon Calculator</h1>
                        <div>
                            <label for="miles">Miles Driven:</label>
                            <input type="text" id="miles">
                        </div>
                        <div>
                            <label for="gallons">Gallons of Gas Used:</label>
                            <input type="text" id="gallons">
                        </div>
                        <div>
                            <label for="mpg">Miles Per Gallon:</label>
                            <input type="text" id="mpg">
                        </div>
                        <div>
                            <label>&nbsp;</label>
                            <input type="button" id="calculate" value="Calculate MPG">
                        </div>
                    </main>
                `;
                collapsibleContainer.style.display = 'block';

                // Add event listener for the calculate button
                document.getElementById('calculate').addEventListener('click', function() {
                    const miles = parseFloat(document.getElementById('miles').value);
                    const gallons = parseFloat(document.getElementById('gallons').value);
                    const mpg = miles / gallons;
                    document.getElementById('mpg').value = mpg.toFixed(2);
                });
            }
        });
    });
});

function escapeHtml(unsafe) {
    return unsafe
        .replace(/&/g, "&amp;")
        .replace(/</g, "&lt;")
        .replace(/>/g, "&gt;")
        .replace(/"/g, "&quot;")
        .replace(/'/g, "&#039;");
}
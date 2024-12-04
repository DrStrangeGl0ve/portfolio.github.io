document.addEventListener('DOMContentLoaded', function() {
    const buttons = document.querySelectorAll('.portfolio__button-group .button');
    const collapsibleContainer = document.getElementById('collapsible-container');
    const minimizeButton = document.getElementById('minimize-button');
    const mpgAppButton = document.getElementById('mpg-app-button');

    buttons.forEach(button => {
        button.addEventListener('click', function(event) {
            event.preventDefault(); // Prevent the default link behavior

            // Update the filePath based on the button clicked
            let filePath;
            switch (button.textContent.trim()) {
                case 'Water Well':
                    filePath = 'assets/code-samples/Java/Lab 1/src/Waterwell.txt';
                    break;
                case 'Book Billing':
                    filePath = 'assets/code-samples/Java/GroceBookBilling.txt';
                    break;
                case 'Gradebook':
                    filePath = 'assets/code-samples/Java/Gradebook.txt';
                    break;
                default:
                    filePath = ''; // Default to an empty path if no match
            }

            if (filePath) {
                fetch(filePath)
                    .then(response => response.text())
                    .then(data => {
                        collapsibleContainer.innerHTML = `<pre><code>${escapeHtml(data)}</code></pre>`;
                        collapsibleContainer.appendChild(minimizeButton); // Re-append the minimize button
                        collapsibleContainer.style.display = 'block';
                    })
                    .catch(error => console.error('Error fetching the file:', error));
            }
        });
    });

    mpgAppButton.addEventListener('click', function(event) {
        event.preventDefault(); // Prevent the default link behavior
        collapsibleContainer.innerHTML = `
            <button id="minimize-button" class="button button--default minimize-button">X</button>
            <div id="mpg-app">
            <main>
                <h1>The Miles Per Gallon Calculator</h1>
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
        collapsibleContainer.appendChild(minimizeButton); // Re-append the minimize button
        collapsibleContainer.style.display = 'block';

        // Add event listener for the calculate button
        document.getElementById('calculate').addEventListener('click', function() {
            const miles = parseFloat(document.getElementById('miles').value);
            const gallons = parseFloat(document.getElementById('gallons').value);
            const mpg = miles / gallons;
            document.getElementById('mpg').value = mpg.toFixed(2);
        });
    });

    minimizeButton.addEventListener('click', function() {
        collapsibleContainer.style.display = 'none';
    });

    function escapeHtml(unsafe) {
        return unsafe
            .replace(/&/g, "&amp;")
            .replace(/</g, "&lt;")
            .replace(/>/g, "&gt;")
            .replace(/"/g, "&quot;")
            .replace(/'/g, "&#039;");
    }
});
document.addEventListener("DOMContentLoaded", () => {
    const toggleButton = document.getElementById("toggle-light-mode");

    toggleButton.addEventListener("click", () => {
        document.body.classList.toggle("light-mode");
    });
});
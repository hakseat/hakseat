const seats = document.querySelectorAll(".seat");

seats.forEach(seat => {
    seat.addEventListener("click", () => {
        if (!seat.classList.contains("selected")) {
            const seatNumber = seat.dataset.seatNumber;
            seat.classList.add("selected");
            seat.textContent = seatNumber;
        } else {
            seat.classList.remove("selected");
            seat.textContent = "";
        }
    });
});
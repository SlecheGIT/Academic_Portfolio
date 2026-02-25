const checkbox = document.getElementById("checkbox");
const cbox = document.querySelector(".checkbox");

if (localStorage.getItem("theme") === null) {
  localStorage.setItem("theme", 0);
  cbox.checked = false;
}

if (localStorage.getItem("theme") == 0) {
  cbox.checked = false;
  document.body.classList.toggle("white");
} else {
  cbox.checked = true;
  document.body.classList.toggle("dark");
}

checkbox.addEventListener("change", () => {
  if (localStorage.getItem("theme") == 0) {
    document.body.classList.remove("white");
    document.body.classList.add("dark");
    cbox.checked = true;
    localStorage.setItem("theme", 1);
  } else {
    document.body.classList.remove("dark");
    document.body.classList.add("white");
    cbox.checked = false;
    localStorage.setItem("theme", 0);
  }
});

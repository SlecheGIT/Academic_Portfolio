const button = document.querySelector("button")
const titulo = document.querySelector(".titulo")
button.addEventListener("click",()=>{
    titulo.innerHTML=Math.random()
})
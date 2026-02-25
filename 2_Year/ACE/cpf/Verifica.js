let cpf = prompt("Digite o cpf: ");
let verifica = true;

if (cpf.length == 14) 
{
    for (let i = 0; i < 14; i++) 
    {
// verifica as posições que deveriam ter 
// pontos.
        if ((i == 3) || (i == 7)) {
            if (cpf[i] != '.') 
                verifica = false;
        } 
// verifica a posição que deveria ter um 
// traço.
        else if (i == 11) {
            if (cpf[i] != '-') 
                verifica = false;
        } 
// caso não seja nenhuma posição de 
// caracteres especiais verifica se 
// não é um numero.
        else if (isNaN(cpf[i])) {
            verifica = false;
        }
    }
} else 
    verifica = false;


if (verifica == true)
    alert("CPF válido");
else 
    alert("CPF inválido");
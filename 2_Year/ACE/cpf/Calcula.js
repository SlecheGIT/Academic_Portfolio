let cpf_char = prompt("Digite o cpf: ");
let valido = true;

if (cpf_char.length == 14) 
{
    for (let i = 0; i < 14; i++) 
    {
// valido as posições que deveriam ter 
// pontos.
        if ((i == 3) || (i == 7)) {
            if (cpf_char[i] != '.') 
                valido = false;
        } 
// valido a posição que deveria ter um 
// traço.
        else if (i == 11) {
            if (cpf_char[i] != '-') 
                valido = false;
        } 
// caso não seja nenhuma posição de 
// caracteres especiais valido se 
// não é um numero.
        else if (isNaN(cpf_char[i])) {
            valido = false;
        }
    }
} else 
    valido = false;

let cpf = [], verificadores = []; // strings
let soma, divisao, resto; // calculos
let i, aux; // operadores

if (valido == true)
{
    // aloca os digitos em um novo vetor valor numerico
    for (i = 0; i < cpf_char.length; i++) 
    {
        if (!isNaN(cpf_char[i])) 
            cpf.push(parseInt(cpf_char[i]));
    }

    // retira os dois ultimos digitos do vetor em ordem decrecente
    verificadores.push(cpf.pop())
    verificadores.push(cpf.pop())
    
    // soma todos os digitos com seus multiplicadores
    i = 10
    soma = cpf.reduce((soma, digito) => soma + digito * i--, 0)

    // calcula a divisão e modulo de 11
    divisao = soma / 11
    resto = soma % 11

    // calcula o 1° digito verificador
    if (resto < 2) 
        cpf.push(0);
    else
        cpf.push(11 - resto); 
    // ! 11- resto assim sempre sobrara uma unidade !

    // verificação se continuará a operação para o 2°digito
    if(cpf[cpf.length-1] == verificadores.pop())   
    {
        i = 11
        soma = cpf.reduce((soma, digito) => soma + digito * i--, 0)
        divisao = soma / 11
        resto = soma % 11

        if (resto < 2) 
            cpf.push(0);
        else
            cpf.push(11 - resto); 

        if(cpf[cpf.length-1] != verificadores.pop())   
            valido = false
    }
    else
        valido = false
}
if (valido) 
    alert("CPF válido");
else 
    alert("CPF inválido");

% Caso base: Fibonacci de 0 é 0
fib(0, 0).

% Caso base: Fibonacci de 1 é 1
fib(1, 1).

% Caso recursivo: Fibonacci de N é a soma dos dois anteriores
fib(N, F) :-
    N > 1,              % Garantir que N é maior que 1
    N1 is N - 1,        % Calcula o índice do termo anterior
    N2 is N - 2,        % Calcula o índice do termo antes do anterior
    fib(N1, F1),        % Calcula o Fibonacci do termo anterior
    fib(N2, F2),        % Calcula o Fibonacci do termo antes do anterior
    F is F1 + F2.       % Soma os dois valores
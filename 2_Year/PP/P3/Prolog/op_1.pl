f91(N,Result):-
    N >= 101,
    Result is N-10.

f91(N,Result):-
    N =< 100,
    f91(N+11,Prox),
    f91(Prox,Result).

fat(1,1).
fat(I,Result):-
    I>1,
    I2 is I-1,
    fat(I2,N1),
    Result is N1 * I.

fib(0,0).
fib(1,1).
fib(I,Result):-
    I1 is I-1,
    I2 is I-2,
    fib(I1,F1),
    fib(I2,F2),
    Result is F1 + F2.

% Caso base: lista vazia resulta em duas listas vazias
separa([], [], []).

% Caso o elemento seja um número
separa([H|T], Letras, [H|Numeros]) :-
    integer(H),               % Verifica se H é um número
    separa(T, Letras, Numeros).

% Caso o elemento seja uma letra
separa([H|T], [H|Letras], Numeros) :-
    \+ integer(H),            % Verifica se H não é um número (então é uma letra)
    separa(T, Letras, Numeros).

remover(X,[X|C],C).
remover(X,[Y|C],[Y|D]):- remover(X,C,D).

tamanho([],0).
tamanho([_|C],X):-
    tamanho(C,Y),
    X is Y+1.

soma([],0).
soma([X|C],S):-
    soma(C,Y),
    S is X+Y.

produto([],1).
produto([X|C],S):-
    produto(C,Y),
    S is X*Y.

first([X|_],X).

last([X|[]],X).
last([_|C],X):-last(C,X).

numbers([]).
numbers([X|C]):-
    integer(X),
    numbers(C).

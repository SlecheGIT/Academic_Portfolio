%fatos

idade(alberto,11).
idade(bianca,12).
idade(celia,27).
idade(divaldo,28).
idade(ermenegildo,62).
idade(filomena,60).
idade(gilberto,64).
idade(hanna,63).

mae(hanna,celia).
mae(celia,bianca).
mae(celia,alberto).
mae(filomena,divaldo).

pai(divaldo,alberto).
pai(divaldo,bianca).
pai(ermenegildo,divaldo).
pai(gilberto,celia).

casado(divaldo,celia).
casado(ermenegildo,filomena).
casado(gilberto,hanna).

%regras

irmao(X,Y):- ((pai(Z,X),pai(Z,Y)) ; (mae(Z,X),mae(Z,Y))),X\=Y.

avo_pai(X,Y):- (pai(X,Z) , (pai(Z,Y) ; mae(Z,Y))).

avo_mae(X,Y):- (mae(X,Z) , (mae(Z,Y) ; pai(Z,Y))).

descendente(X,Y):- pai(X,Y);mae(X,Y).
descendente(X,Y):-
    (pai(X,Z);mae(X,Z)),
    descendente(Z,Y).
% ^
ascendente(X,Y):- pai(Y,X);mae(Y,X).
ascendente(X,Y):-
    (pai(Z,X);mae(Z,X)),
    ascendente(Z,Y).

mais_velho_que(X,Y):- (idade(X,A),idade(Y,B)),A>B.

mais_novo_que(Y,X):- (idade(Y,A),idade(X,B)),A<B.


%fib
fib(0,0).
fib(1,1).
fib(I,F):-
    I>1,
    I1 is I-1,
    I2 is I-2,
    fib((I1),F1),
    fib((I2),F2),
    F is F1 + F2.

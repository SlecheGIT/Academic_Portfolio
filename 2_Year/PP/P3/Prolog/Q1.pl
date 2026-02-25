% Fatos
idade(alberto, 11).
idade(bianca, 12).
idade(celia, 27).
idade(divaldo, 28).
idade(ermenegildo, 62).
idade(filomena, 60).
idade(gilberto, 64).
idade(hanna, 63).

pai(divaldo, alberto).
pai(divaldo, bianca).
pai(gilberto, celia).
pai(ermenegildo, divaldo).

mae(celia, alberto).
mae(celia, bianca).
mae(hanna, celia).
mae(filomena, divaldo).

casado(celia, divaldo).
casado(divaldo, celia).
casado(ermenegildo, filomena).
casado(filomena, ermenegildo).
casado(gilberto, hanna).
casado(hanna, gilberto).


% Regras
irmao(X, Y) :- mae(M, X), mae(M, Y), X \== Y.

avo_masc(X, Y) :- pai(X, Z), (pai(Z, Y); mae(Z, Y)).

avo_fem(X, Y) :- mae(X, Z), (pai(Z, Y); mae(Z, Y)).

% Recursão em descendente
descendente(X, Y) :- pai(Y, X); mae(Y, X). %(X é descendente de Y) se (Y é (pai ou mãe) de X)
descendente(X, Y) :- pai(Z, X), descendente(Z, Y).
descendente(X, Y) :- mae(Z, X), descendente(Z, Y).

ascendente(X, Y) :- descendente(Y, X). %(X é ascendente de Y) se (Y é descendente de X)

mais_velho_que(X, Y) :- idade(X, IdadeX), idade(Y, IdadeY), IdadeX > IdadeY.

mais_novo_que(X, Y) :- mais_velho_que(Y, X). %(X é mais novo que Y) se (Y é mais velho que X)

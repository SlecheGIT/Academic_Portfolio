fatorial(X, F):- X =< 1, F is 1.
fatorial(X, F):-
	X > 1,
	X1 is X - 1,
	fatorial(X1, F1),
	F is X * F1.
	

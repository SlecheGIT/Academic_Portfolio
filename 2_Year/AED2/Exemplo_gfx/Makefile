
make:
	rm exe ; gcc -o exe exemplo.c -I./gfx -L./gfx -lgfx -lSDL -lSDL_gfx -lSDL_ttf -Wall -Wextra -pedantic ; ./exe

exemplo:
	gcc -o exemplo exemplo.c -I$(PWD)/gfx -L$(PWD)/gfx -lgfx -lSDL -lSDL_gfx -lSDL_ttf -Wall -Wextra -pedantic

clean:
	rm exemplo *~

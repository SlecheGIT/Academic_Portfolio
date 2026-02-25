#include "gfx.h"
#include <stdio.h> // printf
#include <unistd.h> // sleep 
#include <stdbool.h> //decisao booleana

#define curva 200 // div 2, curva = 100, valor inicial


void circulo (int x, int y, int rxy, int nivel, int ab) 
{
	ab /= 2;                                    // valores do primeiro loop

	gfx_ellipse((x+ab), (y-ab), rxy/2, rxy/2); // 400, 200, 140, 140
	if (nivel>0)
		circulo(x+ab, y-ab, rxy/2, nivel-1, ab);


	gfx_ellipse((x-ab), (y-ab), rxy/2, rxy/2); // 200, 200, 140, 140
	if (nivel>0)
		circulo(x-ab, y-ab, rxy/2, nivel-1, ab);


	gfx_ellipse((x-ab), (y+ab), rxy/2, rxy/2); // 200, 400, 140, 140
	if (nivel>0)
		circulo(x-ab, y+ab, rxy/2, nivel-1, ab);


	gfx_ellipse((x+ab), (y+ab), rxy/2, rxy/2); // 400, 400, 140, 140
	if (nivel>0)
		circulo(x+ab, y+ab, rxy/2, nivel-1, ab);
	/*
	   formula = (x & y) -+ distancia relativa em comum
	   - or + baseado nos quadrantes em que se encontram
	   +x  -y = primeiro quadrante
	   -x  -y = segundo quadrante
	   -x  +y = terceiro quadrante
	   +x  +y = quarto quadrante
	*/
}

void quadrado (int x1, int y1, int x2, int y2, int nivel, int indice) {

	int inteiro = x2-x1;
	int meio = inteiro/2;
	int quarto = meio/2;

	if (indice !=3) // se a o quadrado de baixo foi feito por ultimo o de cima não sera executado
	{ 
		gfx_rectangle((x1+quarto), (y1-meio), (x2-quarto), (y2-inteiro));  //up = 1
		if (nivel>0)
			quadrado((x1+quarto), (y1-meio), (x2-quarto), (y2-inteiro), nivel-1, 1);
	}


	if (indice !=4) // se a o quadrado da esquerda foi feito por ultimo o da direita não sera executado
	{
		gfx_rectangle((x1+inteiro), (y1+quarto), (x2+meio), (y2-quarto));  //right = 2
		if (nivel>0)
			quadrado((x1+inteiro), (y1+quarto), (x2+meio), (y2-quarto), nivel-1, 2);
	}


	if (indice !=1) // se a o quadrado de cima foi feito por ultimo o de baixo não sera executado
	{	
		gfx_rectangle((x1+quarto), (y1+inteiro), (x2-quarto), (y2+meio));  //down = 3
		if (nivel>0)
			quadrado((x1+quarto), (y1+inteiro), (x2-quarto), (y2+meio), nivel-1, 3);
	}


	if (indice !=2) // se a o quadrado da direita foi feito por ultimo o da esquerda não sera executado
	{
		gfx_rectangle((x1-meio), (y1+quarto), (x2-inteiro), (y2-quarto));  //left = 4
		if (nivel>0)
			quadrado((x1-meio), (y1+quarto), (x2-inteiro), (y2-quarto), nivel-1, 4);
	}

}

int main()
{
	//variaveis do menu
	int choise = 1, nivel = 0; 
	bool pass = false;
	
	int x=300, y=x, rxy=280; // variaveis do circulo
	int x1=200, y1=x1, x2=400, y2=x2; //variaveis do quadrado
	
	// obtendo configuraçoes {
	 do {		
		printf("(1)círculo ou (2)retângulo\n--> ");
		scanf("%d", &choise);

		printf("\n\nnível de recursão? (valor de 0 a 10)\n--> ");
		scanf("%d", &nivel), printf("\n\n");	

		if ((choise == 1 || choise==2) && (nivel>=0 && nivel<=10))
			pass = true;
		else {
			system("clear");
			printf("entrada incorreta\n");
		}
			
	}while (pass == false);
	// } 

	//definindo apenas a cor branca ate o final do programa
	gfx_set_color(255, 255, 255);

	switch (choise)
	{

	case 1:
		gfx_init(600, 600, "círculos");
		gfx_ellipse(x, y, rxy, rxy); 

		if (nivel > 0)
			circulo(x, y, rxy, nivel-1, curva); 
			// cordenadas do centro = x, y
			// raio do circulo = rxy obs: rx = ry
			// definir nivel de recursao = nivel
			// curva inicial da diferença dos circulos = curva

		gfx_paint();
		sleep(10);
		gfx_quit();
		break;
	
	case 2:
		gfx_init(600, 600, "Quadrados");
		gfx_rectangle(x1, y1, x2, y2); 

		if (nivel > 0)
			quadrado(x1, y1, x2, y2, nivel-1, 0); 
			// coordenadas dos dois vertices opostos do quadrado = x1, y1, x2, y2
			// definir nivel de recursao = nivel
			// variavel para orientar qual lado nao tera quadrado = 0
		
		gfx_paint();
		sleep(10);
		gfx_quit();
		break;	

	}
	gfx_clear();
	return 0;
}

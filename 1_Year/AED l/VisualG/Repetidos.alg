algoritmo "semnome"

//        Para o conjunto de 50 numeros armazenados no vetor v
//        calcule a frequencia que os numeros aparecem.
//        A frequencia é a quantidade
//        de vezes que um numero se repete no conjunto.

//armezene o arquivo "a.txt" em uma pasta e atualize o caminho "C:\Windows\Temp\" para a nova pasta
arquivo "C:\Users\Sleche\Documents\Faculdade\VisualG\a.txt"

var
   v, vet:vetor[1..50] de inteiro
   i, j, k, c, na, soma:inteiro
inicio
      //obter os numeros do arquivo e armazena-los no vetor v
      c<-0
      k<-1
      vet[1]<-0
      soma<-0
      para i de 1 ate 50 faca
           leia(v[i])
      fimpara
      escreval
      para i de 1 ate 50 faca
         para j de 1 ate 50 faca
            se (v[i] = v[j]) entao
            c<-c+1
            fimse
         fimpara
         na<-0
         para j de 1 ate k-1 faca
            se (vet[j]= v[i]) entao
               na<-1
            fimse
         fimpara
         se (na = 0) entao
            vet[k] <- v[i]
            k<-k+1

            soma <- soma+c

            escreval(v[i]," = ",c)
         fimse
         c<-0
      fimpara
      escreval(soma)
fimalgoritmo

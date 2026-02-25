# Automato Finito Deterministico
import os

#Entrada dos dados
def entrada():
    alfabeto = input("Entre com o alfabeto: ").split(',')
    estados = input("Entre com os estados: ").split(',')
    estado_inicial = input("Entre com o estado inicial: ")
    estados_aceitacao = input("Entre com os estados de aceitação: ").split(',')

    transicoes = {}
    for estado in estados:
        transicoes[estado] = {}
        for simbolo in alfabeto:
            transicoes[estado][simbolo] = input(f"Delta({estado}, {simbolo}): ")

    
    return alfabeto, estados, estado_inicial, estados_aceitacao, transicoes


# função de processamento do automato
def AFD(estados, alfabeto, estado_inicial, estados_aceitacao, transicoes, palavra):
    estado_atual = estado_inicial
    caminho = estado_inicial

    for simbolo in palavra: #percorre cade letra dentro de palavra
        if simbolo not in alfabeto: #verifica a existencia da letra dentro do alfabeto
            return False

        if estado_atual not in transicoes or simbolo not in transicoes[estado_atual]:
            return False # verifica se o a tabela de transiçoes contem o estado

        estado_atual = transicoes[estado_atual][simbolo] #atualiza o caminho percorrendo o proximo estado
        caminho = caminho + " " + estado_atual 

    print("Sequencia de estados: { " + caminho + " }") #mostra o caminho percorrido
    return estado_atual in estados_aceitacao

# verificar se a palavra é aceita ou não aceita pelo Automato
def printResultado(resultado):
    if resultado:
        print("palavra aceita! \n")
        print("------------------------------\n")
    else:
        print("palavra rejeitada! \n")
        print("------------------------------\n")

# repetição do automato com nova palavra
def loop(estados, alfabeto, estado_inicial, estados_aceitacao, transicoes):
    while True:
        palavra = input("Entre com a palavra a ser verificada: ")
        print("\n")
        resultado = AFD(estados, alfabeto, estado_inicial, estados_aceitacao, transicoes, palavra)

        printResultado(resultado)

        opcao = input("Deseja inserir outra palavra? (s/n): ")
        if opcao.lower() != 's':
            break
    


#função principal
while True:
    os.system("clear");
    print("\n\n----Autômato Finito Determinístico----")
    alfabeto, estados, estado_inicial, estados_aceitacao, transicoes = entrada()

    loop(estados, alfabeto, estado_inicial, estados_aceitacao, transicoes)
    opcao = input("Deseja executar novamente? (s/n): ")
    if opcao.lower() != 's':
        os.system("clear");
        break

        



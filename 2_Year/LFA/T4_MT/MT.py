#Projeto de Ana Clara Dantas da Luz e Caio Eduardo Gouveia Dias.
# rgm: 48923 e 47535 
# estado ' ' o branco simbolizado com um espaço
import os

# Função para entrada dos dados
def entrada_mt():
    alfabeto = input("Entre com o alfabeto (separado por vírgulas): ").split(',')
    estados = input("Entre com os estados (separado por vírgulas): ").split(',')
    estado_inicial = input("Entre com o estado inicial: ")
    estados_aceitacao = input("Entre com os estados de aceitação (separado por vírgulas): ").split(',')

    # Adiciona a possibilidade de transição em branco ( ) ao alfabeto
    alfabeto.append(' ')

    transicoes = {}
    print("\ninsira: (proximo estado, simbolo escrito, direção) ou deixe vazio! ")
    print("estado branco = 1 caracter espaço")
    for estado in estados:
        transicoes[estado] = {}
        for simbolo in alfabeto:
            transicao = input(f"Delta({estado}, {simbolo}): ")
            if transicao.strip():  # Verifica se há algo inserido
                prox_estado, simbolo_escrito, direcao = transicao.split(',')
                transicoes[estado][simbolo] = (prox_estado.strip(), simbolo_escrito.strip(), direcao.strip())

    return alfabeto, estados, estado_inicial, estados_aceitacao, transicoes

# Função para simular a Máquina de Turing
def maquina_de_turing(alfabeto, estados, estado_inicial, estados_aceitacao, transicoes, fita):
    fita = list(fita) + [' ']  # Adiciona espaços em branco no final da fita
    posicao = 0 
    estado_atual = estado_inicial

    while True:
        simbolo_atual = fita[posicao]  

        if estado_atual in transicoes and simbolo_atual in transicoes[estado_atual]:
            prox_estado, simbolo_escrito, direcao = transicoes[estado_atual][simbolo_atual]

            fita[posicao] = simbolo_escrito 
            estado_atual = prox_estado 

            if direcao == 'D':
                posicao += 1
            elif direcao == 'E':
                posicao -= 1
            else:
                raise ValueError("Direção inválida: use 'D' (direita) ou 'E' (esquerda).")

            if posicao == len(fita): 
                fita.append(' ')
            elif posicao < 0: 
                fita.insert(0, ' ')
                posicao = 0 
        else:
            if estado_atual in estados_aceitacao:
                print("\nFita após processamento:", ''.join(fita).strip(' '))
                return True 
            else:
                print("\nFita após processamento:", ''.join(fita).strip(' '))
                return False 

# Função principal
def main():
    print("\n\n----Máquina de Turing----")
    alfabeto, estados, estado_inicial, estados_aceitacao, transicoes = entrada_mt()

    while True:
        print("----------------------------------------")
        palavra = input("Entre com a fita: ")

        resultado = maquina_de_turing(alfabeto, estados, estado_inicial, estados_aceitacao, transicoes, palavra)
        if resultado:
            print("Palavra aceita! \n")
        else:
            print("Palavra rejeitada! \n")

        opcao = input("Deseja inserir outra palavra? (s/n): ")
        if opcao.lower() != 's':
            print("----------------------------------------")
            break

while True:
    os.system("cls");
    main()
    opcao = input("\n\nDeseja inserir outra Maquina de Turing? (s/n): ")
    if opcao.lower() != 's':
        break

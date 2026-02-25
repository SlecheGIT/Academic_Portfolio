# Função para entrada dos dados
def entrada_mt():
    alfabeto = input("Entre com o alfabeto (separado por vírgulas): ").split(',')
    estados = input("Entre com os estados (separado por vírgulas): ").split(',')
    estado_inicial = input("Entre com o estado inicial: ")
    estados_aceitacao = input("Entre com os estados de aceitação (separado por vírgulas): ").split(',')

    # Adiciona a possibilidade de transição em branco (_) ao alfabeto
    alfabeto.append('_')

    # Criação da tabela de transições
    transicoes = {}
    for estado in estados:
        transicoes[estado] = {}
        for simbolo in alfabeto:
            transicao = input(f"Delta({estado}, {simbolo}): (proximo estado, simbolo escrito, direção) ou deixe vazio: ")
            if transicao.strip():  # Verifica se há algo inserido
                prox_estado, simbolo_escrito, direcao = transicao.split(',')
                transicoes[estado][simbolo] = (prox_estado.strip(), simbolo_escrito.strip(), direcao.strip())

    return alfabeto, estados, estado_inicial, estados_aceitacao, transicoes

# Função para simular a Máquina de Turing
def maquina_de_turing(alfabeto, estados, estado_inicial, estados_aceitacao, transicoes, fita):
    fita = list(fita) + ['_']  # Adiciona espaços em branco no final da fita
    posicao = 0  # Cabeçote começa na posição inicial
    estado_atual = estado_inicial

    while True:
        simbolo_atual = fita[posicao]  # Lê o símbolo na posição do cabeçote

        # Verifica se há transição para o estado atual e símbolo atual
        if estado_atual in transicoes and simbolo_atual in transicoes[estado_atual]:
            prox_estado, simbolo_escrito, direcao = transicoes[estado_atual][simbolo_atual]

            # Executa a transição
            fita[posicao] = simbolo_escrito  # Escreve na fita
            estado_atual = prox_estado  # Atualiza o estado

            # Move o cabeçote
            if direcao == 'D':
                posicao += 1
            elif direcao == 'E':
                posicao -= 1
            else:
                raise ValueError("Direção inválida: use 'D' (direita) ou 'E' (esquerda).")

            # Expande a fita se necessário
            if posicao == len(fita):  # Se o cabeçote ultrapassar o final da fita
                fita.append('_')
            elif posicao < 0:  # Se o cabeçote ultrapassar o início da fita
                fita.insert(0, '_')
                posicao = 0  # Ajusta a posição do cabeçote
        else:
            # Verifica se está em um estado de aceitação
            if estado_atual in estados_aceitacao:
                print("Fita após processamento:", ''.join(fita).strip('_'))
                return True  # Palavra aceita
            else:
                print("Fita após processamento:", ''.join(fita).strip('_'))
                return False  # Palavra rejeitada

# Função principal
def main_mt():
    print("\n\n----Máquina de Turing----")
    alfabeto, estados, estado_inicial, estados_aceitacao, transicoes = entrada_mt()

    while True:
        palavra = input("Entre com a palavra a ser verificada: ")
        print("\n")

        resultado = maquina_de_turing(alfabeto, estados, estado_inicial, estados_aceitacao, transicoes, palavra)
        if resultado:
            print("Palavra aceita! \n")
        else:
            print("Palavra rejeitada! \n")

        opcao = input("Deseja inserir outra palavra? (s/n): ")
        if opcao.lower() != 's':
            break

main_mt()

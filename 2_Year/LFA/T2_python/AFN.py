import os

def epsilon_fechamento(afn, estados):
    lista = list(estados)
    fechamento = set(estados)  # Usar set para evitar duplicatas

    while lista:
        estado = lista.pop()

        if (estado, '') in afn['transicoes']:
            destinos = afn['transicoes'][(estado, '')]

            for destino in destinos:
                if destino not in fechamento:
                    fechamento.add(destino)
                    lista.append(destino)

    return list(fechamento)

def nomear_estado(conjunto, nome_estados):
    conjunto_frozen = frozenset(conjunto)
    if conjunto_frozen not in nome_estados:
        novo_nome = f"Q{len(nome_estados)}"
        nome_estados[conjunto_frozen] = novo_nome
    return nome_estados[conjunto_frozen]

def converter_afn_para_afd(afn):
    afn_estados = afn['estados']
    afn_alfabeto = afn['alfabeto']
    afn_transicoes = afn['transicoes']
    afn_iniciais = afn['estado_inicial']
    afn_finais = afn['estados_finais']

    afd_estados = []
    afd_transicoes = {}
    afd_iniciais = epsilon_fechamento(afn, [afn_iniciais])
    afd_finais = []

    lista = [afd_iniciais]
    visitados = set()
    nome_estados = {}

    print(f"\n\nEstado inicial do AFD (fecho-ε de {afn_iniciais}): {afd_iniciais}")

    while lista:
        conjunto = lista.pop()
        conjunto_frozen = frozenset(conjunto)
        nome_conjunto = nomear_estado(conjunto, nome_estados)
        visitados.add(conjunto_frozen)
        afd_estados.append(nome_conjunto)

        print(f"\nProcessando conjunto: {conjunto} (nomeado como {nome_conjunto})")

        if any(estado in afn_finais for estado in conjunto):
            afd_finais.append(nome_conjunto)
            print(f"Conjunto {conjunto} contém estado final do AFN, portanto, {nome_conjunto} é um estado final do AFD.\n")

        for simbolo in afn_alfabeto:
            destinos = []

            for estado in conjunto:
                if (estado, simbolo) in afn_transicoes:
                    destinos.extend(afn_transicoes[(estado, simbolo)])

            destinos_validos = [estado for estado in destinos if estado != '-']
            epsilon_destinos = epsilon_fechamento(afn, destinos_validos)
            epsilon_destinos_frozen = frozenset(epsilon_destinos)

            if epsilon_destinos_frozen:
                nome_destinos = nomear_estado(epsilon_destinos, nome_estados)
                afd_transicoes[(nome_conjunto, simbolo)] = nome_destinos

                if epsilon_destinos_frozen not in visitados:
                    lista.append(epsilon_destinos)

    afd = {
        'estados': afd_estados,
        'alfabeto': afn_alfabeto,
        'transicoes': afd_transicoes,
        'estado_inicial': nomear_estado(afd_iniciais, nome_estados),
        'estados_finais': afd_finais
    }

    return afd

# Função para ler as entradas do usuário e criar o dicionário do AFN
def ler_entradas_usuario():
    print("\n| AFN to AFD |")
    states = input("Insira os estados: ").split(",")
    alphabet = input("Insira o alfabeto: ").split(",")
    # alphabet.append('')
    transitions = {}

    print("Insira as transições:")
    for state in states:
        for symbol in alphabet:
            next_states = input(f"Delta({state},{symbol}): ").split(",")
            transitions[(state, symbol)] = next_states

    start_state = input("Insira o estado inicial: ")
    accept_states = input("Insira o(s) estado(s) de aceitação: ").split(",")
    return {
        'estados': states,
        'alfabeto': alphabet,
        'transicoes': transitions,
        'estado_inicial': start_state,
        'estados_finais': accept_states
    }

##main
while True:
    afn = ler_entradas_usuario()
    afd = converter_afn_para_afd(afn)

    os.system("clear")
    print("\n| AFN Convertido | ")
    print("Estados:")
    for estado in afd['estados']:
        print(estado)

    print("\nAlfabeto:")
    print(afd['alfabeto'])

    print("\nEstado Inicial:")
    print(afd['estado_inicial'])

    print("\nEstados Finais:")
    for estado_final in afd['estados_finais']:
        print(estado_final)

    print("\nTransições:")
    for transicao, destinos in afd['transicoes'].items():
        print(f"Delta({transicao[0]}, {transicao[1]}): {destinos}")

    opcao = input("\nDeseja realizar a operação novamente? (s/n): ")

    if opcao == 'n':
        break

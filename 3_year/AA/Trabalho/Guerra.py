def maximo_vitorias_guerra(N, Q):
    # Ordenar as habilidades de ambos os exércitos em ordem crescente
    N.sort()
    Q.sort()

    vitorias = 0
    Ni = 0
    Qi = 0

    # Percorremos os soldados de ambos os exércitos
    while Ni < len(N) and Qi < len(Q):
        # Escolha Gulosa: Tentar usar o soldado mais fraco disponível de Noglonia
        # para vencer o soldado mais fraco disponível de Quadradonia
        if N[Ni] > Q[Qi]:
            # em vitoria ambos os soldados serao usados na batalha
            vitorias += 1
            Ni += 1
            Qi += 1
        else:
            # Derrota ou empate, sacrifica um soldado
            Ni += 1
            
    return vitorias

# Exemplo de Entrada do documento [cite: 142]
Q = [2, 1, 1]
N = [1, 1, 2]

resultado = maximo_vitorias_guerra(N, Q)
print(f"Resultado esperado: 1")
print(f"Resultado obtido: {resultado}")

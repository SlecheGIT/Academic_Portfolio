def encontrar_maximo_ganho(apostas: list[int]):

    # Caso especial: se a lista de apostas estiver vazia, não há ganho.
    if not apostas:
        return "Sequência de derrotas."

    # Inicializa as variáveis com o valor da primeira aposta.
    ganho_maximo_total = apostas[0]
    ganho_maximo_atual = apostas[0]

    # Percorre a lista a partir do segundo elemento.
    # A variável 'aposta' representa o valor da aposta na iteração atual.
    for aposta in apostas[1:]:
        
        # Decide se é melhor começar uma nova sequência (com a aposta atual)
        # ou continuar a sequência anterior (somando a aposta atual).
        ganho_maximo_atual = max(aposta, ganho_maximo_atual + aposta)
        
        # Atualiza o ganho máximo global se o ganho da sequência atual for maior.
        ganho_maximo_total = max(ganho_maximo_total, ganho_maximo_atual)

    # Ao final, verifica se o ganho máximo encontrado é de fato um ganho (> 0).
    if ganho_maximo_total > 0:
        return ganho_maximo_total
    else:
        return "Sequência de derrotas."

sequencia1 = [12, -4, -10, 4, 9]
resultado1 = encontrar_maximo_ganho(sequencia1)
print(f"Analisando a sequência {sequencia1}:")
print(f"O máximo ganho possível é: {resultado1}\n") # Saída esperada: 13

# 2. Exemplo com apenas perdas
sequencia2 = [-2, -5, -1, -10, -3]
resultado2 = encontrar_maximo_ganho(sequencia2)
print(f"Analisando a sequência {sequencia2}:")
print(f"Resultado: {resultado2}\n") # Saída esperada: Sequência de derrotas.

# 3. Exemplo onde o máximo ganho é um único número
sequencia3 = [10, -3, 20, 10, -2, -8]
resultado3 = encontrar_maximo_ganho(sequencia3)
print(f"Analisando a sequência {sequencia3}:")
print(f"O máximo ganho possível é: {resultado3}\n") # Saída esperada: 10

# 4. Exemplo com lista vazia
sequencia4 = []
resultado4 = encontrar_maximo_ganho(sequencia4)
print(f"Analisando a sequência {sequencia4}:")
print(f"Resultado: {resultado4}\n") # Saída esperada: Sequência de derrotas.
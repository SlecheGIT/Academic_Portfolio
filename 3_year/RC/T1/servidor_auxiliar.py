import json
import os
import math

def verifica_pacotes(pacote, socket_servidor, endereco_cliente):
    try:
        pacote = pacote.decode('utf-8')
        pacote = json.loads(pacote)
        dados_bytes = json.dumps(pacote['dados']).encode('utf-8')
        # checksum enviado == checksum calculado
        if pacote['checksum'] == (sum(dados_bytes) & 0b11111111): # & 0b11111111 limita o checksum a 1 byte
            print(" ✅ Pacote recebido. Enviando ACK...\n")
            socket_servidor.sendto(b'ACK', endereco_cliente)

            tipo = pacote['dados'].pop('tipo')
            return {'tipo': tipo, 'dados': pacote['dados']}
        else:
            print(f" ❌ Pacote recebido corrompido. Enviando NAK.\n")
            socket_servidor.sendto(b'NAK', endereco_cliente)
            return None
    except json.JSONDecodeError:
        socket_servidor.sendto(b'NAK', endereco_cliente)
        return None # se nao conseguir decodificar o pacote ele está corrompido
                    

def salvar_dados(novos_dados):
    dados_salvos = [] #string de dicionarios vazio
    mudanca_de_preco = 0
    try:
        if os.path.getsize('dados.json') > 0:
            with open('dados.json', 'r', encoding=("utf-8")) as arquivo:
                dados_salvos = json.load(arquivo)

                for dados_atuais in dados_salvos:
                    if  dados_atuais['latitude'] == novos_dados['latitude'] and \
                        dados_atuais['longitude'] == novos_dados['longitude']and \
                        dados_atuais['combustivel'] == novos_dados['combustivel']:

                        if dados_atuais['preco'] != novos_dados['preco']:
                            mudanca_de_preco = dados_atuais['preco']
                            dados_atuais['preco'] = novos_dados['preco']
                            print(f"Mesmas coordenadas, preço atualizado: {mudanca_de_preco} -> {novos_dados['preco']}\n")
                        else:
                            print("Dados já existem no arquivo. Não serão duplicados.\n")
                            return
    except FileNotFoundError:
        # se o arquivo nao existir, nas instrucoes seguintes ele sera aberto para escrita e criado
        pass
    except json.JSONDecodeError:
        # caso o arquivo esteja vazio ou corrompido, nas instrucoes seguintes ele sera aberto para escrita e sobrescrevido
        pass

    if mudanca_de_preco == 0: #se nao houve mudanca de preco, adiciona o novo dado
        dados_salvos.append(novos_dados)
        print("Novo posto adicionado.\n")
    # 'w' (write) que sobrescreve o arquivo inteiro com a nova versão.
    # se ja existiu dados, eles foram carregados, caso contrario, o arquivo será criado ou sobrescrito
    with open('dados.json', 'w', encoding=("utf-8")) as arquivo:
        json.dump(dados_salvos, arquivo, indent=4, ensure_ascii=False, sort_keys=False)

def pesquisar_dados(consulta):
    postos_no_raio = []
    try:
        if os.path.getsize('dados.json') > 0:
            with open('dados.json', 'r', encoding=("utf-8")) as arquivo:
                dados_salvos = json.load(arquivo)

                for dados_atuais in dados_salvos:
                    if consulta['combustivel'] == dados_atuais['combustivel']:
                        # formula de Haversine
                        raio_terra_km = 6371.0 #circunferencia da terra
                            
                        # converte as coordenadas do centro da busca e do posto atual para radianos
                        latitude_centro_rad = math.radians(consulta['latitude'])
                        longitude_centro_rad = math.radians(consulta['longitude'])
                        latitude_posto_rad = math.radians(dados_atuais['latitude'])
                        longitude_posto_rad = math.radians(dados_atuais['longitude'])

                        # calcula a diferença
                        delta_longitude = longitude_posto_rad - longitude_centro_rad
                        delta_latitude = latitude_posto_rad - latitude_centro_rad

                        # aplica a fórmula
                        a = math.sin(delta_latitude / 2)**2 + math.cos(latitude_centro_rad) * math.cos(latitude_posto_rad) * math.sin(delta_longitude / 2)**2
                        c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))
                        
                        distancia = raio_terra_km * c

                        # verifica se a distância calculada está dentro do raio de busca, em km e em uma linha reta
                        if distancia <= consulta['raio_busca']:
                            postos_no_raio.append({
                                'preco': dados_atuais['preco'],
                                'distancia': f"{distancia:.3f}",
                                'latitude': dados_atuais['latitude'],
                                'longitude': dados_atuais['longitude']
                            })

    except FileNotFoundError:
        print("Arquivo de dados não encontrado.")
    except json.JSONDecodeError:
        print("Erro ao ler o arquivo de dados. O arquivo pode estar corrompido ou vazio.")

    if postos_no_raio :
        posto_mais_barato = min(postos_no_raio, key=lambda posto: posto['preco'])
        return posto_mais_barato
    else:
        return None
    
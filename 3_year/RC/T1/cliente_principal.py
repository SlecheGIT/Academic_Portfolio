#!/usr/bin/env python3
import socket
import os
import sys
import random
import json

HOST = ''
PORT = ''
PROBABILIDADE_CORROMPER = 0.5 
# 50% de chance de simular um ACK/NAK corrompido; 1.0 = 0% de chance e 0.0 = 100% de chance por causa da forma que foi descrito o trabalho >0.5 corrompe

def montar_pacote(entrada_do_usuario):
    dados = {}
    entrada = [dados.strip() for dados in entrada_do_usuario.split(',')]
    entrada[0] = entrada[0].upper() 

    # verificacao do formato dos dados
    if (len(entrada) != 5):
        return None  # formato invalido, deve ter 6 campos
    else:
        if entrada[0].upper() not in ['D', 'P']: # tipo de mensagem deve ser 'D' ou 'P'
            return None
        if entrada[1] not in ['0', '1', '2']: # tipo de combustível deve ser 0, 1 ou 2
            return None
        if float(entrada[3]) <= -23 or float(entrada[3]) >= -20:
            return None
        if float(entrada[4]) <= -56 or float(entrada[4]) >= -53:
            return None
    try:
        if entrada[0] == 'D':
            dados = {
                'tipo': 'D',
                'combustivel': int(entrada[1]),  # 0 - diesel, 1 - álcool, 2 - gasolina
                'preco': int(float(entrada[2])*1000),
                'latitude': float(entrada[3]),
                'longitude': float(entrada[4])
            }
        elif entrada[0] == 'P':
            dados = {
                'tipo': 'P',
                'combustivel': int(entrada[1]),  # 0 - diesel, 1 - álcool, 2 - gasolina
                'raio_busca': float(entrada[2]),
                'latitude': float(entrada[3]),
                'longitude': float(entrada[4])
            }
    except ValueError:
        return None
  
    return dados


def envio_rdt(dados_cliente, socket_cliente):
    # enviar o pacote e esperar por um ACK/NAK
    tentativa = 1

    if dados_cliente['tipo'] == 'D':
        print(f">> Enviando Dados: \n {dados_cliente}\n")
    elif dados_cliente['tipo'] == 'P':
        print(f">> Enviando Pesquisa: \n {dados_cliente}\n")

    dados_bytes = json.dumps(dados_cliente).encode('utf-8') 

    while True:
        
        # simula a corrupção do ack/nak
        if random.random() > PROBABILIDADE_CORROMPER:
            print("simulacao ACK/NAK corrompido!")
            pacote_para_envio = json.dumps({'checksum': 0, 'dados': dados_cliente}).encode('utf-8')  # envia um pacote corrompido
        else:
            checksum = (sum(dados_bytes) & 0b11111111)
            pacote_para_envio = json.dumps({'checksum': checksum, 'dados': dados_cliente}).encode('utf-8')
        socket_cliente.sendto(pacote_para_envio, (HOST, PORT))
        
        try:
            feedback, _ = socket_cliente.recvfrom(64) # espera apenas por um ACK/NAK
            
            feedback = feedback.decode()

            if feedback == 'ACK':
                print(" ✅ ACK recebido. Mensagem entregue com sucesso!\n")
                break # Sucesso! Sai do loop de reenvio.
            elif feedback == 'NAK':
                print(" ❌ NAK recebido. Reenviando a mensagem...\n") # Continua no loop e reenvia
            else:
                # apenas no caso do ack ser corrompido
                print(f"Resposta inesperada do servidor: '{feedback}'. Reenviando...\n")

        except socket.timeout:
            print(f" ⏰ Timeout! Nenhum feedback recebido. Tentativa {tentativa}/3. Reenviando...\n")
            if tentativa < 3:
                tentativa += 1
            else:
                print(" ❗️servidor nao encontrado, Encerrando o cliente.")
                sys.exit(1)


if __name__ == "__main__":
    os.system('clear')
    if len(sys.argv) != 3:
        print("Uso: python cliente_principal.py <HOST> <PORT>")
        sys.exit(1)
    else:
        HOST = sys.argv[1]
        PORT = int(sys.argv[2])

    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as socket_cliente:
        socket_cliente.settimeout(2.0) # Timeout de 2 segundos
        print("         [CLIENTE]")
        print(f"enviando mensagens para {HOST}:{PORT}")
        print("Formato de Dados: {D, (0 – diesel, 1 – álcool, 2 – gasolina), preço, latitude, longitude}")
        print("Formato de Pesquisa: {P, (0 – diesel, 1 – álcool, 2 – gasolina), raio de busca em km, latitude, longitude}")
        print("-" * 60)

        while True:
            entrada_cliente = input("$ ")
            print("")
            if entrada_cliente.lower() == 'exit':
                print("Encerrando o cliente...")
                break

            dados_para_envio = montar_pacote(entrada_cliente)
            if dados_para_envio is None:
                print("\n! Formato ou entradas Invalidas!  Tente novamente.")
                continue

            envio_rdt(dados_para_envio, socket_cliente)

            if dados_para_envio['tipo'] == 'P':
                # socket_cliente.settimeout(10.0) 
                try:
                    resposta_pesquisa, _ = socket_cliente.recvfrom(512)
                    resposta_pesquisa = resposta_pesquisa.decode('utf-8')
                    if resposta_pesquisa == '-1':
                        print(">> Resposta da pesquisa recebida do servidor:")
                        print("Nenhum posto encontrado no raio especificado\n")
                    else:
                        resposta_pesquisa = json.loads(resposta_pesquisa) 
                        preco = resposta_pesquisa.pop('preco')
                        distancia = resposta_pesquisa.pop('distancia')

                        print(">> Resposta da pesquisa recebida do servidor:")
                        print(f"Preço: {preco} reais, Distância: {distancia} km a {resposta_pesquisa}\n")
                except socket.timeout:
                    print(" ⏰ Timeout! Nenhuma resposta recebida do servidor a tempo.")

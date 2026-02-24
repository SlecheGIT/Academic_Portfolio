#!/usr/bin/env python3
import os
import socket
import threading
import queue
import servidor_auxiliar
import json
import sys

# Anotacoes sobre portas:
# 8080 - HTTP Alternativo para rodar servidores web de teste
# 0 a 1024 - portas reservadas para serviços e protocolos mais fundamentais da internet
# 1024 a 49151 - portas registradas, usadas por aplicativos e protocolos conhecidos
# 49152 a 65535 - uso livre e nao controlado, usada para conexoes temporarias
PORT = ''
HOST = ''
fila_pacotes = queue.Queue()
servidor_rodando = True

def funcao_servidor(socket_servidor):
    while servidor_rodando:
        try:
            pacote_cliente, endereco_cliente = socket_servidor.recvfrom(512)
            #se o timeout ocorrer, pula para except
            pacote_cliente = servidor_auxiliar.verifica_pacotes(pacote_cliente, socket_servidor, endereco_cliente)
            
            if pacote_cliente is not None:
                fila_pacotes.put((pacote_cliente, endereco_cliente))  # adiciona o pacote na fila de processamento

        except socket.timeout:
            continue

    print("Servidor encerrado.")

def funcao_processamento(socket_servidor):
    while servidor_rodando:
        try:
            pacote, endereco_cliente = fila_pacotes.get(timeout=1)  # espera por um pacote na fila

            if pacote['tipo'] == 'D':
                print(f">> Armazenando: \n {pacote['dados']}")
                servidor_auxiliar.salvar_dados(pacote['dados'])

            elif pacote['tipo'] == 'P':
                print(f">> Processando Pesquisa: \n {pacote['dados']}\n")
                posto_mais_barato = servidor_auxiliar.pesquisar_dados(pacote['dados'])

                if posto_mais_barato is not None:
                    print(f">> Posto mais barato encontrado: \n {posto_mais_barato}")
                    print(f"Enviando resposta para {endereco_cliente}\n")
                    pacote_para_envio = json.dumps(posto_mais_barato).encode('utf-8')
                else:
                    print("Nenhum posto encontrado no raio.")
                    print(f"Enviando resposta para {endereco_cliente}\n")
                    pacote_para_envio = b'-1'

                socket_servidor.sendto(pacote_para_envio, endereco_cliente)

        except queue.Empty:
            continue


if __name__ == "__main__":
    os.system('clear')
    if len(sys.argv) != 2:
        print("Uso: python servidor_principal.py <PORT>")
        sys.exit(1)
    else:
        PORT = int(sys.argv[1])
    
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as socket_servidor:
        socket_servidor.bind((HOST, PORT)) # vincula o socket ao endereço e porta
        socket_servidor.settimeout(1.0) # define um timeout de 1 segundo para recvfrom para não travar a thread

        thread_servidor = threading.Thread(target=funcao_servidor, args=(socket_servidor,))
        thread_processamento = threading.Thread(target=funcao_processamento, args=(socket_servidor,))
        thread_servidor.start()
        thread_processamento.start()

        print("         [SERVIDOR]")
        print(f"Servidor iniciado e ouvindo na porta {PORT}")
        print("Digite 'exit' a qualquer momento para parar o servidor.")
        print("-" * 60)

        while True:
            
            comando = input()#""">> """
            if comando.lower() == 'exit':
                print("\nComando 'exit' recebido. Enviando sinal para encerrar...")
                servidor_rodando = False
                thread_servidor.join() 
                thread_processamento.join()
                break
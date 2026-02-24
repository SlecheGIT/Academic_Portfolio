# --- Variáveis Configuráveis ---
HOST = 127.0.0.1
PORT = 57776

SERVER_SOURCE = servidor_principal.py
CLIENT_SOURCE = cliente_principal.py
PYTHON = python3

run_server:
	@$(PYTHON) $(SERVER_SOURCE) $(PORT)
	
run_client:
	@$(PYTHON) $(CLIENT_SOURCE) $(HOST) $(PORT)

clean:
	@find . -type d -name "__pycache__" -exec rm -r {} +

help:
	@echo ""
	@echo "Uso: make [Comando]"
	@echo "Comandos disponíveis:"
	@echo "  run_server    - Inicia o servidor"
	@echo "  run_client    - Inicia o cliente para interagir com o servidor."
	@echo "  clean         - Remove diretórios de cache do Python (__pycache__)."
	@echo ""

# Declara os alvos como "phony" para que o 'make' não os confunda
# com nomes de arquivos reais. Isso força a execução do comando sempre.
.PHONY: run_server run_client clean help
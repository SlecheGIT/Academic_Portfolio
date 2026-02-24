Caio Eduardo Gouveia Dias

Comandos disponíveis:
"make run_server" - Inicia o servidor.
"make run_client" - Inicia o cliente para interagir com o servidor.
"make clean" - Remove diretórios de cache do Python.

As alteracoes de porta e ip usando make devem ser feitas no arquivo Makefile e nas variaveis (HOST,PORT), 
entretanto os Comandos para execucao direta são:

Cliente Python3 cliente_principal.py "HOST" "PORT"
Cliente Python3 servidor_principal.py "PORT"
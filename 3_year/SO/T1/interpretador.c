#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <stdbool.h>

void build_tree(char *pid, short nivel);

int main()
{
    char cwd[1024];
    char comando[256];
    char programa[256];
    char arg[64];
    char *argumentos[32];

    size_t i;

    system("clear");
    while (strcmp(programa, "/bin/exit") != 0)
    {

        bool aguardar = true;
        size_t cont_args = 0;

        getcwd(cwd, sizeof(cwd));
        printf("\n*TRABALHO*\033[1;32m@linux\033[0m:\033[1;35m~%s\033[0m$ ", cwd);
        if (fgets(comando, sizeof(comando), stdin))
        {

            if (strcmp(comando, "\n\0") == 0) // em caso de nao inserir
                continue;

            if (comando[strlen(comando) - 2] == '&')
            {
                aguardar = false;
                comando[strlen(comando) - 2] = ' '; // Remove o '&' da string
                comando[strlen(comando) - 1] = '\0';
            }
            else
                comando[strlen(comando) - 1] = ' '; // Tirar \n
        }
        else
        {
            printf("Erro ao ler a entrada.\n");
        }

        strcpy(programa, "/bin/");          // diretorio
        for (i = 0; comando[i] != ' '; i++) // separar qual programa eh usado
            programa[i + 5] = comando[i];
        programa[i + 5] = '\0';
        i++;

        if (strcmp(programa, "/bin/exit") == 0)
            continue;

        // funcionamento do cd
        if (strcmp(programa, "/bin/cd") == 0)
        { // Verifica se o comando é "cd"
            char *caminho = comando + 3;
            caminho[strlen(caminho) - 1] = '\0';

            if (chdir(caminho) != 0)
            { // Tenta mudar o diretório
                perror("Erro ao mudar de diretório");
            }
            continue;
        }

        if (strcmp(programa, "/bin/tree") == 0)
        {
            char pid_ini[32];
            char adress[32];
            strcpy(adress, "/proc/");
            size_t j;

            for (j = 0; comando[i] != ' '; j++, i++)
                pid_ini[j] = comando[i];

            pid_ini[j] = '\0';
            strcat(adress, pid_ini);

            DIR *diretorio = opendir(adress);
            if (diretorio)
            {
                closedir(diretorio);
                printf("\n---------------------------------------------------------");
                build_tree(pid_ini, 0);
                printf("\n---------------------------------------------------------\n");
            }
            else
            {
                perror("PID nao encontrado");
            }

            continue;
        }

        argumentos[cont_args++] = programa;

        for (size_t j = 0; comando[i] != '\0'; j++, i++)
        {

            if (comando[i] == ' ')
            {

                arg[j] = '\0'; // encerra a string
                argumentos[cont_args] = malloc(sizeof(char) * strlen(arg) + 1);
                strcpy(argumentos[cont_args++], arg);
                i++;
                j = 0; // reseta a posicao do vetor
            }
            else
                arg[j] = comando[i]; // copia cada caracter ate achar um espaco
        }

        if (!aguardar)
        { // gambiarra por erro no &
            argumentos[cont_args - 1] = NULL;
        }
        else
            argumentos[cont_args] = NULL;

        pid_t pid;

        pid = fork();
        if (pid < 0)
        {
            fprintf(stderr, "Fork Failed");
            exit(-1);
        }
        else if (pid == 0)
        { /* Processo filho */
            if (execve(programa, argumentos, NULL) == -1)
            {
                char snap[32] = "/snap";
                strcat(snap, programa);
                argumentos[0] = snap;
                // tenta abrir um programa snap se nao encontrar no bin
                if (execve(snap, argumentos, __environ) == -1)
                {
                    perror("Erro ao executar o programa");
                    exit(1); // Encerra o processo filho em caso de erro
                }
            }
        }
        else
        { /* Processo pai */
            if (aguardar)
            {                          // Se não for execução em background
                waitpid(pid, NULL, 0); // Aguarda o término do processo filho
            }
        }

        for (size_t j = 1; j < cont_args - 1; j++)
            free(argumentos[j]); // desaloca o vetor de ponteiros
    }

    return 0;
}

void build_tree(char *ppid, short nivel)
{

    char estado[4];
    char pai_ppid[32];
    char pid[32];
    char nome_programa[32];
    char stat[64] = "/proc/";
    char task[64];

    strcat(stat, ppid);
    strcpy(task, stat);
    strcat(stat, "/stat");

    strcat(task, "/task/");
    strcat(task, ppid);
    strcat(task, "/children");

    FILE *file = fopen(stat, "r");
    if (!file)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    printf("\n");
    for (size_t i = 0; i < nivel * 3; i++)
        printf(" ");
    printf("|\n");
    for (size_t i = 0; i < nivel * 3; i++)
        printf(" ");
    printf("|--");

    fscanf(file, "%*d %s %s %s", nome_programa, estado, pai_ppid);
    printf(" %s %s %s %s", ppid, nome_programa, estado, pai_ppid);
    fclose(file);

    file = fopen(task, "r");
    if (!file)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int i = 0;
    while ((pid[i] = fgetc(file)) != EOF)
    {

        if (pid[i] == ' ')
        {
            pid[i] = '\0';
            build_tree(pid, nivel + 1);
            i = 0;
        }
        else
            i++;
    }

    fclose(file);
}
// Raphaela Meireles de Souza
// Objetivo: Criar uma lista ordenada e sem elementos repetidos sem diferenciar letras maiúsculas de minúsculas.
// A entrada de dados deve ser feita apos selecionar a opçao de inserir uma palavra.
// No final de programa a saída esperada será uma lista ordenada;

#include <string>
#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
    string palavra; // variavel para receber o valor digitado do usuário
    int opcao; // variavel utilizada no Menu
    int posicao; // variavel para retornar a posição onde o elemento foi encontrado

    Lista_Construtor(); // Para iniciar a Lista

    do {

        cout << "Programa para uso da Lista Singularmente Encadeada\n\n";
        cout << "Escolha uma das opcoes abaixo.\n";
        cout << "Menu: \n";
        cout << "1 - Inserir uma palavra\n";
        cout << "2 - Remover no inicio\n";
        cout << "3 - Remover no fim\n";
        cout << "4 - Remover dado em uma posicao\n";
        cout << "5 - Elemento no inicio\n";
        cout << "6 - Elemento no fim\n";
        cout << "7 - Procurar elemento\n";
        cout << "8 - Numero de elementos na lista\n";
        cout << "9 - Exibir elemento em uma posicao\n";
        cout << "10 - Exibir elementos da Lista\n";
        cout << "11 - Remover e exibir todos os elementos\n";
        cout << "12 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "\nDigite a palavra: ";
                cin.ignore();
                getline(cin, palavra);

                if (Lista_Inserir_Ordenado_Sem_Repeticao(palavra))
                    cout << "\nPalavra inserida com sucesso.\n";
                else
                    cout << "\nPalavra ja existe na lista.\n";

                break;

            case 2:
                if (Lista_Remover_Inicio(palavra))
                    cout << "\nPalavra '" << palavra << "' removida\n\n";
                else
                    cout << "Erro. Lista vazia.\n\n";
                break;

            case 3:
                if (Lista_Remover_Fim(palavra))
                    cout << "\nPalavra removida: " << palavra << "\n";
                else
                    cout << "\nErro. Lista vazia.\n";
                break;

            case 4:
                cout << "\nDigite a posicao para remover: ";
                cin >> posicao;

                if (Lista_Remover(palavra, posicao))
                    cout << "\nPalavra removida: " << palavra << "\n";
                else
                    cout << "\nErro. Posicao invalida ou lista vazia.\n";
                break;

            case 5:
                if (Lista_Inicio(palavra))
                    cout << "\nPalavra no inicio: " << palavra << "\n";
                else
                    cout << "\nLista vazia.\n";
                break;

            case 6:
                if (Lista_Fim(palavra))
                    cout << "\nPalavra no fim: " << palavra << "\n";
                else
                    cout << "\nLista vazia.\n";
                break;

            case 7:
                cout << "\nDigite a palavra para procurar: ";
                cin.ignore();
                getline(cin, palavra);

                if (Lista_BuscarPeloElemento(palavra, posicao))
                    cout << "\nPalavra encontrada na posicao: " << posicao << "\n";
                else
                    cout << "\nPalavra nao encontrada.\n";
                break;

            case 8:
                cout << "\nNumero de palavras na lista: " << Lista_Tamanho() << "\n";
                break;

            case 9:
                cout << "\nDigite a posicao desejada: ";
                cin >> posicao;

                if (Lista_BuscarPelaPosicao(palavra, posicao))
                    cout << "\nPalavra na posicao " << posicao << ": " << palavra << "\n";
                else
                    cout << "\nPosicao invalida ou lista vazia.\n";
                break;

            case 10:
                cout << "\nPalavras na lista:\n";
                posicao = 0;
                while (Lista_BuscarPelaPosicao(palavra, posicao)) {
                    cout << "Posicao " << posicao << ": " << palavra << "\n";
                    posicao++;
                }
                cout << "\n";
                break;

            case 11:
                cout << "\nRemovendo todas as palavras:\n";
                while (Lista_Remover_Inicio(palavra)) {
                    cout << "Palavra removida: " << palavra << "\n";
                }
                cout << "\nLista Vazia.\n";
                break;

            case 12:
                Lista_Destrutor();
                cout << "\nPrograma encerrado.\n";
                break;

            default:
                cout << "\nOpcao invalida.\n";
        }

        cout << "\n";
    } while (opcao != 12);

    system("pause");
    return 0;
}
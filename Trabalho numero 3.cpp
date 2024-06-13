// Trabalho numero 3.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class PilhaDePratos {
private:
    stack<string> pilha;

public:
    void adicionarPrato(const string& prato) {
        pilha.push(prato);
        cout << "Prato " << prato << " adicionado a pilha." << endl;
    }

    void removerPrato() {
        if (pilha.empty()) {
            cout << "A pilha esta vazia. Nenhum prato para remover." << endl;
        }
        else {
            string pratoRemovido = pilha.top();
            pilha.pop();
            cout << "Prato " << pratoRemovido << " removido do topo da pilha." << endl;
        }
    }

    void exibirPilha() const {
        if (pilha.empty()) {
            cout << "A pilha esta vazia." << endl;
        }
        else {
            stack<string> pilhaTemp = pilha; // Criar uma copia
            while (!pilhaTemp.empty()) {
                cout << pilhaTemp.top() << endl;
                pilhaTemp.pop();
            }
        }
    }
};

void menu() {
    PilhaDePratos pilha;
    int opcao;
    string prato;

    do {
        cout << "\nMenu de operacoes:" << endl;
        cout << "1. Adicionar prato a pilha" << endl;
        cout << "2. Remover prato do topo da pilha" << endl;
        cout << "3. Exibir todos os pratos na pilha" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma operacao (1-4): ";
        cin >> opcao;
        cin.ignore(); // Limpar a palavra

        switch (opcao) {
        case 1:
            cout << "Digite o nome do prato: ";
            getline(cin, prato);
            pilha.adicionarPrato(prato);
            break;
        case 2:
            pilha.removerPrato();
            break;
        case 3:
            pilha.exibirPilha();
            break;
        case 4:
            cout << "Encerrando o programa." << endl;
            break;
        default:
            cout << "Escolha incorreta. Tente novamente." << endl;
        }
    } while (opcao != 4);
}

int main() {
    menu();
    return 0;
}


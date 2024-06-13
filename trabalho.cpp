#include <iostream>
#include <queue>
#include <string>

using namespace std;

class FilaDeAtendimento {
private:
    queue<string> fila;

public:
    void adicionarCliente(const string& cliente) {
        fila.push(cliente);
        cout << "Cliente " << cliente << " adicionado a fila." << endl;
    }

    void atenderCliente() {
        if (!fila.empty()) {
            string clienteAtendido = fila.front();
            fila.pop();
            cout << "Cliente " << clienteAtendido << " atendido e removido da fila." << endl;
        }
        else {
            cout << "Nenhum cliente na fila para atender." << endl;
        }
    }

    void exibirFila() const {
        if (!fila.empty()) {
            cout << "Clientes na fila de espera:" << endl;
            queue<string> copiaFila = fila; // Criar uma copia da fila 
            while (!copiaFila.empty()) {
                cout << copiaFila.front() << endl;
                copiaFila.pop();
            }
        }
        else {
            cout << "A fila esta vazia." << endl;
        }
    }
};

void menu() {
    FilaDeAtendimento fila;
    int escolha;
    string nomeCliente;

    do {
        cout << "\nMenu de operacoes:" << endl;
        cout << "1. Adicionar cliente a lista de espera" << endl;
        cout << "2. Responder (remover) cliente da lista de espera" << endl;
        cout << "3. Exibir todos os clientes na lista de espera" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha um (1-4): ";
        cin >> escolha;

        switch (escolha) {
        case 1:
            cout << "Digite o nome do cliente: ";
            cin >> nomeCliente;
            fila.adicionarCliente(nomeCliente);
            break;
        case 2:
            fila.atenderCliente();
            break;
        case 3:
            fila.exibirFila();
            break;
        case 4:
            cout << "Encerrando o programa." << endl;
            break;
        default:
            cout << "Escolha incorreta. Tente novamente." << endl;
        }
    } while (escolha != 4);
}

int main() {
    menu();
    return 0;
}

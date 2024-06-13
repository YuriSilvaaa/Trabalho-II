#include <iostream>
#include <string>

using namespace std;

class Estacao {
public:
    string nome;
    Estacao* proxima;

    Estacao(const string& nome) : nome(nome), proxima(nullptr) {}
};

class LinhaMetro {
private:
    Estacao* cabeca;

public:
    LinhaMetro() : cabeca(nullptr) {}

    ~LinhaMetro() {
        Estacao* atual = cabeca;
        while (atual != nullptr) {
            Estacao* proxima = atual->proxima;
            delete atual;
            atual = proxima;
        }
    }

    void adicionarEstacao(const string& nome) {
        Estacao* novaEstacao = new Estacao(nome);
        if (cabeca == nullptr) {
            cabeca = novaEstacao;
        }
        else {
            Estacao* atual = cabeca;
            while (atual->proxima != nullptr) {
                atual = atual->proxima;
            }
            atual->proxima = novaEstacao;
        }
        cout << "Estacao " << nome << " adicionada a linha." << endl;
    }

    void removerEstacao(const string& nome) {
        if (cabeca == nullptr) {
            cout << "A linha esta vazia. Nenhuma estacao para remover." << endl;
            return;
        }

        if (cabeca->nome == nome) {
            Estacao* estacaoParaRemover = cabeca;
            cabeca = cabeca->proxima;
            delete estacaoParaRemover;
            cout << "Estacao " << nome << " removida da linha." << endl;
            return;
        }

        Estacao* atual = cabeca;
        Estacao* anterior = nullptr;

        while (atual != nullptr && atual->nome != nome) {
            anterior = atual;
            atual = atual->proxima;
        }

        if (atual == nullptr) {
            cout << "Estacao " << nome << " nao encontrada na linha." << endl;
            return;
        }

        anterior->proxima = atual->proxima;
        delete atual;
        cout << "Estacao " << nome << " removida da linha." << endl;
    }

    void exibirLinha() const {
        if (cabeca == nullptr) {
            cout << "A linha esta vazia." << endl;
            return;
        }

        Estacao* atual = cabeca;
        cout << "Estacoes na linha:" << endl;
        while (atual != nullptr) {
            cout << atual->nome << endl;
            atual = atual->proxima;
        }
    }
};

void menu() {
    LinhaMetro linha;
    int opcao;
    string nome;

    do {
        cout << "\nMenu de operacoes:" << endl;
        cout << "1. Adicionar estacao a linha" << endl;
        cout << "2. Remover estacao da linha" << endl;
        cout << "3. Exibir todas as estacoes na linha" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma operacao (1-4): ";
        cin >> opcao;
        cin.ignore(); // Limpar a escrita

        switch (opcao) {
        case 1:
            cout << "Digite o nome da estacao: ";
            getline(cin, nome);
            linha.adicionarEstacao(nome);
            break;
        case 2:
            cout << "Digite o nome da estacao a ser removida: ";
            getline(cin, nome);
            linha.removerEstacao(nome);
            break;
        case 3:
            linha.exibirLinha();
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

#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Função para listar contatos
void listarContatos(vector<string>& contatos) {
    cout << "\n***** LISTA DE CONTATOS *****" << endl;
for (size_t i = 0; i < contatos.size(); i++) {
        cout << i + 1 << ": " << contatos[i] << endl;
    }
    cout << "*****************************" << endl;
}

// Função para adicionar novo contato
void adicionarContato(vector<string>& contatos) {
    string novoContato;
    cout << "\nDigite o nome do novo contato: ";
    cin >> novoContato;
    contatos.push_back(novoContato);
    cout << "\nContato adicionado com sucesso!" << endl;
}

// Função para excluir um contato
void excluirContato(vector<string>& contatos) {
    listarContatos(contatos);
    int indice;
    cout << "\nDigite o número do contato que deseja excluir: ";
    cin >> indice;
    
    // Correção para evitar comparação entre tipos diferentes
    if(indice > 0 && static_cast<size_t>(indice) <= contatos.size()) {
        contatos.erase(contatos.begin() + (indice - 1));
        cout << "\nContato excluído com sucesso!" << endl;
    } else {
        cout << "\nNúmero inválido!" << endl;
    }
}

// Função para mandar mensagem para um contato
void mandarMensagem(vector<string>& contatos) {
    listarContatos(contatos);
    int indice;
    cout << "\nDigite o número do contato para quem deseja mandar mensagem: ";
    cin >> indice;

    // Correção para evitar comparação entre tipos diferentes
    if(indice > 0 && static_cast<size_t>(indice) <= contatos.size()) {
        string mensagem;
        cout << "\nDigite sua mensagem para " << contatos[indice - 1] << ": ";
        cin.ignore();
        getline(cin, mensagem);
        cout << "\nMensagem enviada para " << contatos[indice - 1] << ": \"" << mensagem << "\"" << endl;
    } else {
        cout << "\nNúmero de contato inválido!" << endl;
    }
}

int main(){
    // variáveis
    string login, senha;
    int opcao;
    vector<string> contatos = {"Carlos", "Maicon", "Eduardo", "Rafael", "Lilian", 
                               "Luana", "Leticia", "Fernando", "Pedro"};

    cout << "************************" << endl;
    cout << "BEM VINDO A LISTA DE CONTATOS" << endl;
    cout << "Autor: Ronny Rocke" << endl;
    cout << "************************" << endl;

    bool autenticado = false;

    // Autenticação com possibilidade de tentar novamente
    while (!autenticado) {
        cout << "\nDigite Login: ";
        cin >> login;
        cout << "\nDigite a Senha: ";
        cin >> senha;

        if (login == "ronny" && senha == "123") {
            autenticado = true;
        } else {
            cout << "\nLogin ou senha incorretos! Tente novamente." << endl;
        }
    }

    bool menu = true;
    while(menu) {
        cout << "\nVocê Logou Na Conta" << endl;
        cout << "\n1: Ver Contatos" << endl;
        cout << "2: Adicionar Contato" << endl;
        cout << "3: Excluir Contato" << endl;
        cout << "4: Mandar Mensagem" << endl;
        cout << "5: Sair" << endl;
        cout << "\nEscolha uma opção: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                listarContatos(contatos);
                break;

            case 2:
                adicionarContato(contatos);
                break;

            case 3:
                excluirContato(contatos);
                break;

            case 4:
                mandarMensagem(contatos);
                break;

            case 5:
                cout << "\nVocê Saiu!" << endl;
                menu = false;
                break;

            default:
                cout << "\nOpção inválida!" << endl;
                break;
        }
    }

    return 0;
}

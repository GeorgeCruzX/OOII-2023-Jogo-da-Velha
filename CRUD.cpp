#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;
class Pessoa {
private:
    string nome;
    string email;
    string telefone;
    int idade;
public:
    Pessoa(string n, string e, string t, int i)
        : nome(n), email(e), telefone(t), idade(i) {}

    string getNome(){ 
        return nome; 
    }
    string getEmail(){ 
        return email; 
    }
    string getTelefone(){ 
        return telefone; 
    }
    int getIdade(){ 
        return idade; 
    }
    void exibirInfo(){
        cout << "\nNome: " << nome << "\nEmail: " << email
                  << "\nTelefone: " << telefone << "\nIdade: " << idade << endl;
    }
};

void adicionarPessoa(string nomeArquivo, Pessoa pessoa) {
    ofstream arquivo(nomeArquivo, ios::app);  // Abre o arquivo em modo de adição
    
    if (arquivo.is_open()) {
        arquivo << pessoa.getNome() << "," << pessoa.getEmail() << ","
                << pessoa.getTelefone() << "," << pessoa.getIdade() << "\n";

        cout << "Pessoa adicionada com sucesso.\n";
    } else {
        cerr << "Erro ao abrir o arquivo para adicionar pessoa.\n";
    }
}

void listarPessoas(string nomeArquivo) {
    ifstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            // Processa cada linha para obter dados da pessoa
            string nome, email, telefone;
            int idade;

            istringstream iss(linha);
            getline(iss, nome, ',');
            getline(iss, email, ',');
            getline(iss, telefone, ',');
            
            iss >> ws >> idade;

            Pessoa pessoa(nome, email, telefone, idade);
            pessoa.exibirInfo();
        }

        arquivo.close();
    } else {
        cerr << "Erro ao abrir o arquivo para listar pessoas.\n";
    }
}
bool buscarPessoaPorNome(string nomeArquivo, string nomeBusca) {
    ifstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            string nome, email, telefone;
            int idade;

            istringstream iss(linha);
            getline(iss, nome, ',');
            getline(iss, email, ',');
            getline(iss, telefone, ',');
            iss >> idade;

            if (nome == nomeBusca) {
                Pessoa pessoa(nome, email, telefone, idade);
                pessoa.exibirInfo();
                arquivo.close();
                return true;
            }
        }

        arquivo.close();
        cout << "Pessoa nao encontrada.\n";
        return false;
    } else {
        cerr << "Erro ao abrir o arquivo para buscar pessoa.\n";
        return false;
    }
}

void editarPessoa(string nomeArquivo, string nomeBusca) {
    
    if (buscarPessoaPorNome(nomeArquivo, nomeBusca)) {
        ifstream arquivoEntrada(nomeArquivo);
        ofstream arquivoTemp("temp.txt");

        if (arquivoEntrada.is_open() && arquivoTemp.is_open()) {
            string linha;
            while (getline(arquivoEntrada, linha)) {
                string nome, email, telefone;
                int idade;

                istringstream iss(linha);
                getline(iss, nome, ',');
                getline(iss, email, ',');
                getline(iss, telefone, ',');
                iss >> idade;

                if (nome == nomeBusca) {
                    string novoNome, novoEmail, novoTelefone;
                    int novaIdade;

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Digite o novo nome: ";
                    getline(std::cin, novoNome);

                    cout << "Digite o novo email: ";
                    getline(std::cin, novoEmail);

                    cout << "Digite o novo telefone: ";
                    getline(std::cin, novoTelefone);

                    cout << "Digite a nova idade: ";
                    cin >> novaIdade;

                    arquivoTemp << novoNome << "," << novoEmail << ","
                                << novoTelefone << "," << novaIdade << "\n";

                    cout << "Pessoa editada com sucesso.\n";
                } else {
                    arquivoTemp << linha << "\n";
                }
            }

            arquivoEntrada.close();
            arquivoTemp.close();

            // Substitui o arquivo original pelo temporário
            remove(nomeArquivo.c_str());
            rename("temp.txt", nomeArquivo.c_str());
        } else {
            cerr << "Erro ao abrir o arquivo para editar pessoa.\n";
        }
    }
    
}
void excluirPessoa(string nomeArquivo, string nomeExclusao) {
    if (buscarPessoaPorNome(nomeArquivo, nomeExclusao)) {
        ifstream arquivoEntrada(nomeArquivo);
        ofstream arquivoTemp("temp.txt");

        if (arquivoEntrada.is_open() && arquivoTemp.is_open()) {
            string linha;
            while (getline(arquivoEntrada, linha)) {
                string nome, email, telefone;
                int idade;

                istringstream iss(linha);
                getline(iss, nome, ',');
                getline(iss, email, ',');
                getline(iss, telefone, ',');
                iss >> idade;

                if (nome != nomeExclusao) {
                    arquivoTemp << linha << "\n";
                } else {
                    cout << "Pessoa excluida com sucesso.\n";
                }
            }

            arquivoEntrada.close();
            arquivoTemp.close();

            remove(nomeArquivo.c_str());
            rename("temp.txt", nomeArquivo.c_str());
        } else {
            cerr << "Erro ao abrir o arquivo para excluir pessoa.\n";
        }
    }
}

Pessoa criar(){
    string nome, email, telefone;
    int idade;

    cout<<"\nCadastrar Pessoa\n";
    cout<<"Digite o Nome: ";
    cin>>nome;
    cout<<"Digite o E-mail: ";
    cin>>email;
    cout<<"Digite o Telefone: ";
    cin>>telefone;
    cout<<"Digite a Idade: ";
    cin>>idade;

    Pessoa pessoa(nome, email, telefone, idade);
    return pessoa;
}

void menuOpcoes(int op){
    const std::string nomeArquivo = "pessoas.txt";
    string nome;
    switch (op)
    {
    case 1:
        system("cls");
        adicionarPessoa(nomeArquivo, criar());
        break;
    case 2:
        system("cls");
        listarPessoas(nomeArquivo);
        system("pause");
        break;
    case 3:
        system("cls");
        cout<<"\nDigite o nome da Pessoa: ";
        cin>>nome;
        editarPessoa(nomeArquivo, nome);
        break;
    case 4:
        system("cls");
        cout<<"\nDigite o nome da Pessoa: ";
        cin>>nome;
        excluirPessoa(nomeArquivo, nome);
        break;
    case 5:
        system("cls");
        std::cout<<"Saindo...\n";
        break;
    
    default:
        system("cls");
        std::cout<<"Opcao invalida\n";
        break;
    }
}

void menu(){
    int op = 0;
    system("cls");
    while (op != 5)
    {
        std::cout<<"1 - Cadastrar Pessoa\n";
        std::cout<<"2 - Listar Pessoas\n";
        std::cout<<"3 - Editar Pessoa\n";
        std::cout<<"4 - Excluir Pessoa\n";
        std::cout<<"5 - Sair\n";
        std::cin>>op;
        menuOpcoes(op);
    }
}

    


int main() {
    
    menu();

    return 0;

}

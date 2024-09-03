/* =======================================================================
GRUPO:
 - Fabio Damas Valim (202410372)
 - Guilherme Lirio Miranda (202410367)
 - Marcos Vinicius Pereira (202411098)
TEMA:
 - Atletas
CAMPOS:
 - Id (inteiro)
 - Nome (string)
 - Data de nascimento (inteiro)
 - Esporte (string)
 - Nacinalidade (string)
========================================================================== */

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;

struct atleta{
    int id;
    char nome[50];
    int nascimento;
    char esporte[50];
    char nacionalidade[50];
};

int particiona_lomuto(atleta* v, int p, int r, int opcao) {
    //Algoritmo de particionamento do vetor para ser utilizado no quicksort
    //Iremos particionar de acordo com a opcao escolhida pelo usuario 
    if(opcao == 4) {//Nessa opcao ocorrera o particionamento em relacao ao id
        int pivo = v[r].id;
        int j = p;
        int k;
        for (k = p; k < r; k++) {
            if (v[k].id <= pivo) {
                swap(v[j], v[k]);
                j++; 
            } 
        }
        swap(v[j], v[r]);
        return j;
    } else if(opcao == 9) {//Nessa opcao ocorrera o particionamento em relacao ao nome
        string pivo = v[r].nome;
        int j = p;
        int k;
        for (k = p; k < r; k++) {
            if (v[k].nome <= pivo) {
                swap(v[j], v[k]);
                j++; 
            }
        }
        swap(v[j], v[r]);
        return j;
    } else if (opcao == 10) {//Particionamento em relacao ao ano de nascimento
        int pivo = v[r].nascimento;
        int j = p;
        int k;
        for (k = p; k < r; k++) {
            if (v[k].nascimento <= pivo) {
                swap(v[j], v[k]);
                j++; 
            } 
        }
        swap(v[j], v[r]);
        return j;
    }
    return -1;
}

void quicksort(atleta* vetor, int pos_pivo, int fim, int opcao) {      
    if(opcao == 4) {//ordena o vetor com base no numero ID
        int pos_novo_pivo;         
        if (pos_pivo < fim) {  
        pos_novo_pivo = particiona_lomuto(vetor, pos_pivo, fim,4);
        quicksort(vetor, pos_pivo, pos_novo_pivo - 1,4); 
        quicksort(vetor, pos_novo_pivo + 1, fim,4); 
        }
    } else if(opcao == 9) {//ordena o vetor com base no nome do atleta
        int pos_novo_pivo;         
        if (pos_pivo < fim) {  
        pos_novo_pivo = particiona_lomuto(vetor, pos_pivo, fim,9);
        quicksort(vetor, pos_pivo, pos_novo_pivo - 1,9); 
        quicksort(vetor, pos_novo_pivo + 1, fim,9); 
        }
    } else if(opcao == 10) {//ordena o vetor com base no ano de nascimento
        int pos_novo_pivo;         
        if (pos_pivo < fim) {  
        pos_novo_pivo = particiona_lomuto(vetor, pos_pivo, fim,10);
        quicksort(vetor, pos_pivo, pos_novo_pivo - 1,10); 
        quicksort(vetor, pos_novo_pivo + 1, fim,10); 
        }
    }
}

int busca_binaria(atleta* album, int num_registros, int procurado) {
    //busca binaria
    //a funcao retorna a posicao do elemento procurado
    int inicio = 0;
    int fim = (num_registros - 1);
    int meio = (inicio + fim) / 2;

    while(inicio <= fim) {
        if(procurado == album[meio].id) {
            return meio;
        } else if(procurado > album[meio].id) {
            inicio = (meio + 1);
            meio = (inicio + fim) / 2;
        } else if(procurado < album[meio].id) {
            fim = (meio - 1);
            meio = (inicio + fim) / 2;
        }
    }
    //caso o elemento nao seja encontrado o programa retorna -1
    return -1;
}

void listar_registros(atleta* album, int num_registros) {
    //lista todos os registros armazenados no vetor album
    for(int i = 0; i < num_registros; i++) {
        cout << "( " <<  album[i].id << " ) ";
        cout << album[i].nome << " - ";
        cout << album[i].nascimento << " - ";
        cout << album[i].esporte << " - ";
        cout << album[i].nacionalidade << endl;
    }
}

void listar_registros_intervalo(atleta* album, int c, int f) {
    //lista os registros armazenados no vetor album no intervalo(c -> f)
    //O usuario deve inserir o intervalo de id's que deseja visualizar
    for(int i = (c-1); i < f; i++) {
        cout << "( " <<  album[i].id << " ) ";
        cout << album[i].nome << " - ";
        cout << album[i].nascimento << " - ";
        cout << album[i].esporte << " - ";
        cout << album[i].nacionalidade << endl;
    }
}

void incluir_registro(atleta* &album, int &num_registros) {
    cout << endl;
    //Iremos redimensionar o vetor em +1 posicao para que nao tenha risco
    //de uso indevido de memoria
    num_registros++;
    atleta* novo_album = new atleta[num_registros];
    for(int i = 0; i < (num_registros-1); i++) {
        //copiando os elementos para o vetor redimensionado
        novo_album[i] = album[i];
    }
    delete[] album;
    album = novo_album;
    
    album[num_registros-1].id = num_registros;

    cout << "Nome do atleta: ";
    cin.ignore();
    cin.getline(album[num_registros-1].nome, 50);
    cout << "Ano de nascimento: ";
    cin >> album[num_registros-1].nascimento;
    cout << "Esporte: ";
    cin.ignore();
    cin.getline(album[num_registros-1].esporte, 50);
    cout << "Pais de origem: ";
    cin.getline(album[num_registros-1].nacionalidade, 50);;
    
    cout << endl;
    cout << "*  Atleta registrado com sucesso!  *" << endl;
    cout << endl;
}

void excluir_registro(atleta* &album, int num_registros) {
    //procedimento que exclui um determinado registro selecionado pelo usuario
    //o usuario devera digitar o id que deseja excluir da lista
    int identificador, opcao;

    //iremos garantir que o vetor esteja ordenado para que seja realizada a 
    //busca binaria
    quicksort(album,0,(num_registros-1),5);

    cout << endl;
    cout << "Digite o id que deseja excluir: ";
    cin >> identificador;

    //chamamos a funcao de busca binaria para verificar se o id existe
    if(busca_binaria(album, num_registros, identificador) != (-1)) {
        //Se a busca nao retornar -1 significa que o id existe no vetor
        //O programa certifica se o usuario deseja de fato excluir o registro
        cout << "Tem certeza que deseja excluir o registro abaixo? " << endl;
        cout << "( " <<  album[identificador-1].id << " ) ";
        cout << album[identificador-1].nome << " - ";
        cout << album[identificador-1].nascimento << " - ";
        cout << album[identificador-1].esporte << " - ";
        cout << album[identificador-1].nacionalidade << endl;
        cout << endl;
        cout << "1 - SIM" << endl << "2 - NAO" << endl;
        cin >> opcao;

        //para excluir um registro, sinalizamos com valor -1 para todos os campos
        //os registros sinalizados serao descartados quando forem salvos em um
        //novo arquivo
        if(opcao == 1) {
            album[identificador-1].id = -1;
            album[identificador-1].nome[0] = '\0';
            album[identificador-1].nascimento = '\0';
            album[identificador-1].esporte[0] = '\0';
            album[identificador-1].nacionalidade[0] = '\0';
            cout << endl;
            cout << "*  Registro excluido com sucesso!  *" << endl;
            cout << endl;
        } else if(opcao == 2) {
            //caso o usuario mude de ideia e nao queira mais excluir, o menu sera
            //aberto novamente e o programa nao ira realizar a exclusao
            cout << endl;
        }
    } else {
        //caso a busca binaria retorne -1, ou seja, o id digitado pelo usuario
        //nao foi encontrado no vetor
        cout << endl;
        cout << "*  id invalido!  *" << endl;
        cout << endl;
    }
}

void buscar_id(atleta* album, int num_registros) {
    //Primeiro ordena-se o vetor pelo numero id para que seja chamada
    //a busca binaria
    quicksort(album,0,(num_registros-1),4);

    int procurado;

    cout << "Digite o id que deseja buscar: ";
    cin >> procurado;

    int indice = busca_binaria(album,num_registros,procurado);

    if(indice == -1) {
        cout << "*  Registro nao encontrado!  *" << endl;
    } else {
        cout << "\n*  Registro encontrado com sucesso!  *" << endl;
        cout << "( " <<  album[indice].id << " ) ";
        cout << album[indice].nome << " - ";
        cout << album[indice].nascimento << " - ";
        cout << album[indice].esporte << " - ";
        cout << album[indice].nacionalidade << endl;
        cout << endl;
    }
    
}

int busca_binaria_nome(atleta* album, int num_registros, string procurado) {
    //busca binaria
    //a funcao retorna a posicao do elemento procurado
    int inicio = 0;
    int fim = (num_registros - 1);
    int meio = (inicio + fim) / 2;

    while(inicio <= fim) {
        if(procurado == album[meio].nome) {
            return meio;
        } else if(procurado > album[meio].nome) {
            inicio = (meio + 1);
            meio = (inicio + fim) / 2;
        } else if(procurado < album[meio].nome) {
            fim = (meio - 1);
            meio = (inicio + fim) / 2;
        }
    }
    //caso o elemento nao seja encontrado o programa retorna -1
    return -1;
}

void buscar_nome(atleta* album, int num_registros) {
    char nome[50];

    cout << "Digite o nome do atleta que deseja buscar: ";
    cin.ignore();
    cin.getline(nome, 50);

    //Primeiro iremos ordenar o vetor por nome para que seja realizada a busca binaria
    quicksort(album,0,(num_registros-1),9);

    int indice = busca_binaria_nome(album,num_registros,nome);

    if(indice == -1) {
        cout << "*  Registro nao encontrado!  *" << endl;
        cout << endl;
    } else {
        cout << "\n*  Registro encontrado com sucesso!  *" << endl;
        cout << "( " <<  album[indice].id << " ) ";
        cout << album[indice].nome << " - ";
        cout << album[indice].nascimento << " - ";
        cout << album[indice].esporte << " - ";
        cout << album[indice].nacionalidade << endl;
        cout << endl;
    }
}

void importarBinario(atleta* &album, int &num_registros) {
    cout << "Digite o nome do arquivo binario (com extensao):" << endl;
    string arq;
    cin >> arq;
    
    ifstream arquivoBin(arq, ios::binary);

    //primeiro iremos realizar quantos registros nosso arquivo possui
    atleta cont;
    while (arquivoBin.read(reinterpret_cast<char *>(&cont), sizeof(atleta))) {
        num_registros++;
    }

    arquivoBin.clear();
    arquivoBin.seekg (0, arquivoBin.beg);//retornamos para o inicio do registro
    //Passando os registros do arquivo binario para o vetor
    //e redimensionando o vetor quando necessario
    int tamanho = 40;
    for(int i = 0; i < num_registros; i++) {
        if(i == tamanho) {
            //condicao que ira redimensionar o vetor de 10 em 10 posicoes
            //quando necessario
            atleta* novo_album = new atleta[tamanho + 10];
            for(int j = 0; j < tamanho; j++) {
                //copiando os elementos para o vetor redimensionado
                novo_album[j] = album[j];
            }
            tamanho += 10;
            delete[] album;
            album = novo_album;
        }

        arquivoBin.read(reinterpret_cast<char *>(&album[i]),sizeof(album[i]));
    }
}

void importarCsv(atleta* &album, int &num_registros) {
    cout << "Digite o nome do arquivo CSV (com extensao):" << endl;
    string arq;
    cin >> arq;

    ifstream arquivoCsv(arq);

    string linha;

    //primeiro contamos quantas linhas nosso arquivo csv possui
    //isto é, a quantidade de registros
    while(getline(arquivoCsv, linha)) {
        num_registros++;
    }
    
    num_registros -= 1;//retirar a contagem do cabecalho

    arquivoCsv.clear();
    arquivoCsv.seekg (0, arquivoCsv.beg);//retornamos a leitura para o inicio do arquivo
    
    getline(arquivoCsv,linha);//ignora o cabecalho

    //Passando os registros do arquivo csv para o vetor
    //e redimensionando de acordo com a necessidade
    int tamanho = 40;
    for(int i = 0; i < num_registros; i++) {
        if(i == tamanho) {
            //condicao que ira redimensionar o vetor de 10 em 10 posicoes
            //quando necessario
            atleta* novo_album = new atleta[tamanho + 10];
            for(int j = 0; j < tamanho; j++) {
                //copiando os elementos para o vetor redimensionado
                novo_album[j] = album[j];
            }
            tamanho += 10;
            delete[] album;
            album = novo_album;
        }
    
        string registroString;
        char lixo;//ignora a virgula

        arquivoCsv >> album[i].id;//lendo o id
        arquivoCsv >> lixo;

        getline(arquivoCsv,registroString,',');//lendo o nome como string e transformando
        strcpy(album[i].nome, registroString.c_str());//em um vetor de caracteres
        
        arquivoCsv >> album[i].nascimento;//ano de nascimento
        arquivoCsv >> lixo;
        
        getline(arquivoCsv,registroString,',');//esporte
        strcpy(album[i].esporte, registroString.c_str());

        getline(arquivoCsv,registroString);//nacionaliade
        strcpy(album[i].nacionalidade, registroString.c_str());
    }
}

void exportarCsv(atleta* &album, int num_registros) {
    ofstream gravaCsv("arquivo-exportado.csv");

    gravaCsv << "id,nome,ano de nascimento,esporte,nacionalidade" << endl;

    for(int i = 0; i < num_registros; i++) {
        if(album[i].id > 0) {
            gravaCsv << album[i].id << ",";
            gravaCsv << album[i].nome << ",";
            gravaCsv << album[i].nascimento << ",";
            gravaCsv << album[i].esporte << ",";
            gravaCsv << album[i].nacionalidade << endl;
        }
    }
}

void gravarAlteracoes(atleta* &album, int num_registros) {
    //As alteracoes serao gravadas em um arquivo binario
    ofstream gravaBin("novo-registros.bin", ios::binary);

    for(int i = 0; i < num_registros; i++) {
        if(album[i].id > 0) {//os arquivos excluidos nao serao gravados
            gravaBin.write(reinterpret_cast<const char*>(&album[i]), sizeof(atleta));
        }
    }
}

int main() {
    atleta* album = new atleta[40];

    int num_registros = 0;

    //A variavel "verifica" indica se o programa ira chamar o menu novamente ou nao
    bool verifica = true;
    bool inclusao = false;
    int opcao;
    string arq;
    while(verifica) {
        //O menu sera chamado toda vez que o programa finalizar uma opcao
        cout << "*-------------------- MENU -----------------------*" << endl;
        cout << "|                                                 |"<< endl;
        cout << "| Digite:                                         |"<< endl;
        cout << "| 1 - Importar arquivo binario                    |"<< endl;
        cout << "| 2 - Importar arquivo CSV                        |"<< endl;
        cout << "| 3 - Exportar arquivo CSV                        |"<< endl;
        cout << "| 4 - Para listar registros                       |"<< endl;
        cout << "| 5 - Para incluir um registro                    |"<< endl;
        cout << "| 6 - Para excluir um registro                    |"<< endl;
        cout << "| 7 - Buscar registro por id                      |"<< endl;
        cout << "| 8 - Buscar registro por nome                    |"<< endl;
        cout << "| 9 - Ordenar registros por nome                  |"<< endl;
        cout << "| 10 - Ordenar registros por ano de nascimento    |"<< endl;
        cout << "| 11 - Gravar alteracoes                          |"<< endl;
        cout << "| 0 - Para sair                                   |"<< endl;
        cout << "|                                                 |"<< endl;
        cout << "*-------------------------------------------------*"<< endl;

        cin >> opcao;

        //Executa a ação com base na opção escolhida
        switch(opcao) {
        case 1:
            if(!inclusao) {
                importarBinario(album, num_registros);
                cout << endl;
                cout << "*  Arquivo binario importado com sucesso!  *" << endl;
                inclusao = true;
                cout << endl;
            } else {
                cout << endl;
                cout << "*  O programa ja foi inicializado com um arquivo!  *" << endl;
                cout << endl;
            }
            break;
        case 2:
            if(!inclusao) {
                importarCsv(album, num_registros);
                cout << endl;
                cout << "*  Arquivo CSV importado com sucesso!  *" << endl;
                inclusao = true;
                cout << endl;
            } else {
                cout << endl;
                cout << "*  O programa ja foi inicializado com um arquivo!  *" << endl;
                cout << endl;
            }
            break;
        case 3:
            exportarCsv(album, num_registros);
            cout << endl;
            cout << "*  Arquivo exportado com sucesso (arquivo-exportado.csv)" << endl;
            cout << endl;
            break;
        case 4:
            if(inclusao) {
                int c, f;
                quicksort(album, 0, (num_registros-1),4);
                cout << "Digite o intervalo de registros que deseja listar (1 - " << num_registros <<
                ")" << endl;
                cout << "inicio: ";
                cin >> c;
                cout << "fim: ";
                cin >> f;
                cout << endl;
                listar_registros_intervalo(album, c, f);
                cout << endl;
            } else {
                cout << endl;
                cout << "*  O programa ainda nao foi inicializado com nenhum arquivo de registros!  *" << endl;
                cout << endl;
            }
            break;
        case 5:
            if(inclusao) {
                incluir_registro(album, num_registros);
            } else {
                cout << endl;
                cout << "*  O programa ainda nao foi inicializado com nenhum arquivo de registros!  *" << endl;
                cout << endl;
            }
            break;
        case 6:
            if(inclusao) {        
                excluir_registro(album, num_registros);
            } else {
                cout << endl;
                cout << "*  O programa ainda nao foi inicializado com nenhum arquivo de registros!  *" << endl;
                cout << endl;
            }
            break;
        case 7:
            if(inclusao) {
                buscar_id(album , num_registros);
            } else {
                cout << endl;
                cout << "*  O programa ainda nao foi inicializado com nenhum arquivo de registros!  *" << endl;
                cout << endl;
            }
            break;
        case 8:
            if(inclusao) {
                buscar_nome(album , num_registros);
            } else {
                cout << endl;
                cout << "*  O programa ainda nao foi inicializado com nenhum arquivo de registros!  *" << endl;
                cout << endl;
            }
            break;
        case 9:
            if(inclusao) {
                quicksort(album, 0, (num_registros-1), 9);
                listar_registros(album, num_registros);
                cout << "\n*  Registros ordenados por nome com sucesso!  *" << endl;
                cout << endl;
            } else {
                cout << endl;
                cout << "*  O programa ainda nao foi inicializado com nenhum arquivo de registros!  *" << endl;
                cout << endl;
            }
            break;
        case 10:
            if(inclusao) {
                quicksort(album, 0, (num_registros-1),10);
                listar_registros(album, num_registros);
                cout << "\n*  Registros ordenados por data de nascimento com sucesso!  *" << endl;
                cout << endl;
            } else {
                cout << endl;
                cout << "*  O programa ainda nao foi inicializado com nenhum arquivo de registros!  *" << endl;
                cout << endl;
            }
            break;
        case 11:
            if(inclusao) {
                gravarAlteracoes(album , num_registros);
                cout << "\n*  Salvo com sucesso (novo-registros.bin)  *" << endl;
                cout << endl;
            } else {
                cout << endl;
                cout << "*  O programa ainda nao foi inicializado com nenhum arquivo de registros!  *" << endl;
                cout << endl;
            }
            break;
        case 0:
            //caso o usuario digite 0 o menu nao sera chamado novamente
            verifica = false;
            cout << endl;
            break;
        }
    }

    cout << "*  Fim do programa!  *" << endl;

    delete[] album;
    return 0;
}
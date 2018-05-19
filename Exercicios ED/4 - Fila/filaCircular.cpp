// fila implementada em arranjo (circular)
#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Dado;

class fila {
    private:
        int capacidade;
        Dado *dados;
        int tamanho;
        int posInicio;
        int posFim;
    public:
        fila (int cap = 100);
        ~fila ();
        void enfileira (Dado valor);
        Dado desenfileira ();
        Dado espia (); // acessa elemento do topo, mas não retira
        void depura (); // imprime os dados do vetor da fila
        void info ();  // imprime informações da fila (tamanho, posInicio, posFim, etc.
    protected :
        void PosCabRab ();
};

fila::fila (int cap) : capacidade(cap) {
    dados = new Dado[capacidade];
    posInicio = -1;
    posFim =-1;
    tamanho = 0;
}

void fila::enfileira (Dado valor) {
    if (tamanho == capacidade) {
        cerr << "capacidade máxima atinjida " << endl;
        return;
    }
    if (posInicio == -1)
        ++posInicio;
    ++posFim;
    dados[posFim] = valor;
    ++tamanho;
    cout << dados[posFim]  << endl;
    PosCabRab();
}

Dado fila::desenfileira () {
    if (tamanho == 0) {
        cerr << "Não existe elementos na fila" << endl;
        exit(EXIT_FAILURE);
    }
    Dado valorpos = dados[posInicio];
    dados[posInicio] = -1;
    ++posInicio;
    --tamanho;
    return valorpos;
}

Dado fila::espia () {
    return dados[posInicio];
}

void fila::depura () {
    cout << "|";
    if (posInicio < posFim) {
        for (int i = posInicio; i <= posFim; ++i) {
            cout << dados[i] << " [" << i <<"]" <<"****";
        }
    } else {
        for (int i = posInicio; i < capacidade; ++i) {
            cout << dados[i] << " [" << i <<"] " <<"****";
        }
        for (int i = 0; i <= posFim; i++) {
            cout << dados[i] <<" [" << i <<"] " <<"****";
        }
        
    }
    cout << "|" << endl;
}

void fila::PosCabRab () {
    if (posFim == capacidade-1)
        posFim = -1;
    if (posInicio == capacidade-1)
        posInicio = -1;
}

void fila::info () {
    cout << "Tamanho : " << tamanho << endl;
    cout << "Posição da Cabeça : " << posInicio << endl;
    cout << "Posição do Fim : " << posFim << endl;
    cout << "Capacidade Máxima " << capacidade << endl;
}

fila::~fila () {
    delete[] dados;
}

int main () {
    fila banco(6);
    banco.enfileira(5);
    banco.enfileira(6);
    banco.enfileira(4);
    banco.enfileira(9);
    banco.enfileira(3);
    banco.depura();
    banco.info();
    cout << banco.desenfileira() << endl;
    cout << banco.desenfileira() << endl;
    banco.enfileira(56);
    banco.enfileira(78);
    banco.enfileira(110);
    banco.enfileira(565);
    banco.espia();
    cout << banco.desenfileira() << endl;
    banco.enfileira(565);
    banco.depura();
    banco.info();
    
    return 0;
}


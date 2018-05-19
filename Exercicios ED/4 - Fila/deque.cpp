#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Dado;

class Noh {
	friend class Deque;
	private :
		Dado mConteudo;
		Noh* mProximo;
		Noh* mAnterior;
	public:
		Noh (Dado valor = 0);
};

Noh::Noh (Dado valor) : mConteudo(valor) {
	mProximo = NULL;
	mAnterior = NULL;
}

class Deque {
	private:
	    Noh* mEsquerda;
	    Noh* mDireita;
	    int mTamanho; 
	public:
	    Deque ();
	    ~Deque ();
	    void insereNaEsquerda (Dado dado);
	    void insereNaDireita (Dado dado);
	    Dado retiraEsquerda ();
	    Dado retiraDireita ();
	    Dado espiaEsquerda ();
	    Dado espiaDireita ();
	    void imprime ();
	    inline bool vazia ();
};

Deque::Deque () {
	mEsquerda = NULL;
	mDireita = NULL;
	mTamanho = 0;
}

void Deque::insereNaEsquerda(Dado dado) {
	Noh* novo  = new Noh(dado);
	if (vazia()) {
		mEsquerda = novo;
		mDireita = novo;
	}
	novo->mProximo = mEsquerda;
	mEsquerda->mAnterior = novo;
	mEsquerda = novo;
	++mTamanho;
}

void Deque::insereNaDireita(Dado dado) {
	Noh* novo  = new Noh(dado);
	if (vazia()) {
		mEsquerda = novo;
		mDireita = novo;
	}
	mDireita->mProximo = novo;
	novo->mAnterior = mDireita;
	mDireita = novo;
	++mTamanho;
}

Dado Deque::retiraEsquerda () {
	if (vazia()) {
		cerr << "Não existe itens ! " << endl;
		exit(EXIT_FAILURE);
	}
	Dado valoresq = mEsquerda->mConteudo;
	Noh* aquelequemorre = mEsquerda;
	Noh* aux = mEsquerda->mProximo;
	aux->mAnterior = NULL;
	mEsquerda = aux;
	--mTamanho;
	delete aquelequemorre;
	return valoresq;
}

Dado Deque::retiraDireita () {
	if (vazia()) {
		cerr << "Não existe itens ! " << endl;
		exit(EXIT_FAILURE);
	}
	Dado valordir = mDireita->mConteudo;
	Noh* aquelequemorre = mDireita;
	Noh* aux = mDireita->mAnterior;
	aux->mProximo = NULL;
	mDireita = aux;
	--mTamanho;
	delete aquelequemorre;
	return valordir;
}

inline bool Deque::vazia() {
	return mEsquerda == NULL;
}

 Dado Deque::espiaEsquerda () {
 	return mEsquerda->mConteudo;
 }

 Dado Deque::espiaDireita () {
 	return mDireita->mConteudo;
 }

void Deque::imprime () {
	char extremidade;
	cin >> extremidade;
	switch (extremidade) {
		case 'e': 
		{
			Noh* aux = mEsquerda;
			while (aux != NULL) {
				cout << "[" << aux->mConteudo << "]" << "<-->";
				aux = aux->mProximo;
			}
			cout << "NULL" << endl;
			break;
		}
		case 'd' :
		{
			Noh* aux = mDireita;
			while (aux != NULL) {
				cout << "[" << aux->mConteudo << "]" << "<-->";
				aux = aux->mAnterior;
			}
			cout << "NULL";
			break;
		}
		default :
		{
			cout << "Extremidade inválida " << endl;
			imprime();
		}
	}
}

Deque::~Deque () {
	Noh* aux = mEsquerda;
	Noh* aquelequemorre;
	while (aux != NULL) {
		aquelequemorre = aux;
		aux = aux->mProximo;
		delete aquelequemorre;
	}
	mTamanho = 0;
	mEsquerda = NULL;
	mDireita = NULL;
}

int main () {
	int tam = 5, num;
	Deque passarela;
	for (int i = 0; i < tam; ++i) {
		cin >> num;
		passarela.insereNaDireita(num);
	}
	cin >> num;
	passarela.insereNaEsquerda(num);
	passarela.insereNaEsquerda(6);
	cout << passarela.espiaDireita() << endl;
	cout << passarela.espiaEsquerda() << endl;
	passarela.imprime();
	return 0;
}
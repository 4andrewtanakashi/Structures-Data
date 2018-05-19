//Coloca Em uma extremidade e tira da outra extremidade.

#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Dado;

class Noh {
	friend class Fila;
	public :
		Noh (Dado d = 0);
	private :
		Noh* mProximo;
		Dado mConteudo;
};

Noh::Noh(Dado d) : mConteudo(d) 
{
	mProximo = NULL;
}

class Fila {
	friend class Pilha;
	public :
		Fila();
		void Enfilera (Dado valor);
		Dado Desenfilera ();
		bool PossuiEle ();
	private :
		Noh* mInicio;
		Noh* mFim;
		int mTamanho;
		void RemoveTodos ();
	protected :
		inline bool Vazia ();
};

class Pilha {
	public:
		Pilha (){};
		~Pilha ();
		void Empilha (Dado valor);
		Dado Desempilha ();
	protected:
		Fila fila1;
		Fila fila2;
	private :
		Dado DesempilhaFila1 ();
		Dado DesempilhaFila2 ();
};

Fila::Fila () {
	mInicio = NULL;
	mFim = NULL;
	mTamanho = 0;
}

void Fila::Enfilera (Dado valor)
{
	Noh* novo = new Noh(valor);
	if(Vazia()) {
		mInicio = novo;
		mFim = novo;
	} else {
		mFim->mProximo = novo;
		mFim = novo;
	}
	++mTamanho;
}

Dado Fila::Desenfilera ()
{
	if(mTamanho > 0) {
		Dado valcont = mInicio->mConteudo;
		Noh* aquelequemorrre = mInicio;
		Noh* aux = mInicio->mProximo;
		mInicio = aux;
		delete aquelequemorrre;
		--mTamanho;
		return valcont;
	}
	cerr << "A Fila está vazia" << endl;
	exit(EXIT_FAILURE);
}

bool Fila::PossuiEle () 
{
	if(Vazia()) {
		return false;
	} else
	return true;
}

inline bool Fila::Vazia () 
{
	return (mInicio == NULL);
}

void Fila::RemoveTodos ()
{
	Noh* aux = mInicio;
	Noh* aquelequemorre;
	while (aux != NULL) {
		aquelequemorre = aux;
		aux = aux->mProximo;
		delete aquelequemorre;
	}
	mTamanho = 0;
	mInicio = NULL;
	mFim = NULL;
}

void Pilha::Empilha(Dado valor)
{
	fila1.Enfilera(valor);
}

Dado Pilha::Desempilha ()
{
	if (fila1.mTamanho == 1) {
		fila2.Enfilera(fila1.Desenfilera());
		return fila2.Desenfilera();
	}
	if ((fila1.mTamanho > 0) and (fila1.PossuiEle() == 1)) {
		return DesempilhaFila1();
	}
	return DesempilhaFila2();
}

Dado Pilha::DesempilhaFila1 () {
	Dado salvavalor = 0;
	while (fila1.mTamanho > 0) {
		fila2.Enfilera(fila1.Desenfilera());
		if ((fila1.mTamanho == 1)) {
			salvavalor = fila1.Desenfilera();
		} else if ((fila1.mTamanho == 0) and (fila2.mTamanho == 1)) {
			salvavalor = fila2.Desenfilera();
		}
	}
	return salvavalor;
}

Dado Pilha::DesempilhaFila2 () {
	Dado salvavalor = 0;
	while (fila2.mTamanho > 0) {
		fila1.Enfilera(fila2.Desenfilera());
		if (fila2.mTamanho == 1) {
			salvavalor = fila2.Desenfilera();
		} else if ((fila2.mTamanho == 0) and (fila1.mTamanho == 1)) {
			salvavalor = fila1.Desenfilera();
		}
	}
	return salvavalor;
}

Pilha::~Pilha ()
{
	fila1.RemoveTodos();
	fila2.RemoveTodos();
}

int main() {
	Pilha pratos;
    pratos.Empilha(1);
    pratos.Empilha(2);
    pratos.Empilha(3);
    pratos.Empilha(4);
    cout << pratos.Desempilha() << endl;
    cout << pratos.Desempilha() << endl;
    cout << pratos.Desempilha() << endl;
    cout << pratos.Desempilha() << endl;
    pratos.Empilha(100);
    cout << pratos.Desempilha() << endl;
    pratos.Empilha(200);
    pratos.Empilha(201);
    cout << pratos.Desempilha() << endl;
    cout << pratos.Desempilha() << endl;
    return 0;
}
//Coloca Em uma extremidade e tira da outra extremidade.

#include <iostream>

using namespace std;

typedef int Dado;

class Noh {
	friend class Fila;
	public :
		Noh(Dado d=0);
	private :
		Noh* mProximo;
		Dado mConteudo;
};

Noh::Noh(Dado d) : mConteudo(d) {
	mProximo = NULL;
}

class Fila {
	public :
		Fila();
		void Enfilera(Dado valor);
		Dado Desenfilera();
		Dado Espia();
	private :
		Noh* mInicio;
		Noh* mFim;
		int mTamanho;
	protected :
		inline bool Vazia();
};

Fila::Fila() {
	mInicio = NULL;
	mFim = NULL;
	mTamanho = 0;
}

void Fila::Enfilera(Dado valor) {
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

Dado Fila::Desenfilera() {
	if(mTamanho > 0) {
		Dado valcont = mInicio->mConteudo;
		Noh* aquelequemorrre = mInicio;
		Noh* aux = mInicio->mProximo;
		mInicio = aux;
		delete aquelequemorrre;
		--mTamanho;
		return valcont;
	} else {
		cerr << "A Fila está vazia" << endl;
		return 0;
	}
	
}

Dado Fila::Espia() {
	if(Vazia()) {
		cout << "A Fila está vazia" << endl;
		return 0;
	} else
	return mInicio->mConteudo;
}

inline bool Fila::Vazia() {
	return(mInicio==NULL);
}

int main() {
    Fila mercado;
    mercado.Enfilera(1);
    mercado.Enfilera(2);
    mercado.Enfilera(3);
    mercado.Enfilera(4);
    cout <<" Espia : " <<mercado.Espia() << endl;
    cout <<"Desenfilera  :" << mercado.Desenfilera() << endl;
    cout <<"Desenfilera  :" << mercado.Desenfilera() << endl;
    cout <<"Desenfilera  :" << mercado.Desenfilera() << endl;
    cout <<"Desenfilera  :" << mercado.Desenfilera() << endl;
    return 0;
}

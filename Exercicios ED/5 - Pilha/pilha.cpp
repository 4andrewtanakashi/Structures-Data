//Coloca Em uma extremidade e tira da mesma extremidade.

#include <iostream>

using namespace std;

typedef int Dado;

class Noh {
	friend class Pilha; 
	public :
		Noh(Dado = 0);
	private :
		Dado mConteudo;
		Noh* mProximo;
};

Noh::Noh(Dado d) : mConteudo(d) {
	mProximo = NULL;
}

class Pilha {
	public :
		Pilha();
		void Empilha(Dado valor);
		Dado Desempilha();
		Dado Espia();
	private :
		Noh* mTopo;
		int mTamanho;
	protected :
		inline bool Vazia();
};

Pilha::Pilha() {
	mTopo = NULL;
	mTamanho = 0;
}

void Pilha::Empilha(Dado valor) {
	Noh* novo = new Noh(valor);
	if(Vazia()) {
		mTopo = novo;
	} else {
		novo->mProximo = mTopo;
		mTopo = novo;
	}
	++mTamanho;
}

Dado Pilha::Desempilha() {
	if(Vazia()) {
		cout << "A pilha esta fazia" << endl;
		return 0;
	} 
	Dado valorpos = mTopo->mConteudo;
	Noh* aux = mTopo->mProximo;
	Noh* aquelequemorre = mTopo;
	mTopo = aux;
	delete aquelequemorre;
	--mTamanho;
	return valorpos;
}

inline bool Pilha::Vazia() {
	return (mTopo==NULL);
}

Dado Pilha::Espia() {
	if(mTopo==NULL)
		return 0;
	return mTopo->mConteudo;
}

int main() {
	Pilha problemas;
	problemas.Empilha(10);
	problemas.Empilha(2);
	problemas.Empilha(33);
	problemas.Empilha(456);
	cout << problemas.Espia() << endl;
	cout << problemas.Desempilha() << endl;
	cout << problemas.Espia() << endl;
    return 0;
}

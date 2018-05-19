#include <iostream>
#include <cstdlib>

using namespace std;

typedef char Dado;

class Noh {
	friend class Pilha;
	private :
		Dado mDado;
		Noh* mProximo;
	public :
		Noh (Dado d = 0);
};

Noh::Noh (Dado d) : mDado(d) {
	mProximo = NULL;
}

class Pilha {
	private : 
		Noh* mTopo;
		int mTamanho;
	protected :
		inline bool Vazia ();
	public:
		Pilha();
		~Pilha();
		void Empilha (Dado valor);
		Dado Desempilha ();
		Dado Espia ();
		void EstaContido (string conjy);
};

Pilha::Pilha () {
	mTamanho = 0;
	mTopo = NULL;
}

void Pilha::Empilha (Dado valor) {
	Noh* novo  = new Noh(valor);
	if (Vazia()) {
		mTopo = novo;
	} else {
		novo->mProximo = mTopo;
		mTopo =novo;
	}
	++mTamanho;
}

Dado Pilha::Desempilha () {
	if (mTamanho == 0) {
		cerr << "Não existe itens " << endl;
		exit(EXIT_FAILURE);
	}
	Dado valorpos = mTopo->mDado;
	Noh* aquelequemorre = mTopo;
	mTopo = mTopo->mProximo;
	delete aquelequemorre;
	--mTamanho;
	return valorpos;
}

Dado Pilha::Espia () {
	return mTopo->mDado;
}

inline bool Pilha::Vazia () {
	return (mTopo == NULL);
}

void Pilha::EstaContido (string conjy) {
	Pilha inverso;
	if (mTamanho != conjy.length()) {
		cout << "Não possui o mesmo mTamanho " << endl;
	 }
	 Dado letra;
	 unsigned int contvdd = 0;
	 for (int i = 0; i < conjy.length(); ++i) {
	 	letra = this->Desempilha();
	 	if (letra == conjy[i]) {
	 		++contvdd;
	 	}
	 }
	 if (contvdd == conjy.length()) {
	 	cout << " XcY " << endl;
	 } else
	 	cout << "X/cY" << endl;
}

Pilha::~Pilha () {
	Noh* aux = mTopo;
	Noh* aquelequemorre;
	while (aux != NULL) {
		aquelequemorre = aux;
		aux = aux->mProximo;
		delete aquelequemorre;
	}
	mTamanho = 0;
	mTopo = NULL;
}

int main () {
	string conjx, conjy;
	Pilha testainverso;
	cin >> conjx;
	 for (unsigned int i = 0; i < conjx.length(); ++i) {
	 	testainverso.Empilha(conjx[i]);
	 }
	 cin >> conjy;
	 testainverso.EstaContido(conjy);
	return 0;
}
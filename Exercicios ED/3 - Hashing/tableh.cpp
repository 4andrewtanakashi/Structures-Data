#include <iostream>

using namespace std;

const unsigned int NUMPRIMO = 13;

int FuncaoHash(string chave, unsigned int M) {
	int hash = 0;
	for(int i = 0; i < chave.length(); ++i) {
		hash = (NUMPRIMO*hash+chave[i])%M;
	}
	return hash;
}

class Noh {
	friend class TabelaHash;
	public :
		Noh() {
			mProximo = NULL;
			mChave = " ";
			mValor = " ";
		}
	protected :
		Noh* mProximo;
		string mChave;
		string mValor;
};

class TabelaHash {
	public:
		TabelaHash(unsigned int cap = 20);
		~TabelaHash();
		void Insere(string c, string v);
		string Verifica(string c);
		void ImprimeDebug();
	protected :
		Noh** mElementos;
		unsigned int mCapacidade;
};

TabelaHash::TabelaHash(unsigned int cap) : mCapacidade(cap) {
	mElementos = new Noh*[cap];
	for(unsigned int i = 0; i < cap; ++i) 	{
		mElementos[i] = NULL;
	}
}

void TabelaHash::Insere(string c, string v) {
	int h = FuncaoHash(c, mCapacidade);
	if(Verifica(c) == "Nao encontrado") {
		if(mElementos[h] == NULL) {
			mElementos[h] = new Noh;
			mElementos[h]->mChave = c;
			mElementos[h]->mValor = v;
		} else {
			cout << "Colidiu !" << endl;
			Noh* aux = mElementos[h];
			while(aux->mProximo != NULL) {
				aux = aux->mProximo;
			}
			Noh* novo = new Noh;
			novo->mChave = c;
			novo->mValor = v;
			aux->mProximo = novo;
		}
	} else {
		cout << "Esse elemento existe" << endl;
	}
}

string TabelaHash::Verifica(string c) {
	int h = FuncaoHash(c, mCapacidade);
	if((mElementos[h] != NULL) and (mElementos[h]->mChave == c)) {
		return mElementos[h]->mValor;
	} else {
		Noh* ptrele = mElementos[h];
		while((ptrele != NULL) and (ptrele->mChave == c)) {
			ptrele = ptrele->mProximo;
		}
		if((ptrele != NULL) and (ptrele->mChave == c)) {
			return ptrele->mValor;
		} else {
			return "Nao encontrado";
		}
	}
}

void TabelaHash::ImprimeDebug() {
	Noh* aux;
	for (int i = 0; i < mCapacidade; ++i) {
		aux = mElementos[i];
		while(aux!=NULL) {
			cout << "[" << aux->mChave << ", " <<
			aux->mValor << "] ->";
			aux = aux->mProximo;
		}
	}
	cout << "NULL" << endl;
}

TabelaHash::~TabelaHash() {
	for (int i = 0; i < mCapacidade; ++i) {
		Noh* aux = mElementos[i];
		Noh* aquelequemorre;
		while(aux!=NULL) {
			aquelequemorre = aux;
			aux = aux-> mProximo;
			delete aquelequemorre;
		}
	}
	delete[] mElementos;
}

int main() {
	TabelaHash tableh;
	tableh.Insere("Hi","Hell");
	tableh.Insere("Hi","Hell");
	tableh.Insere("Hi","Hell");
	tableh.Insere("ih","lleh");
	tableh.Insere("sa45d45","s4s4");
	tableh.Insere("ksk","sksks");
	tableh.Insere("lsls","s5sa46s5");
	tableh.Insere("skasksa222","21s51a");
	tableh.Insere("Tô","Ferrado");
	tableh.ImprimeDebug();
	return 0;
}
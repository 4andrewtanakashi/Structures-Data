#include <iostream>
#include <cstdlib>

using namespace std;
 
typedef int Dado;

class  Noh {
	friend class Lista;
	public :
		Noh(Dado valor = 0);
	protected :
		Noh* mProximo;
		Dado mConteudo;
 };

 Noh::Noh(Dado valor) : mConteudo(valor) {
 	mProximo = NULL; 
 }

 class Lista  {
	 public:
	 	Lista();
	 	Lista(const Lista& listactrlc);
	 	~Lista();
	 	void Insere(Dado valor);
	 	void InsereNoFim(Dado valor);
	 	void InsereNoInicio(Dado valor);
	 	void InsereNaPosicao(unsigned int pos, Dado valor);
	 	void Imprime();
	 	int Procura(Dado valor);
	 	inline bool Vazia();
	 	Lista& operator=(const Lista& listactrlc);
	 	Lista& operator+(const Lista& listactrlc);
	 	void ImprimeReverso();
	 	//void TrocaPos(unsigned int pri, unsigned int sec);
	 	//void RemoveRepetidos();
	 protected :
	 	Noh* mPrimeiro;
	 	Noh* mUltimo;
	 	unsigned int mTamanho;
	 private :
	 	void RemoveTodos();
	 	void AuxRecursivo(Noh* atual);
 };

 Lista::Lista() {
 	mPrimeiro = NULL;
 	mUltimo = NULL;
 	mTamanho = 0;
 }

 Lista::Lista(const Lista& listactrlc) {
 	mTamanho = 0;
 	mPrimeiro = NULL;
 	mUltimo = NULL;

 	Noh* aux = listactrlc.mPrimeiro;

 	while(aux != NULL) {
 		this->InsereNoFim(aux->mConteudo);
 		aux = aux->mProximo;
 	}
 }

void Lista::Insere(Dado valor) {
	InsereNoFim(valor);
}

void Lista::InsereNoFim(Dado valor) {
	Noh* novo = new Noh(valor);
	if(Vazia()) {
		mPrimeiro = novo;
		mUltimo = novo;
	} else {
		mUltimo->mProximo = novo;
		mUltimo = novo;
	}
	++mTamanho;
}

void Lista::InsereNoInicio(Dado valor) {
	Noh* novo = new Noh(valor);
	if(Vazia()) {
		mPrimeiro = novo;
		mUltimo = novo;
	} else {
		novo->mProximo = mPrimeiro;
		mPrimeiro = novo;
	}
	++mTamanho;
}

void Lista::InsereNaPosicao(unsigned int pos, Dado valor) {
	if((pos <= mTamanho) and (pos >= 0)) {
		Noh* novo = new Noh(valor);
		if(Vazia()) {
			mPrimeiro = novo;
			mUltimo = novo;
		} else {
			if(pos == 0) {
				InsereNoInicio(valor);
			} else {
				Noh* aux = mPrimeiro;
				unsigned int contapos = 0;
				while(contapos < pos-1) {
					aux = aux->mProximo;
					++contapos;
				}
				if(aux==NULL) {
					InsereNoFim(valor);
				} else {
					novo->mProximo = aux->mProximo;
					aux->mProximo = novo;
				}
				++mTamanho;
			}
		}
	} else {
		cerr << "posiscao inesistente " << endl;
		exit(EXIT_FAILURE);
	}
} 

void Lista::Imprime() {
	Noh* auximp = mPrimeiro;
	while(auximp != NULL) {
		cout << "[" << auximp->mConteudo << "]" <<
		"->";
		auximp = auximp->mProximo;
	}
	cout << "NULL" << endl;
}

Lista& Lista::operator=(const Lista& listactrlc) {
	RemoveTodos();
	Noh* aux = listactrlc.mPrimeiro;
	while(aux != NULL) {
		this->InsereNoFim(aux->mConteudo);
		aux = aux->mProximo;
	}
	return *this;
}

void Lista::RemoveTodos() {
	Noh* aux = mPrimeiro;
	Noh* aquelequemorre = NULL;
	while(aux != NULL) {
		aquelequemorre = aux;
		aux = aux->mProximo;
		delete aquelequemorre;
	}
	mTamanho = 0;
	mPrimeiro = NULL;
	mUltimo = NULL;
}

inline bool Lista::Vazia() {
	return (mPrimeiro==NULL);
}

int Lista::Procura(Dado valor) {
	Noh* aux = mPrimeiro;
	if(aux->mConteudo == valor) {
		return aux->mConteudo;
	}
	while((aux != NULL) and (aux->mConteudo != valor)) {
		aux = aux->mProximo;
	}
	 if(aux == NULL) {
		return -1;
	}
	return aux->mConteudo;
}

Lista& Lista::operator+(const Lista& listactrlc) {
	Noh* aux = listactrlc.mPrimeiro;
	int value = 0;
	while(aux != NULL) {
		value = Procura(aux->mConteudo);
		if(value != aux->mConteudo) {
			this->InsereNoFim(aux->mConteudo);
		}
		aux = aux->mProximo;
	}
	return *this;
}

void Lista::ImprimeReverso() {
	AuxRecursivo(mPrimeiro);
	cout << "NULL" << endl;
}

void Lista::AuxRecursivo(Noh* atual) {
	if(atual->mProximo!=NULL) {
		if(atual->mProximo!= NULL) {
			AuxRecursivo(atual->mProximo);
		}
		cout << "[" << atual->mConteudo << "]" << "->";
	}
	
}

Lista::~Lista() {
	Noh* aux = mPrimeiro;
	Noh* aquelequemorre = NULL;
	while(aux != NULL) {
		aquelequemorre = aux;
		aux = aux->mProximo;
		delete aquelequemorre;
	}
	mTamanho = 0;
	mPrimeiro = NULL;
	mUltimo = NULL;
}

 int main() {
 	Dado num = 0;
 	unsigned int posicao = 0;
 	unsigned int repeticao = 0;
 	cout << "Digite a quantidade de números que deseja inserir " << endl;
 	cin >> repeticao;
 	Lista minhalista;
 	for(unsigned int i = 0; i < repeticao; ++i) {
 		cin >> num;
 		minhalista.Insere(num);
 	}

 	Lista lista2;
 	lista2 = minhalista;
 	cout << "lista2" << endl;
 	lista2.Imprime();

 	cout << "num " << endl;
 	cin >> num;
 	minhalista.InsereNoInicio(num);
 	
 	cout << "posicao e num " << endl;
 	cin >> posicao;
 	cin >> num;
 	minhalista.InsereNaPosicao(posicao, num);

 	minhalista.Imprime();

 	cout << "Lista 3" << endl;
 	Lista Lista3(lista2);
 	Lista3.Imprime();

 	cout << "minhalista" << endl;
 	Lista3+minhalista;
 	Lista3.Imprime();

 	cout << "----------------------------" << endl;
 	cout << "Imprime Reverso : " << endl; 
 	Lista3.ImprimeReverso();

 	return 0;
 }
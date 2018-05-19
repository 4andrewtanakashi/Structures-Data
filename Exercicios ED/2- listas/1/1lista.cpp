#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Dado;

class Noh {
	friend class Lista;
	public:
		Noh(Dado d = 0);
	protected:
		Dado mDado;
		Noh* mProximo;
	private :
};

Noh::Noh(Dado d) : mDado(d) {
	mProximo = NULL;
}

class Lista {
	public:
		Lista();
		Lista(const Lista& listactrlc);
		~Lista();
		void Insere(Dado vdado);
		void InsereNoFim(Dado vdado);
		void InsereNoInicio(Dado vdado);
		void InsereNaPosicao(int posicao, Dado vdado);
		void Imprime();
		inline bool Vazia();
		void Remove(int posicao);
		int Procura(Dado valor);
		void ImprimeReverso();
		Noh* AcessaPosicao(int posicao);
		void ExibirConteudo(int pos);
		Lista& operator=(const Lista& listactrlc);
		Lista& operator+(const Lista& listactrlc);
		void TrocaDePosicao(unsigned int first, unsigned int second);
	protected:
		Noh* mPrimeiro;
		Noh* mUltimo;
		int mTamanho;
	private:
		void ImprimeReversoRecursivo(Noh* atual);
		void ApagaTudo();
};

Lista::Lista() {
	mPrimeiro = NULL;
	mUltimo = NULL;
	mTamanho = 0;
}

Lista::Lista(const Lista& listactrlc ) {
	mTamanho = 0;
	mPrimeiro = NULL;
	mUltimo = NULL;

	Noh* aux = listactrlc.mPrimeiro;
	while(aux != NULL) {
		this->InsereNoFim(aux->mDado);
		aux=aux->mProximo;
	}
}

void Lista::Insere(Dado vdado) {
	char qualinsers;
	cout << " Digite uma letra para iniciar a insercao " << endl;
	cin >> qualinsers;
	switch (qualinsers) {
		case 'i':
		{
			InsereNoInicio(vdado);
			break;
		}
		default :
		{
			InsereNoFim(vdado);
			break;
		}

	}
}

void Lista::InsereNoFim(Dado vdado) {
	Noh* novo = new Noh(vdado);

	if(Vazia()) {
		mPrimeiro = novo;
		mUltimo = novo;
	} 
	else {
		mUltimo->mProximo = novo;
		mUltimo = novo;
	}
	++mTamanho;
}

void Lista::InsereNoInicio(Dado vdado) {

	Noh* novo = new Noh(vdado);

	if(Vazia()) {
		mPrimeiro = novo;
		mUltimo = novo;
	} else {
		novo->mProximo = mPrimeiro;
		mPrimeiro = novo;
	}
	++mTamanho;
}

void Lista::Imprime() {
	Noh* aux = mPrimeiro;
	int i = 0;
	while(aux != NULL) {
		cout << "Valor no Noh : " <<"[" << i << "]" <<" "<< aux->mDado << endl;
		aux = aux->mProximo;
		++i;
	}
}

void Lista::InsereNaPosicao(int posicao, Dado vdado) {
	Noh* novo = new Noh(vdado);
	if((posicao <= mTamanho) and (posicao >= 0)) {
		if(Vazia()) {
			mPrimeiro = novo;
			mUltimo = novo;
		} else if(posicao == 0) {
			InsereNoInicio(vdado);
		} else if(posicao == mTamanho) {
			InsereNoFim(vdado);
		} else {
			Noh* aux = mPrimeiro;
			int contpos = 0;
			while(contpos < posicao - 1) {
				aux = aux->mProximo;
				++contpos;
			}
			novo->mProximo = aux->mProximo;
			aux->mProximo = novo;
		}
		++mTamanho;
	} else {
		cerr << "Deu certo nao so !!! " << endl;
		exit(EXIT_FAILURE);
	}
}

inline bool Lista::Vazia() {
	return (mPrimeiro==NULL);
}

void Lista::ApagaTudo() {
	Noh* aux = mPrimeiro;
	Noh* oquemorre;
	while(aux!=NULL) {
		oquemorre = aux;
		aux = aux->mProximo;
		delete oquemorre;
	}
	mTamanho = 0;
	mPrimeiro = NULL;
	mUltimo = NULL;
}

void Lista::Remove(int posicao) {
	Noh* auxquemorre = mPrimeiro;
	int posaux = 0;
	if((posicao < mTamanho) and (posicao >= 0)) {
		if(posicao == 0) {
			mPrimeiro = mPrimeiro->mProximo;
			delete auxquemorre;
		} else  {
			auxquemorre = auxquemorre->mProximo;
			Noh* anterior = mPrimeiro;
			posaux = 1;
			while((auxquemorre != NULL) and (posaux < posicao)) {
				anterior = auxquemorre;
				auxquemorre = auxquemorre->mProximo;
				++posaux;
			}
			if(auxquemorre == NULL) {
				anterior->mProximo = NULL;
				mUltimo = anterior;
				delete auxquemorre;
			} else {
				anterior->mProximo = auxquemorre->mProximo;
				delete auxquemorre;
			}
		}
		--mTamanho;
	} else {
		cerr << "Epa posicao doida !!! " << endl;
		exit(EXIT_FAILURE);
	}
	
}

int Lista::Procura(Dado valor) {
	Noh* investigador = mPrimeiro;
	int posproc = 0;
	if(investigador->mDado == valor) {
		return posproc;
	}
	while((investigador != NULL) and (investigador->mDado != valor)){
		investigador = investigador->mProximo;
		++posproc;
		if(investigador == NULL) {
			return -1;
		}
	}
	return posproc;
}

void Lista::ImprimeReverso() {
	ImprimeReversoRecursivo(mPrimeiro);
	cout << "Saiu do recursivo! "<< endl;
}

void Lista::ImprimeReversoRecursivo(Noh* atual) {
	cout << "atual->mProximo != NULL ?";
	if (atual->mProximo != NULL) {
		if (atual->mProximo != NULL) {
			cout << "Sim! Atual tem o valor: " << atual->mDado << endl;
			ImprimeReversoRecursivo(atual->mProximo);
		} else {
			cout << "Não! Agora vai comecar o retorno das chamadas recursivas!" << endl;
		}
		cout << "Sai do IF!" << endl;
		cout << atual->mDado << endl;
	}
}


Noh* Lista::AcessaPosicao(int posicao) {
	Noh* procurador = mPrimeiro;
	int posaux = 0;
	if(posicao == posaux) {
		return procurador;
	}
	if ((posicao < mTamanho) and (posicao >= 0)) {
		while((procurador != NULL) and (posaux < posicao)) {
			procurador = procurador->mProximo;
			++posaux;
		}
		
		return procurador;
	}
	cerr << "Ai tu mandou posicao errada !!!" << endl;
	procurador = NULL;
	return procurador;
}

void Lista::ExibirConteudo(int pos) {
	Noh* Acesso = AcessaPosicao(pos);
	if (Acesso == NULL) {
		cout << "Não deu certo, pos não existe !!!" << endl;
	} else
		cout << "mDado" <<" "<<Acesso->mDado << endl;
}

Lista& Lista::operator=(const Lista& listactrlc) {
	ApagaTudo();
	Noh* aux = listactrlc.mPrimeiro;
	while(aux!=NULL) {
		this->InsereNoFim(aux->mDado);
		aux=aux->mProximo;
	}
	return *this;
}

Lista& Lista::operator+(const Lista& listactrlc) {
	Noh* aux = listactrlc.mPrimeiro;
	while(aux!=NULL) {
		this->InsereNoFim(aux->mDado);
		aux=aux->mProximo;
	}
	return *this;
}

void Lista::TrocaDePosicao(unsigned int first, unsigned int second) {
	if((first<=mTamanho) and (second<mTamanho)) {
		if(first==0) {
			if(second==1) {
				Noh* aux = mPrimeiro;
				
				Noh* aux2 = mPrimeiro->mProximo;
				aux = aux2->mProximo;
				aux2->mProximo = aux;
				mPrimeiro = aux2;
			} 
		}

	}
}

Lista::~Lista() {
	Noh* aux = mPrimeiro;
	Noh* aquelequemorre;
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
	Dado num;
	Lista minhalista;
	cin >> num;
	while(num > -1) {
		if(num > -1) {
			minhalista.InsereNoFim(num);
		}
		cin >> num;
		
	}
	cout << "Insira a posicao e o elemento" << endl;
	int pos;
	cin >> pos;
	cin >> num;
	minhalista.InsereNaPosicao(pos,num);
	minhalista.Imprime();
	cout << "Insira posicao a ser removida " << endl;
	cin >> num;
	minhalista.Remove(num);
	minhalista.Imprime();
	cout << "Valor a ser procurado !!! " << endl;
	cin >> num;
	cout << minhalista.Procura(num) << endl;
	cout << "pos a ser procurado !!! " << endl;
	cin >> num;
	minhalista.ExibirConteudo(num);

	while(num > -1) {
		if(num > -1) {
		 	minhalista.Insere(num);
		}
		cin >> num;
	}
	
	Lista lista2(minhalista);
	cout << "------2_Lista : ---------" << endl;
	lista2.Imprime();
	cout <<"-------------------------- " << endl;
	
	Lista lista3=lista2;
	cout << "------3_Lista : ---------" << endl;
	lista3.Imprime();
	cout <<"-------------------------- " << endl;

	minhalista+lista2;
	cout << "------1_Lista : Expandida ---------" << endl;
	minhalista.Imprime();
	cout <<"-------------------------- " << endl;

	cout << "--------Imprime Reverso--------" << endl;
	minhalista.ImprimeReverso();
	cout << "Saiu do imprime Reverso!" << endl;

	unsigned int pri = 0, sec = 1;
	minhalista.TrocaDePosicao(pri, sec);
	cout << "---------------------" << endl;
	minhalista.Imprime();

	return 0;
}

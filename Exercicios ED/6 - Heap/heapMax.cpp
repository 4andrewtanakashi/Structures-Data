#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Dado;

void Troca(Dado* vet, int pos1, int pos2 ) {
	Dado aux = vet[pos1];
	vet[pos1] = vet[pos2];
	vet[pos2] = aux;
}

class MaxHeap {
	public:
		MaxHeap ();
		MaxHeap (Dado vet[], int tam, int cap = 0);
		~MaxHeap ();
		void Imprime ();
		void Insere (Dado conteudo);
		Dado RetiraRaiz ();
		Dado EspiaRaiz ();
	protected :
		Dado* mHeap;
	 	int mCapacidade;
	 	int mTamanho;
	private :
		inline int Pai (int i);
		inline int Esquerda (int i);
		inline int Direita (int i);
		void CorrigeDescendo (int i);
		void CorrigeSubindo (int i);
		void Arruma ();
};

MaxHeap::MaxHeap () 
{
	mCapacidade = 10;
	mHeap = new Dado[mCapacidade];
	mTamanho = 0; 
}

inline int MaxHeap::Pai (int i)
{
	return (i-1)/2;
}

inline int MaxHeap::Esquerda (int i)
{
	return (i*2)+1;
}

inline int MaxHeap::Direita (int i) 
{
	return (i*2)+2;
}

MaxHeap::MaxHeap (Dado vet[],  int tam,  int cap)
{	
	mTamanho = tam;
	if (cap == 0)
		mCapacidade = tam;
	else
		mCapacidade = cap;
	mHeap = new Dado[mCapacidade];
	for (int i = 0; i < mTamanho; ++i) {
		mHeap[i] = vet[i];
	}
	Arruma();
}

void MaxHeap::Insere (Dado conteudo)
{	
	if (mTamanho == mCapacidade) {
		cerr << "Tá cheio !!!" << endl;
		exit(EXIT_FAILURE);
	}
	mHeap[mTamanho] = conteudo;
	CorrigeSubindo(mTamanho);
	++mTamanho;
}

void MaxHeap::CorrigeSubindo (int i)
{

	int p = Pai(i);
	if (mHeap[p] < mHeap[i]) {
		Troca(mHeap, p, i);
		CorrigeSubindo(p);
	}
}

void MaxHeap::CorrigeDescendo (int i) 
{
	int esq = Esquerda(i);
	int dir = Direita(i);
	int maior;
	if ((esq < mTamanho) and (mHeap[esq] > mHeap[i])) {
		maior = esq;
	} else {
		maior = i;
	}
	if ((dir < mTamanho) and (mHeap[dir] > mHeap[maior])) {
		maior = dir;
	}
	if (maior != i) {
		Troca(mHeap, maior, i);
		CorrigeDescendo(maior);
	}
}

Dado MaxHeap::RetiraRaiz () {
	if (mTamanho == 0) {
		cerr << "Ai mano, só tem raiz aqui" << endl;
		exit(EXIT_FAILURE);
	}
	Dado valorraiz = mHeap[0];
	Troca(mHeap, 0, mTamanho-1);
	--mTamanho;
	CorrigeDescendo(0);
	return valorraiz;
}

void MaxHeap::Arruma () {
	for (int i = (mTamanho/2)-1; i >=0 ; --i) {
		CorrigeDescendo(i);
	}
}

Dado MaxHeap::EspiaRaiz () {
	return mHeap[0];
}

void MaxHeap::Imprime () 
{

	cout << "#" << mHeap[0] << "#" << " ";
	for (int i = 1; i < mTamanho; ++i) {
		
		cout << "(" << mHeap[i] << ")" <<
		" ";
	}
	cout << endl;
}

MaxHeap::~MaxHeap ()
{
	mCapacidade = 0;
	mTamanho = 0;
	delete[] mHeap;
}

int main() {
	MaxHeap meuheap;
	meuheap.Insere(65);
	meuheap.Insere(200);
	meuheap.Insere(21);
	meuheap.Imprime();
	Dado vet[] ={56, 858, 689, 44, 69};
	unsigned int tam = 5;
	MaxHeap meuheap2(vet, tam);
	cout << "Raiz" << meuheap2.EspiaRaiz() << endl;
	meuheap2.Imprime();
	return 0;
}
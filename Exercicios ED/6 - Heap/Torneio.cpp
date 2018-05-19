#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef int Dado;

void Troca(Dado* vet, int pos1, int pos2 ) {
	Dado aux = vet[pos1];
	vet[pos1] = vet[pos2];
	vet[pos2] = aux;
}

class Torneio {
	public:
		Torneio (Dado vet[], int tam, int cap = 0);
		~Torneio ();
		void Imprime ();
		//~ void Insere (Dado conteudo);
		//~ Dado RetiraRaiz ();
		//~ Dado EspiaRaiz ();
	protected :
		Dado* mHeap;
	 	int mCapacidade;
	 	int mTamanho;
	private :
		inline int Pai (int i);
		//~ inline int Esquerda (int i);
		//~ inline int Direita (int i);
		//~ void CorrigeDescendo (int i);
		void vecedores (int i);
		bool pow (int tamanho);
		//~ void Arruma ();
};

inline int Torneio::Pai (int i)
{
	return (i-1)/2;
}

//~ inline int Torneio::Esquerda (int i)
//~ {
	//~ return (i*2)+1;
//~ }

//~ inline int Torneio::Direita (int i) 
//~ {
	//~ return (i*2)+2;
//~ }

Torneio::Torneio (Dado vet[],  int tam,  int cap)
{
	if (pow(tam)) {
		mTamanho = tam;
		mCapacidade = cap;
		mHeap = new Dado[mCapacidade];
		int j = 0;
		for (int i = mTamanho-1; i < mCapacidade; ++i) {
			mHeap[i] = vet[j];
			++j;
		}
		vecedores(mCapacidade-1);
		mTamanho = mCapacidade;
}

bool Torneio::pow (int tamanho) {
	int pot = 0;
	for (int i = 0; i < tamanho; i++) {
		pow(2, i);
	}
	
}

//~ void Torneio::Insere (Dado conteudo)
//~ {	
	//~ if (mTamanho == mCapacidade) {
		//~ cerr << "Tá cheio !!!" << endl;
		//~ exit(EXIT_FAILURE);
	//~ }
	//~ mHeap[mTamanho] = conteudo;
	//~ vecedores(mTamanho);
	//~ ++mTamanho;
//~ }

void Torneio::vecedores (int i)
{
	if (i > 0) {
		int p = Pai(i);
		if (mHeap[i] > mHeap[i-1]) {
			mHeap[p] = mHeap[i];
			i -= 2;
			vecedores(i);
		} else {
			mHeap[p] = mHeap[i-1];
			i -= 2;
			vecedores(i);
		}
	}
}

//~ void Torneio::CorrigeDescendo (int i) 
//~ {
	//~ int esq = Esquerda(i);
	//~ int dir = Direita(i);
	//~ int maior;
	//~ if ((esq < mTamanho) and (mHeap[esq] > mHeap[i])) {
		//~ maior = esq;
	//~ } else {
		//~ maior = i;
	//~ }
	//~ if ((dir < mTamanho) and (mHeap[dir] > mHeap[maior])) {
		//~ maior = dir;
	//~ }
	//~ if (maior != i) {
		//~ Troca(mHeap, maior, i);
		//~ CorrigeDescendo(maior);
	//~ }
//~ }

//~ Dado Torneio::RetiraRaiz () {
	//~ if (mTamanho == 0) {
		//~ cerr << "Ai mano, só tem raiz aqui" << endl;
		//~ exit(EXIT_FAILURE);
	//~ }
	//~ Dado valorraiz = mHeap[0];
	//~ Troca(mHeap, 0, mTamanho-1);
	//~ --mTamanho;
	//~ CorrigeDescendo(0);
	//~ return valorraiz;
//~ }

//~ void Torneio::Arruma () {
	//~ for (int i = (mTamanho/2)-1; i >=0 ; --i) {
		//~ CorrigeDescendo(i);
	//~ }
//~ }

//~ Dado Torneio::EspiaRaiz () {
	//~ return mHeap[0];
//~ }

//~ void Torneio::Imprime () 
//~ {

	//~ cout << "#" << mHeap[0] << "#" << " ";
	//~ for (int i = 1; i < mTamanho; ++i) {
		
		//~ cout << "(" << mHeap[i] << ")" <<
		//~ " ";
	//~ }
	//~ cout << endl;
//~ }

Torneio::~Torneio ()
{
	mCapacidade = 0;
	mTamanho = 0;
	delete[] mHeap;
}

int main() {
	Dado vet[] ={1, 2, 90, 120, 1245, 24, 229, 189, 79, 99, 45, 78, 24, 11, 65, 4};
	unsigned int tam = 16;
	Torneio biriba(vet, tam, (2*tam)-1);
	biriba.Imprime();
	return 0;
}

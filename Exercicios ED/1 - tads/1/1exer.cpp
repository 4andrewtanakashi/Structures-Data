#include <iostream>
using namespace std;


enum tipo {fib, fet, ric};

class FFR {
    private:
   	 tipo meuTipo;
   	 int termo1, termo2;
   	 long calculaFib (int n);
   	 long calculaFet (int n);
   	 long calculaRic (int n);
   	 long* calculaSeqFib (int n);
   	 long* calculaSeqFet (int n);
   	 long* calculaSeqRic (int n);
    public:    
   	 FFR (tipo t); // construtor para Fibonacci
   	 FFR (tipo t, int t1, int t2); // construtor para Fettuccine e Ricci
   	 long calculaTermo (int n); //calcula o n-esimo termo
   	 long* calculaSequencia (int n); // retorna um vetor com os 
    // n primeiros termos




};
FFR::FFR(tipo t) {
  meuTipo = t;
}
FFR::FFR(tipo t, int t1, int t2) {
  meuTipo = t;
  termo1 = t1;
  termo2 = t2;
}

long FFR::calculaTermo(int n) {
   cout << "n-esimo termo : " <<  endl;
   cout << "Fibonacci : " << calculaFib(n) << endl;
   calculaFet(n);
  cout << "Ricci : " << calculaRic(n) << endl;
  return 0;
}
long FFR::calculaFib(int n) {
  if (n==0) {
    return fib;
  } else if (n==1) {
    return fet;
  } else {
    return calculaFib(n-1)+calculaFib(n-2);
  }
}
long FFR::calculaFet(int n) {
  int i = 3, fettres = 0, ft2 = termo2, ft1 = termo1;
  ++n;
  if (n>=2) {
    fettres = ft2 + ft1;
    ++i;
  }
  while ((n==i)||(i<=n)) {
    if (i%2==0) {
      ft1 = ft2;
      ft2 = fettres; 
      fettres = ft2 - ft1;
      ++i;
    } else {
      ft1 = ft2;
      ft2 = fettres;
      fettres = ft2 + ft1;
      ++i;
    }
  }
  if (n == 0) {
    cout << "Fettuccine : " << ft1 << endl;
  } else if (n == 1) {
    cout << "Fettuccine : " << ft2 << endl;
  } else
    cout << "Fettuccine : " << fettres << endl;
  return 0;
}
long FFR::calculaRic(int n) {
    if (n==0) {
      return termo1;
  } else if (n==1) {
      return termo2;
  } else {
      return calculaRic(n-2)+calculaRic(n-1);
    }
}
long* FFR::calculaSequencia(int n) {
  long* seq = calculaSeqFib(n);
  cout << fib << " Sequencia fibonacci : " << endl;
  for (int i = 0; i < n; ++i) {
    cout << *(seq+i) << " ";
  }
  cout << endl;
  
  /*seq = calculaSeqFet(n);
  cout << fib << " Sequencia Fettuccine : " << endl;
  for (int i = 0; i < n; ++i) {
    cout << *(seq+i) << " ";
  }
  cout << endl;
    */
  delete[] seq;
  return 0;
}
long* FFR::calculaSeqFib (int n) { 
  int i = 0, j = 0;
  int fn = 0, f0 = 0, f1 = 1;
  long* vetfib = new long[n];
  vetfib[0] = fn;
  ++j;
  while (i<n) {
    f0 = f1;
    f1 = fn;
    fn = f1 + f0;
    vetfib[j] = fn;
    ++j;
    ++i;
  }
  return vetfib;
}
/*long* FFR::calculaSeqFet (int n) {
   int i = 3, fettres = 0, ft2 = termo2, ft1 = termo1;
   int j = 2;
   long* vetfet = new long[n];
   vetfet[0] = ft1;
   vetfet[1] = ft2;
  if (n>=2) {
    fettres = ft2 + ft1;
    vetfet[j] = fettres;
    ++i;
    ++j;
  }
  while ((n==i)||(i<=n)) {
    if (i%2==0) {
      ft1 = ft2;
      ft2 = fettres; 
      fettres = ft2 - ft1;
      vetfet[j] = fettres;
      ++i;
      ++j;
    } else {
      ft1 = ft2;
      ft2 = fettres;
      fettres = ft2 + ft1;
      vetfet[j] = fettres;
      ++i;
      ++j;
    }
  }
  return vetfet;
}*/
int main() {
  int ter1, ter2;
  cout << "Digite dois números : ";
  cin >> ter1 >> ter2;
  FFR num(fib, ter1, ter2);
  int qnt;
  cout << "Digite a quantidade de termos : ";
  cin >> qnt;
  num.calculaTermo(qnt);
  num.calculaSequencia(qnt);
  return 0;
}
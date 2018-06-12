// Grupo Videojuegos, Fran López-Bleda
// https://www.aceptaelreto.com/problem/statement.php?id=229&cat=78
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>

class Nodo_c {
private:
  /* data */
  Nodo_c* nodoDerecha;
  Nodo_c* nodoIzquierda;


public:
  Nodo_c
  Nodo_c (arguments);
  virtual ~Nodo_c ();
};

// función que resuelve el problema
//el coste es O(K*(2*Log(N))+1), siendo K el numero de partituras a repartir y N el numero de grupos de instrumentos

int resolver(std::vector<int> &v , int & nTotal) {
  int nTimes=0;
  int resto = 0;
  for (size_t i = 0; i < v.size(); i++) {
    //std::cout << resto << ' '<< nTotal << '\n';
    if(resto == nTotal){
      nTimes++;
    }
    resto+=v[i];
    nTotal-=v[i];

  }
  if(resto == nTotal){
    nTimes++;
  }
  return nTimes;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
  std::size_t nNodos;
  std::cin >> nNodos;
	if (nNodos == 0)
		return false;

  std::vector<int> preOrden(nNodos);
  std::vector<int> inOrden(nNodos);

  for (size_t i = 0; i < nNodos; i++) {
    std::cin >> v.at(i);
    cantidad += v.at(i);

  }

  std::cout << resolver(v,cantidad) << '\n';
	// escribir sol
	return true;
}



int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto


	while (resuelveCaso())
	{

	}


	// Para restablecer entrada. Comentar para acepta el reto

	return 0;
}

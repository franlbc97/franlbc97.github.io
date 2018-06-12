---
categories:
  - Programación
tags:
  - Árboles binarios
  - EDA
---
# Construimos un AABB a partir del inorden y el postorden
Hablemos de árboles binarios, imaginemos que tenemos que saber la forma del árbol y unicamente nos dan su recorrido en inorden y en preorden. Hago una breve introducción de las formas de recorrer un árbol binario para ir calentando.
## Formas de recorrer un Árbol binario
hay 3 formas de recorrer árboles binarios, **Postorden**, **inorden** y **preorden**. Se diferencian entre sí de estas formas:
### Postorden
Está es la mas comun de recorrerla ya que se empieza por el nodo raíz. Se recorre en este orden.
1. Raíz
2. Hijo izquierdo
3. Hijo derecho

### Inorden
Se recorre de la siguiente forma:
1. Hijo izquierdo
2. Raíz
3. Hijo derecho

### Preorden
Se recorre de la siguiente forma:
1. Hijo izquierdo
3. Hijo derecho
2. Raíz

## Planteamiento del problema
Analizamos los datos que nos dan, son el recorrido inorden del árbol y el recorrido preorden.
```
4 2 5 1 6 3 7 // inorden
4 5 2 6 7 3 1 // postorden
```
Como hemos visto antes en el recorrido preorden lo ultimo que miramos es la raíz, por lo tanto ya tenemos el nodo raíz del árbol, necesitamos saber cuales son los hijos del nodo raiz, y lo que hacemos es buscar el valor de la raíz en el recorrido inorden. se quedaría algo así.
```
|           |
|    | |    |
4 2 5 1 6 3 7 // inorden
4 5 2 6 7 3 1 // postorden
            |
```
Esto significaría que todo lo que hay a la izquierda del recorrido inorden, son los posibles hijos izquierdos, y los que se han quedado a la derecha, son los posibles hijos derechos.
Sabiendo esto, tambíen sabemos que el anterior al ultimo numero del recorrido postorden, será su hijo derecho, entonces se aplica otra vez el plan anterior y ya tienes su hijo derecho y sus posibles hijos, izquierdos y derechos. Una vez que ya llegamos al final de los hijos derechos, el resto serán izquierdos, por lo tanto necesitamos limitar de alguna forma la busqueda en en inorden porque ya sabemos entre las 2 posiciones que pueden estar.
```
       |     |
           | |
4 2 5 1 6 3 7 // inorden
4 5 2 6 7 3 1 // postorden
          |
        |
```
## Desarrollo del problema
Imaginemos el siguiente struct, y una para inicializarla y destruirla, y una función para buscar en un vector dados los limites.
```
struct SNode{
  int value;
  NodoAABB * left;
  NodoAABB * right;
}

SNode* initNode(const int & value){
  SNode * node = new SNode();
  node->valor = value;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}

void deleteNode(SNode * node){
  if(!node) return;
  deleteNode(node->left);
  deleteNode(node->right);
  delete node;
}

int busca (std::vector<int> & v,int & first, int & end,int & valor){
  int i;
  for ( i = first; i < end; i++) {
    if(v[i]==valor) break;
  }
  return i;
}
```
Con esto ya podriamos hacer un árbol binario de enteros. Lo que vendría siendo el *core* de la solución sería este algoritmo, que su definición sería.
```
/*
  /// @param post: el recorrido postorden
  /// @param in: el recorrido inorden
  /// @param inStr: límite inferior para la busqueda en el recorrido inorden
  /// @param inEnd: límite superior para la busqueda en el recorrido inorden
  /// @param inStr: índice del recorrido postorden
  /// @return Nodo resultante
*/
SNode * Construye(std::vector<int> & post,std::vector<int> & in, int inStr,int inEnd, int & postIndex )
```
Primero tenemos que hacer los casos base, que es, si no hay donde buscar, es decir `inStr > inEnd`:
```
if(inStr > inEnd)
  return nullptr;
```
Terminado esto significa que al menos si podemos tener un nodo, por lo tanto iniciamos un nodo con el valor al que indica el indice de postorden, ya que es la raíz y le restamos 1 al indice.
```
SNode * node = initNode(post[postIndex]);
postIndex--;
```
Para conseguir eficiencia, en el caso que el rango de busqueda sea uno significará que no hay más donde mirar (`inStr==inEnd`), por lo tanto devolveriamos el valor metido.
```
if(inStr==inEnd)
  return node;
```
Lo que realizariamos después sería buscar el valor del nodo actual en el rango de busqueda de inorden, y almacenar la posición para así luego saber las posiciones en las que estan los hijos de este nodo.
```
int index = busca(in,inStr,inEnd,node->valor);
```
Ahora pasariamos lo que viene siendo la recursividad de la función, donde asignamos primero el hijo derecho del nodo, y luego el izquierdo, ya que vamos en el orden inverso de postorden, y devolvemos el nodo, ya que estará construido.
```
node->right = Construye(post, in, index+1, inEnd, postIndex);
node->left  = Construye(post, in, inStr, index-1, postIndex);
return node;
```

La función completa sería:
```
SNode * Construye(std::vector<int> & post,std::vector<int> & in, int inStr,int inEnd, int & postIndex ){
  if(inStr > inEnd)
    return nullptr;

  if(inStr==inEnd)
    return node;
  SNode * node = initNode(post[postIndex]);
  postIndex--;
  int index = busca(in,inStr,inEnd,node->valor);

}

```

---
categories:
  - Programación
tags:
  - Arboles binarios
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

## Desarrollo del problema
imaginemos que tenemos la siguiente clase nodo:
```
class Nodo_c {
public:
  Nodo_c* nodoIzquierda;
  Nodo_c* nodoDerecha;
  int valor;
  Nodo_c (int v):valor(v),nodoDerecha(0),nodoIzquierda(0){};
  virtual ~Nodo_c (){
    delete nodoIzquierda;
    delete nodoDerecha;
  };

};

```

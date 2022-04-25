/* 5142095 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/iterador.h"


struct nature {
  nat natural;
  nature * sig;
};
struct _rep_iterador {
  nature * actual;
  nature * lst;
  nature * fst;
};

TIterador crearIterador() {
  TIterador iter = new _rep_iterador;
  iter->actual = NULL;
  iter->fst = NULL;
  iter->lst = NULL;
  return iter;
}

void liberarIterador(TIterador iter) {
  while(iter->fst != NULL){
    iter->actual = iter->fst;                 //pongo a actual en fst
    iter->fst = iter->fst->sig;               //avanzo el fst
    delete iter->actual;                        //borro actual.
  }
  delete iter;
}

bool estaDefinidaActual(TIterador iter) {
  bool esta;
  if(iter!=NULL){
    esta = iter->actual != NULL;
  } else {
    esta = false;
  }
  return esta;
}

void agregarAIterador(nat elem, TIterador const iter) {
  if(iter->lst == NULL){
    nature * elemento = new nature;
    elemento->natural = elem;
    elemento->sig = NULL;

    iter->fst = elemento;
    iter->lst = elemento;
  } else if (iter->lst != NULL) {                //"si ya hay elementos"dsa
    iter->lst->sig = new nature;            //creo celda para elem
    iter->lst = iter->lst->sig;             //lst avanza al nuevo
    iter->lst->sig = NULL;                  //el ultimo de la lista apunta a null
    iter->lst->natural = elem;
  }
}

void reiniciarIterador(TIterador const iter) {
  iter->actual = iter->fst;
}

void avanzarIterador(TIterador const iter) {
  if(estaDefinidaActual(iter)) {
    iter->actual = iter->actual->sig;
  }
}

nat actualEnIterador(TIterador iter) {
  return iter->actual->natural;
}

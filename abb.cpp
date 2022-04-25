/* 5142095 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/abb.h"

struct _rep_abb {
  TInfo dato;
  TAbb izq;
  TAbb der;
};

TAbb crearAbb() { 
  TAbb arbol = NULL;
  return arbol;
}

void liberarAbb(TAbb abb) {
  if(abb != NULL){
  	liberarAbb(abb->izq);
  	liberarAbb(abb->der);
    liberarInfo(abb->dato);
    delete abb;
  }
}

bool esVacioAbb(TAbb abb) { 
  if (abb == NULL){
    return true;
  } else {
    return false;
  }
}

TAbb buscarSubarbol(nat elem, TAbb abb) { 		//Lo diseñe para que lo recorra entero!! Es de busqueda!!
	if (abb != NULL && natInfo(abb->dato) == elem){
		return abb;
	} else if (abb == NULL){
		return NULL;
	} else {
		TAbb arbol;
		arbol = buscarSubarbol(elem, abb->izq);
		if (arbol == NULL) arbol = buscarSubarbol(elem, abb->der);
  	return arbol;
	}
}

TInfo raiz(TAbb abb) { return abb->dato; }

TAbb izquierdo(TAbb abb) { return abb->izq; }

TAbb derecho(TAbb abb) { return abb->der; }

TInfo menorEnAbb(TAbb abb) { 
	if (abb->izq != NULL){
		return menorEnAbb(abb->izq);
	} else {
		return abb->dato;
	}
}

TInfo mayorEnAbb(TAbb abb) { 
	if (abb->der != NULL){
		return mayorEnAbb(abb->der);
	} else {
		return abb->dato;
	}
}

TAbb consAbb(TInfo dato, TAbb izq, TAbb der) { 
	TAbb arbol = crearAbb();
	arbol = new _rep_abb;
	arbol->dato = dato;
	if (esVacioAbb(izq)){
		arbol->izq = NULL;
	} else {
		arbol->izq = izq;
	}
	if (esVacioAbb(der)){
		arbol->der = NULL;
	} else {
		arbol->der = der;
	}
	return arbol;
}

TAbb insertarEnAbb(TInfo dato, TAbb abb) { 
	if(abb == NULL){
		TAbb abb = new _rep_abb;
		abb->dato = dato;
		abb->izq = NULL;
		abb->der = NULL;
		return abb;
	} else if (natInfo(dato) < natInfo(abb->dato)) {
		abb->izq = insertarEnAbb(dato, abb->izq);
		return abb;
	} else {
		abb->der = insertarEnAbb(dato, abb->der);
		return abb;
	}
}


TAbb removerDeAbb(nat clave, TAbb abb) { 
	if(clave < natInfo(abb->dato)){
		abb->izq = removerDeAbb(clave, abb->izq);
		return abb;
	} else if(clave > natInfo(abb->dato)){
		abb->der = removerDeAbb(clave,abb->der);
		return abb;
	} else {					//Si el que quiero remover es la raiz
		if(abb->izq == NULL && abb->der == NULL){
			liberarInfo(abb->dato);
			delete abb;
			return NULL;
		} else if (abb->izq != NULL && abb->der == NULL){
			liberarInfo(abb->dato);
			TAbb reemplazar = abb->izq;
			delete abb;
			return reemplazar;
		} else if (abb->izq == NULL && abb->der != NULL){
			liberarInfo(abb->dato);
			TAbb reemplazar = abb->der;
			delete abb;
			return reemplazar;
		} else {
			liberarInfo(abb->dato);
			TInfo data = copiaInfo(mayorEnAbb(abb->izq));	//No puede compartir memoria
			abb->dato = data;
			nat aBorrar = natInfo(mayorEnAbb(abb->izq));
			abb->izq = removerDeAbb(aBorrar, abb->izq);
			return abb;
		}
	}
}


TAbb copiaAbb(TAbb abb) { 
	if(abb != NULL){
		TAbb arbol = crearAbb();
		arbol = new _rep_abb;
		arbol->dato = copiaInfo(abb->dato);
		arbol->izq = copiaAbb(abb->izq);
		arbol->der = copiaAbb(abb->der);
		return arbol;
	} else {
		return NULL;
	}
}

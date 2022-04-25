/* 5142095 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/aplicaciones.h"
#include "../include/cadena.h"
#include "string.h"

static TCadena linealizacionAux(TCadena & caden, TAbb abb){
  if(abb != NULL){
    if(derecho(abb) != NULL){
      caden = linealizacionAux(caden, derecho(abb));
    }
    caden = insertarAlInicio(natInfo(raiz(abb)), realInfo(raiz(abb)), caden);
    if (izquierdo(abb) != NULL){
      caden = linealizacionAux(caden, izquierdo(abb));            
    }
  } else {            //Si abb es NULL devuelvo cadena = NULL
    caden = NULL;
  }
  return caden;
}

TCadena linealizacion(TAbb abb) { 
  TCadena caden = crearCadena();
  caden = linealizacionAux(caden, abb);
  return caden;
}

static void altura(TAbb abb, TAbb nodo){     //Quiero saber la altura de un nodo
  if(!esVacioAbb(nodo)){
    if (natInfo(raiz(nodo)) < natInfo(raiz(abb))){
      printf("-");
      altura(izquierdo(abb), nodo);
    } else if (natInfo(raiz(nodo)) > natInfo(raiz(abb))) {
      printf("-");
      altura(derecho(abb), nodo);
    } else {
      imprimirInfo(raiz(nodo));
      printf("\n");
    }
  }
}

static void recorridaDeNodos(TAbb abb, TAbb nodo){
  if( !esVacioAbb(nodo) ){
    if( !esVacioAbb(derecho(nodo) )){
      recorridaDeNodos(abb, derecho(nodo));
    }
    
    altura(abb, nodo);

    if( !esVacioAbb(izquierdo(nodo)) ) {
      recorridaDeNodos(abb, izquierdo(nodo));
    }
  }
}

void imprimirAbb(TAbb abb) {
  TAbb nodo = abb;
  recorridaDeNodos(abb, nodo);
}

static nat max(nat a,nat b){
  if(a>b){
    return a;
  } else {
    return b;
  }
}
static nat min(nat a, nat b){
  if(a<b){
    return a;
  } else {
    return b;
  }
}

static nat alturaMax(TAbb abb){
  if( esVacioAbb(abb)){
    return 0;
  } else {
    return (1 + max(alturaMax(izquierdo(abb)), alturaMax(derecho(abb)) ));
  }
}

static nat alturaMin(TAbb abb){
  if( esVacioAbb(abb)){
    return 0;
  } else {
    return (1 + min(alturaMin(izquierdo(abb)), alturaMin(derecho(abb)) ));
  }
}

/* Me puedo fijar si todas las hojas estan en el mismo nivel. 
Si la altura maxima es distinta de la minima, devuelve false */ 
bool esPerfecto(TAbb abb) { 
  if(alturaMax(abb) == alturaMin(abb)){
    return true;
  } else {
    return false;
  }
}


static TAbb filtro(double limite, TAbb abb){
  if(!esVacioAbb(abb)){
    TAbb filtIzq = menores(limite, izquierdo(abb));
    TAbb filtDer = menores(limite, derecho(abb));
    if(realInfo(raiz(abb)) < limite){         //"Si lo quiero copiar"
      TAbb agrego = crearAbb();
      TInfo inf = copiaInfo(raiz(abb));
      agrego = consAbb(inf, filtIzq, filtDer);
      return agrego;
    } else {
      if(esVacioAbb(filtIzq)){
        return filtDer;
      } else if (esVacioAbb(filtDer)){
        return filtIzq;
      } else {
        TAbb nuevo = crearAbb();
        TInfo copia = copiaInfo(raiz(abb));
        nuevo = consAbb(copia,filtIzq, filtDer);
        return nuevo;
      }
    }
  } else {
    return NULL;
  }

}

TAbb menores(double limite, TAbb abb) { 
  TAbb arbol = filtro(limite, abb);
  if(!esVacioAbb(arbol)){
    if(realInfo(raiz(arbol)) >= limite){
      arbol = removerDeAbb(natInfo(raiz(arbol)), arbol);
    }
  }
  return arbol;
}

static nat valorAltura(TAbb abb, TAbb nodo){     //Quiero saber la altura de un nodo
  if(!esVacioAbb(nodo)){
    if (natInfo(raiz(nodo)) < natInfo(raiz(abb))){
      return 1 + valorAltura(izquierdo(abb), nodo);
    } else if (natInfo(raiz(nodo)) > natInfo(raiz(abb))) {
      return 1 + valorAltura(derecho(abb), nodo);
    } else {
      return 1;
    }
  } else {
    return 0;
  }
}

static TIterador caminoAscendenteAux(nat clave, nat & k, TAbb abb, TIterador itera){  
  if(natInfo(raiz(abb)) < clave){
    itera = caminoAscendenteAux(clave, k, derecho(abb), itera);
  } else if (natInfo(raiz(abb)) > clave){
    itera = caminoAscendenteAux(clave, k, izquierdo(abb), itera);
  }
  if(k>0){
    agregarAIterador(natInfo(raiz(abb)), itera);
    k--;
    return itera;
    
  }
  return itera;
  /* if(!esVacioAbb(abb)){        ME LO DEVOLVÍA DADO VUELTA
    if(( (valorAltura(abb, nodo))) <= k){
      agregarAIterador(natInfo(raiz(abb)), itera);
    }
    if(natInfo(raiz(abb)) < natInfo(raiz(nodo))){
      itera = caminoAscendenteAux(nodo, k, derecho(abb), itera);
    } else if (natInfo(raiz(abb)) > natInfo(raiz(nodo))){
      itera = caminoAscendenteAux(nodo, k, izquierdo(abb), itera);
    } else {
      return itera;
    }
  }
  return itera; */
}


TIterador caminoAscendente(nat clave, nat k, TAbb abb) { 
  TIterador iter = crearIterador();
  //TAbb nodo = buscarSubarbol(clave, abb);
  iter = caminoAscendenteAux(clave, k, abb, iter);
  //iter = darVuelta(iter);
  return iter;
}


/* Dada una raiz, quiero que me devuelva un arreglo de caracteres en el orden en el que lo voy a imprimir */
static void imprimirConPrefijo(ArregloChars prefijo, nat largo, nat k, TPalabras secuencia){
  if (letra(secuencia) == '\0') {
    prefijo[largo] = '\0';
    if(k +1 > largo){
      printf("%s\n", prefijo);
    }
  } else {
    prefijo[largo] = letra(secuencia);
    imprimirConPrefijo(prefijo, largo + 1, k, subarboles(secuencia));
  }
  if (siguientes(secuencia) != NULL)
    imprimirConPrefijo(prefijo, largo, k, siguientes(secuencia));

}

void imprimirPalabrasCortas(nat k, TPalabras palabras) {
  TPalabras palabra = subarboles(palabras);
  
  char asd = 'l';
  ArregloChars pref = &asd;
  imprimirConPrefijo(pref, 0, k, palabra);

}

static TPalabras buscarFinPrefijoAux(ArregloChars prefijo, TPalabras palabras, nat largo){
  if(palabras != NULL){
    if(letra(palabras) == prefijo[largo-1]){
      if(largo != strlen(prefijo)){
        return buscarFinPrefijoAux(prefijo, subarboles(palabras), largo + 1);
      } else {
        return palabras;
      }
    } else {
      return buscarFinPrefijoAux(prefijo, siguientes(palabras), largo);
    }
  } else {
    return NULL;
  }
}
TPalabras buscarFinPrefijo(ArregloChars prefijo, TPalabras palabras) {
  TPalabras palabra = subarboles(palabras);
  palabra = buscarFinPrefijoAux(prefijo, palabra, 1);
  return palabra;
}

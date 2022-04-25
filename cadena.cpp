/* 5142095 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cadena.h"
#include "../include/info.h"

struct _rep_cadena {
  TInfo inf;
  TCadena nxt;
  TCadena prev;            //Cada nodo va a tener un puntero al anterior
};

TCadena crearCadena() {
  TCadena cad = NULL;
  return cad;
}


void liberarCadena(TCadena cad) {
    if(cad!=NULL){
      TCadena borrar;          //delete borra memoria y variable??
      cad->prev->nxt=NULL;
      do{
        borrar = cad;
        liberarInfo(cad->inf);
        cad = cad->nxt;
        delete borrar;
      } while (cad!=NULL);
      delete cad;
    }
}

nat cantidadEnCadena(TCadena cad) {
  nat cantidad = 0;
  if(cad!=NULL){
    TCadena aux = cad;

    do{
      cantidad++;
      aux=aux->nxt;
    }while (aux!=cad);
  }
  return cantidad;
}

bool estaEnCadena(nat natural, TCadena cad) {
  TCadena primero = cad;
  bool esta = false;
  if(cad!=NULL){
    do{
      if(cad!=NULL && natInfo(cad->inf) == natural) {esta = true;}
      cad=cad->nxt;
    }while(cad!=primero && esta != true);
  }

  return esta;
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad) {
  TCadena caden = new _rep_cadena;
  caden->inf = crearInfo(natural,real);
  if(cad==NULL){
    caden->nxt = caden;
    caden->prev = caden;
  } else {
    caden->nxt = cad;
    caden->prev = cad->prev;
    cad->prev->nxt = caden;
    cad->prev = caden;
  }
  return caden;
}

TInfo infoCadena(nat natural, TCadena cad) {
  while (natInfo(cad->inf)!=natural)               //Por precondicion, está en la cadena!
  {
    cad=cad->nxt;
  }
  return cad->inf;
}

TInfo primeroEnCadena(TCadena cad) {
  return cad->inf;                        //(Pueden o no compartir memoria)
}

TCadena cadenaSiguiente(TCadena cad) {
  if(cad != NULL){ cad=cad->nxt; } 
  return cad;
}

TCadena removerDeCadena(nat natural, TCadena cad) {
  TCadena caden = cad;
  while (natInfo(caden->inf)!=natural)
  {
    caden=caden->nxt;
  }
  TCadena borrar = caden;
  if(cantidadEnCadena(cad) != 1){

    caden->prev->nxt = caden->nxt;
    caden->nxt->prev = caden->prev;
  } else {
    cad = NULL;
  }
  liberarInfo(borrar->inf);
  if(borrar == cad){ cad=cad->nxt;}
  delete borrar;
  return cad;
}

void imprimirCadena(TCadena cad) {
  if(cad!=NULL){
    TCadena aux = cad;
    do{
      imprimirInfo(aux->inf);
      aux=aux->nxt;
    } while(aux!=cad);
  }
    printf("\n");
}


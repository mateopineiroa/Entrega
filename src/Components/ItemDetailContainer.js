import { useState, useEffect } from "react";
import ItemDetail from "./ItemDetail.js"
//import img from "../../public/Img/ImagenProducto"



const ItemDetailContainer = () => {
  /* En el container va toda la logica. Se consiguen los elementos que contiene. Estan los estados, los efectos. */
  const [elemento, setElemento] = useState([])      /* Un objeto unicamente */
  
  
  /* fetch('https://fakestoreapi.com/products')
      .then(res=>res.json())
      .then(json=>console.log(json)) 
          
    Si quiero hacer un fetch a un json, el archivo tiene que estar en la carpeta PUBLIC por que webpack me unifica todos los elementosde src en un solo archivo.         
    Otra forma de traerte un elemento json puede ser directamente hacerle import.   
  */
  
  useEffect(() => {
    const promesa = new Promise(res => {
      setTimeout(() => {
        res([{titulo:"BMW Serie 1 2.0 120i Coupe Active 156cv", detalle: "Bmw 120i Coupé Automático Secuencial. Segundo dueño. Ficha en Scarpa, cubiertas Bridgestone nuevas. Excelente estado. Posible permuta. Financiación de hasta USD 5.000 hasta en 24 cuotas.", link:"https://picsum.photos/300/300"}])
      }, 2000)
    })
      
    promesa
      .then(data => {
        setElemento(data)
    })
  }, elemento)
  console.log("En el container, el elemento es:", elemento)
  let ind = 0
  return (
          <div class="">
            <ItemDetail lista={elemento} indice={ind} />
          </div>
          )
}

export default ItemDetailContainer
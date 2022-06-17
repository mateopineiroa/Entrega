import { useState } from "react";
import ItemDetail from "./ItemDetail.js"

const promesa = new Promise(res => {
    setTimeout(() => {
        res({titulo:"BMW Serie 1 2.0 120i Coupe Active 156cv", detalle: "Bmw 120i Coupé Automático Secuencial. Segundo dueño. Ficha en Scarpa, cubiertas Bridgestone nuevas. Excelente estado. Posible permuta. Financiación de hasta USD 5.000 hasta en 24 cuotas.", link:"../img/ImagenProducto.webp"})
    }, 2000)
})


const ItemDetailContainer = () => {
    const [elemento, setElemento] = useState({stock:"Cargando...", ubicacionProducto: "Cargando..."})      /* Arreglo vacio */
    
    promesa.then(data => {
        setElemento(data)
    })
    console.log(elemento)
    return (
        <div>
            <ItemDetail prop={elemento} />
        </div>
    )
}

export default ItemDetailContainer
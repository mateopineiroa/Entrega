import { useState } from "react";
import ItemDetail from "./ItemDetail.js"

const promesa = new Promise(res => {
    setTimeout(() => {
        res({stock:"23", ubicacionProducto: "Muy lejos, ni te gastes"})
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
            <ItemDetail />
            <p>Texto random {elemento.ubicacionProducto}</p>
        </div>
    )
}

export default ItemDetailContainer
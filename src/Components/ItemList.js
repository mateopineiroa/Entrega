import {useState} from 'react'
import Item from "./Item.js"

const ItemList = () => {
    //const objeto = {producto:"Arroz"};
    const [elemento, setElemento] = useState({stock:"Cargando...", ubicacionProducto: "Cargando..."})      /* Arreglo vacio */
    let promesita = new Promise(res => {  
        setTimeout(() => {
            res([{stock:23, ubicacionProducto: "Muy lejos, ni te gastes"}])
        }, 2000)
    })
    promesita.then((data) => {
        //console.log("data es:", data)
        setElemento(data)
    })
    return (
        <Item elemento= {elemento} />
        )
}

export default ItemList
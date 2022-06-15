import {useState} from "react"

const ItemCount = (prop) => {
    
    const [cantidad, cambiarCantidad] = useState(parseInt(prop.initial)) //Estado inicial: 0
    const aumentoCantidad = (tope) => {
        if (cantidad!=tope){
            cambiarCantidad(cantidad+1)
        } else {
            console.log("Lo siento pero el tope es:", tope)
        }
    }
    const disminuyoCantidad = () => {
        if (cantidad != 1)
            cambiarCantidad(cantidad-1)
    }
    return (
        <>
            <p>El contador va: {cantidad}</p>
            <button onClick={() => {aumentoCantidad(prop.stock)}}>+</button>
            <button onClick={disminuyoCantidad}>-</button>
        </>
    )

}

export default ItemCount
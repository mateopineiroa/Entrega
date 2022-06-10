import {useState} from "react"

const ItemCount = (prop) => {
    const tope = prop.stock
    const [cantidad, cambiarCantidad] = useState(prop.initial) //Estado inicial: 0
    const aumentoCantidad = (tope) => {
        if (cantidad!=tope){
            cambiarCantidad(parseInt(cantidad)+1)
        } else {
            console.log("Lo siento pero el tope es:", tope)
        }
    }
    const disminuyoCantidad = () => {
        if (cantidad != 0)
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
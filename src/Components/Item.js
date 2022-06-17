  import {useState} from "react"


const Item = (prop) => {
    /* const [elemento, setElemento] = useState({stock:"Cargando...", ubicacionProducto: "Cargando..."})     //Arreglo vacio
    let promesita = new Promise(res => {  
        setTimeout(() => {
            res({stock:23, ubicacionProducto: "Muy lejos, ni te gastes"})
        }, 2000)
    })
    promesita.then((data) => {
        //console.log("data es:", data)
        setElemento(data)
    }) */
    return (
        <div class="item">           {/* react no me deja añadir style a prepo(?) */}
            <p><b>Elemento:</b> {prop.elemento.producto}</p>
            <p><b>Stock:</b> {prop.elemento.stock}</p>
            <p><b>Hay que ir a comprarlo a:</b> {prop.elemento.ubicacionProducto}</p>
        </div>
    )
}

export default Item
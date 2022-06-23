


const ItemDetail = (prop) => {
    console.log("El elemento que me llega en detail es",prop.lista)
    
    return (
        <div class="box">
            <h3>{prop.lista[prop.indice].titulo}</h3>
            <img src={prop.lista[prop.indice].link} alt="Imagen de producto"></img>
            <p>{prop.lista[prop.indice].detalle}</p>
        </div>
    )
}

export default ItemDetail
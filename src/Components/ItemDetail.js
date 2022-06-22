


const ItemDetail = (prop) => {
    console.log("El elemento que me llega es",prop)
    return (
        <div class="box">
            <h3>{prop.titulo}</h3>
            <img src={prop.link} alt="Imagen de producto"></img>
            <p>{prop.detalle}</p>
        </div>
    )
}

export default ItemDetail
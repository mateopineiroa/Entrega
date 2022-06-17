


const ItemDetail = (prop) => {
    let link = prop.link
    console.log(prop)
    return (
        <div class="box">
            <h3>{prop.titulo}</h3>
            <img src={link} alt="Imagen de producto"></img>
            <p>{prop.detalle}</p>
        </div>
    )
}

export default ItemDetail
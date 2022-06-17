


const ItemDetail = (prop) => {
    let link = prop.link
    return (
        <div>
            <h3>{prop.titulo}</h3>
            <img src={link}></img>
            <p>{prop.detalle}</p>
        </div>
    )
}

export default ItemDetail
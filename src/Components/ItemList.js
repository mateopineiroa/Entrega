import Item from "./Item.js"

const ItemList = ({producto}) => {
    //const objeto = {producto:"Arroz"};
    console.log("El prop es",producto)
    
    return (
        producto.map(p =>
            <Item producto= {p.producto} ubicacion= {p.ubicacionProducto} stock={p.stock} />
            )
        )
}

export default ItemList
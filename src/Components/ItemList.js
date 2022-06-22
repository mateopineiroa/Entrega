import Item from "./Item.js"

const ItemList = ({producto}) => {
  console.log(producto)
  return (
    producto.map(p =>
      <Item producto= {p.nombre} ubicacion= {p.ubicacion} stock={p.stock} />
      )
    )
}

export default ItemList
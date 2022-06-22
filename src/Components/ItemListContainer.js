/* import Alert from "react-bootstrap"; */
import Alert from 'react-bootstrap/Alert';		/* import { Alert } from 'react-bootstrap'; idem */
import Counter from "./ItemCount"
import ItemList from "./ItemList.js"
import { useEffect, useState } from 'react';
import asyncMock from '../utils/asyncMock';
import productos from "../utils/productos"

const ItemListContainer = (prop) => {
  const [elemento, setElemento] = useState([])      /* Arreglo vacio */

  useEffect(() => {
    asyncMock(3000, productos)
      .then(data => setElemento(data))
  }, [elemento])


  return (
    <>
      <Counter stock="3" initial="1" />
			<Alert variant = "info">{prop.greeting}</Alert>		{/* https://react-bootstrap.github.io/components/alerts/ */}
      <ItemList producto = {elemento} />
    </>
  )
}
export default ItemListContainer

/* import Alert from "react-bootstrap"; */
import Alert from 'react-bootstrap/Alert';		/* import { Alert } from 'react-bootstrap'; idem */
import Counter from "./ItemCount"
import ItemList from "./ItemList.js"

const ListaConteiner = (prop) => {
  console.log("El objeto del greeting es:", prop, prop.greeting)
  return (
    <>
      <Counter stock="3" initial="1" />
			<Alert variant = "info">{prop.greeting}</Alert>		{/* https://react-bootstrap.github.io/components/alerts/ */}
      <ItemList />
    </>
  )
}
export default ListaConteiner
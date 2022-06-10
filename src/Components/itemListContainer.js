/* import Alert from "react-bootstrap"; */
import Alert from 'react-bootstrap/Alert';		/* import { Alert } from 'react-bootstrap'; idem */
import Counter from "./ItemCount"

const ListaConteiner = (prop) => {
  return (
    <>
      <Counter stock="3" initial="1" />
			<Alert variant = "info">{prop.greeting}</Alert>		{/* https://react-bootstrap.github.io/components/alerts/ */}
    </>
  )
}
export default ListaConteiner
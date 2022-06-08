/* import Alert from "react-bootstrap"; */
import Alert from 'react-bootstrap/Alert';		/* import { Alert } from 'react-bootstrap'; idem */

const ListaConteiner = (prop) => {
  return (
    <>
			<Alert variant = "info">{prop.greeting}</Alert>		{/* https://react-bootstrap.github.io/components/alerts/ */}
      
    </>
  )
}
export default ListaConteiner
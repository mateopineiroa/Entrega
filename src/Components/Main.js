import Cart from "./ItemListContainer"
import 'bootstrap/dist/css/bootstrap.min.css';
import ItemDetailContainer from "./ItemDetailContainer"; 
import ItemListContainer from "./ItemListContainer"

const Main = () => {
    let greeting = "Thank you for entering my web page"
    return (
        <>
            <Cart greeting = {greeting} />
            <ItemDetailContainer />
            <ItemListContainer />
        </>
    )
}

export default Main;
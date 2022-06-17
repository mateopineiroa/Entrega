import NavBar from "./Components/NavBar"
import Cart from "./Components/ItemListContainer"
import 'bootstrap/dist/css/bootstrap.min.css';
import './App.css';
import ItemDetailContainer from "./Components/ItemDetailContainer"; 

function App() {
  let greeting = "Thank you for entering my web page"
  return (
    <div className="App">
      <NavBar test="Holis" />
      <Cart greeting = {greeting} />
      <ItemDetailContainer />
    </div>
  );
}

export default App;

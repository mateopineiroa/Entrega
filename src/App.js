import NavBar from "./Components/NavBar"
import Cart from "./Components/itemListContainer"
import 'bootstrap/dist/css/bootstrap.min.css';
import './App.css';

function App() {
  let greeting = "Thank you for entering my web page"
  return (
    <div className="App">
      <NavBar test="Holis" />
      <Cart greeting = {greeting} />
    </div>

  );
}

export default App;

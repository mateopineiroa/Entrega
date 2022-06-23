import NavBar from "./Components/NavBar"
import 'bootstrap/dist/css/bootstrap.min.css';
import './App.css';
import Main from "./Components/Main"

function App() {
  let greeting = "Thank you for entering my web page"
  return (
    <div className="App">
      <NavBar test="Holis" />
      <Main />
    </div>
  );
}

export default App;
/* min 50 */
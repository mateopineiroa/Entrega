import logo from "../logo.svg";
const Cart = () => {
    console.log("carta enviada");
    return (
        <div>
            {/* <Button /> */}      {/* Que pasa si importo Button de la libreria react-bootstrap?? */}
            {/* <button type="button" class="btn btn-primary">Primary</button> */}      {/* Funciona bootstrap clasico */}
            <img class="w-25" src={logo} alt="texto"/>
        </div>
    );
}
export default Cart;
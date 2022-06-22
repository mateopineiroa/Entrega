import Cart from "./CartWidget"

const Nav = (props) => {
    console.log("NavBar importado exitosamente", props.test)
    return (
        <div class="box nav">
            <Cart />
            <h3>Inmobiliaria Piñeiro</h3>
            <ul>
                <a href="/#">Proyectos</a>
                <a href="/#">Propiedades</a>
                <a href="/#">Servicios</a>
                <a href="/#">Contacto</a>
            </ul>
        </div>
    );
}

export default Nav;

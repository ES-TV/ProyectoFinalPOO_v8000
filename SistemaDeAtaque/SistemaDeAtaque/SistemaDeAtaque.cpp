#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <thread> // esta libreria es para usar la funcion sleep_for y hacer pausas en el programa
#include <chrono> // esta libreria es para usar la funcion seconds y hacer pausas

class Item
{
private:
	std::string nombreItem;
	std::string categoriaItem;
	int cantidadItem, danio, precioItem;
	std::string descripcionItem;

public:
	Item(std::string p_nombreItem, std::string p_categoriaItem, int p_cantidadItem, int p_danio, int p_precioItem, std::string p_descripcionItem)
	{
		nombreItem = p_nombreItem;
		categoriaItem = p_categoriaItem;
		cantidadItem = p_cantidadItem;
		danio = p_danio;
		precioItem = p_precioItem;
		descripcionItem = p_descripcionItem;
	}

	void fn_mostrarConsumibleInventario()
	{
		std::cout << "Nombre: " << nombreItem << std::endl;
		std::cout << "Categoria: " << categoriaItem << std::endl;
		std::cout << "Cantidad: " << cantidadItem << std::endl;
	}

	void fn_mostrarArmaInventario()
	{
		std::cout << "Nombre: " << nombreItem << std::endl;
		std::cout << "Categoria: " << categoriaItem << std::endl;
		std::cout << "Danio: " << danio << std::endl; // En este caso el precio del arma se usara como su danio
	}




};

class Personaje // Esta va a ser la clase Padre/Base de los personajes
{
protected:
	std::string nombre;
	int vida;
	int danio;

public:
	Personaje(std::string p_nombre, int p_vida, int p_danio) // Constructor de la clase Padre/Base
	{
		nombre = p_nombre;
		vida = p_vida;
		danio = p_danio;
	}

	void fn_attack(int p_danio) // Funciob de restar vida
	{
		vida -= p_danio;
		if (vida <= 0)
		{
			vida = 0;
		}
	}

	bool fn_estavivo()
	{
		if (vida <= 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	int fn_getVida()
	{
		return vida;
	}

	int fn_getDanio()
	{
		return danio;
	}

	std::string fn_getNombre()
	{
		return nombre;
	}
};

class Jugador : public Personaje // Clase Jugador que heredara cosas de la principal ya le decimos que va a ser Heredera de la clase Padre/Base
{
protected:
	std::vector<Item> inventario; // Aqui se declara el inventario del jugador como un vector de objetos de la clase Item


public:
	Jugador(std::string p_nombreJugador, int p_vidaJugador, int p_danioJugador) : // Constructor para esta clase usando la herencia de la clase Padre/Base
		Personaje(p_nombreJugador, p_vidaJugador, p_danioJugador) // Asi es como se declara el constructor, solo que con los mismos parametros de de esta clase
		// (Se pudieron poner los constructores en la misma fila pero para los comentarios os separe)
	{

	}

	void fn_agregarItem(Item item) // Funcion para agregar items al inventario del jugador, se usara mas adelante
	{
		inventario.push_back(item);
	}

	void fn_menuInventario() // Funcion para mostrar el menu del inventario del jugador, se usara mas adelante
	{
		std::cout << "Menu de Inventario\Selecciona una opcion:" << std::endl;
		std::cout << "------------------" << std::endl;
		std::cout << "1. Consumibles" << std::endl;
		std::cout << "2. Armas" << std::endl;
		std::cout << "3. Salir" << std::endl;
		std::cout << "------------------" << std::endl;

	}

	void fn_showInventarioConsumibles() // Funcion para mostrar el inventario del jugador, se usara mas adelante
	{
		std::cout << "------------------" << std::endl;
		std::cout << "   Consumibles  " << nombre << ":" << std::endl;
		std::cout << "------------------" << std::endl;
		for (int i = 0; i < inventario.size(); i++)
		{
			std::cout << i + 1 << ".-";
			inventario[i].fn_mostrarConsumibleInventario();
		}
		std::system("pause");
	}

	void fn_showInventarioArmas() // Funcion para mostrar el inventario del jugador, se usara mas adelante
	{
		std::cout << "------------------" << std::endl;
		std::cout << "     Armas      " << nombre << ":" << std::endl;
		std::cout << "------------------" << std::endl;
		for (int i = 0; i < inventario.size(); i++)
		{
			std::cout << i + 1 << ".-";
			inventario[i].fn_mostrarArmaInventario();
		}
		std::system("pause");
	}

};

class Enemigo : public Personaje
{
public:
	// Aqui trate de hacer vectores con varios enemigos pero no supe como hacerlo, asi que hice 3 objetos de la clase Enemigo


	Enemigo(std::string p_nombreEnemy, int p_vidaEnemy, int p_danioEnemy) :
		Personaje(p_nombreEnemy, p_vidaEnemy, p_danioEnemy)
	{

	}
};

class Tienda
{
private:
	std::vector<Item> inventario;

public:
	Tienda()
	{

	}



};

// Aqui se crean los objetos como variables globales para poder usarlas en cualquier parte del codigo
Jugador objJugador("Zawardo", 40, 10); // Nombre, vida, danio
Enemigo objEnemy1("Chaneque", 20, 3);
Enemigo objEnemy2("Bruja", 30, 5);
Enemigo objEnemy3("Nahual", 40, 7);
Enemigo enemigos[] = { objEnemy1, objEnemy2, objEnemy3 }; // Se genero un vector con los obejots de enemigos
Enemigo objEnemy = enemigos[std::rand() % 3]; // Ya se hace el random para pelear
Item itemConsumibleA("Gansito", "(Consumible)", 10, 0, 10, "Delicioso aperitivo para curar puntos de Salud"); // Nombre, categoria, cantidad, daño, precio, descripcion
Item itemConsumibleA("Monster", "(Consumible)", 10, 0, 5, "Bebida brutalmente energetica para recuperar puntos de Energia");

void fn_EfectoTexto(std::string texto) // Esta funcion es para imprimir el texto con un efecto de juego  que se imprime letra por letra (Se usara en ve del std::cout)
{
	for (char c : texto)
	{
		std::cout << c << std::flush; // Imprime cada caracter y vacia el buffer para que se vea el efecto de escritura
		std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Pausa de 50 milisegundos entre cada caracter
	}
	std::cout << std::endl; // Salto de linea al final del texto
}

void fn_ImprimirTextoPelea()
{

	fn_EfectoTexto("Te has encontrado con un " + objEnemy.fn_getNombre());
	fn_EfectoTexto("Sus stats son:\n Vida: " + std::to_string(objEnemy.fn_getVida()) + " Danio = " + std::to_string(objEnemy.fn_getDanio()));
	// Se usa el std::to_string() para convertir los numeros a string para imprimirlos igual evitando errores matematicos
	std::system("pause");
	// Atacar
	do
	{
		int danioJugador = objJugador.fn_getDanio();
		objEnemy.fn_attack(danioJugador);
		fn_EfectoTexto("Zawardo pega un machetazo haciendole " + std::to_string(danioJugador) + " de danio al enemigo");
		fn_EfectoTexto("Vida del enemigo: " + std::to_string(objEnemy.fn_getVida())); // Aqui checamos la vida del enemigo
		std::system("pause");
		int danioEnemy = objEnemy.fn_getDanio();
		objJugador.fn_attack(danioEnemy);
		fn_EfectoTexto("El enemigo te ataca dandote " + std::to_string(danioEnemy) + " de danio");
		fn_EfectoTexto("Vida: " + std::to_string(objJugador.fn_getVida())); // Aqui checamos la vida del jugador
		std::system("pause");
		std::system("cls");
	} while (objJugador.fn_estavivo() && objEnemy.fn_estavivo());
	fn_EfectoTexto("El enemigo ha sido derrotado");
}

int main()
{
	std::srand(time(NULL));

	fn_ImprimirTextoPelea();
	
	return 0;
}

/*
Lo que falta:
- Hacer una probabilidad de fallo del ataque
- Nivelar daños y vidas
*/

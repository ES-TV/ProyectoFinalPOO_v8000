#include <iostream>
#include <string>
#include <vector>
#include <random>

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

	void fn_Attack(int p_danio) // Funciob de restar vida
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

	int fn_GetDanio()
	{
		return danio;
	}

};

class Jugador : public Personaje // Clase Jugador que heredara cosas de la principal ya le decimos que va a ser Heredera de la clase Padre/Base
{
protected:
	std::string nombrePersonaje = "Zawardo";
	int vidaPersonaje = 40;
	int danioPresonaje = 10;


public:
	Jugador(std::string p_nombreJugador, int p_vidaJugador, int p_danioJugador) : // Constructor para esta clase usando la herencia de la clase Padre/Base
		Personaje(p_nombreJugador, p_vidaJugador, p_danioJugador) // Asi es como se declara el constructor, solo que con los mismos parametros de de esta clase
		// (Se pudieron poner los constructores en la misma fila pero para los comentarios os separe)
	{
		p_nombreJugador = nombrePersonaje;
		p_vidaJugador = vidaPersonaje;
		p_danioJugador = danioPresonaje;
	}
};

class Enemigo : public Personaje
{
public:
	// Aqui trate de hacer vectores con varios enemigos pero no supe como hacerlo, asi que hice 3 objetos de la clase Enemigo
	std::string nombreEnemigo;
	int vidaEnemigo;
	int danioEnemigo;

	Enemigo(std::string p_nombreEnemy, int p_vidaEnemy, int p_danioEnemy) :
		Personaje(p_nombreEnemy, p_vidaEnemy, p_danioEnemy)
	{
		nombreEnemigo = p_nombreEnemy;
		vidaEnemigo = p_vidaEnemy;
		danioEnemigo = p_danioEnemy;
	}
};

int main()
{
	std::srand(time(NULL));

	Jugador objJugador("Zawardo", 40, 10);
	Enemigo objEnemy1("Chaneque", 20, 3);
	Enemigo objEnemy2("Bruja", 30, 5);
	Enemigo objEnemy3("Nahual", 40, 7);

	Enemigo enemigos[] = { objEnemy1, objEnemy2, objEnemy3 }; // Se genero un vector con los obejots de enemigos
	Enemigo objEnemy = enemigos[std::rand() % 3]; // Ya se hace el random para pelear

	std::cout << "Te has encontrado con un " << objEnemy.nombreEnemigo << std::endl;
	std::cout << "Sus stats son: " << "Vida: " << objEnemy.fn_getVida() << " Danio: " << objEnemy.fn_GetDanio() << std::endl;
	std::system("pause");
	// Atacar
	do
	{
		int danioJugador = objJugador.fn_GetDanio();
		objEnemy.fn_Attack(danioJugador);
		std::cout << "Zawardo pega un machetazo haciendole " << danioJugador << " de danio al enemigo" << std::endl;
		std::cout << "Vida del enemigo: " << objEnemy.fn_getVida() << std::endl; // Aqui checamos la vida del enemigo
		std::system("pause");
		int danioEnemy = objEnemy.fn_GetDanio();
		objJugador.fn_Attack(danioEnemy);
		std::cout << "El enemigo te ataca dandote " << danioEnemy << " de danio" << std::endl;
		std::cout << "Vida: " << objJugador.fn_getVida() << std::endl; // Aqui checamos la vida del jugador
		std::system("pause");
		std::system("cls");
	} while (objJugador.fn_estavivo() && objEnemy.fn_estavivo());
	std::cout << "El enemigo ha sido derrotado" << std::endl;
	
	return 0;
}

/*
Lo que falta:
- Hacer una probabilidad de fallo del ataque
- Nivelar daños y vidas
*/

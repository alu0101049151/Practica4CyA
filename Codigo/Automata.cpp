/* *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia (CyA)
 * Curso: 2º
 * Práctica 4 CyA - Eliminador de comentarios
 * Autor: Basilio Gómez Navarro
 * Correo: alu0101049151@ull.edu.es
 * Fecha 13/10/2019
 * Archivo Automata.cpp: Clase Automata. Representa un autómata finito.
 *                       Este fichero contiene la implementación de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
 * Historial de revisiones
 *                   13/10/2019 - Creación (primera versión) del código
 * */


#include "Automata.h"


Automata::Automata (std::string& ficheroEntrada)
{
	leeAutomata (ficheroEntrada);
}


Automata::Automata () {}


Automata::~Automata (){}


int Automata::getNumeroEstados () const
{
	return numeroEstados_;
}


int Automata::getEstadoArranque () const
{
	return estadoArranque_;
}


std::set<Estado> Automata::getEstados () const
{
	return estados_;
}


int Automata::getEstadoActual () const
{
	return estadoActual_;
}


void Automata::setEstadoActual (int nuevoEstado)
{
	estadoActual_ = nuevoEstado;
}


void Automata::insertEstados (Estado estado)
{
	estados_.insert(estado);
}


void Automata::leeAutomata (std::string& ficheroEntrada)
{
	std::ifstream input_file;
	input_file.open(ficheroEntrada);

	if (!input_file.is_open())
		std::cerr << "Ha ocurrido un problema al abrir el fichero de entrada, por favor, inténtelo de nuevo" << NEWLINE;
	else {                 // Si el fichero se ha abierto correctamente.

		std::string leido;   // Línea leída del fichero.
		
		std::getline(input_file, leido); // Lee el número de estados del autómata.
    numeroEstados_ = stoi(leido);
		leido.clear();

		std::getline(input_file, leido); // Lee el identificador del estdo de arranque;
		estadoArranque_ = stoi(leido);
		leido.clear();


		std::string auxString;   // String auxiliar para leer la información de cada estado.
		int auxId;               // Identificador auxiliar de un estado;
		int numeroTransiciones;  // Indica el número de transiciones de un estado.
		bool auxAceptacion;      // Identificador auxiliar de aceptación de un estado.
		char auxEntrada;         // Identificador auxiliar de la entrada de una transición.
		int  auxDestino;         // Identificador auxiliar del destino de la transición.

		while (!input_file.eof()) {  // Lee la informaciónn pertinente a cada estado del autómata.
			
			std::getline(input_file, leido);
			std::stringstream iss(leido);

			iss >> auxString;    // Lectura del identificador numérico del estado.
			if (!auxString.empty()) {
      	std::cout << "Identificador auxiliar del estado: " << auxString << NEWLINE;
				auxId = stoi(auxString);
				auxString.clear();

				iss >> auxString;   // Lectura de la etiqueta de aceptación del etado.
				std::cout << "Identificador de aceptación: " << auxString << NEWLINE;
				auxAceptacion = stoi(auxString);
				auxString.clear();

				iss >> auxString;   // Lectura del número de transiciones de un estado.
				std::cout << "Numero de transiciones del estado: " << auxString << NEWLINE;
				numeroTransiciones = stoi(auxString);
				auxString.clear();

				Estado auxEstado(auxId, auxAceptacion);

				for (int i = 0; i < numeroTransiciones; ++i) {
				
					iss >> auxString;
					std::cout << "Entrada: " << auxString << NEWLINE;
					auxEntrada = auxString[0];
					auxString.clear();

					iss >> auxString;
					std::cout << "Destino: " << auxString << NEWLINE;
					auxDestino = stoi(auxString);
					auxString.clear();

					Transicion auxTransicion(auxEntrada, auxDestino);
					auxEstado.insertTransiciones(auxTransicion);
			
				}

		      estados_.insert(auxEstado);  // Llenado del conjunto de estados del autómata.
			    leido.clear();
		  }
	  }
  }
}


void Automata::writeAutomata (std::ostream& os) const
{
	os << numeroEstados_ << NEWLINE;
	os << estadoArranque_ << NEWLINE;

	for (auto i: estados_) {
	}
}

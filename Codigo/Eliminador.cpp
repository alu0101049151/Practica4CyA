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
 * Archivo Eliminador.cpp: Clase Eliminador. Es la clase que se encarga de
 *                         analizar un fichero de entrada y eliminar sus
 *                         comentarios haciendo uso de un objeto Automata.
 *                         Este fichero contiene la implementación de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
 * Historial de revisiones
 *                   13/10/2019 - Creación (primera versión) del código
 * */

#include "Eliminador.h"

Eliminador::Eliminador (std::string& ficheroEntrada, std::string& ficheroSalida, std::string& ficheroAutomata):
	automata_(ficheroAutomata)
{
	eliminar (ficheroEntrada, ficheroSalida);
}

Eliminador::~Eliminador () {}


// Lee el fichero de entrada, llama a analizar para analizar lo leído y exporta
// el resultado al fichero de salida 
void Eliminador::eliminar (std::string& ficheroEntrada, std::string& ficheroSalida)
{
	std::ifstream input_file;
	std::ofstream output_file;

	input_file.open(ficheroEntrada);

	if (!input_file.is_open()) 
		std::cerr << "Ha ocurrido un problema al abrir el fichero de entrada, por favor inténtelo de nuevo" << NEWLINE;
	
	else {

		char leido;     // Carácter leido del fichero.
		
		output_file.open(ficheroSalida);

		automata_.setEstadoActual(automata_.getEstadoArranque()); // Inicializamos el estado actual del Automata al de arranque.

		while (!input_file.eof()) {
			input_file.get(leido);
			analiza (leido, output_file);
		}

		input_file.close();
		output_file.close();
	}
}


void Eliminador::analiza (char aAnalizar, std::ostream& os)
{
	bool estadoEncontrado = false;              // Variable para controlar si se ha encontrado el estado buscado.
	bool transicionEncontrada = false;         // Variable para controlar si se ha encontrado la transicion.
	char transformado;

	transformado = transforma(aAnalizar);

	for (auto i: automata_.getEstados()) {
		std::cout << "Id estado: " <<  i.getIdEstado() << NEWLINE;
		std::cout << "Estado actual: " << automata_.getEstadoActual() << NEWLINE;
		if (i.getIdEstado() == automata_.getEstadoActual()) {
		  for (auto j: i.getTransiciones()) {
				  if ((j.getEntrada() == transformado) && !transicionEncontrada) {
					  transicionEncontrada = true;
						if (i.getAceptacion())
							os << aAnalizar;
					  automata_.setEstadoActual(j.getDestino());
					  std::cout << "Esta imprimiendo analizar: " << aAnalizar << NEWLINE;
				  }
		  }
		}	
		transicionEncontrada = false;
	}
}



char Eliminador::transforma (char aAnalizar)
{
	switch (aAnalizar) {
		case '/':
			{
			  if (automata_.getEstadoActual() == 5 || automata_.getEstadoActual() == 2 || automata_.getEstadoActual() == 3)
			    return '$';
			  else
				  return '/';
			  break;
			}
		case '*':
			{
				if (automata_.getEstadoActual() == 0 || automata_.getEstadoActual() == 2 || automata_.getEstadoActual() == 5)
          return '$';
        else
          return aAnalizar;
        break;
			}
		case '"':
			{
			  if (automata_.getEstadoActual() == 2 || automata_.getEstadoActual() == 3 || automata_.getEstadoActual() == 4)
				  return '$';
			  else
				  return aAnalizar;
				break;
      }
		case '\n':
			{
				if (automata_.getEstadoActual() == 2)
					return aAnalizar;
				else
					return '$';
				break;
			}
		default:
			return '$';
	}
}

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
 * Archivo Eliminador.h: Clase Eliminador. Es la clase que se encarga de
 *                       analizar un fichero de entrada y eliminar sus
 *                       comentarios haciendo uso de un objeto Automata.
 *                       Este fichero contiene la definición de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
 * Historial de revisiones
 *                   13/10/2019 - Creación (primera versión) del código
 * */

#ifndef PRACTICA4_ELIMINADOR_H
#define PRACTICA4_ELIMINADOR_H

#include <istream>

#include "Automata.h"


class Eliminador
{
	public:
		Eliminador (std::string& ficheroEntrada, std::string& ficheroSalida, std::string& ficheroAutomata);
		~Eliminador ();

	protected:
		// Método que lee el fichero de entrada, y en base al resultado del metodo
		// "analiza", escribe en el fichero de salida.
		void eliminar (std::string& ficheroEntrada, std::string& ficheroSalida);

		// Método para analizar cada uno de los caracteres leídos del fichero de
		// entrada
		void analiza (char aAnalizar, std::ostream& os);

    // Método encargado de transformar los carcateres distintos de / * en $ ó %
		char transforma (char aAnalizar);

	private:
		Automata automata_;  // Será el autómata que nos permita llevar a cabo el análisis del fichero de entrada.
		

};

#endif // PRACTICA4_ELIMINADOR_H

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
 * Archivo Automata.h: Clase Automata. Representa un autómata finito.
 *                     Este fichero contiene la definición de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
 * Historial de revisiones
 *                   13/10/2019 - Creación (primera versión) del código
 * */

#ifndef PRACTICA4_AUTOMATA_H
#define PRACTICA4_AUTOMATA_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Estado.h"


//CONSTANTES
const char NEWLINE = '\n';


class Automata
{
	public:
		Automata (std::string& ficheroEntrada);
		Automata ();
		~Automata ();

		int getNumeroEstados () const;
		int getEstadoArranque () const;
		int getEstadoActual () const;
		std::set<Estado> getEstados () const;
		
		void setEstadoActual (int nuevoEstado);
		
		void insertEstados (Estado estado);
		void writeAutomata (std::ostream& os) const;

	protected:
		// Lee el autómata del fichero de entrada.
		void leeAutomata(std::string& ficheroEntrada);

	private:
		int numeroEstados_; // ??????????? Es necesario?
		int estadoActual_;
		int estadoArranque_;        
		std::set<Estado> estados_;   // Conjunto de estados del autómata.
};

#endif //PRACTICA4_AUTOMATA_H

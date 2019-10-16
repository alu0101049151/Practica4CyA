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
 * Archivo mainUnCommetn.cpp: Contiene la función main del proyecto, la cual
 *                            recoge el nombre del fichero de entrada y el
 *                            de salida. 
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
 * Historial de revisiones
 *                   13/10/2019 - Creación (primera versión) del código
 * */

#include "Automata.h"


int main (int argc, char const* argv[])
{
	std::string input = "../Entradas/automata.nfa;

  if (argv[1] == NULL) {
    //AYUDA DEL PROGRAMA
  }
  else {

		Automata automata(0, input);
	}
	return 0;
}

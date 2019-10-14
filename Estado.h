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
 * Archivo Estado.h: Clase Estado. Representa un estado de un autómata finito.
 *                   Este fichero contiene la definición de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
 * Historial de revisiones
 *                   13/10/2019 - Creación (primera versión) del código
 * */

#ifndef PRACTICA4_ESTADO_H
#define PRACTICA4_ESTADO_H

#include "Transicion.h"

#include <set>

class Estado
{
	public:
		Estado (int idEstado);
		Estado (const Estado& estado);
		~Estado ();

		int getIdEstado () const;
		std::set<Transicion> getTransiciones () const;

		void insertTransiciones (Transicion transicion);

	protected:
		int operator< (const Estado& estado) const;

	private:
		int idEstado_;
		std::set<Transicion> transiciones_;

};
#endif //PRACTICA4_ESTADO_H

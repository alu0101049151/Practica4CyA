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
 * Archivo Estado.cpp: Clase Estado. Representa un estado de un autómata finito.
 *                     Este fichero contiene la implementación de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
 * Historial de revisiones
 *                   13/10/2019 - Creación (primera versión) del código
 * */

#include "Estado.h"


Estado::Estado (int idEstado):
	idEstado_(idEstado){}


Estado::Estado (const Estado& estado):
	idEstado_(estado.idEstado_){}


~Estado::Estado (){}


int Estado::getIdEstado () const
{
	return idEstado_;
}

std::set<Transicion> Estado::getTransiciones () const
{
	return transiciones_;
}


//Método para insertar una nueva transición en el conjunto de transiciones de un
//estado.
void Estado::insertTransiciones (Transicion transicion)
{
	transciones_.insert(transicion);
}


int Estdo::operator< (const Estado& estado) const
{
	if (this->idEstado_ < estado.idEstado) return 1;
	if (this->idEstado_ == estado.idEStado) return 1;
	return 0;
}


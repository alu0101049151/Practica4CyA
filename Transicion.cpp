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
 * Archivo Transicion.cpp: Clase Transicion. Representa una transición entre dos
 *                         estados de un autómata finito.
 *                         Este fichero contiene la implementación de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
 * Historial de revisiones
 *                   13/10/2019 - Creación (primera versión) del código
 * */

#include "Transicion.h"

Transicion::Transicion (char entrada, int destino):
	entrada_(entrada),
	destino_(destino){}


Transicion::Transicion (const Transicion& transicion):
	entrada_(transicion.entrada_),
	destino_(transicion.destino_){}


Transicion::~Transicion (){}


char Transicion::getEntrada () const
{
	return entrada_;
}


int Transicion::getDestino () const
{
	return destino_;
}


int Transicion::operator< (const Transicion& transicion) const
{
	if (this->entrada_ < transicion.entrada_) return 1;
	if (this->entrada_ == transicion.entrada_ && this->destino_ < transicion.destino_) return 1;
	return 0;
}


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
 * Archivo Transicion.h: Clase Transicion. Representa una transición entre dos
 *                       estados de un autómata finito.
 *                       Este fichero contiene la definición de la clase.
 *
 * Referencias:
 *                   Enunciado de la prácita:
 *                   https://campusvirtual.ull.es/1920/pluginfile.php/166891/mod_assign/introattachment/0/CYA_1920_Practica_4.pdf?forcedownload=1
 * Historial de revisiones
 *                   13/10/2019 - Creación (primera versión) del código
 * */

#ifndef PRACTICA4_TRANSICION_H
#define PRACTICA4_TRANSICION_H

class Transicion
{

	public:
		Transicion (char entrada, int destino);
		Transicion (const Transicion& Transicion);
		~Transicion ();

		char getEntrada () const;
		int getDestino () const;

		int operator< (const Transicion& transicion) const;

	private:
		char entrada_;   //Carácter de entrada que determina el estado al que se transita
		int  destino_;   //Identificador del estado de destino al que transita con "entrada_"
};

#endif // PRACTICA4_TRANSICION_H


//
// Created by clinux01 on 18/11/22.
//

#ifndef TP_JUEGODEPALABRAS_JUEGO_H
#define TP_JUEGODEPALABRAS_JUEGO_H


#include "Tipos.h"
#include "variante.h"
#include "Letra.h"

class juego {
public:
    const Nat numJugadores() const;
    juego(Nat numJugadores, variante var, Repositorio rep);
    void ubicar(Ocurrencia o);
    const variante obtenerVariante() const;
    const Nat obtenerTurno() const;
    const Nat obtenerPuntaje() const;
    const bool EsjugadaValida(Ocurrencia o) const;
    const Letra fichaEnPosicion(Nat fila , Nat columna) const;
    const bool hayFicha(Nat fila, Nat columna) const;
    const Nat cuantasDeEstaTiene(Letra l, Nat idCliente) const;

private:
    Repositorio _rep;
    struct Casillero{
        Letra letra;
        Nat   turnoJugado;
        bool  ocupado;
    };
    using Tablero = vector<vector<Casillero>>;
    Tablero tablero;
    variante v;
    Nat numJug;
    Nat turnoActual;
    struct jugador{
        using Mano = vector<int>;
        Mano mano;
        Nat puntaje;
        Ocurrencia fichasQuePusoDesde;

    };
    using Jugadores = vector<jugador>;
    Jugadores jugadores;
    Jugadores repartirFichas(variante v, Nat cantJugadores, Repositorio rep);
    Tablero crearTablero(Nat tamano);
};
#endif //TP_JUEGODEPALABRAS_JUEGO_H

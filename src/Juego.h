#ifndef TP_JUEGODEPALABRAS_JUEGO_H
#define TP_JUEGODEPALABRAS_JUEGO_H

#include "Variante.h"


class Juego {
public:
    const Nat numJugadores() const;
    Juego(Nat numJugadores, Variante var, Repositorio rep);
    void ubicar(Ocurrencia o);
    const Variante obtenerVariante() const;
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
    Variante v;
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
    Jugadores repartirFichas(Variante v, Nat cantJugadores, Repositorio rep);
    Tablero crearTablero(Nat tamano);
};

#endif //TP_JUEGODEPALABRAS_JUEGO_H

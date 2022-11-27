#include "Fachada_Variante.h"

Fachada_Variante::Fachada_Variante(Nat tamanoTab, Nat cantFichas, const map<Letra, Nat> &puntajes,
                                   const set<vector<Letra>> &palabrasLegitimas)
        : _var(tamanoTab,cantFichas, puntajes,palabrasLegitimas){}

Nat Fachada_Variante::tamanoTablero() const {
    return _var.tamanoTablero();
}

Nat Fachada_Variante::fichas() const {
    return _var.cantFichas();
}

Nat Fachada_Variante::puntajeLetra(Letra l) const {
    return _var.puntajeLetra(l);
}

bool Fachada_Variante::palabraLegitima(const Palabra &palabra) const {
    return _var.palabraLegitima(palabra);
}


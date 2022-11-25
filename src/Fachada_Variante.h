#ifndef FACHADA_VARIANTE_H
#define FACHADA_VARIANTE_H

//#include "Tipos.h"
#include "variante.h"
#include "Letra.h"

class Fachada_Variante {
public:
    /**
     * Construye una Fachada_Variante a partir de los parametros de las variantes
     */
    Fachada_Variante(
            Nat tamanoTab,
            Nat cantFichas,
            const map<Letra, Nat>& puntajes,
            const set<vector<Letra>>& palabrasLegitimas
    );

    /**
     * Retorna el tamano del tablero de la variante
     */
    Nat tamanoTablero() const;

    /**
     * Retorna la cantidad de fichas que cada jugador deberia tener en su mano.
     */
    Nat fichas() const;

    /**
     * Retorna el puntaje de la letra l
     */
    Nat puntajeLetra(Letra l) const;

    /**
     * Indica si una palabra es legitima o no
     */
    bool palabraLegitima(const Palabra& palabra) const;

private:
    variante _var;

    trie pasarATrie(const set<vector<Letra>> &set);
};

Abecedario pasarAVector(const map<Letra, Nat> &map);

Fachada_Variante::Fachada_Variante(Nat tamanoTab, Nat cantFichas, const map<Letra, Nat> &puntajes,
                                   const set<vector<Letra>> &palabrasLegitimas)
            : _var(pasarATrie(palabrasLegitimas),cantFichas, pasarAVector(puntajes),tamanoTab,pasarATrie(palabrasLegitimas).obtenerLmax()){}

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


Abecedario pasarAVector(const map<Letra, Nat> &map) {
    Abecedario abc(map.size(),0);
    for(auto x: map){
        abc[ord(x.first)] = x.second;
    }
    return abc;
}

trie Fachada_Variante::pasarATrie(const set <vector<Letra>> &set) {
    trie res = trie();
    string s;

    for (auto x: set) {
        s = "";
        for (char y: x){
            s.push_back(y);

        }

        res.insert(make_pair(s,1));

    }
    return res;
}

#endif //FACHADA_VARIANTE_H

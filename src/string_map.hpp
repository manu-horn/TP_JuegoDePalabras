#include "string_map.h"
#include "vector"
template <typename T>
string_map<T>::string_map():_size(0),lmax(0){
    raiz=new Nodo();
    vector<Nodo*> v(256, nullptr);
    this->raiz->definicion=nullptr;
    this->raiz->siguientes=v;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    destructor(raiz);
    raiz=new Nodo();
    vector<Nodo*> v(256, nullptr);
    this->raiz->definicion=nullptr;
    this->raiz->siguientes=v;
    copiar(d.raiz, "");
}
template<typename T>
void string_map<T>::copiar(Nodo* nodo, const string key){
    if (nodo->definicion != nullptr) {
        insert(make_pair(key, *(nodo->definicion)));
    }
    for (int i = 0; i < nodo->siguientes.size(); i++) {
        if (nodo->siguientes[i] != nullptr) {
            copiar(nodo->siguientes[i], key + char(i));
        }
    }
}
template<typename T>
void string_map<T>::destructor(Nodo* nodo){
    for (int i = 0; i < nodo->siguientes.size(); i++) {
        if (nodo->siguientes[i] != nullptr) {
            destructor(nodo->siguientes[i]);
        }
    }
    delete nodo->definicion;
    delete nodo;
}


template <typename T>
string_map<T>::~string_map(){
    destructor(this->raiz);
}

template<typename T>
void string_map<T>::insert(const pair<string, T>& p){
    if(p.first.size() > lmax){
        lmax = p.first.size();
    }
    Nodo* aux=this->raiz;
    for(int i=0;i<p.first.size();i++) {
        int indice = int(p.first[i]);
        if (aux->siguientes[int(p.first[i])]==nullptr) {
            Nodo* nuevo=new Nodo();
            nuevo->definicion = nullptr;
            vector<Nodo*> v(256, nullptr);
            nuevo->siguientes = v;
            aux->siguientes[int(p.first[i])]=nuevo;
            aux=nuevo;
        } else {
            aux=aux->siguientes[int(p.first[i])];
        }
    }
    if (aux->definicion != nullptr) {
        delete aux->definicion;
    }
    T* def=new T(p.second);
    aux->definicion=def;
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}


template <typename T>
int string_map<T>::count(const string& key) const{
      Nodo* aux=this->raiz;
      int count=0;
      int j=0;
      for(int i=0;i<key.size();i++){
          if(aux->siguientes[int(key[i])]!=nullptr) {
              aux = aux->siguientes[int(key[i])];
              j++;
          }
      }
      if(aux->definicion!=nullptr && (j==key.size())){
          count=1;
      }
      return count;
}

template <typename T>
const T& string_map<T>::at(const string& key) const {
    Nodo* aux=this->raiz;
    for(int i=0;i<key.size();i++){
        aux=aux->siguientes[int(key[i])];
    }
    return *(aux->definicion);
}

template <typename T>
T& string_map<T>::at(const string& key) {
    Nodo* aux=this->raiz;
    for(int i=0;i<key.size();i++){
         aux=aux->siguientes[int(key[i])];
    }
    return *(aux->definicion);
}


template <typename T>
void string_map<T>::erase(const string& key) {
    bool res=true;
    Nodo* aux=this->raiz;
    Nodo* padre=nullptr;
    for(int i=0;i<key.size();i++){
        padre=aux;
        aux=aux->siguientes[int(key[i])];
    }
    delete aux->definicion;
    aux->definicion=nullptr;
    /*for(int i=0;i<256;i++){
         if(aux->siguientes[i]!=nullptr && padre!=nullptr){
             res=false;
         }
    }

    if(res){
        for(int i=0;i<key.size();i++){
            delete aux;
            aux=padre;

        }
    }*/
}
template<typename T>
int string_map<T>::size_aux(Nodo* nodo) const{
    int size = 0;
     for(int i=0;i<nodo->siguientes.size();i++) {
         if (nodo->siguientes[i] != nullptr) {
             size += size_aux(nodo->siguientes[i]);
         }
     }
     size += nodo->definicion != nullptr ? 1 : 0;
     return size;
}

template <typename T>
int string_map<T>::size() const{
      return size_aux(this->raiz);

}
template<typename T>
bool string_map<T>::empty_aux(Nodo* nodo) const{
    bool esvacio=true;
    if(nodo->definicion!=nullptr && nodo!=this->raiz){
        esvacio=false;
    }
    for(int i=0;i<256;i++){
        if(nodo->siguientes[i]!=nullptr){
            empty_aux(nodo->siguientes[i]);
        }
    }
    return esvacio;
}

template <typename T>
bool string_map<T>::empty() const{
    return empty_aux(this->raiz);
}
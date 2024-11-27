#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <vector>
using namespace std;

template<class T, T vacio = nullptr>
class CGrafo {
private:
    class CArco {
    public:
        T info;
        int v; // indice del vértice de llegada
        CArco(int vLlegada) {
            info = vacio;
            v = vLlegada;
        }
    };

    class CVertice {
    public:
        T info;
        vector<CArco*>* ady; // Lista de adyacencia
        CVertice() {
            info = vacio;
            ady = new vector<CArco*>();
        }
    };

    vector<CVertice*>* vertices;

public:
    CGrafo() {
        vertices = new vector<CVertice*>();
    }

    int adicionarVertice(T info) {
        CVertice* vert = new CVertice();
        vert->info = info;
        vertices->push_back(vert);
        return vertices->size() - 1;
    }

    int cantidadVertices() {
        return vertices->size();
    }

    T obtenerVertice(int v) {
        return (vertices->at(v))->info;
    }

    void modificarVertice(int v, T info) {
        (vertices->at(v))->info = info;
    }

    int adicionarArco(int v, int vLlegada) {
        CVertice* ver = vertices->at(v);
        CArco* arc = new CArco(vLlegada);
        ver->ady->push_back(arc);
        return ver->ady->size() - 1;
    }

    int cantidadArcos(int v) {
        return (vertices->at(v))->ady->size();
    }

    T obtenerArco(int v, int apos) {
        CVertice* ver = vertices->at(v);
        return (ver->ady->at(apos))->info;
    }

    void modificarArco(int v, int apos, T info) {
        CVertice* ver = vertices->at(v);
        (ver->ady->at(apos))->info = info;
    }

    int obtenerVerticeLlegada(int v, int apos) {
        CVertice* ver = vertices->at(v);
        return (ver->ady->at(apos))->v; // indice del vértice de llegada
    }
};


#endif // !__GRAFO_HPP__
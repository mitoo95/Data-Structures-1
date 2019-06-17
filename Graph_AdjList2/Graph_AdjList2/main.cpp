#include <iostream>
#include <windows.h>
#include "Graph.h"

using namespace std;

int main()
{
	Graph *G = new Graph();
	int opc;
	

	G->addVertex("TIJ");
	G->addVertex("MTY");
	G->addVertex("MZT");
	G->addVertex("BJX");
	G->addVertex("GDL");
	G->addVertex("SAN");
	G->addVertex("TAM");
	G->addVertex("MEX");
	G->addVertex("CUN");
	G->addVertex("MID");

	G->addEdge(G->getVertex("TIJ"), G->getVertex("MTY"), 800);
	G->addEdge(G->getVertex("MZT"), G->getVertex("TIJ"), 400);
	G->addEdge(G->getVertex("MZT"), G->getVertex("BJX"), 300);
	G->addEdge(G->getVertex("MTY"), G->getVertex("BJX"), 700);
	G->addEdge(G->getVertex("BJX"), G->getVertex("SAN"), 900);
	G->addEdge(G->getVertex("BJX"), G->getVertex("TAM"), 400);
	G->addEdge(G->getVertex("BJX"), G->getVertex("MEX"), 350);
	G->addEdge(G->getVertex("GDL"), G->getVertex("MZT"), 500);
	G->addEdge(G->getVertex("GDL"), G->getVertex("MTY"), 450);
	G->addEdge(G->getVertex("GDL"), G->getVertex("BJX"), 250);
	G->addEdge(G->getVertex("GDL"), G->getVertex("MEX"), 500);
	G->addEdge(G->getVertex("SAN"), G->getVertex("MID"), 1200);
	G->addEdge(G->getVertex("TAM"), G->getVertex("MID"), 450);
	G->addEdge(G->getVertex("MEX"), G->getVertex("MID"), 450);
	G->addEdge(G->getVertex("MEX"), G->getVertex("CUN"), 650);
	G->addEdge(G->getVertex("CUN"), G->getVertex("GDL"), 650);

	do
	{
		system("cls");
		cout << "1. Ingresar Vertice" << endl;
		cout << "2. Ingresar arista" << endl;
		cout << "3. Lista de adyacencia" << endl;
		cout << "4. Tamaño" << endl;
		cout << "5. Eliminar vertice" << endl;
		cout << "6. Eliminar arista" << endl;
		cout << "7. Anular" << endl;
		cout << "8. Recorrido en profundidad" << endl;
		cout << "9. Salir" << endl;
		cout << endl << "Elija una opcion: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
		{
			string nombre;
			system("cls");
			cout << "Ingrese el nombre del vertice: ";
			cin.ignore();
			getline(cin, nombre, '\n');
			G->addVertex(nombre);
			cin.get();
			cin.get();
			break;
		}
		case 2:
		{
			string origen, destino;
			int peso;
			system("cls");
			if (G->isEmpty())
			{
				cout << "El grafo esta vacio" << endl;
			}
			else
			{
				cout << "Ingrese del nombre del vertice origen: ";
				cin.ignore();
				getline(cin, origen, '\n');
				cout << "Ingrese el nombre del vertice destino: ";
				getline(cin, destino, '\n');
				cout << "Ingrese el peso: ";
				cin >> peso;

				if (G->getVertex(origen) == NULL || G->getVertex(destino) == NULL)
				{
					cout << "Uno de los vertices no es valido" << endl;
				}
				else
				{
					G->addEdge(G->getVertex(origen), G->getVertex(destino), peso);
				}
			}
			cin.get();
			cin.get();
			break;
		}
		case 3:
		{
			system("cls");
			if (G->isEmpty())
			{
				cout << "El grafo esta vacio" << endl;
			}
			else
			{
				G->adjList();
			}
			cin.get();
			cin.get();
			break;
		}
		case 4:
		{
			system("cls");
			if (G->isEmpty())
			{
				cout << "El grafo esta vacio" << endl;
			}
			else
			{
				cout << "Tamano: " << G->size() << endl;
			}
			cin.get();
			cin.get();
			break;
		}
		case 5:
		{
			string nombre;
			system("cls");
			if (G->isEmpty())
			{
				cout << "El grafo esta vacio" << endl;
			}
			else
			{
				cout << "Ingrese el nombre del vertice a eliminar: ";
				cin.ignore();
				getline(cin, nombre, '\n');
				if (G->getVertex(nombre) == NULL)
				{
					cout << "Vertice invalido" << endl;
				}
				else
				{
					G->deleteVertex(G->getVertex(nombre));
				}
			}
			cin.get();
			cin.get();
			break;
		}
		case 6:
		{
			string origen, destino;
			system("cls");
			if (G->isEmpty())
			{
				cout << "El grafo esta vacio" << endl;
			}
			else
			{
				cout << "Ingrese del nombre del vertice origen: ";
				cin.ignore();
				getline(cin, origen, '\n');
				cout << "Ingrese el nombre del vertice destino: ";
				getline(cin, destino, '\n');
				if (G->getVertex(origen) == NULL || G->getVertex(destino) == NULL)
				{
					cout << "Vertices no validos" << endl;
				}
				else
				{
					G->deleteEdge(G->getVertex(origen), G->getVertex(destino));
				}
			}
			cin.get();
			cin.get();
			break;
		}
		case 7:
		{
			system("cls");
			if (G->isEmpty())
			{
				cout << "El grafo esta vacio" << endl;
			}
			else
			{
				G->Nullify();
			}
			cin.get();
			cin.get();
			break;
		}
		case 8:
		{
			string nombre;
			system("cls");
			if (G->isEmpty())
			{
				cout << "El grafo esta vacio" << endl;
			}
			else
			{
				cout << "Ingrese el nombre del vertice inicial: ";
				cin.ignore();
				getline(cin, nombre, '\n');
				if (G->getVertex(nombre) == NULL)
				{
					cout << "Ese vertice es invalido" << endl;
				}
				else
				{
					G->depthPath(G->getVertex(nombre));
				}
			}
			cin.get();
			cin.get();
			break;
		}
		case 9:
		{
			break;
		}
		default:
		{
			cout << "Elija una opcion valida" << endl;
		}
		}
	} while (opc != 9);
	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <locale.h>

using namespace std;

void main() {

	setlocale(LC_ALL, "");

	// En aquest apartat he posat totes les variables.
	vector <string> listausuarios;
	vector <string> listacontrase�a;
	string username;
	string passwordUser;
	string contrase�anuevouser, verificacioncontrase�anuevouser, nuevouser;
	string usuariocambiarcontrase�a;
	string contrase�anuevaususario;
	short respuestaadmin;
	bool funcionamientoentios = true;

	queue<string> tareaqueue;
	vector<queue<string>> tareasEntiOS;

	listausuarios.push_back("Admin");
	listacontrase�a.push_back("Admin");

	tareasEntiOS.push_back(tareaqueue);

	cout << "=======================================" << endl;
	cout << "========== MARC_SANTACANA_OS ==========" << endl;
	cout << "=======================================" << endl;
	cout << "                                       " << endl;
	cout << "Nom d'usuari: ";
	cin >> username;
	cout << "Contrasenya: ";
	cin >> passwordUser;

	while (username != listausuarios[0] && passwordUser != listacontrase�a[0])
	{
		cout << "ERROR: Inicia com a Admin";
		cout << endl;

		cout << "Nom d'usuari: ";
		cin >> username;
		cout << "Contrasenya: ";
		cin >> passwordUser;
	}

	while (funcionamientoentios == true) {
		if (username == listausuarios[0] && passwordUser == listacontrase�a[0]) {

			// Aqui lo que se ha echo es cerrar el if ya que si lo poenmos hasta el final se nos quedara para siempre ah�
			cout << "Logeado como: " << listausuarios[0] << endl;
			cout << "1- Gestionar Usuarios" << endl;
			cout << "2- Cambiar Usuarios" << endl;
			cout << "3- Gestionar directorios" << endl;
			cout << "4- Gestionar tareas" << endl;
			cout << "5- Salir" << endl;
			// Pedimos una repsuesta al usuario para que seleccione que quiere
			cout << "Respuesta:";
			cin >> respuestaadmin;
		}

		// El codi seguent el que fa es dir "respuestaadmin es igual que x numero.
		if (username != listausuarios[0])
		{
			// En aquesta part encara que l'usuari agafi el numero 1 pasar� directament al case 2 ja que suma automaticament 1 llavors
			// l'apartat que administra els usuaris nomes haura de ser visible per al usuari.
			cout << "Loguejat com: " << username << endl;
			cout << "1- Canviar Usuaris" << endl;
			cout << "2- Gestionar directoris" << endl;
			cout << "3- Gestionar tasques" << endl;
			cout << "4- Sortir" << endl;

			cout << "Resposta: ";
			cin >> respuestaadmin;
			respuestaadmin++;

		}
		switch (respuestaadmin) {
		case 1:
			short respuestacaso1;
			// Aquest codic selecciona les opcions de canvi d'usuari.
			do {
				for (int i = 0; i < listausuarios.size(); i++)
				{
					if (username == listausuarios[i])
					{
						cout << "Loguejat" << endl;
					}

				}

				// Aquest es el menu que hi ha dins de l'opci� dels usuaris.
				cout << "Loguejat com: " << listausuarios[0] << endl;
				cout << endl;
				cout << "1- Crear usuari" << endl;
				cout << "2- Modificar contrasenya" << endl;
				cout << "3- Eliminar usuari" << endl;
				cout << "4- Tornar" << endl;

				cout << "Resposta:";
				cin >> respuestacaso1;

				switch (respuestacaso1) {
				case 1:
					// Aquesta part es dedica a agafar el nom del nou usuari.
					cout << "Nou usuari:";
					cin >> nuevouser;

					cout << "Contrasenya:";
					cin >> contrase�anuevouser;

					cout << "Verificacio contrase�ya:";
					cin >> verificacioncontrase�anuevouser;

					// Aquesta part compara les contrasenyes per a poguer afegir els usuaris.
					if (contrase�anuevouser == verificacioncontrase�anuevouser) {
						listausuarios.push_back(nuevouser);
						listacontrase�a.push_back(verificacioncontrase�anuevouser);

						tareasEntiOS.push_back(tareaqueue);

						cout << "Usuari afegit correctament" << endl;
					}
					else {
						cout << "ERROR: Les contrasenyes no coincideixen." << endl;
					}
					break;

				case 2:
					// Aquest codic, case 2 modifica la contrasenya dels usuaris existents.
					cout << "Modificar contrasenya d'usuaris" << endl;

					cout << "Nom d'usuari al que es vol cambiar la contrasenya: ";
					cin >> usuariocambiarcontrase�a;
					cout << endl;

					cout << "Contrasenya nova:";
					cin >> contrase�anuevaususario;
					// Aqui demana una segona contrasenya per a verificar despres que sigui real.
					for (int i = 0; i < listausuarios.size(); i++)
					{
						if (usuariocambiarcontrase�a == listausuarios[i])
						{
							// Aquesta part t� coma funci� que es sobreescribeixi. 
							listacontrase�a[i] = contrase�anuevaususario;
						}
					}
					cout << endl;
					break;

					// Aquesta part es dedica a eliminar usuaris que nosaltres volem.
				case 3:
					string usuarioeliminar;
					char respuestaeliminarusuario;
					string usuarioexistente;

					cout << "Eliminar usuaris" << endl;

					cout << "Quin usuari vols eliminar?: ";
					cin >> usuarioeliminar; cout << endl;
					// Aquesta part avisa a l'usuari que s'eliminar� a "tal" usuari.
					cout << "Eliminar�s l'usuari:" << usuarioeliminar << " �EST�S SEGUR? (S/N)";
					cin >> respuestaeliminarusuario;
					cout << endl;

					// En aquesta part fem un if per a saber si realment es vol eliminar l'usuari seleccionat.
					if (respuestaeliminarusuario == 'S')
					{
						for (int i = 0; i < listausuarios.size(); i++)
						{
							if (usuarioeliminar == listausuarios[i])
							{
								listausuarios.erase(listausuarios.begin() + i);

								cout << "Usuari borrat correctament";

							}
							else
							{
								cout << "ERROR: No s'ha trobat l'usuari";
							}
						}
					}
					break;
				}

			} while (respuestacaso1 != 4);

			break;

		case 2: {
			bool verificaci�nwhile = true;
			while (verificaci�nwhile == true)
			{
				// Aquesta part del codic verifica si existeix l'usuari.
				cout << "Cambiar d'usuari:";
				cin >> username;

				for (int i = 0; i < listausuarios.size(); i++)
				{
					if (username == listausuarios[i])
					{
						cout << "Contrasenya:";
						cin >> passwordUser;
						verificaci�nwhile = false;
						// Aquesta part verifica el usuari i la contrasenya.
						while (passwordUser != listacontrase�a[i])
						{
							cout << "ERORR: Contrasenya incorrecta torna-ho a intentar:";
							cin >> passwordUser;
						}

					}
					// Aquesta part verifica que el while esta en funcionament tota l'estona en cas de que l'usuari no existeixi.
				}
				if (verificaci�nwhile == true)
				{
					cout << "ERROR: No existeix este user.";
				}

			}
			break;
		}
		case 3: {

			short selectorcaso3;

			do
			{
				// DIRECTORIS

				cout << "1- Veure directoris" << endl;
				cout << "2- Crear directoris" << endl;
				cout << "3- Renombrar" << endl;
				cout << "4- Eliminar" << endl;
				cout << "5- Tornar" << endl;

				cin >> selectorcaso3;
				// DIRECTORIS

				switch (selectorcaso3)
				{
				case 1:

					break;

				case 2:

					break;

				case 3:

					break;

				case 4:

					break;

				}
			} while (selectorcaso3 != 5);

			break;
		}

		case 4: {
			// En la casella 4 podem crear tasques per als usuaris.
			short selectortareas;
			do
			{
				int usuarioposici�n = 0;
				string tarea;
				for (short i = 0; i < username.size(); i++)
				{
					if (usuarioposici�n == username[i])
					{
						usuarioposici�n = i;
					}
				}

				cout << "   TASQUES" << endl;
				cout << "             " << endl;
				cout << "Loguejat com:" << username << endl;
				cout << "1- Crear tasca" << endl;
				cout << "2- Mostrar seguent tasca" << endl;
				cout << "3- Completar tasca" << endl;
				cout << "4- Tornar" << endl;
				cout << "Resposta:";
				cin >> selectortareas;

				switch (selectortareas)
				{
				case 1:
					// Aquesta part del codic ens permet crear tasques autom�ticament.
					cout << "Tasca:";
					cin >> tarea;
					cout << endl;

					tareasEntiOS[usuarioposici�n].push(tarea);
					cout << "Tasca actualitzada";
					cout << endl;

					break;

				case 2:
					// Aquesta part del codic ens permetr� mostrar les tasques que hem creat si mostrem i no hi ha res el codic peta.
					cout << "Mostrar la seguent tasca." << endl;
					cout << "Tasca:" << tareasEntiOS[usuarioposici�n].front();
					cout << endl;

					break;

				case 3:
					// Aquesta part ens permetr� borrar les tasques que hem creat.
					cout << "Eliminar tasca";
					cout << endl;
					cout << "Tasca finalitzada:" << tareasEntiOS[usuarioposici�n].front() << endl;
					tareasEntiOS[usuarioposici�n].pop();

					cout << "Finalitzat amb exit";
					cout << endl;

					break;
				}
			} while (selectortareas != 4);
			break;
		}
		case 5:
			cout << "Sortint...";

			exit(0);
		}
	}
}





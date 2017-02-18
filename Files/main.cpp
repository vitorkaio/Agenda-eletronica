#include "Adicionar.h"
#include "Altera.h"
#include "Excluir.h"
#include "Consulta.h"
#include "Funcoes.h"

int main()
{
	system("chcp 1252 > temp");

	vector<Pessoa>agenda;
	char opMenu, opSubMenu;

	//Constr�i o menu e suas op��es.
	do{

		limpaTela();

		menu();
		cin >> opMenu;
		cin.ignore();

		switch (opMenu){

		//************************* Cadastro *************************
		case '1':

			limpaTela();

			do{

				limpaTela();

				cout << "\n\t\t\t********** Cadastro **********\n\n";

				//Aprenseta as op��es do submenu.
				subMenu();
				cin >> opSubMenu;
				cin.ignore();

				//Submenu.
				switch (opSubMenu){

					//************************* Adicionando uma pessoa *************************
				case '1':

					limpaTela();

					adicionaPessoa(agenda);

					pause();

					break;

					//************************* Adicionando um telefone *************************
				case'2':

					limpaTela();

					//Se n�o houver nenhuma pessoa cadastrada, n�o adiciona.
					if (agenda.size() == 0){

						cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
						pause();
						break;
					}
						

					else
						adicionaTelefone(agenda);

					pause();

					break;

					//************************* Adicionando um email *************************
				case'3':

					limpaTela();

					//Se n�o houver nenhuma pessoa cadastrada, n�o adiciona.
					if (agenda.size() == 0){

						cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
						pause();
						break;
					}

					else
						adicionaEmail(agenda);

					pause();

					break;

					//************************* Adicionando uma tarefa *************************
				case'4':

					limpaTela();

					//Se n�o houver nenhuma pessoa cadastrada, n�o adiciona.
					if (agenda.size() == 0){

						cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
						pause();
						break;
					}

					else
						adicionaTarefa(agenda);

					pause();

					break;

				}



			} while (opSubMenu != '5');


			break;

		//************************* Consulta *************************
		case '2':

			limpaTela();

			do{

				limpaTela();

				cout << "\n\t\t\t********** Consulta **********\n\n";

				//Aprenseta as op��es do submenu.
				subMenu();
				cin >> opSubMenu;
				cin.ignore();

				//Submenu.
				switch (opSubMenu){

					//************************* Consultando uma pessoa *************************
				case '1':

					limpaTela();

					//Verificando se algu�m foi cadastrado.
					if (agenda.size() == 0){

						cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
						pause();
						break;
					}

					else
					  consultaPessoa(agenda);

					pause();

					break;

					//************************* Consultando um telefone *************************
				case'2':

					limpaTela();

					//Se n�o houver nenhuma pessoa cadastrada, n�o adiciona.
					if (agenda.size() == 0){

						cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
						pause();
						break;
					}

					else
						consultaTelefone(agenda);

					pause();

					break;

					//************************* Consultando um email *************************
				case'3':

					limpaTela();

					//Se n�o houver nenhuma pessoa cadastrada, n�o adiciona.
					if (agenda.size() == 0){

						cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
						pause();
						break;
					}

					else
						consultaEmail(agenda);

					pause();

					break;

					//************************* Consultando uma tarefa *************************
				case'4':

					limpaTela();

					//Se n�o houver nenhuma pessoa cadastrada, n�o adiciona.
					if (agenda.size() == 0){

						cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
						pause();
						break;
					}

					else
						consultaTarefa(agenda);

					pause();

					break;

				}

			} while (opSubMenu != '5');


		break;
        
		//************************* Altera��o *************************
		case '3':

			limpaTela();

			do{

				limpaTela();

				cout << "\n\t\t\t********** Altera��o **********\n\n";

				//Aprenseta as op��es do submenu.
				subMenu();
				cin >> opSubMenu;
				cin.ignore();

				//Submenu.
				switch (opSubMenu){

					//************************* Alterando uma pessoa *************************
				case '1':

					limpaTela();

					//Verificando se algu�m foi cadastrado.
					if (agenda.size() == 0){

						cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
						pause();
						break;
					}

					alteraPessoa(agenda);

					pause();

					break;

					//************************* Alterando um telefone *************************
				case'2':

					limpaTela();

					//Se n�o houver nenhuma pessoa cadastrada, n�o adiciona.
					if (agenda.size() == 0){

						cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
						pause();
						break;
					}

					else
						alteraTelefone(agenda);

					pause();

					break;

					//************************* Alterando um email *************************
				case'3':

					limpaTela();

					//Se n�o houver nenhuma pessoa cadastrada, n�o adiciona.
					if (agenda.size() == 0){

						cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
						pause();
						break;
					}

					else
						alteraEmail(agenda);

					pause();

					break;

					//************************* Alterando uma tarefa *************************
				case'4':

					limpaTela();

					//Se n�o houver nenhuma pessoa cadastrada, n�o adiciona.
					if (agenda.size() == 0){

						cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
						pause();
						break;
					}

					else
						alteraTarefa(agenda);

					pause();

					break;

				}

			} while (opSubMenu != '5');
			
			
		break;

		//************************* Exclus�o *************************
		case '4':

			limpaTela();

			do{

				limpaTela();

				cout << "\n\t\t\t********** Exclus�o **********\n\n";

				//Aprenseta as op��es do submenu.
				subMenu();
				cin >> opSubMenu;
				cin.ignore();

				//Submenu.
				switch (opSubMenu){

				//************************* Excluindo uma pessoa *************************
				case '1':

					limpaTela();

					//Verificando se algu�m foi cadastrado.
					if (agenda.size() == 0){

						cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
						pause();
						break;
					}

					else
					  excluiPessoa(agenda);

					pause();

					break;

					//************************* Excluindo um telefone *************************
				case'2':

					limpaTela();

					//Se n�o houver nenhuma pessoa cadastrada, n�o adiciona.
					if (agenda.size() == 0){

						cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
						pause();
						break;
					}

					else
						excluiTelefone(agenda);

					pause();

					break;

					//************************* Excluindo um email *************************
				case'3':

					limpaTela();

					//Se n�o houver nenhuma pessoa cadastrada, n�o adiciona.
					if (agenda.size() == 0){

						cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
						pause();
						break;
					}

					else
						excluiEmail(agenda);

					pause();;

					break;

					//************************* Excluindo uma tarefa *************************
				case'4':

					limpaTela();

					//Se n�o houver nenhuma pessoa cadastrada, n�o adiciona.
					if (agenda.size() == 0){

						cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
						pause();
						break;
					}

					else
						excluiTarefa(agenda);

					pause();

					break;

				}

			} while (opSubMenu != '5');

			break;

			//************************* Relat�rio *************************
		case '5': 

			limpaTela();
			
			//Se n�o houver nenhuma pessoa cadastrada, n�o adiciona.
			if (agenda.size() == 0){

				cout << "\n\n Tem que cadastrar uma pessoa primeiro\n\n";
				pause();
				break;
			}

			else
				exibeAgenda(agenda);

			pause();
			
		break;

		case '6':

			limpaTela();

			do{

				limpaTela();

				cout << "\n\n 1.Per�odo anivers�rio"
					<< "\n 2.Per�odo sete dias"
					<< "\n 3.Aniversariantes hoje"
					<< "\n 4.Sair"
					<< "\n Op��o: ";

				cin >> opSubMenu;
				cin.ignore();

				switch (opSubMenu){

					limpaTela();

				case '1':

					if (agenda.size() == 0){

						cout << "\n\n Agenda vazia\n";
						pause();
						break;
					}

					periodoDeAniversariantes(agenda);

					pause();

					break;

				case '2':

					if (agenda.size() == 0){

						cout << "\n\n Agenda vazia\n";
						pause();
						break;
					}

					verificaAniversarioSeteDias(agenda);

					pause();

					break;

				case '3':

					if (agenda.size() == 0){

						cout << "\n\n Agenda vazia\n";
						pause();
						break;
					}

					int test = verificaAniversariantes(agenda);

					if (test == 0)
						cout << "\n\n Sem aniversariantes hoje\n\n";

					pause();

					break;

				}
			
			
			} while (opSubMenu != '4');

			
		     

			break;

		}
	

	} while (opMenu != '7');


	return 0;
}
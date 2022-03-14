#include <stdio.h>

#define NUMESTADOS 50

typedef struct {
	char denominacion[20];
	int numeroClientes;
} tEstadoClientes;

typedef struct {
	tEstadoClientes tabla[NUMESTADOS];
	int numEstadosGuardados;
} tEstadoClientesContenedor;

void inicializar_estados(tEstadoClientesContenedor* stds) {
	stds->numEstadosGuardados = 0;
}

int menu() {
	int opcion;

	printf("**************************************************************************\n");
	printf("Teclea el numero de la opcion escogida o cualquier otro numero para salir : \n");
	printf("1. Introducir estado y numero de clientes.\n");
	printf("2. Modificar estado o clientes.\n");
	printf("3. Borrar estado y clientes.\n");
	printf("4. Listar estados.\n");
	printf("**************************************************************************\n");
	scanf("%d", &opcion);
	return opcion;
}

void introducir_estado(tEstadoClientesContenedor* stds) {
	if (stds->numEstadosGuardados < 50) {
		tEstadoClientes std;
		printf("Teclea el nombre del estado\n");
		scanf("%s", std.denominacion);
		printf("Teclea el numero de clientes\n");
		scanf("%d", &std.numeroClientes);
		stds->tabla[stds->numEstadosGuardados] = std;
		stds->numEstadosGuardados++;
	}
}

void modificar_estado(tEstadoClientesContenedor* stds) {
	int numero;
	printf("Teclea el numero del estado a modificar a partir del orden de presentacion de estos\n");
	scanf("%d", &numero);
	printf("Teclea el nuevo nombre del estado\n");
	scanf("%s", stds->tabla[numero].denominacion);
	printf("Teclea el nuevo numero de clientes\n");
	scanf("%d", &(stds->tabla[numero].numeroClientes));
}

void borrar_estado(tEstadoClientesContenedor* stds) {
	int numero;
	printf("Teclea el numero del estado a borrar a partir del orden de presentacion de estos\n");
	scanf("%d", &numero);
	if ((numero < stds->numEstadosGuardados) && (numero >= 0)) {
		while (numero < stds->numEstadosGuardados) {
			stds->tabla[numero] = stds->tabla[numero + 1];
			numero++;
		}
		stds->numEstadosGuardados--;
	}
}

void listar_estados(tEstadoClientesContenedor stds) {
	int i;
	for (i = 0; i < stds.numEstadosGuardados; i++)
	{
		printf("%s\n", stds.tabla[i].denominacion);
		printf("%d\n\n", stds.tabla[i].numeroClientes);
	}
}

int main() {
	tEstadoClientesContenedor stds;
	int o;

	inicializar_estados(&stds);

	o = menu();
	while ((o >= 1) && (o <= 4))
	{
		if (o == 1) {
			introducir_estado(&stds);
		}
		if (o == 2) {
			modificar_estado(&stds);
		}
		if (o == 3) {
			borrar_estado(&stds);
		}
		if (o == 4) {
			listar_estados(stds);
		}

		o = menu();
	}

	return 0;
}
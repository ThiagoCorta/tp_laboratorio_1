
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmpleado;

int menuAbm();
int menuModificar();

/** \brief Es un entero ESTATICO que se incrementa cada ves que se llama a la funcion.
 *
 * \return el entero anterior +1;
 *
 */
int getIdEmployee();

/** \brief A la variable isEmpty de la estructura de empleados le pone un 0(VACIO)
 *
 * \param array empleados
 * \param tamanio del array
 * \return 0 si pudo iniciarlizar a todos, -1 si hubo un error.
 *
 */
int initEmployees(eEmpleado* list, int len);

/** \brief Busca un espacio vacio entre los empleados, mira la variable isEmpty.
 *
 * \param array empleados.
 * \param tamanio del array
 * \return el indice libre.
 *
 */
int findEmptySlot(eEmpleado* list, int len);

/** \brief Agrega un empleado al array de empleados.
 *
 * \param array empleados.
 * \param tamanio del array.
 * \param nombre del empleado.
 * \param apellido del empleado.
 * \param salario del empleado.
 * \param sector del empleado.
 * \return devuelve 0 si se agrego al empleado y -1 si no pudo.
 *
 */
int addEmployee(eEmpleado* list, int len, char name[],char lastName[],float salary,int sector);

/** \brief Busca un empleado segun el ID que le pasas.
 *
 * \param array empleados.
 * \param tamanio del array.
 * \param ID que queres buscar.
 * \return el indice del empleado con ese id.
 *
 */
int findEmployeeById(eEmpleado* list, int len,int id);

/** \brief Da la baja LOGICA del empleado, pone el estado del empleado de 1 a 0.
 *
 * \param array empleados.
 * \param tamanio del array.
 * \param ID que queres dar de baja.
 * \return devuelve 1 si pudo dar la baja LOGICA.
 *
 */
int removeEmployee(eEmpleado* list, int len, int id);

/** \brief Ordena los empleados por sector y apellido alfabeticamente.
 *
 * \param array empleados
 * \param tamanio del array
 * \return nada
 *
 */
int sortEmployees(eEmpleado list[], int len);

/** \brief muestra UN empleado.
 *
 * \param se le pasa un empleado.
 * \return 0 si pudo ordenarlos, -1 si no pudo.
 *
 */
void printEmployee(eEmpleado list);

/** \brief Con la otra funcion que sabe mostrar 1 empleado, se usa esta para mostrar muchos.
 *
 * \param array empleados.
 * \param tamanio del array.
 * \return nada
 *
 */
void printEmployees(eEmpleado list[], int len);

/** \brief Te muestra empleados, te pide ingresar un ID del emp que queres modificar, te abre un menu y elegis que modificar.
 *
 * \param array empleados.
 * \param tamanio del array.
 * \return 1 si pudo modificar, 0 si no pudo.
 *
 */
int modifyEmployee(eEmpleado* list, int len);

/** \brief Carga empleados hardcodeados al array.
 *
 * \param array de empleados.
 * \param tamanio del array.
 * \return nada.
 *
 */
void hardCodearEmpleados(eEmpleado* list, int len);

/** \brief Te calcula la suma de todos los sueldos de emp activos, promedio y cuantos superan el promedio de sueldos.
 *
 * \param array empleados.
 * \param tamanio del array.
 * \param variable float para guardar el promedio.
 * \param variable float para guardar el total de sueldos
 * \param variable float para guardar la cantidad de emp que superan al sueldo promedio.
 * \return 1 si pudo cargar todas las variables, -1 si no pudo.
 *
 */
int infoSueldos(eEmpleado* list, int len,float* pFloatProm,float* pFloatTotal, int* pIntCant);

/** \brief Valida un flag que se le pase.
 *
 * \param un entero "flag".
 * \param un mensaje de error.
 * \return devuelve el estado del flago 0 o 1, 1 seria cargado.
 *
 */
int validateFlag(int* flag, char* msgError);

/** \brief Recorre el array de empleados y ve que todo este vacio.
 *
 * \param array empleados.
 * \param tamanio del array.
 * \return 0 si esta vacio -1 si hay por lo menos 1 empleado cargado.
 *
 */
int listEmpty(eEmpleado* list, int len);

/** \brief Ajusta una cadena de caracteres de forma que la primer letra sea mayuscula y el resto minuscula.
 *
 * \param una cadena de caracteres pasada por referencia.
 * \return 0 si pudo ajustarla -1 si no.
 *
 */
int ajustarNombre(char* name);

/** \brief Ajusta una cadena de caracteres de forma que todo quede en  minuscula.
 *
 * \param una cadena de caracteres pasada por referencia.
 * \return 0 si pudo ajustarla -1 si no.
 *
 */
void nombreMinuscula(char* name);


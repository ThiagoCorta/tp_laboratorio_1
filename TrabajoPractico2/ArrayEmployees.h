
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
void initEmployees(eEmpleado* list, int len);
int findEmptySlot(eEmpleado* list, int len);
int getIdEmployee(eEmpleado* list, int len);
void addEmployee(eEmpleado* list, int len, char name[],char lastName[],float salary,int sector);
int findEmployeeById(eEmpleado* list, int len,int id);
int removeEmployee(eEmpleado* list, int len, int id);
void sortEmployees(eEmpleado list[], int len);
void printEmployee(eEmpleado list);
void printEmployees(eEmpleado list[], int len);
int menuModificar();
void modifyEmployee(eEmpleado* list, int len);
void hardCodearEmpleados(eEmpleado vec[], int tam);
int infoSueldos(eEmpleado* list, int len,float* pFloatProm,float* pFloatTotal, int* pIntCant);
int validateFlag(int* flag, char* msgError);
int listEmpty(eEmpleado* list, int len);


# Proyecto de simulador de cajero automatico en C  :atm:  :money_with_wings:


## Requisitos de instalacion
- Tener git y un compilador

## Guia de instalación
1. Crear directorio
2. Abrir git e ir al directorio
3. Ejecutar git clone https://github.com/Diego-BA-code/cajero.git

## Guia de usuario
# Explicación/descripción 
Tenenemos una struct de clientes en la cual se almacenaran los siguientesdatos:
- n_cuenta:Este es un dato de tipo entedero.
- nombre: Es un tipo de dato de carácter el cual tiene 40 caracteres para almacenar el nombre del usuario.
- apellido:Es un tipo de dato de carácter el cual tiene 40 caracteres para almacenar el apellido del usuario.
- nip:Es un tipo de dato entero en el cual se almacena el nip del usuario.
- saldo: Es un tipo de dato flotante, se almacena la cantidad de dinero que tiene enl usuario en su cuenta.
- bloqueada: Es un tipo de dato entero, se almacena los datos y si en el bloqueo es un -2, se bloquea la cuenta.
- intentos: Es un tipo de datos entero, se almacena los intentos que usuario hace para acceder a su cuenta, con base a este dato y al dato bloqueo se valida el nip.
- movimientos: Esun tipo de dato entero, tiene un capacidad de 10 movimientos. Con esta se veran reflejados los movimientos realizados.
  
## Descripción
### Funciones
#### guardar_clientes
- Tipo
  - void
- Parametros
  struct cliente *clientes, int n_usuarios
  -  int n_usuarios: numero de usuarios actuales
  -  struct cliente *clientes: Puntero a la estructura de clientes 
- Salida
  - No devuelve nada, solo genera el archivo de texto con los datos de las personas
 
 #### login
- Tipo
  - int
- Parametros
  struct cliente *clientes, int nip, int n_cuenta
  -  struct cliente *clientes: Puntero a la estructura de clientes 
  -  int n_cuenta: Numero que ingreso el usuario
  -  int nip: Nip que ingreso el usuario
- Salida
  - Devuelve un codigo de estado al intentar ingresar
    - 1 Login exitoso
    - -1 Pin incorrecto
    - -2 Cuenta bloqueada
    - 0 Cuenta no encontrada

 #### login
- Tipo
  - int
- Parametros
  struct cliente *clientes, int nip, int n_cuenta
  -  struct cliente *clientes: Puntero a la estructura de clientes 
  -  int n_cuenta: Numero que ingreso el usuario
  -  int nip: Nip que ingreso el usuario
- Salida
  - Devuelve un codigo de estado al intentar ingresar
    - 1 Login exitoso
    - -1 Pin incorrecto
    - -2 Cuenta bloqueada
    - 0 Cuenta no encontrada

#### menu_cliente
- Tipo
  - void
- Parametros
  struct cliente *clientes, int indice_cuenta
  -  struct cliente *clientes: Puntero a la estructura de clientes 
  -  int indice_cuenta: El indice del arreglo en el que se encontro el numero de cuenta del cliente
- Salida
  - No devuelve nada, solo muestra el menu de clientes

#### buscar_nombre
- Tipo
  - void
- Parametros
  struct cliente *clientes, char nombre[40]
  -  struct cliente *clientes: Puntero a la estructura de clientes 
  -  char nombre: El nombre de la persona a buscar ingresado por el usuario
- Salida
  - No devuelve nada, solo muestra el menu de clientes
 
#### buscar_indice_cuenta
- Tipo
  - int
- Parametros
  struct cliente *clientes, int n_cuenta
  -  struct cliente *clientes: Puntero a la estructura de clientes 
  -  int n_cuenta: El numero de cuenta a buscar para obtener el indice
- Salida
  - Devuelve el indice en el que esta ubicado el cliente en el arreglo de estructura de clientes y si no lo encuentra, devuelve -1;
  
#### validar
- Tipo
  - int
- Parametros
  float x
  -  float x: El numero que se va a validar
- Salida
  - Devuelve 1 si la cantidad es valida y 0 si no es valida
 
#### consultar_saldo
- Tipo
  - void
- Parametros
  struct cliente *clientes, int i
  -  struct cliente *clientes: Puntero a la estructura de clientes
  -  int i: indice del arreglo de estructuras en el que se buscara 
- Salida
  - No devuelve nada, solo consulta el saldo del usuario
 
#### realizar_deposito
- Tipo
  - void
- Parametros
  struct cliente *clientes, int i_remitente, int n_cuenta_destino
  -  struct cliente *clientes: Puntero a la estructura de clientes
  -  int i_remitente: indice del arreglo de estructuras del cliente que hace el deposito
  -  int n_cuenta_destino: numero de cuenta al que se va a realizar el deposito
-  Salida
  - No devuelve nada, solo modifica el saldo del remitente y de la cuenta a la que deposita, tambien guarda el movimiento tanto en el struct del remitente y del que recibe

#### realizar_retiro
- Tipo
  - void
- Parametros
  struct cliente *clientes, int indice
  -  struct cliente *clientes: Puntero a la estructura de clientes
  -  int indice: Indice del arreglo de estructuras de la cuenta de la cual se retirara el dinero
-  Salida
  - No devuelve nada, solo modifica el saldo de la persona que realiza el retiro y guarda su movimiento

 
#### agregar_usuario
- Tipo
  - void
- Parametros
  struct cliente *clientes, int *n
  -  struct cliente *clientes: Puntero a la estructura de clientes
  -  int *n: Puntero que recibe la direccion de memoria de una variable que almacena el numero actual de usuarios
-  Salida
  - No devuelve nada, solo aumenta el numero de clientes

#### imprimir_usuarios
- Tipo
  - void
- Parametros
  struct cliente *clientes
  -  struct cliente *clientes: Puntero a la estructura de clientes
-  Salida
  - No devuelve nada, solo imprime todos los datos de todos los clientes registrados

  



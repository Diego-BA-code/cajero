# Proyecto de simulador de cajero automatico en C  :atm:  :money_with_wings:


## Requisitos de instalacion
- Tener git y un compilador

## Guia de instalación
1. Crear directorio

![image](https://github.com/user-attachments/assets/04e8f425-8765-475f-8fb4-079ad72424de)

3. Abrir git e ir al directorio

![image](https://github.com/user-attachments/assets/ed6fbb92-b708-4ba7-bfc4-0408f10d0eb7)

5. Ejecutar git clone https://github.com/Diego-BA-code/cajero.git

![image](https://github.com/user-attachments/assets/f10e74cd-0c03-40e1-b847-8df5cbe87898)


## Guia de usuario
## Al abrir el programa se desplegará un menú de 6 opciones son las siguientes:

## Opción 1 "Iniciar Sesion" 
Si presiona el número 1, se abrira la opción número 1, lo primero que le solicitara es ingresar su numero de cuenta, una vez ingresado el numero de cuenta te pedira ingresar el NIP, debes ingresar el nip de cuenta ya que si te equivocas 3 veces se bloqueara tu cuenta y te regresa al menú principal, si ingresas el nip correcto, se te deplegara el menú cliente, en el menu de cliente tendras 4 opciones, que son las siguietes:

### 1. Consultar saldo: 
Al presional el 1 se abrira la opcion de consultar saldo, dentro de esta opcion te dara a escoger otras 2 opciones, la primera sera ver tu saldo actual, esta se abrira cuando presiones el numero 1 y unicamente te indicara el saldo de tu cuenta; la segunda sera ver el historial de movimientos, esta opción se abrira al presionar el número 2 y al hacerlo te dara los ultimos movimientos guardados en tu cuenta (tanto retiros como depositos).

### 2. Realizar deposito: 
Al presionar el 2 se abrira la opcion de realizar deposito, dentro de esta opcion te pedira ingresar el numero de cuenta al que deseas hacer el deposito, luego te pedira que ingreses la cantidad que quieres depositar, una vez des enter, te dira que tu deposito se realizo con exito.

### 3. Realizar Retiro: 
Al presionar el número 3 se abrira la opcion de realizar retiro, dentro de esta opcion te pedira que ingreses la cantidad que deseas retirar, ojo tiene que ser una cantidad menor o igual a la que tines en la cuenta elegida, ya que si ingresas una cantidad mayor, te dira que no tienes suficiente saldo y te regresara al menu principal, en caso de que ingreses una cantidad correcta te pedira que confirmes si quieres realizar el retiro, si presionas 1 se realizara el retiro, si presionas 2 se canmcelara y te indicara que tu saldo sigue siendo el mismo, ademas de regresarte al menu principal, tambien la cantidad que ingreses debe ser positiva en caso de que ingreses una cantidad negativa te pedira que ingreses una cantidad nueva y positiva.

### 4. Salir: 
Al presionar el numero 4 se elegira la opcion de salir, al hacerlo saldras de tu cuentta y regresaras al menú principal del programa.

## Opción 2: "Busqueda" 
Si presiona el numero 2, se abrira dicha opcion, esta funcion de esta opcion es darte el numero de cuenta de una persona al ingresar su nombre, bsicamente dentro de esta opcion te solicitara que ingreses el nombre del cliente del que deseas obtener el numero de cuenta, al ingresar el nombre, te regresara el numero de cuenta que tiene el cliente.

## Opción 3: "Deposito"
La funcion de esta opcion es realizar un deposito a alguna cuenta, al  presionar el numero 3, se abrira dicha opcion, dentro de ella te solicitara el numero de cuenta al que deseas realizar el deposito, una vez ingresado el numero de cuenta, te pedira que ingreses la cantidad de dinero que quieres depositar, una vez ingresada la cantidad te dira que el deposito se realizo con exito.

## Opción 4: "Crear cuenta" 
La funcion de la opcion crear cuenta basicamente te permite crear una cuenta desde 0, en caso de que e cliente no cuente con una, al presionar el numero 4 se abriran esta opcion, dentro de esta te pedira que ingreses el numero de cliente con el que deseas identificarte, una vez ingresado el numero, lo siguiente que te pedira es ingresar tu nombre (ojo solo tu nombre), ya ingresado el nombre lo siguiente que te pedira sera ingresar tu apellido, Ya con esos tres datos ingresados te solicitara un NIP que sera la contraseña de tu cuenta, despues de ingresar tu nip te pedira el saldo inicial de tu cuenta, ya con esto te dira que tu usuario a sido añadido con exito y con esto ya podras acceder a tu cuenta.

## Opción 5: "Salir" 
Si presionas el numero 5 elegiras la opcion salir, con esto se cerrara por completo el programa, viendo un bonito mensaje de despedida.

## Opción 6: "Guardar" 
Si presionas el numero 6, elegiras la opcion guardar, con esto almacenara los datos de los clientes y los ultimos movimientos realizados, se guardaran en un archivo de texto.
# Explicación/descripción 
Tenenemos una struct de clientes en la cual se almacenaran los siguientesdatos:
- n_cuenta:Este es un dato de tipo entero,se almacena la cuenta del usuario.
- nombre: Es un tipo de dato de carácter el cual tiene 40 caracteres para almacenar el nombre del usuario.
- apellido:Es un tipo de dato de carácter el cual tiene 40 caracteres para almacenar el apellido del usuario.
- nip:Es un tipo de dato entero en el cual se almacena el nip del usuario.
- saldo: Es un tipo de dato flotante, se almacena la cantidad de dinero que tiene enl usuario en su cuenta.
- bloqueada: Es un tipo de dato entero, se almacena los datos y si en el bloqueo es un -2, se bloquea la cuenta.
- intentos: Es un tipo de datos entero, se almacena los intentos que usuario hace para acceder a su cuenta, con base a este dato y al dato bloqueo se valida el nip.
- movimientos: Es un tipo de dato entero, tiene un capacidad de 10 movimientos. Con esta se veran reflejados los movimientos realizados.
  
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

  



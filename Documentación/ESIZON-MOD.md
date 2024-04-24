---
bibliography: ../Referencias.bib
biblio-style: "apalike"
link-citations: true

title: 'Metodología de la Programación'
author: 
- Pablo Torres Diez  (<pablo.torresdiez@alum.uca.es>)

---
# <span style='color:blue'> **ESIZON** </span> 

***

[comment]:<> "Los tres asteriscos añaden una línea horizontal"

## Índice 
- [ **ESIZON** ](#-esizon-)
  - [Índice](#índice)
  - [Introducción](#introducción)
- [Documentación de usuario](#documentación-de-usuario)
  - [Descripción funcional](#descripción-funcional)
  - [Tecnología](#tecnología)
  - [Manual de instalación](#manual-de-instalación)
  - [Acceso al sistema](#acceso-al-sistema)
  - [Manual de referencia](#manual-de-referencia)
  - [Guía del operador](#guía-del-operador)
- [Documentación del sistema](#documentación-del-sistema)
  - [Especificación del sistema](#especificación-del-sistema)
  - [Módulos](#módulos)
  - [Plan de prueba](#plan-de-prueba)
    - [Prueba de los módulos](#prueba-de-los-módulos)
    - [Prueba de integración](#prueba-de-integración)
    - [Plan de pruebas de aceptación](#plan-de-pruebas-de-aceptación)
- [Documentación del código fuente](#documentación-del-código-fuente)
    - [Cabeceras Módulo Menu:](#cabeceras-módulo-menu)
    - [Cabeceras Módulo Cliente:](#cabeceras-módulo-cliente)
    - [Cabeceras Módulo Proveedores:](#cabeceras-módulo-proveedores)
    - [Cabeceras Módulo DescuentosClientes:](#cabeceras-módulo-descuentosclientes)
- [Referencias {-}](#referencias--)

***



<div id='introducción' />

## Introducción

Este programa es la implementación de una versión simplificada de un portal de compras online, donde tenemos a diferentes perfiles:
El usuario comun como cliente, que realizara compras, seguimiento de pedidos y devoluciones.
Los vendedores donde tenemos al proveedor principal, los cualeson los propietarios de la aplicacion, ESIZON, y los secundraios, que  pueden ser diferentes proveedores.

* Las principales caracteristicas del programa por parte de los proveedores (ESIZON y otros) es la gestion, venta y envios de productos, con funciones segundarios como la creación de vales y descuentos, y por parte de la logistica, el envio a direccion del cliente o lockers, y la gestion del trasnportista

* Las principales caracteristicas del programa por parte de los clientes es la vista del catalogo y compra de productos, teniendo la opcion de seguimientos de envios a domicilio o lockers, y la devolución de los mismos, con la posibilidad de aplicar descuentos o vales y usando su cartera como metodo de pago.

En la documentación de este programa se distingue dos partes:

* Documentación interna: Documentación contenida en las lineas de comentarios del programa, que se podra ver en el codigo.

* Documentación externa: Documentación que recoge los diferentes manuales para el usuario y su instalaciñon, analisis, diagramas y prubas del sistema de su correcto funcionamiento. Se diferencia dos partes: Documentacion del usuario y documentacion del sistema.





<div id='usuario' />

# Documentación de usuario
A continuación se explicara todo lo relacionado con la funciones del sistema para el usuario, asi como todos sus manuales. 


<div id='funcional' />

## Descripción funcional

Este programa esta escrito en lenguaje C, contine 13 modulos, en cada uno de ellos tiene su respectiva funciones y estructura que interactuán entre si para llevar a cabo un sistema de venta de productos.

La funcion principal, llamada menu(), es la que lleva a cabo el inicio del programa, carga y guarda la información y alverga el menu principal de programa, donde podra iniciar sesion, clientes o proveedores, y el registro de nuevos clientes. En funcion de lo opción elegida y del usuario que inicie sesión le llevara a diferentes menu, respetivas llamadas a función.

La función MenuClientes() es el menu para los clientes donde podran 

La función MenuProveedores()

La función MenuAdmin() es el menu de los administradores, o mejor dicho, el principal proveedor/propietraio de la aplicación ESIZON, los cuales tendran acceso a toda la información de la aplicación, que podrangestionar y tienen la posibilidad dar de alta nuevos proveedores y gestionarlos.


<div id='tecnología' />

## Tecnología

Para el desarrollo del programa se han usado dos diferentes entornos de desarrollo:

* [Code::Blocks](https://www.codeblocks.org/): Version 20.3
* [Visual Studio Code](https://code.visualstudio.com/)): Version 1.80.0
* [Markdown](https://www.markdownguide.org/): Via Visual Studio Code
* [Trello](https://trello.com/invite/b/zDIorH4J/ATTI2f2f140eafb616ff6908029566238102D6126EEC/esizon): Gestión de trabajo para el desarrollo del programa
* [Github Desktop](https://github.com/Pablote303/ESIZON): Actualizaciones del desarrollo y repositorio
  
//
También se pueden añadir los iconos representativos de las herramientas, para ello incluir la imagen como se ha descrito más arriba.  

Si se necesita hacer referencia a algunos documentos se incluyen las citas que sean necesarias [@Ejemplo1][@Ejemplo2][@Ejemplo3].
//

<div id='instalación' />

## Manual de instalación

Los requisito del programa son:
* Si se ejecuta por el executable (.exe) como minimo el S.O: Windows XP (Service Pack 2)
* Si es necesario copilar para otros sistema operativos sera necesario la instalación de GNU Compiler para el sistema operativo deseado.

Para la instalación del programa nos bastara por ejecutarlo por primera vez (ESIZON.exe) y el propio programa inicializara el sistema, generando los ficheros necesarios. Para otros sistemas operativos, una vez copilado y ejecutado procedera al mismo procedimiento.

La primera vez que se ejecute el programa nos pederila la creación de un usuario root, la cual nos solicitara una nueva contraseña y creara este usuario administrador, mostrara por pantalla los datos necesarios para iniciar sesion con dicho usuario.
Se recomienda la creación de un usario cliente y otro usuario proveedor par el correcto funcionamiento del programa.

<div id='acceso' />

## Acceso al sistema

Para acceder al sistema podremos elegir dos opciones que nos mostrara en el primer menu nada mas ejecutar el sistema una vez inicializado, la primera es Iniciar Sesion donde con los datos, email y contraseña, la cual nos llevara al menu correspondiente, cliente, proveedor o administrador; la segunda opcion es Registrarse, esta opcion sera valida solo para el usuario cliente ya que solo podremos crear tal usuario, los demas solo podra dar de alta un administrador, despues de completar el formulario podremos iniciar sesion como en la primer a opción.


<div id='referencia' />

## Manual de referencia

Una vez iniciada la sesion tendremos 3 posibles perfiles segun nuestros datos: Cliente, Proveedor o Administrador (Operador). Tendremos 3 menús diferentes:

**Los Clientes** tendran acceso en su menú a 6 diferentes opciones:
* En la opción de *Perfil* podremos gestionar nuestra información, tanto visualizarla como modificarla.
* En la opción de *Productos* tendremos acceso al catalogo de productos que se ofertan.
* En la opción de *Descuentos* mostrara el listado de descuentos y vales obtenidos.
* En la opcion de *Pedidos* es la función principal del sistema ya que podremos realizar las compras en la aplicación y gestionaremos nuestros pedidos, como envios pendientes. Podra aplicar descuentos y/o cheques. Podra realizar pedidos a domicilio o usar la funcion de locker del sistema.
* En la opcion de *Devolución* podremos gestionar devoluciones de productos de pedidos ya realizados.
* Por ultimo podremos cerrar sesión y volver al menu principal.


**Los Proveedores** tendran acceso en su menú a 4 diferentes opciones:
* En la opción de *Perfil*, al igual que los clientes, podran visualizar y modificar sus datos.
* En la opción de *Productos* accedera a la información de sus productos que estén dados de alta en la plataforma, donde podrá realizar altas, bajas, búsquedas, listados y modificaciones de productos.
* En la opción de *Pedidos* accedera únicamente a la información de los pedidos de productos que él mismo suministra, donde podrá gestionar el estado de dichos pedidos de productos, asignar transportistas, lockers, etc.
* Por ultimo podremos cerrar sesión y volver al menu principal.

**Los Administradores** tendran acceso en su menu a 10 diferentes opciones:
* En la opcion de *Perfil* visualizara su información y podra modificar su contraseña.
* En la opción de *Clientes* podra acceder a los datos de los clientes y podra gestionar altas, bajas, busquedas, listados y modificación de datos.
* En la opción de *Proveedores* al igual que en la opción de *Clientes* podra gestionar la información de los proveedores del sistema, ademas con la opción exclusiva de poder dar de alta a nuevos proveedores.
* En la opción de *Productos* accedera a la información de los productos dados de alta en la plataforma y mediante su menú correspondiente podrá realizar altas, bajas, búsquedas, listados y modificaciones de productos.
* En la opción de *Categorias* accedera a la información de las categorías dadas de alta en la plataforma y mediante el menú correspondiente podrá realizar altas, bajas, búsquedas, listados y modificaciones de categorías, tambien podrá generar listados de productos por categoría.
* En la opción de *Pedidos* accedera a la información de los pedidos dados de alta en la plataforma, mediante el menú correspondiente podrá realizar altas, bajas, búsquedas, listados y modificaciones de pedidos. En los listados habrá que contemplar la posibilidad de listarlos según su estado. Esto es necesario para poder localizar rápidamente los pedidos cuya fecha de entrega sea próxima
y que, por tanto, deben ser procesados con mayor prioridad. Otras opciones permitidas será la asignación de transportistas a los productos pedidos en función de la dirección del cliente y ciudad de reparto. Así como llevar a cabo la asignación de lockers a los pedidos en base a la localidad de entrega y ubicación del locker.
* En la opción de *Transportistas* accedera a la información de todos los transportistas dados de alta en la plataforma y mediante el menú correspondiente podrá realizar altas, bajas, búsquedas, listados y modificaciones de transportistas.
* En la opción de *Descuentos* accedera a la información de todos los códigos promocionales y/o cheques regalo dados de alta en la plataforma. Mediante el menú correspondiente podrá realizar altas, bajas, búsquedas, listados y modificaciones de estos descuentos Además también podrá generar los listados de clientes que tienen asignado algún cheque regalo/código promocional, así como los listados de clientes que han hecho uso de algún cheque regalo/código promocional. Podrá asignar a un cliente determinado un cheque regalo. Podra crear descuentos o cheques aplicables a todos los usuarios.
* En la opción de *Devoluciones* gestionara las devoluciones de pedidos realizados por los clientes, donde podra listar, gestionar y dar de alta nuevas solicitudes.
* Por ultimo podremos cerrar sesión y volver al menu principal.


<div id='operador' />

## Guía del operador

* El administrador ser el primer usuario que inicie la aplicación y cree el usuario root.
* Gestionara la información total del sistema.
* Es el responsable de gestionar las altas de nuevos proveedores, ya que es unico usuario con esta opción.
* Es el responsable de gestionar los transportes y lockers, realizara la gestión de envios, dara de alta a los trasnportistas y la gestión de Lockers.


<div id='sistema' />

# Documentación del sistema
A continuación se explicará el funcionamiento de los módulos, su análisis y diseño y prueba del software. 


<div id='requisitos' />

## Especificación del sistema

Se nos plantea realizar la implementación de un sistema simplificado de una aplicación para comprar productos del proveedor ESIZON y otros proveedores adheridos.
Tenemos tres tipos de usuarios, Cliente, el usuario normal, que podrá utilizar la aplicación para hacer uso de ella, Administrador, ESIZON, que sera la encargada principal de la aplicación de su correcto funcionamiento de la gestión de productos de ESIZON, y administrara todos los datos de la aplicación. Los Proveedores, parecidos a los administradores pero limitado, gestionara solo la información relacionada con sus productos.

Restricciones del programa:

* La aplicación también almacenará los datos de los clientes, proveedores, productos, categorías, descuentos, descuentos de clientes, lockers, compartimentos de lockers, pedidos, productos pedidos, transportistas y devoluciones.
* Solo puede haber dtres tipos de perfiles: cliente, administrador y proveedores.

A continuación se representará gráficamente la estructura de los módulos del programa.


///Imagen organigrama.


<div id='módulos' />

## Módulos

* Módulo **Menu** contiene los menus de los diferentes usarios y las llamadas a funciones necesario para que el programa funcione.
* Módulo **Clientes** gestiona la indormación de los clientes del sistema, donde se podran dar de alta, baja, modificar, listar y buscar datos.
* Módulo **Proveedores** gestiona la indormación de los proveedores o administradores del sistema, donde se podran dar de alta, baja, modificar, listar y buscar datos. Tambien alberga las funciones administrativas del sistema
* Módulo **Productos** *modulo sin desarrollo...*
* Módulo **Categorías** *modulo sin desarrollo...*
* Módulo **Descuentos** *modulo sin desarrollo...*
* Módulo **DescuentosClientes** Aplica los distintos descuentos y/o cheques del sistema a cada cliente compatible, y su estado y valides, gestiona toda información de los descuentos de cada cliente.
* Módulo **Lockers** *modulo sin desarrollo...*
* Módulo **CompartimentosLockers** *modulo sin desarrollo...*
* Módulo **Pedidos** *modulo sin desarrollo...*
* Módulo **ProductosPedidos** *modulo sin desarrollo...*
* Módulo **Transportistas** *modulo sin desarrollo...*
* Módulo **Devoluciones** *modulo sin desarrollo...*

* *Módulo **Demo** estemodulo sustituye los modulos faltantes por si es necesario de su funcionamiento para los renstantes*. 


<div id='pruebas' />

## Plan de prueba


Las pruenas realizadas corresponderan solo a los modulos de Menu, Clientes, Proveedores y DescuentosClientes, excluyendo el *módulo demo* ya que no estaba previsto al inicio del desarrolo de la aplicación.

### Prueba de los módulos
Incluir toda la batería de pruebas realizadas. Pruebas de caja blanca y pruebas de caja negra.  

### Prueba de integración
Incluir toda la batería de pruebas realizadas. Pruebas de caja blanca y pruebas de caja negra.  

### Plan de pruebas de aceptación
Estas pruebas deben diseñarse con el usuario del sistema. Deben describir las pruebas que son necesarias pasar para que el sistema sea aceptado por el usuario final.  



<div id='sistema' />

# Documentación del código fuente

### Cabeceras Módulo Menu:

### Cabeceras Módulo Cliente:

### Cabeceras Módulo Proveedores:

### Cabeceras Módulo DescuentosClientes:

<div id='referencias' />

# Referencias {-}

---
nocite: |
  @*
...

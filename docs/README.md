# Informe Técnico
## Curso: Estructura de datos
## Detección y reidentificación de caras en secuencias de imágenes o video
### Alumnos:
Joshir Contreras 
## Resumen

El taller al que damos inicio nos encomendamos en generar un sistema de vigilancia en base al reconocimiento de personas. Para esta entrega se pide un programa con la ayuda de la biblioteca OpenCV en donde debemos detectar las personas que se presenten en un conjunto de imagenes, video o algun tipo de camara, marcando a estas personas en rectangulos de color rojo y tambien identificando el centro de esta figura con el objetivo de que un guardia pueda acceder a los datos recopilados por nuestro programa. Para lograr la realizacion de este taller, se instalo la IDE Visual Studio Code junto con OpenCV y CMake, usando las librerias de dichos programas para poder reconocer a las personas. Luego de investigar, se logra implementar de buena forma y con imagenes de referencias realizamos las pruebas obteniendo exito.

## 1. Introduccion

La tecnologia avanza cada vez mas rapido, asi se ve reflejada en la deteccion automatica de personas y de otro tipo de figuras a partir de una camara, imagen o video, esta necesidad cada vez esta mas presente en la vida cotidiana por lo cual es importante saber manipular y comprender el uso de estas nuevas tecnologias debido a que nos genera una ventaja y gran conocimiento a la hora de llevarla a la practica. Es por esto que con este proyecto genera la necesidad de aprender mas sobre el tema y asi poder crear habilidades y conocimientos nuevos, que hasta ahora son poco conocidos.

Este taller lleva la idea de usar programas y sus librerias, las cuales son las principales herramientas en la deteccion de personas, lo cual servira para lograr los objetivos de este mismo, poder determinar las personas que salen o entran, obtenidas de un video, camara o imagenes.
Para completar esta tarea es importante la forma de buscar la informacion, por lo cual es importante buscar en foros o videos la implementacion de dichas herramientas para desarrollar y entender nuestro problema.

### 1.1 Descripcion del problema

Existe el desafio de crear un programa que reconozca personas en imagenes, videos o camara con el fin de identificarlos en rectangulos para que el guardia pueda saber la cantidad de personas que entran o salen de un determinado lugar.

### 1.2 Objetivos

**Objetivo General:**

Construir un programa que detecte a las personas encapsulandolas en un rectangulo.

**Objetivos Especificos:**

1. Creacion del repositoria Github
2. Instalacion IDE Visual Studio Code , OpenCV y CMake
3. Investigar como reconocer a las personas con las librerias de dichos programas
4. Codigo de identificacion 

Los objetivos específicos son acciones específicas que son desarrolladas para lograr cumplir el objetivo general, por ejemplo:

1. La creacion del repositorio sirve para mantener ver el avance del proyecto.
2. Descargar e instalar los programas.
3. Investigar las herramientas que tenemos para poder reconocer a las personas.
4. Aplicar lo aprendido construyendo un codigo que nos permita resolver las problematicas planteadas.

### 1.3 Solucion Propuesta

Generar un codigo que permita reconocer a las personas, que tiene implemenatado el cumplimiento del objetivo y ademas generar las imagenes con los rectangulos para que asi la personas pueda comprobar que el algoritmo funciona de forma correcta.

## 2. Materiales y metodos
- IDE Visual Studio Code 
- Biblioteca OpenCV
- CMake
- Imagen de personas

Configurando la IDE con OpenCV se podra implementar de buena manera las librerias de esta y ademas con la orientacion de objetos podremos manipulas de manera correcta el uso de los archivos y el analisis de las imagenes.

### 2.1 Instalacion
- IDE Visual Studio Code: Es una IDE en donde se desarrollara el codigo del taller y se realizaran las pruebas necesarias para completar los requerimientos
- Biblioteca OpenCv: Libreria libre de vision artifical que cuenta con las herramientas y librerias necesarias para la deteccion de personas, ademas de ser compatible con la IDE.
- CMake: Herramientas que servira para la automatizacion y generacion de codigo.

### 2.2 Diseño

- Clase Detector: Sirve para detectar las personas dentro la imagen y generar el cuadrado que encapsula a dicho elemento.
- Clase Persona: Guarda los datos de los puntos elementales a la figura generada en la clase Detector, ademas calcula el centro dela figura.
- Clase NodoPersona: Sirve para guardar a las personas y asi póder agregarlas a una linkedList.
- Clase ListaPersonas: Guarda los elementos de NodoPersona y realiza la implementacion de diferenciar las personas.

### 2.3 Implementacion

- Detector de Personas

El codigo carga la imagen y ajusta los parametros para generar los rectangulos dependiendo de la cantidad de personas que se procesen en la imagen, moviendo los parametros se puede encontrar una mejor o peor optimizacion en la busqueda de personas. El codigo se presenta a continuacion: 
```c++
if (m == Default)
        hog.detectMultiScale(img, found, 0, Size(2,2), Size(3,3), 1.02, 2, false);
else if(m == Dainler)
        hog_d.detectMultiScale(img, found, 0, Size(4,4), Size(8,8), 1.01, 3, true);
```
En estas lineas de codigo se aprecia la imagen de entrada y los parametros de deteccion.

- Creacion de rectangulos

Dentro de este codigo nos encontramos con las personas con los atributos que poseen, los cuales son las direcciones de los 4 puntos de dicha representacion imaginaria que genera el detector de personas. Se ve reflejado con las siguientes lineas de codigo: 

```c++
 rectangle(imagen, cv::Point(p.getXInicio(), p.getYInicio()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0,0,255), 2);
 circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 2);
 //circle(imagen, cv::Point(p.getXInicio(), p.getYInicio()), 3, cv::Scalar(255, 0, 0), 2);
 //circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
```
En dichas lineas nos encontramos la conformacion del rectangulo, asi como sus caracteristicas, ademas de agregar el centro de dicha figura con las caracterizticas necesarias para la implementacion.

- Creacion Linea de separacion

Nos encontramos con una linea imaginaria que sirve para poder identificar cuantas personas salen o entran dentro de la imagen, video o camara de video, se implemento con el siguiente codigo: 

```c++
Point p1(175,0), p2(175, 300);
int thickness = 1;
line(imagen, p1, p2, Scalar(255, 255, 0), thickness, LINE_8);
```
Con esta funcion podemos identificar en cada imagen cuantas personas se encuentran en el lado izquierdo (Salida) y derecho (Entrada), asi podemos calcular los requerimientos necesarios.

- Entrada y Salida

Dentro de este punto, segun la linea marcada en el punto anterior, podemos indentificar si la persona se encutra en al entrada y salida, mediante un contador vamos realizando el calculo total de dicha problematica. En el siguiente codigo se puede ver la implementacion:

```c++
int contSalida=0;
int contEntrada=0;
...
...
if( p.getXCentro() < p1.x){
    contSalida++;
}else{
    contEntrada++;
}
```

Su principal funcion es calcular mediante el centro de la persona, si este centro es menor a la distancia a la que se encuentra la linea, suma al contador de salida, de ser mayor, suma al contador de entrada, todo esto tomando el eje X de ambos objetos.

- Velocidad Persona por Hora

Dentro de este parametro se utiliza la libreria de C++ e implementamos ctime, para poder calcular la hora de inicio del programa y el final. Se presenta en el siguiente codigo:

```c++
time_t TiempoInicio = time(0);
tm *ltm = localtime(&TiempoInicio);
int HoraInicio = ltm->tm_hour;
int MinutoInicio = ltm->tm_min;
...
...
...
//Termino del programa
time_t TiempoFinal = time(0);
tm *ltme = localtime(&TiempoFinal);
int HoraFinal = ltme->tm_hour;
int MinutoFinal = ltme->tm_min;

double MinutosTranscurridos = (double)(HoraFinal-HoraInicio) + (double)(MinutoFinal - MinutoInicio)/60;
double EntradaHora = ((double)contEntrada / MinutosTranscurridos);
double SalidaHora = ((double)contSalida / MinutosTranscurridos);
```
Aqui calculamos la hora inicial a la que se ejecuta el programa y luego la de termino, se restan las horas y los minutos para luego dividir con respecto a la cantidad de personas que salieron y la cantidad de personas que entraron.

- Diferenciacion 

Dentro de esta seccion no se pudo completar, la logica para realizar esto era en una primera instancia, crear la listaPersonas, verificar si esta lista estaba vacia, de ser asi se agregarian las personas encontradas en la primera imagen. Posterior a esto, se volveria a preguntar a si la lista estaba vacia, en este momento no lo estaria, por eso se compararia cada dato actual con los datos de la lista para buscar la menor distancia, la complicacion fue el tema de la LinkedList y la distancia maxima de separacion, asi para saber si la persona mas cercana corresponde de verdad a esa, y no lo asociamos solo por el menor.
De igual forma en el main.cpp se ve el avance de esta problematica, la cual esta de forma comentada para no ocacionar inconvenientes con la otra parte del codigo.

## 3. Resultados Obtenidos

Una vez cargado el codigo nos arroja las imagenes presentadas como ejemplo,encapsuladas en los rectangulos rojos y tambien el caluclo de la cantidad de personas que entran y salen en el total de imagenes.

![imagen](https://github.com/JoshirCS/ED22-01-Contreras/blob/main/docs/imagenes/referencias/e2.jpg) ![consola](https://github.com/JoshirCS/ED22-01-Contreras/blob/main/docs/imagenes/referencias/consola.jpg)

## 4. Conclusiones

Analizando lo realizado, se da cuenta de que no todos los objetivos se completaron de la mejor manera posible, teniendo muchas mejoras en la realizacion y organizacion de este proyecto. Lo positivo es la buena interaccion con la IDE y la libreria OpenCV, lo cual sirve como experiencia y aprender mas sobre el manejo de otro tipo de lenguaje que en el mundo laboral me servira para afrontar cualquier tipo de desafios relacionados a la lectura de Personas.

# Anexos

## Anexo A: Instalación librerías OpenCV

Se descargo he instalo OpenCV, luego se agrego a las variables de entorno del sistema la carpeta bin y la carpeta lib, asi obtenemos un buen funcionamiento de la herramienta, podiendo ejecutar de buena manera los binarios y bibliotecas de OpenCV

## Anexo B: Instalación de IDE y configuración librerías OpenCV

Se descargo e instalo la IDE Visual Studio Code, en donde creamos el proyecto, instalamos las extenciones de C++ y el CMake y luego cargamos los argumentos de OpenCV en la Clase creada por CMake

# Referencia

.
# Referecia

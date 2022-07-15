![imagen ucn](https://github.com/JoshirCS/ED22-01-Contreras/blob/main/docs/imagenes/60x60-ucn-negro.png)
# Informe Técnico
## Curso: Estructura de datos
## Detección y re-identificación de caras en secuencias de imágenes o vídeo
### Alumnos:
Joshir Contreras 
## Resumen

El taller al que damos inicio nos encomendamos en generar un sistema de vigilancia en base al reconocimiento de personas. Para esta entrega se pide un programa con la ayuda de la biblioteca OpenCV en donde debemos detectar las personas que se presenten en un conjunto de imágenes, vídeo o algún tipo de cámara, marcando a estas personas en rectángulos de color rojo y también identificando el centro de esta figura con el objetivo de que un guardia pueda acceder a los datos recopilados por nuestro programa. Para lograr la realización de este taller, se instalo la IDE Visual Studio Code junto con OpenCV y CMake, usando las librerías de dichos programas para poder reconocer a las personas. Luego de investigar, se logra implementar de buena forma y con imágenes de referencias realizamos las pruebas obteniendo éxito.

## 1. Introducción

La tecnología avanza cada vez mas rápido, así se ve reflejada en la detección automática de personas y de otro tipo de figuras a partir de una cámara, imagen o vídeo, esta necesidad cada vez esta mas presente en la vida cotidiana por lo cual es importante saber manipular y comprender el uso de estas nuevas tecnologías debido a que nos genera una ventaja y gran conocimiento a la hora de llevarla a la practica. Es por esto que con este proyecto genera la necesidad de aprender mas sobre el tema y así poder crear habilidades y conocimientos nuevos, que hasta ahora son poco conocidos.

Este taller lleva la idea de usar programas y sus librerías, las cuales son las principales herramientas en la detección de personas, lo cual servirá para lograr los objetivos de este mismo, poder determinar las personas que salen o entran, obtenidas de un vídeo, cámara o imágenes.
Para completar esta tarea es importante la forma de buscar la información, por lo cual es importante buscar en foros o vídeos la implementación de dichas herramientas para desarrollar y entender nuestro problema.

### 1.1 Descripción del problema

Existe el desafió de crear un programa que reconozca personas en imágenes, vídeos o cámara con el fin de identificarlos en rectángulos para que el guardia pueda saber la cantidad de personas que entran o salen de un determinado lugar.

### 1.2 Objetivos

**Objetivo General:**

Construir un programa que detecte a las personas encarcelándolas en un rectángulo.

**Objetivos Especificos :**

1. Creación del repositorio Github
2. Instalación IDE Visual Studio Code , OpenCV y CMake
3. Investigar como reconocer a las personas con las librerías de dichos programas
4. Código de identificación 

Los objetivos específicos son acciones específicas que son desarrolladas para lograr cumplir el objetivo general, por ejemplo:

1. La creación del repositorio sirve para mantener ver el avance del proyecto.
2. Descargar e instalar los programas.
3. Investigar las herramientas que tenemos para poder reconocer a las personas.
4. Aplicar lo aprendido construyendo un código que nos permita resolver las problemáticas planteadas.

### 1.3 Solución Propuesta

Generar un código que permita reconocer a las personas, que tiene implementado el cumplimiento del objetivo y ademas generar las imágenes con los rectángulos para que así la personas pueda comprobar que el algoritmo funciona de forma correcta.

## 2. Materiales y métodos
- IDE Visual Studio Code 
- Biblioteca OpenCV
- CMake
- Imagen de personas

Configurando la IDE con OpenCV se podrá implementar de buena manera las librerías de esta y ademas con la orientación de objetos podremos manipulas de manera correcta el uso de los archivos y el análisis de las imágenes.

### 2.1 Instalación
- IDE Visual Studio Code: Es una IDE en donde se desarrollara el código del taller y se realizaran las pruebas necesarias para completar los requerimientos
- Biblioteca OpenCv: Librería libre de visión artificial que cuenta con las herramientas y librerías necesarias para la detección de personas, ademas de ser compatible con la IDE.
- CMake: Herramientas que servirá para la automatización y generación de código.

### 2.2 Diseño

- Clase Detector: Sirve para detectar las personas dentro la imagen y generar el cuadrado que encapsula a dicho elemento.
- Clase Persona: Guarda los datos de los puntos elementales a la figura generada en la clase Detector, ademas calcula el centro dela figura.
- Clase ArbolABB: Sirve para guardar la coordenada del centro de la figura creada en la clase Persona, teniendo como raiz el centro de la particion de la imagen, podiendo completar asi el arbol con las entradas a la derecha y las salidas a la izquierda.

### 2.3 Implementación

- Detector de Personas

El código carga la imagen y ajusta los parámetros para generar los rectángulos dependiendo de la cantidad de personas que se procesen en la imagen, moviendo los parámetros se puede encontrar una mejor o peor optimización en la búsqueda de personas. El código se presenta a continuación: 
```c++
if (m == Default)
        hog.detectMultiScale(img, found, 0, Size(2,2), Size(3,3), 1.02, 2, false);
else if(m == Dainler)
        hog_d.detectMultiScale(img, found, 0, Size(4,4), Size(8,8), 1.01, 3, true);
```
En estas lineas de código se aprecia la imagen de entrada y los parámetros de detección.

- Creación de rectángulos

Dentro de este código nos encontramos con las personas con los atributos que poseen, los cuales son las direcciones de los 4 puntos de dicha representación imaginaria que genera el detector de personas. Se ve reflejado con las siguientes lineas de código: 

```c++
 rectangle(imagen, cv::Point(p.getXInicio(), p.getYInicio()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0,0,255), 2);
 circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 2);
 //circle(imagen, cv::Point(p.getXInicio(), p.getYInicio()), 3, cv::Scalar(255, 0, 0), 2);
 //circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);
```
En dichas lineas nos encontramos la conformación del rectángulo, así como sus características, ademas de agregar el centro de dicha figura con las características necesarias para la implementación.

- Creación Linea de separación

Nos encontramos con una linea imaginaria que sirve para poder identificar cuantas personas salen o entran dentro de la imagen, vídeo o cámara de vídeo, se implemento con el siguiente código: 

```c++
Point p1(175,0), p2(175, 300);
int thickness = 1;
line(imagen, p1, p2, Scalar(255, 255, 0), thickness, LINE_8);
```
Con esta función podemos identificar en cada imagen cuantas personas se encuentran en el lado izquierdo (Salida) y derecho (Entrada), así podemos calcular los requerimientos necesarios.

- Creación Arbol Binario de Busqueda

Se crea un ABB para poder almacenar la coordenada del centro de las personas detectadas, en donde se agregara en la raiz la coordenada de la mitad de la imagen, y dependiendo de donde estaran las personas identificadas se agregaran en el arbol, a continuacion se muestra ek codigo del Arbol:

```c++
class ArbolABB{
    private:
        class Nodo{
            public:
                Nodo(const int dat, Nodo *izquierdo=nullptr, Nodo *derecho=nullptr) :
                    dato(dat), izq(izquierdo), der(derecho) {}
                    int dato;
                    Nodo *izq;
                    Nodo *der;
        };
        Nodo *raiz;
        Nodo *actual;
        int contador;
    public:
        ArbolABB() : raiz(nullptr), actual(nullptr) {}
        void Insertar(const int dato);
        bool Vacio(Nodo *r) { return r==nullptr; }
        int NumeroNodosIzq();
        int NumeroNodosDer();
        void auxContador(Nodo *nodo);
        
};
```
implementando los metodos correctos podemos calcular los requerimientos que se nos piden.

- Entrada y Salida 

Dentro de este punto, según el arbol binario mencionado con anterioridad, los nodos que se encuentran en el lado izquierdo de la raiz seran de salida y en el lado derecho la entrada. En el siguiente código se puede ver la implementación del calculo de los hijos izquieros y derechos del arbol:

```c++
int ArbolABB::NumeroNodosIzq(){
    contador = 0;
    auxContador(raiz->izq);
    return contador;
}
void ArbolABB::auxContador(Nodo *nodo){
    contador++;
    if(nodo->izq) auxContador(nodo->izq);
    if(nodo->der) auxContador(nodo->der);
}
int ArbolABB::NumeroNodosDer(){
    contador = 0;
    auxContador(raiz->der);
    return contador;
}
```

Con esto podemos calcular la cantidad de personas que se encuentran una funcion que recorre el arbol por su parte izquierda y tambien una funcion que recorre su parte derecha, teniendo una funcion auxiliar que servira para recorrer y sumar la cantidad de hijos que se presentan en cada lado respectivo.

- Velocidad Persona por Hora

Dentro de este parámetro se utiliza la librería de C++ e implementamos ctime, para poder calcular la hora de inicio del programa y la hora en la que se pide este requerimiento. Se presenta en el siguiente código:

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
double EntradaHora = ((double)arbol.NumeroNodosDer() / MinutosTranscurridos);
cout<<"\n"<<"==============================================================================="<<"\n";
cout<<"\n"<<" Velocidad de personas que entraron (Zona derecha): "<< EntradaHora <<"\n";
cout<<"\n"<<"=============================================================================="<<"\n";
```
Aquí calculamos la hora inicial a la que se ejecuta el programa y luego la ejecucion del requerimiento, se restan las horas y los minutos para luego dividir con respecto a la cantidad de personas que salieron y la cantidad de personas que entraron. Esto proporciona la cantidad de personas que entran en una hora, segun las imagenes y el tiempo transcurrido.

- Imagenes a analizar

Este parametro es para el administrador, en donde el podra elegir cuales imagenes deseea cargar en el programa para que el guardia pueda ejecutar los requerimientos necesarios.
```c++
cout<<"\n"<<"\nEscoja la carpteta que desee ser analizada: .";
                cout<<"\n"<<"\n1.Carpeta01 .";
                cout<<"\n"<<"\n2.Carpeta02 .";
                cin>>res;
                if(res == 1){
                    imagesStr->push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/Carpeta01/image1679.png");
                    imagesStr->push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/Carpeta01/image1680.png");
                    imagesStr->push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/Carpeta01/image0292.png");
                    imagesStr->push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/Carpeta01/image0293.png");
                    cond=false;
                    cond1=false;
                    
                }else if(res ==2){
                    imagesStr->push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/Carpeta02/image1679.png");
                    imagesStr->push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/Carpeta02/image1680.png");
                    cond1=false;
                    cond=false;
                }
```

Se le da la opcion al administrador de cargar la carpeta que el desee, para que el guardia pueda implementar analizar y realizar las operaciones que el desee.

## 3. Resultados Obtenidos

Una vez cargado el código nos arroja las imágenes presentadas como ejemplo,encapsuladas en los rectángulos rojos y también el calculo de la cantidad de personas que entran y salen en el total de imágenes.

![imagen](https://github.com/JoshirCS/ED22-01-Contreras/blob/main/docs/imagenes/referencias/e2.jpg) 

## 4. Conclusiones

Analizando el trabajio realizado, se da cuenta de que los objetivos se cumplen en su totalidad, si bien, tiene muchas mejoras en la realizacion de este codigo, pudiendo optimizarlo de una mejor manera, se logra una buena organizacion con los tiempos estimados y un buen desarrollo de este trabajo. Ademas se presenta una uena interacción con la IDE y la librería OpenCV, lo cual sirve como experiencia y aprender mas sobre el manejo de otro tipo de lenguaje que en el mundo laboral me servirá para afrontar cualquier tipo de desafíos relacionados a la lectura de Personas.

# Anexos

## Anexo A: Instalación librerías OpenCV

Se descargo he instalo OpenCV, luego se agrego a las variables de entorno del sistema la carpeta bin y la carpeta lib, así obtenemos un buen funcionamiento de la herramienta, pudiendo ejecutar de buena manera los binarios y bibliotecas de OpenCV

## Anexo B: Instalación de IDE y configuración librerías OpenCV

Se descargo e instalo la IDE Visual Studio Code, en donde creamos el proyecto, instalamos las extensiones de C++ y el CMake y luego cargamos los argumentos de OpenCV en la Clase creada por CMake

# Referencia

.

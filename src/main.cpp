#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>
#include <ctime>

#include "Detector.hpp"
#include "Persona.hpp"
#include "ArbolABB.hpp"

using namespace cv;
using namespace std;
/*
    Funcion que sirve para cargar las imagenes que son analizadas, desplegandolas por pantalla con el rectangulo y el punto identificando a las personas.  
*/
void MostrarImagenes(vector<string>imagesStr,vector<string>*imagenes, Mat imagen,Detector detector){
     cout << "imgesStr = {";
    for (string n:imagesStr)
    {
        cout<<n<<",";
    }
    cout << "};"<<endl;

    for(string im : imagesStr){
        imagen = imread(im);
        
        Point p1(175,0), p2(175, 300);
        int thickness = 1;

        line(imagen, p1, p2, Scalar(255, 255, 0), thickness, LINE_8);

        detector.toggleMode();
        cout << detector.modeName() << endl;

        vector<Persona> found = detector.detect(imagen);
    
        for (vector<Persona>::iterator i = found.begin(); i != found.end(); ++i)
        {
            Persona &p = *i;

            rectangle(imagen, cv::Point(p.getXInicio(), p.getYInicio()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0,0,255), 2);
            circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 2);
        }
        imshow("Detector Personas", imagen);
        waitKey(0);
        
    }
}
/*
    Funcion que sirve para cargar el Arbol Binadrio de Busqueda con los centros de las personas, que son analizadas mediante el detector.
    Retornara el arbol cargado de personas.
*/
ArbolABB CargarArbol(ArbolABB arbol, vector<string>imagesStr,vector<string>*imagenes, Mat imagen,Detector detector){
    arbol.Insertar(175);
    cout<< "imagesStr = {";
    for(string n:imagesStr){
        cout<<n<<",";
    }
    cout <<"};"<<endl;

    for(string im:imagesStr){
        imagen = imread(im);
        detector.toggleMode();
        cout << detector.modeName() <<endl;

        vector<Persona> found = detector.detect(imagen);
        for(vector<Persona>::iterator i= found.begin(); i !=found.end(); i++){
            Persona &p = *i;
            arbol.Insertar(p.getXCentro());
        }
    }
    
    return arbol;
}
/*
    Funcion Menu administrador, en donde se cargaran las imagenes que seran analizadas en nuestro programa.
    Retornara el vector con las imagenes seleccionadas.
*/
vector<string> MenuAdmin(vector<string> &imagesStr){
    vector<string> imagenes;
    int elec;
    bool cond=true;
    bool cond1=true;
    while(cond){
        cout<<"\n"<<"==============================================================================="<<"\n";
	    cout<<"\n"<<"                               MENU DE ADMIN                                   "<<"\n";
	    cout<<"\n"<<"==============================================================================="<<"\n";
        cout<<"\n"<<"\n1.Obtener imagenes.";
        cout<<"\n"<<"\n2.Salir.";
        cout<<"\n"<<"\n"<<">>>>Estimado usuario digite el numero de la operacion a realizar: "; 
        cin>>elec;
        int res;
        if(elec ==1){
            while(cond1){
                cout<<"\n"<<"\nEscoja la carpteta que desee ser analizada: .";
                cout<<"\n"<<"\n1.Carpeta01 .";
                cout<<"\n"<<"\n2.Carpeta02 .";
                cin>>res;
                if(res == 1){
                    imagenes.push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/Carpeta01/image1679.png");
                    imagenes.push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/Carpeta01/image1680.png");
                    imagenes.push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/Carpeta01/image0292.png");
                    imagenes.push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/Carpeta01/image0293.png");
                    cond=false;
                    cond1=false;
                    cout<<"==============================================================================="<<"\n";
                    cout<<"\n"<<"             CARGADO CON EXITO, VOLVIENDO AL MENU PRINCIPAL              "<<"\n";
                    cout<<"\n"<<"==============================================================================="; 
                    

                }else if(res ==2){
                    imagenes.push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/Carpeta02/image1679.png");
                    imagenes.push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/Carpeta02/image1680.png");
                    cond1=false;
                    cond=false;
                    cout<<"==============================================================================="<<"\n";
                    cout<<"\n"<<"             CARGADO CON EXITO, VOLVIENDO AL MENU PRINCIPAL              "<<"\n";
                    cout<<"\n"<<"===============================================================================";
                }else{
                    cout<<"==============================================================================="<<"\n";
                    cout<<"\n"<<"             ESTIMADO USUARIO LA OPCION MARCADA ES INVALIDA                    "<<"\n";
                    cout<<"\n"<<"==============================================================================="; 
                }
            }
        }else if(elec ==2){
            cout<<"==============================================================================="<<"\n";
            cout<<"\n"<<"                    VOLVIENDO AL MENU PRINCIPAL                                 "<<"\n";
            cout<<"\n"<<"==============================================================================="; 
            cond=false;
        }else{
            cout<<"==============================================================================="<<"\n";
            cout<<"\n"<<"             ESTIMADO USUARIO LA OPCION MARCADA ES INVALIDA                    "<<"\n";
            cout<<"\n"<<"==============================================================================="; 
        }
    }
    return imagenes;

}
/*
    Funcion Menu de guardia, en donde se ejecutaran las opciones que vaya eligiendo el usuario. 
*/
void MenuGuardia(ArbolABB arbol, vector<string>imageStr,vector<string>*imagenes, Mat imagen,Detector detector,int HoraInicio, int MinutoInicio){
    if(imageStr.empty()){
        cout<<"\n"<<"==============================================================================="<<"\n";
	    cout<<"\n"<<"          EL ADMINISTRADOR AUN NO CARGA ARCHIVOS PARA ANALIZAR                 "<<"\n";
	    cout<<"\n"<<"==============================================================================="<<"\n";
    }else{
        int elec;
        bool cond=true;
        while(cond){
            cout<<"\n"<<"==============================================================================="<<"\n";
	        cout<<"\n"<<"                               MENU DE GUARDIA                                 "<<"\n";
	        cout<<"\n"<<"==============================================================================="<<"\n";
            cout<<"\n"<<"\n1.Ver la deteccion de personas.";
            cout<<"\n"<<"\n2.Ver trafico de entrada.";
            cout<<"\n"<<"\n3.Ver trafico de salida.";
            cout<<"\n"<<"\n4.Ver la velocidad de entrada.";
            cout<<"\n"<<"\n5.Ver la velocidad de salida.";
            cout<<"\n"<<"\n6.Salir.";
            cout<<"\n"<<"\n"<<">>>>Estimado usuario digite el numero de la operacion a realizar: "; 
            cin>>elec;
            if(elec ==1){
                MostrarImagenes(imageStr,imagenes,imagen,detector);
            }
            else if(elec ==2){
                cout<<"\n"<<"==============================================================================="<<"\n";
	            cout<<"\n"<<" Cantidad de personas que entraron (Zona derecha): "<<arbol.NumeroNodosDer()<<"\n";
	            cout<<"\n"<<"==============================================================================="<<"\n";
            }
            else if(elec ==3){
                cout<<"\n"<<"==============================================================================="<<"\n";
	            cout<<"\n"<<" Cantidad de personas que salieron (Zona Izquierda): "<<arbol.NumeroNodosIzq()<<"\n";
	            cout<<"\n"<<"==============================================================================="<<"\n";
            }
            else if(elec ==4){
                time_t TiempoFinal = time(0);
                tm *ltme = localtime(&TiempoFinal);
                int HoraFinal = ltme->tm_hour;
                int MinutoFinal = ltme->tm_min;
                double MinutosTranscurridos = (double)(HoraFinal-HoraInicio) + (double)(MinutoFinal - MinutoInicio)/60;
                double EntradaHora = ((double)arbol.NumeroNodosDer() / MinutosTranscurridos);
                cout<<"\n"<<"==============================================================================="<<"\n";
	            cout<<"\n"<<" Velocidad de personas que entraron (Zona derecha) por hora: "<< EntradaHora <<"\n";
	            cout<<"\n"<<"=============================================================================="<<"\n";
            }
            else if(elec ==5){
                time_t TiempoFinal = time(0);
                tm *ltme = localtime(&TiempoFinal);
                int HoraFinal = ltme->tm_hour;
                int MinutoFinal = ltme->tm_min;
                double MinutosTranscurridos = (double)(HoraFinal-HoraInicio) + (double)(MinutoFinal - MinutoInicio)/60;
                double SalidaHora = ((double)arbol.NumeroNodosIzq() / MinutosTranscurridos);
                cout<<"\n"<<"==============================================================================="<<"\n";
	            cout<<"\n"<<" Cantidad de personas que salieron (Zona Izquierda) por hora: "<<SalidaHora<<"\n";
	            cout<<"\n"<<"==============================================================================="<<"\n";
            }
            else if(elec ==6){
                cond=false;
            }
        }
    }
}
/*
    Funcion Menu, en donde se ejecutaran todo el programa y deplegara las opciones que puede ejecutar el usuario.
*/
void Menu(ArbolABB arbol, vector<string>imagesStr,vector<string>*imagenes, Mat imagen,Detector detector, int HoraInicio, int MinutoInicio){
    int elec;
    bool cond=true;
    while(cond){
         cout<<"\n"<<"==============================================================================="<<"\n";
	    cout<<"\n"<<"                       IDENTIFICACION DE PERSONAS                              "<<"\n";
	    cout<<"\n"<<"==============================================================================="<<"\n";
        cout<<"\n"<<"\n1.Menu de Guardia.";
        cout<<"\n"<<"\n2.Menu de Administrador.";
        cout<<"\n"<<"\n3.Salir.";
        cout<<"\n"<<"\n"<<">>>>Estimado usuario digite el numero de la operacion a realizar: "; 
        cin>>elec;
        if(elec == 1){
            MenuGuardia(arbol,imagesStr,imagenes,imagen,detector,HoraInicio, MinutoInicio);
        }
        else if(elec == 2){
            imagesStr = MenuAdmin(imagesStr);
            arbol = CargarArbol(arbol,imagesStr,imagenes,imagen,detector);
        }else if(elec == 3){
            
            exit(0);
        }else{
            cout<<"==============================================================================="<<"\n";
            	   cout<<"\n"<<"             ESTIMADO USUARIO LA OPCION MARCADA ES INVALIDA                    "<<"\n";
            	   cout<<"\n"<<"==============================================================================="; 
        }
    }
}


/*
 Aqui comienza la ejecuccion del programa Identifiacion de personas.
*/
int main(int argc, char** argv )
{
    ArbolABB arbol;
    vector<string>imagesStr;
    vector<string>*imagenes = &imagesStr;
    Mat imagen;
    Detector detector;

    time_t TiempoInicio = time(0);
    tm *ltm = localtime(&TiempoInicio);
    int HoraInicio = ltm->tm_hour;
    int MinutoInicio = ltm->tm_min;

    Menu(arbol,imagesStr,imagenes,imagen,detector, HoraInicio, MinutoInicio);
    return 0;
};

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>
#include <ctime>

#include "Detector.hpp"
#include "Persona.hpp"
//#include "ListaPersonas.hpp"
//#include "NodoPersona.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{   
    //ListaPersonas<NodoPersona<Persona>> listaP;

    time_t TiempoInicio = time(0);
    tm *ltm = localtime(&TiempoInicio);
    int HoraInicio = ltm->tm_hour;
    int MinutoInicio = ltm->tm_min;

    Detector detector;
    Mat imagen;

    vector<String>imagesStr;

    imagesStr.push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/imagenes/image1679.png");
    imagesStr.push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/imagenes/image1680.png");
    imagesStr.push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/imagenes/image0292.png");
    imagesStr.push_back("C:/Users/JoshiR/workspace/Estructura datos/taller/imagenes/image0293.png");
    
    //variable de contador salida y entrada;
    int contSalida=0;
    int contEntrada=0;

    //variable de id, la cual se le asignara a cada persoan que ingrese a la listaPersonas
    int id=0;


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
            /*
            //se crea el nodo persona.
            NodoPersona<Persona> NP(p,id,0);
            
            //se agregan las personas al nodo.
            if(listaP.isEmpty()){
                listaP.add_primero(NP);
                listaP.print();
                id++;
            }else{

            }
            */

            cout << "(" << p.getXInicio() << ", "<< p.getYInicio() << ")" << endl;
            rectangle(imagen, cv::Point(p.getXInicio(), p.getYInicio()), cv::Point(p.getXFin(), p.getYFin()), cv::Scalar(0,0,255), 2);
            circle(imagen, cv::Point(p.getXCentro(), p.getYCentro()), 3, cv::Scalar(0, 0, 255), 2);
            //circle(imagen, cv::Point(p.getXInicio(), p.getYInicio()), 3, cv::Scalar(255, 0, 0), 2);
            //circle(imagen, cv::Point(p.getXFin(), p.getYFin()), 3, cv::Scalar(0, 255, 255), 2);

            //Se empieza a contar cuantas personas entran y salen dependiendo de la posicion en la que se encuentren en la imagen
            if( p.getXCentro() < p1.x){
                contSalida++;
            }else{
                contEntrada++;
            }
        }
        imshow("People detector", imagen);
        waitKey(0);
        
    }
    time_t TiempoFinal = time(0);
    tm *ltme = localtime(&TiempoFinal);
    int HoraFinal = ltme->tm_hour;
    int MinutoFinal = ltme->tm_min;

    int MinutosTranscurridos = (HoraFinal-HoraInicio)*60 + (MinutoFinal - MinutoInicio);
    float EntradaHora = ((float)contEntrada / MinutosTranscurridos);
    float SalidaHora = ((float)contSalida / MinutosTranscurridos);

    //cout << "Hora y min inicio: " << HoraInicio << "," << MinutoInicio << endl;
    //cout << "Hora y min final: " << HoraFinal << "," << MinutoFinal << endl;

    cout << "Cantidad total de personas que entraron: " << contEntrada <<"\nCantidad total de personas que salieron: " << contSalida <<"\nVelocidad entrada promedio por hora: " << EntradaHora <<"\nVelocidad salida promedio por hora: "<< SalidaHora <<endl;
    
    return 0;
    
};


#include "Persona.hpp"

Persona::Persona(cv::Rect &r){
    xInicio = r.x;
    yInicio = r.y;
    xFin = r.x + r.width;
    yFin = r.y + r.height;
    xCentro = r.x + ((float)r.width/2.0);
    yCentro = r.y + ((float)r.height/2.0);
}

int Persona::getXInicio(){
    return xInicio;
}
int Persona::getYInicio(){
    return yInicio;
}
int Persona::getXFin(){
    return xFin;
}
int Persona::getYFin(){
    return yFin;
}
int Persona::getXCentro(){
    return xCentro;
}
int Persona::getYCentro(){
    return yCentro;
}

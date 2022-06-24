#ifndef PERSONA_H
#define PERSONA_H

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

class Persona{
    private:
        int xInicio;
        int yInicio;
        int xFin;
        int yFin;
        int xCentro;
        int yCentro;
    public:
        Persona(cv::Rect&);

        int getXInicio();
        int getYInicio();
        int getXFin();
        int getYFin();
        int getXCentro();
        int getYCentro();
};

#endif

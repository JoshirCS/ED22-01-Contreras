#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>

using namespace cv;
using namespace std;

#include "Detector.hpp"

void Detector::toggleMode(){ 
    m = (m == Default ? Dainler : Default); 
}

string Detector::modeName() const {
    return (m == Default ? "Default" : "Dainler" );
}
vector<Persona> Detector::detect(InputArray img){

    vector<Rect> found;

    if (m == Default)
        hog.detectMultiScale(img, found, 0, Size(2,2), Size(3,3), 1.02, 2, false);
    else if(m = Dainler)
        hog_d.detectMultiScale(img, found, 0, Size(4,4), Size(8,8), 1.01, 3, true);
    
    vector<Persona> personas;
    for (vector<Rect>::iterator i = found.begin(); i != found.end(); ++i){
        Rect &r = *i;
        Persona p(r);
        personas.push_back(p);
    }
    return personas;
}
//se debe modificar en Persona
void Detector::adjustRect(Rect & r) const{
    r.x += cvRound(r.width*0.1);
    r.width = cvRound(r.width*0.8);
    r.y += cvRound(r.height*0.07);
    r.height = cvRound(r.height*0.8);

}

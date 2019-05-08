#ifndef CURRENTLOCATIOMANAGER_H
#define CURRENTLOCATIOMANAGER_H
#include<coordinatemanager.h>

class CurrentLocatioManager :public CoordinateManager
{
private:

    QString str_UrlforCurrentPlaceAPI{"http://api.ipstack.com/178.212.111.37?access_key=587cda62d522cc42b75ac4342281c937"};



public:
  CurrentLocatioManager();



     virtual void getCoordinate();

     virtual ~CurrentLocatioManager(){}
};

#endif // CURRENTLOCATIOMANAGER_H

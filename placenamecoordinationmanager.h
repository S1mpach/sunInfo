#ifndef PLACENAMECOORDINATIONMANAGER_H
#define PLACENAMECOORDINATIONMANAGER_H

#include<coordinatemanager.h>

class PlaceNameCoordinationManager :public CoordinateManager
{
private:

    const QString API {"&key=8bc42fdfc412429f83fa5224e1fa66d2"};
    const QString countryCode {"&countrycode=ua"};
    const QString additionOptions {"&limit=1&no_annotations=1"};
    const QString baseOfUrl = {"http://api.opencagedata.com/geocode/v1/json?q="};





public:
   PlaceNameCoordinationManager();

    QString generateUrlForRequest();




    QString getPlaceName() const;
    void setPlaceName(const QString &value);

    virtual void getCoordinate();

    virtual ~PlaceNameCoordinationManager(){}
};


#endif // PLACENAMECOORDINATIONMANAGER_H

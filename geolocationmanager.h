#ifndef GEOLOCATIONMANAGER_H
#define GEOLOCATIONMANAGER_H


#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QObject>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include<QApplication>
#include<iostream>
#include<memory>
#include<location.h>

#include<weathermanager.h>
#include<placenamecoordinationmanager.h>
#include<currentlocatiomanager.h>
#include<suninfo.h>

class GeoLocationManager
{

private:
    static std::shared_ptr<GeoLocationManager> ptr_LocationManager;

    GeoLocationManager():currLocationManager(new CurrentLocatioManager),
        placeNameLocatinManager(new PlaceNameCoordinationManager),
        weatherManager(new WeatherManager)
   {}

    GeoLocationManager(const GeoLocationManager&) = default;
    GeoLocationManager& operator=(GeoLocationManager&) = default;

    std::shared_ptr<CurrentLocatioManager> currLocationManager;
    std::shared_ptr<PlaceNameCoordinationManager> placeNameLocatinManager;
    std::shared_ptr<WeatherManager> weatherManager;



public:

     SunInfo getInfo();
     SunInfo getInfo(QString placeName);




    ~GeoLocationManager(){}
    static std::shared_ptr<GeoLocationManager> getAccess()
    {
         static std::shared_ptr<GeoLocationManager>generatedManager (new GeoLocationManager );
        return generatedManager;
    }


};




#endif // GEOLOCATIONMANAGER_H

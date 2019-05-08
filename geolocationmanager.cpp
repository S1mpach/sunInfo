#include "geolocationmanager.h"






SunInfo GeoLocationManager::getInfo()
{
    currLocationManager->getCoordinate();

    return weatherManager->getSunInfo(currLocationManager->getPtr_Location());
}

SunInfo GeoLocationManager::getInfo(QString placeName)
{
    placeNameLocatinManager->setPlaceName(placeName);
    placeNameLocatinManager->getCoordinate();
    return weatherManager->getSunInfo(placeNameLocatinManager->getPtr_Location());
}

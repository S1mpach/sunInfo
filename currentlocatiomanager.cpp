#include "currentlocatiomanager.h"




CurrentLocatioManager::CurrentLocatioManager():CoordinateManager ()
{
    QObject::connect(ptr_networkManager.get(), &QNetworkAccessManager::finished,
                     [&](QNetworkReply *reply)
    {

        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Got some error " << reply->error();

        }else {
            const int resultCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            qDebug() << "Received code :" << resultCode;
            if (resultCode == 200)
            {
                QString strReply = QString::fromStdString( reply->readAll().toStdString() );

                QJsonDocument jsonResponse = QJsonDocument::fromJson( strReply.toUtf8() );

                QJsonObject responseObject =  jsonResponse.object();

                QString place = responseObject.value("country_name").toString() + " "
                        + responseObject.value("region_name").toString() + " "
                        + responseObject.value("city").toString();

                ptr_Location->setPlace(place);
                ptr_Location->setLatitude(responseObject.value("latitude").toDouble());
                ptr_Location->setLongitude(responseObject.value("longitude").toDouble());
                qDebug()<<"COORD";
                qDebug()<<ptr_Location->getPlace();
                qDebug()<<ptr_Location->getLatitude();
                qDebug()<<ptr_Location->getLongitude();
            }
        }
        reply->deleteLater();
    }
    );

    QObject::connect(ptr_networkManager.get(), SIGNAL(finished(QNetworkReply*)),eventLoop.get(), SLOT(quit()));

}

void CurrentLocatioManager::getCoordinate()
{

    ptr_networkRequest->setUrl( str_UrlforCurrentPlaceAPI );

    ptr_networkManager->get(*ptr_networkRequest);

    eventLoop->exec();
//    qDebug()<<ptr_Location->getPlace();
//    qDebug()<<ptr_Location->getLatitude();
//    qDebug()<<ptr_Location->getLongitude();



}

#include "placenamecoordinationmanager.h"


PlaceNameCoordinationManager:: PlaceNameCoordinationManager(): CoordinateManager()
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

                QJsonObject responseObject = jsonResponse.object();
                QJsonArray results_Response = responseObject.value("results").toArray();

                QJsonValue valueOfFirstElement = results_Response[0];

                QJsonObject obj_FirstElement = valueOfFirstElement.toObject();



                QJsonObject geometry_Response = obj_FirstElement.value("geometry").toObject();
                ptr_Location->setLatitude( geometry_Response.value("lat").toDouble() );
                ptr_Location->setLongitude( geometry_Response.value("lng").toDouble() );


            }
        }
        reply->deleteLater();
    }
    );
    QObject::connect(ptr_networkManager.get(), SIGNAL(finished(QNetworkReply*)),eventLoop.get(), SLOT(quit()));



}

QString PlaceNameCoordinationManager::generateUrlForRequest()
{
    return baseOfUrl + ptr_Location->getPlace() + countryCode + additionOptions + API;
}

void PlaceNameCoordinationManager::getCoordinate()
{




    ptr_networkRequest->setUrl( generateUrlForRequest() );


    ptr_networkManager->get(*ptr_networkRequest);

    eventLoop->exec();
    qDebug()<<ptr_Location->getPlace();
    qDebug()<<ptr_Location->getLatitude();
    qDebug()<<ptr_Location->getLongitude();

}

QString PlaceNameCoordinationManager::getPlaceName() const
{
    return ptr_Location->getPlace();
}

void PlaceNameCoordinationManager::setPlaceName(const QString &value)
{
    ptr_Location->setPlace(value);
}

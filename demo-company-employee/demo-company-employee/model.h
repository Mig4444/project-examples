#ifndef MODEL_H
#define MODEL_H

#include <QString>
#include <QDebug>

class Model
{
public:
    //Constructor specified as a singleton
    Model &getInstance()
    {
        Model *instance_m = new Model();
        return *instance_m;
    }

    // Set all required fields for the creation of the request to display: INSERT
    QString model_user_request();

    // Set all required fields for the creation of a new employee
    QString model_edition_creation_request();
    // Set a new value to a single field on target employee: UPDATE...etc.
    QString model_edition_modification_request();

    // Alter tables: ADD/DROP...etc. instruction
    QString model_administator_request();

public slots:


};

#endif // MODEL_H

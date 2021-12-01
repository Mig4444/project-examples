#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QString>

#include "type.h"

class Controller
{
public:
    //Constructor specified as a singleton
    Controller &getInstance()
    {
        Controller *instance_m = new Controller();
        return *instance_m;
    }

    // Getters
    // Each getter will pass a new item or information to look for
    // Controller communication with the Model
    // when on User screen. In order to enter the search filters
    void controller_get_age();
    void controller_get_gender();
    void controller_get_enterDate();
    void controller_get_salary();
    void controller_get_typeOfContract();
    void controller_get_departement();
    void controller_get_level();
    void controller_get_calendar();
    void controller_get_hierachyResponsible();
    void controller_get_name();
    void controller_get_surname();
    void controller_get_id();
    void controller_get_previousProject();
    void controller_get_previousTeam();
    void controller_get_currentProject();
    void controller_get_currentTeam();

    // Setters
    // Controller communication with the Model
    // when on Edit screen. In order to add a new employee or modify existing employee settings
    void controller_set_age(uint8_t age);
    void controller_set_gender(uint8_t gender);
    void controller_set_enterDate(QString enterDate);
    void controller_set_salary(float_t salary);
    void controller_set_typeOfContract(uint8_t typeOfContract);
    void controller_set_departement(uint8_t deparement);
    void controller_set_level(uint8_t level);
    void controller_set_calendar(QString calendar);
    void controller_set_hierachyResponsible(QString hierachyResponsible);
    void controller_set_name(QString name);
    void controller_set_surname(QString surname);
    void controller_set_id(QString id);
    void controller_set_previousProject(QString previousProject);
    void controller_set_previousTeam(QString previousProject);
    void controller_set_currentProject(QString previousProject);
    void controller_set_currentTeam(QString previousProject);
    void controller_submit_employee();
    // Verification that new employee doesn't already exists
    void controller_check_employee_exist();

    // Setters
    // Controller communication with the Model
    // when on Administrator screen
    // This instruction will directly impact the structure of the DB.
    void controller_add_column(QString columnName, uint8_t type, uint8_t length, uint8_t options);
    void controller_erase_column(QString columnName);

private:
    Controller(){}; // Default
    Controller(const Controller&); // Call
    Controller& operator=(const Controller&); // Operator
};

#endif // CONTROLLER_H

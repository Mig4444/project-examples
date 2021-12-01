#ifndef TABDIALOG_H
#define TABDIALOG_H

#include <QObject>
#include <QDialog>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QFileInfo;
class QTabWidget;
QT_END_NAMESPACE

class SearchTab : public QWidget
{
    // The Q_OBJECT macro must appear in the private section of
    // a class definition that declares its own signals and slots or that uses other
    // services provided by Qt's meta-object system.
    Q_OBJECT
public:
    // Default constructor for tab search
    SearchTab(QWidget *parent = nullptr);

public slots:
    // Methods to be triggered by signals
    // Signal incoming from the result of the search
    bool Set_TextBrowser();
    bool Clear_TextBrowser();

private:
    // Items to display - related to the GUI
    QLabel *firstNameLabel;
    QLineEdit *firstNameEdit;
    QLabel *secondNameLabel;
    QLineEdit *secondNameEdit;
    QLabel *idLabel;
    QLineEdit *idEdit;
    QLabel *resultLabel;
    QTextBrowser *resultTextBrowser;

    // Disposition of the elements
    QVBoxLayout *mainLayout;
};

class EditionTab : public QWidget
{
    Q_OBJECT

public:
    EditionTab(QWidget *parent = nullptr);

public slots:
    // Methods to be triggered by signals
    // Signal incoming from the result of the search

private:
    // Items to display - related to the GUI
    QLabel *nameLabel;
    QLineEdit *nameEdit;

    QLabel *surnameLabel;
    QLineEdit *surnameEdit;

    QLabel *idLabel;
    QLineEdit *idEdit;

    QLabel *ageLabel;
    QLineEdit *ageEdit;

    QLabel *genderLabel;
    QLineEdit *genderEdit;

    QLabel *enterDateLabel;
    QLineEdit *enterDateEdit;

    QLabel *salaryLabel;
    QLineEdit *salaryEdit;

    QLabel *typeOfContractLabel;
    QLineEdit *typeOfContractEdit;

    QLabel *departmentLabel;
    QLineEdit *departmentEdit;

    QLabel *leveleLabel;
    QLineEdit *levelEdit;

    QLabel *calendarLabel;
    QLineEdit *calendarEdit;

    QLabel *hierachyLabel;
    QLineEdit *hierachyEdit;

    QLabel *prevProjLabel;
    QLineEdit *prevProjEdit;

    QLabel *currProjLabel;
    QLineEdit *currProjEdit;

    // Disposition of the elements
    QVBoxLayout *mainLayout;
};

class AdministratorTab : public QWidget
{
    Q_OBJECT

public:
    AdministratorTab(QWidget *parent = nullptr);

public slots:
    // Methods to be triggered by signals
    // Signal incoming from the result of the search

private:
    // Items to display - related to the GUI
    QLabel *addColumnNameLabel;
    QLineEdit *addColumnNAmeEdit;

    QLabel *addColumnVarLabel;
    QLineEdit *addColumnVarEdit;

    QLabel *addColumnLenghtLabel;
    QLineEdit *addColumnLenghtEdit;

    QLabel *addColumnOptionsLabel;
    QLineEdit *addColumnOptionstEdit;

    QPushButton *submitButton;

    // Disposition of the elements
    QVBoxLayout *mainLayout;
};

class TabDialog : public QDialog
{
    Q_OBJECT

public:
    TabDialog(QWidget *parent = nullptr);

private:
    // Contains the tabs
    QTabWidget *tabWidget;

    // Contains the buttons descriptions
    QDialogButtonBox *buttonBox;
};

#endif // TABDIALOG_H

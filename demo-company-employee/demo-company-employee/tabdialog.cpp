#include <QtWidgets>

#include "tabdialog.h"

//Tabs constrution
TabDialog::TabDialog(const QString &fileName, QWidget *parent)
    : QDialog(parent)
{
    QFileInfo fileInfo(fileName);

    // Initialization of member variable linked to the tabs
    tabWidget = new QTabWidget;
    tabWidget->addTab(new SearchTab(), tr("Search"));
    tabWidget->addTab(new EditionTab(), tr("Edition"));
    tabWidget->addTab(new AdministratorTab(), tr("Administrator"));

    // Initialization of member variable linked to buttons
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    // Connect the signals
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    // Position the elements ont he layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Tab Dialog"));
}

// Search tab inside construction
SearchTab::SearchTab(QWidget *parent)
    : QWidget(parent)
{
    //First name label and edit box
    QLabel *firstNameLabel = new QLabel(tr("First Name:"));
    QLineEdit *firstNameEdit = new QLineEdit();

    //Second name label and edit box
    QLabel *secondNameLabel = new QLabel(tr("Second Name:"));
    QLineEdit *secondNameEdit = new QLineEdit();

    //
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(firstNameLabel);
    mainLayout->addWidget(firstNameEdit);
    mainLayout->addWidget(secondNameLabel);
    mainLayout->addWidget(secondNameEdit);

    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

// Edition tab inside construction
EditionTab::EditionTab(QWidget *parent)
    : QWidget(parent)
{

}

AdministratorTab::AdministratorTab(QWidget *parent)
    : QWidget(parent)
{

}

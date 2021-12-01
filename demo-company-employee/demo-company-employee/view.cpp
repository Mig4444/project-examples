#include <QtWidgets>

#include "view.h"

//Tabs constrution
TabDialog::TabDialog(QWidget *parent)
    : QDialog(parent)
{
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
    qDebug()<<"TabDialog exiting";
}

// Search tab inside construction
SearchTab::SearchTab(QWidget *parent)
    : QWidget(parent)
{
    //First name label and edit box
    firstNameLabel = new QLabel(tr("First Name:"));
    firstNameEdit = new QLineEdit();
    firstNameLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    //Second name label and edit box
    secondNameLabel = new QLabel(tr("Second Name:"));
    secondNameEdit = new QLineEdit();

    //id label and edit box
    idLabel = new QLabel(tr("ID"));
    idEdit = new QLineEdit();

    //results
    resultLabel = new QLabel(tr("Results:"));
    resultTextBrowser = new QTextBrowser();

    // Linking signals
    // Signal -> object emmiting the signal
    // Slot -> action to be taken if signal is received
    connect(firstNameEdit,SIGNAL(textChanged(const QString &)),
            this,SLOT(Set_TextBrowser()));

    // Construct the Layout
    mainLayout = new QVBoxLayout;

    mainLayout->addWidget(firstNameLabel);
    mainLayout->addWidget(firstNameEdit);

    mainLayout->addWidget(secondNameLabel);
    mainLayout->addWidget(secondNameEdit);

    mainLayout->addWidget(idLabel);
    mainLayout->addWidget(idEdit);

    mainLayout->addWidget(resultLabel);
    mainLayout->addWidget(resultTextBrowser);

    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

bool SearchTab::Set_TextBrowser()
{
    qDebug()<<"Passing by Set_TextBrowser";
    resultTextBrowser->clear();
    resultTextBrowser->append(firstNameEdit->text());
    return 0;
}


bool SearchTab::Clear_TextBrowser()
{
    qDebug()<<"Passing by Clear_TextBrowser";
    return 0;
}

// Edition tab inside construction
EditionTab::EditionTab(QWidget *parent)
    : QWidget(parent)
{
    qDebug()<<"Passing by EditionTab";
}

AdministratorTab::AdministratorTab(QWidget *parent)
    : QWidget(parent)
{
    qDebug()<<"Passing by AdministratorTab";
}

#ifndef TABDIALOG_H
#define TABDIALOG_H

#include <QDialog>

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
    SearchTab(QWidget *parent = nullptr);
};

class EditionTab : public QWidget
{
    Q_OBJECT

public:
    EditionTab(QWidget *parent = nullptr);
};

class AdministratorTab : public QWidget
{
    Q_OBJECT

public:
    AdministratorTab(QWidget *parent = nullptr);
};

class TabDialog : public QDialog
{
    Q_OBJECT

public:
    TabDialog(const QString &fileName, QWidget *parent = nullptr);

private:
    // Contains the tabs
    QTabWidget *tabWidget;
    // Contains the buttons descriptions
    QDialogButtonBox *buttonBox;
};

#endif // TABDIALOG_H

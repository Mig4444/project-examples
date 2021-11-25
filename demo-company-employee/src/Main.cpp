//Test de un Hello World en wxWidgets

//#include "imagen.xpm" //Imagen en formato xpm
#include <iostream>
#include "wx/wx.h"
//#include <wx/app.h>
//using namespace std;

wxString title ("Barra Superior");

//Declaraciones

//Cada aplicacion wxWidget define una clase derivada de wxApp
class MiApp:public wxApp
{
    public:
    //Llamado al inicio startup, es como el main en c
    virtual bool OnInit();//main wxWidgets , mas abajo se implementa
};

//Declaracion de la clase frame principal

//----------------------------------------------------------------------

class MiFrame:public wxFrame
{
    public:
    //Constructor de la clase
    MiFrame(const wxString& titulo);

    // Dos "event handlers" , gestion de eventos
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnSize(wxSizeEvent& event);//Manipulacion del Frame
    void OnButtonOk(wxCommandEvent& event);//Click boton OK

    private:
    /*Macro para informar a wxWidgets de la gestion de eventos
    *Declara la tabla de eventos en esta clase ,mas abajo
    * la implemento entre BEGIN_ y END_EVENT_TABLE
    */
    DECLARE_EVENT_TABLE()
};

//----------------------------------------------------------------------

/*Implementacion , MiApp
*Cuando se crea el objeto MiApp se asigna a la variable global wxTheApp
* pero mejor que hacer un CAST emplear el MACRO  DECLARE_APP despues de
* la declaracion de la clase , wxGetApp retorna una ref. al objeto MiApp
*/
DECLARE_APP(MiApp)

//Macro que Proporciona a wxWidgets los medios de crear el objeto MiApp
IMPLEMENT_APP(MiApp)

//----------------------------------------------------------------------

//Implementacion OnInit,Inicializa la aplicacion

bool MiApp::OnInit()
{
    //Crea la ventana principal , una instancia de nuestra clase MiFrame
    //El titulo lo pasamos al constructor envuelto en el macro wxT
    //macro de conversion de strings y char al tipo apropiado
    MiFrame *frame=new MiFrame(wxT("Titulo Mini wxWidgets"));

    //Mostrar la ventana
    frame->Show(true);

    //Arranca el bucle de eventos
    return true ;//Si false limpia sus estructuras y sale
}

//----------------------------------------------------------------------

//Tabla de eventos para MiFrame DECLARE_EVENT_TABLE() en MiFrame
//Deteccion de los clicks de raton con wxID_ABOUT y wxID_EXIT
//Que se dirigen a MiFrame::OnAbout y OnQuit
BEGIN_EVENT_TABLE (         MiFrame,wxFrame)
    EVT_MENU(wxID_ABOUT,    MiFrame::OnAbout)
    EVT_MENU(wxID_EXIT,     MiFrame::OnQuit)
    EVT_SIZE(               MiFrame::OnSize)//No tiene argumento
    EVT_BUTTON(wxID_OK,     MiFrame::OnButtonOk)
END_EVENT_TABLE()

//Declaracion de OnAbout conectado al click del raton desde la EVENT_TABLE
void MiFrame::OnAbout(wxCommandEvent& event)
{
    wxString mensaje;
    //Contenido dentro de la ventana abierta
    mensaje.Printf(wxT("La version wxWidgets es %s"),wxVERSION_STRING);
    //Nombre de la barra de titulo Antonio Villanueva
    wxMessageBox (mensaje,wxT("Antonio Villanueva"),wxOK | wxICON_INFORMATION,this);
}
//Declaracion de OnQuit conectado al click del raton desde la EVENT_TABLE
void MiFrame::OnQuit(wxCommandEvent& event)
{
    //Destruccion del Frame , de hecho va generar un wxEVT_CLOSE_WINDOW
    //wxWidgets gestiona por defecto este evento
    Close();
}

void MiFrame::OnSize(wxSizeEvent& event)//Manipulacion del Frame
{
	//wxMessageBox( wxT("Cambiando size de la ventana !") );
}

void MiFrame::OnButtonOk(wxCommandEvent& event)//Manipula boton OK
{
    //Abre ventana informando ....
    wxMessageBox( wxT("Has hecho click en el boton OK !") );
}

//Constructor de MiFrame implementa un icono una barra status y menu
//wxID_ANY le dice a Widgets de generar un identificador por su cuenta
MiFrame::MiFrame(const wxString& titulo):wxFrame(NULL,wxID_ANY,title)
{
    //Define el icono del frame
    //SetIcon(wxIcon(imagen_xpm));

    //Crea la barra de Menu
    wxMenu *fileMenu=new wxMenu;

    //Crea el menu
    wxMenu *menuAyuda=new wxMenu;

    //Anade el Acerca de en el menu de ayuda
    menuAyuda->Append(wxID_ABOUT,wxT("&Acerca ...\tF1"),
                        wxT("Muestra Dialogo Acerca de "));

    //Anade el Salir en el fileMenu
    fileMenu->Append(wxID_EXIT,wxT("E&xit\tALT+X"),
                                wxT("Salir "));
    //Creamos la barra de menus
    wxMenuBar *menuBar=new wxMenuBar();

    //Ahora los anadimos a la barra de menu
    menuBar->Append(fileMenu,wxT("&File"));
    menuBar->Append(menuAyuda,wxT("&Ayuda"));

    //Adjuntamos este Menu al Frame
    SetMenuBar(menuBar);


    //Crea una barra de estado inferior,solo para divertirnos
    CreateStatusBar(2);
    SetStatusText(wxT("Barra inferior"));//Inferior ventana

    //Crea un boton OK y lo coloca en el centro de la ventana
    wxButton* boton=new wxButton(this,wxID_OK,wxT("OK"),wxPoint(150,100));

}

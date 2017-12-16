#include <Windows.h>
#include <string>
using namespace std;
#define V_ALTO 160
#define V_ANCHO 245
#define V_TITULO "Primera Victima GUI"
#define V_CLASE "PrimeraVictimaGUI"
#define V_COLOR static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
#define CL_BLANCO RGB(255, 255, 255)
#define CL_NEGRO RGB(0, 0, 0)
#define CL_ROJO RGB(255, 0, 0)
#define CL_VERDE RGB(0, 255, 0)
#define CL_AZUL RGB(0, 0, 255)
#define FONT_SIZE 20
#define FONT_NAME "Comic Sans MS"
#define NO_CTRLS 1
#define C_LABEL "STATIC"
#define C_BUTTON "BUTTON"

#define L1_ALTO 20
#define L1_ANCHO 210
#define L1_X 10
#define L1_Y 50
#define L1_ID 0
#define L1_TEXT "HOLA"
#define L1_ESTILO ES_CENTER | WS_CHILD | WS_VISIBLE

typedef struct {
	LPSTR Tipo;
	LPSTR Texto;
	HANDLE CtrlHWND;
	DWORD ID;
	INT Alto;
	INT Ancho;
	INT PosX;
	INT PosY;
	DWORD Estilo;
} CONTROL, *PCONTROL;

class Window {
private:
	HWND hwnd; // handle de ventana
	HINSTANCE hInstance; // Instancia de la aplicación
	WNDCLASSEX wincl; // Clase de ventana
	PCONTROL Control; // Controles de la ventana
	HFONT hfComicSans; // Fuente de los controles
	HBRUSH PincelStatic; // Pincel de colores

	void CentrarVentana(); // Ubicar la ventana en el centro
	void Inicializar(); // Inicializar todos los datos
	void CrearControles(); // Crear controles de la ventana

	// Procedimiento dinámico de ventana
	LRESULT WndProc(HWND, UINT, WPARAM, LPARAM);

	/*
	 ----PARTE IMPORTANTE----
	 LA API DE WINDOWS NECESITA REFERENCIAS ESTÁTICAS
	 EN SUS FUNCIONES ENTONCES, NO PODEMOS USAR UN PROCEDIMIENTO DE HILO, DIÁLOGO
	 O VENTANA EN UNA CLASE PORQUE DEBE SER ESTÁTICO Y POR ENDE, NO SE PUEDEN HACER
	 REFERENCIAS A MIEMBROS DINÁMICOS DESDE UN PRODEDIMIENTO ESTÁTICO, POR EJEMPLO:
	 EL PUNTERO this NO PUEDE SER USADO DESDE UN MIEMBRO ESTÁTICO.

	 PARA SOLUCIONAR ESTE INCONVENIENTE, TENEMOS QUE HACER UNAS CUANTAS COSAS.
	 EN EL CASO DE LOS HILOS, DEBEMOS PASAR EL PUNTERO this COMO PARÁMETRO, ESTO
	 ES PARA PODER DECLARAR UNA CLASE QUE TENGA ESA DIRECCIÓN Y PODER USAR LOS
	 MIEMBROS DINÁMICOS, PERO DE MANERA ESTÁTICA.
	 EN EL CASO DEL PROCEDIMIENTO DE VENTANA, LA COSA SE COMPLICA AUNQUE LA
	 LÓGICA ES LA MISMA, DEBEMOS PASAR EL PUNTERO this COMO ÚLTIMO PARÁMETRO Y
	 USARLO EN EL EVENTO "WM_NCCREATE" Y GUARDARLO EN LA SECCIÓN USERDATA QUE
	 ALMACENA UN DWORD. LUEGO CAMBIAMOS EL PUNTERO AL PROCEDIMIENTO ESTÁTICO A
	 OTRO SIMILAR PERO MÁS LIGERO.
	 ESTE PROCEDIMIENTO LIGERO, LO QUE HACE ES RECUPERAR EL PUNTERO this, LO
	 CONVIERTE EN UNA CLASE Y LLAMA AL PROCEDIMIENTO DINÁMICO. */

// Procedimiento de ventana inicial, para inicializaciones
static LRESULT CALLBACK WinProcInicial(HWND hWnd, UINT Msg, WPARAM wParam,
		LPARAM lParam) {
	if (Msg == WM_NCCREATE)
	{ // Lparam contiene una referencia a una estructura de tipo:
		LPCREATESTRUCT CreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
		// El puntero this se encuentra en el campo lpCreateParams
		void * lpCreateParam = CreateStruct->lpCreateParams;
		// Armamos una referencia a la clase que apunta this
		Window * EstaVentana = reinterpret_cast<Window*>(lpCreateParam);
		// Guardamos el puntero this en la sección USERDATA
		SetWindowLongPtr(hWnd, GWLP_USERDATA,
				reinterpret_cast<LONG_PTR>(EstaVentana));
		// Cambiamos la dirección del procedimiento de ventana
		SetWindowLongPtr(hWnd, GWLP_WNDPROC,
				reinterpret_cast<LONG_PTR>(&Window::WinProcRedir));
	}
	// Si no es el evento NCCREATE o si ya terminamos...
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

static LRESULT CALLBACK WinProcRedir(HWND hWnd, UINT Msg, WPARAM wParam,
		LPARAM lParam) { // Recuperamos el puntero this
	LONG_PTR UserData = GetWindowLongPtr(hWnd, GWLP_USERDATA);
	// Armamos la clase
	Window * EstaVentana = reinterpret_cast<Window*>(UserData);
	// Llamamos al procedimiento dinámico
	return EstaVentana->WndProc(hWnd, Msg, wParam, lParam);
}

public:
Window(HINSTANCE hInst);
void Correr(); // Iniciar la aplicación
};

// DEFINICION DE LA CLASE............
Window::Window(HINSTANCE hInst) {
	hInstance = hInst;
	Inicializar();
}

void Window::Inicializar() { // Datos de la ventana
	wincl.hInstance = hInstance;
	wincl.lpszClassName = V_CLASE;
	wincl.hbrBackground = V_COLOR;
	wincl.lpfnWndProc = &Window::WinProcInicial;
	wincl.style = CS_DBLCLKS;
	wincl.cbSize = sizeof(WNDCLASSEX);
	wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;
	wincl.cbClsExtra = NULL;
	wincl.cbWndExtra = NULL;

	// Registrar la clase
	RegisterClassEx(&wincl);
	// Crear la Ventana
	hwnd = CreateWindowEx(NULL, V_CLASE, V_TITULO,
			WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
			V_ANCHO, V_ALTO, NULL, (HMENU) NULL, hInstance, (LPVOID)this);
	// Crear controles de la ventana
	CrearControles();
}

void Window::CentrarVentana() { // Obtener coordenadas horizontales centrales
	int posX = (GetSystemMetrics(SM_CXSCREEN) / 2) - (V_ANCHO / 2);
	// Obtener coordenadas verticales centrales
	int posY = (GetSystemMetrics(SM_CYSCREEN) / 2) - (V_ALTO / 2);
	// Centrar la ventana en pantalla
	SetWindowPos(hwnd, NULL, posX, posY, NULL, NULL, SWP_NOSIZE);
}

void Window::CrearControles() { // Crear tantos controles como indique NO_CTRLS
	Control = new CONTROL[NO_CTRLS];
	// Llenar los datos de los controles....
	Control[L1_ID].Alto = L1_ALTO;
	Control[L1_ID].Ancho = L1_ANCHO;
	Control[L1_ID].PosX = L1_X;
	Control[L1_ID].PosY = L1_Y;
	Control[L1_ID].Tipo = C_LABEL;
	Control[L1_ID].Estilo = L1_ESTILO;
	Control[L1_ID].Texto = L1_TEXT;
	Control[L1_ID].ID = L1_ID;
	// Crear la fuente que usarán los controles
	hfComicSans = CreateFont(FONT_SIZE, NULL, NULL, NULL, FW_NORMAL, FALSE, FALSE,
			FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, FONT_NAME);
	// El pincel de fondo de los controles
	PincelStatic = CreateSolidBrush(CL_NEGRO);
	// Crear los controles y asignarle el texto a cada uno
	for (int i = 0; i < NO_CTRLS; i++) {
		Control[i].CtrlHWND = CreateWindowEx(NULL, Control[i].Tipo, NULL,
				Control[i].Estilo, Control[i].PosX, Control[i].PosY, Control[i].Ancho,
				Control[i].Alto, hwnd, (HMENU)Control[i].ID, NULL, NULL);
		SetDlgItemText(hwnd, Control[i].ID, Control[i].Texto);
		SendMessage(GetDlgItem(hwnd, i), WM_SETFONT,
				reinterpret_cast<WPARAM>(hfComicSans), TRUE);
	}
}

LRESULT Window::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
	switch (Msg) {
	case WM_DESTROY: // Si el usuario pulsa la "X", nos vamos
				PostQuitMessage(0);
		break;
		// Asignar los colores a los controles
	case WM_CTLCOLORSTATIC:
		SetBkColor((HDC)wParam, CL_NEGRO);
		if (((HWND)lParam == Control[L1_ID].CtrlHWND)) {
			SetTextColor((HDC)wParam, CL_ROJO);
		}
		else {
			SetTextColor((HDC)wParam, CL_VERDE);
		}

		return (LRESULT)PincelStatic;
	default:
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}
	return 0;
}

// Ciclo principal del programa.
void Window::Correr() {
	MSG mensaje;
	CentrarVentana();
	ShowWindow(hwnd, SW_SHOWDEFAULT);
	UpdateWindow(hwnd);
	while (GetMessage(&mensaje, hwnd, NULL, NULL) == TRUE) {
		TranslateMessage(&mensaje);
		DispatchMessage(&mensaje);
	}
}

// El main de nuestro programa
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
		LPTSTR lpCmdLine, int nCmdShow) {
	// Creamos la ventana.
	Window *Ventana = new Window(hInstance);
	// Abrimos la ventana
	Ventana->Correr();
	delete Ventana;
	return EXIT_SUCCESS;
}
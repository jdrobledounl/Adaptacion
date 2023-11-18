/*
* ADAPTACION: Investigue e implemente una aplicaci�n que permita al usuario cambiar el tama�o de la
ventana, pero que el mismo no pueda ser menor a 100x100 ni mayor a 1000x1000. 
Nota: para este ejercicio trat� de interpretar el c�digo generado a trav�s de IA tras haber intentado 
generar un c�digo que ponga l�mites inferiores y superiores pero sin resultados satisfactorios.

*/
#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    // Configuraci�n de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Resizable Window");

    // Limites de tama�o de la ventana
    const int minWidth = 100;
    const int minHeight = 100;
    const int maxWidth = 1000;
    const int maxHeight = 1000;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::Resized:
                // Asegurar que el tama�o est� dentro de los l�mites
                if (event.size.width < minWidth) {
                    event.size.width = minWidth;
                }
                else if (event.size.width > maxWidth) {
                    event.size.width = maxWidth;
                }

                if (event.size.height < minHeight) {
                    event.size.height = minHeight;
                }
                else if (event.size.height > maxHeight) {
                    event.size.height = maxHeight;
                }

                // Actualizar el tama�o de la ventana
                window.setSize(sf::Vector2u(event.size.width, event.size.height));
                break;

            default:
                break;
            }
        }

        // L�gica del juego aqu�...

        // Dibujar en la ventana
        window.clear(sf::Color::White);

        // Dibujar otros elementos aqu�...

        window.display();
    }

    return 0;
}
